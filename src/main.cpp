#include "main.h"
#include "mockup.h"

#include <Arduino.h>
#include <Wire.h>
#include <HTTPClient.h>

#include <SPI.h>
#include <TFT_eSPI.h>
#include "FT62XXTouchScreen.h"
#include "Adafruit_SHTC3.h"
#include "Sensesiot.h"

#include <WiFi.h>
#include <EEPROM.h>

TFT_eSPI tft = TFT_eSPI();
FT62XXTouchScreen touchScreen = FT62XXTouchScreen(TFT_WIDTH, PIN_SDA, PIN_SCL);

#include "esp_freertos_hooks.h"
#include "ui/ui.h"

static const uint16_t screenWidth = 480;
static const uint16_t screenHeight = 320;

static lv_disp_draw_buf_t disp_buf;
static lv_color_t buf[screenWidth * 10];

static void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p);
static void touchpad_read(lv_indev_drv_t *drv, lv_indev_data_t *data);

static void lv_tick_task(void *arg);
static void lv_handler_task(void *arg);
static void update_screen_task(void *arg);

esp_timer_handle_t ticker_timer;
esp_timer_handle_t handler_timer;
esp_timer_handle_t update_screen_timer;
const esp_timer_create_args_t ticker_timer_args = {
    .callback = &lv_tick_task,
    .name = "lv_tick_task"};
const esp_timer_create_args_t ticker_handler_args = {
    .callback = &lv_handler_task,
    .name = "lv_handler_task"};
const esp_timer_create_args_t update_screen_args = {
    .callback = &update_screen_task,
    .name = "update_screen_task"};

Adafruit_SHTC3 shtc3 = Adafruit_SHTC3();
bool hasShtc3;
sensors_event_t humidityEvent, tempEvent;

#define SOIL_MOIST_PIN (A0)
// TODO led light switch assign here
#define LED_RELAY_PIN (2)
#define PUMP_RELAY_PIN (32)
#define FAN_RELAY_PIN (33)

#define PIN_ACTIVE_LOW (0)

#define SOIL_MOIST_VAL_MAX (800)
#define SOIL_MOIST_VAL_MIN (200)

unsigned long dataReadTs;
unsigned long sendDataTs;
#define DATA_READ_DELAY (1000)
#define SEND_DATA_DELAY (2000)

double temp = NAN;
double humid = NAN;
double lightLux = NAN;
double waterLevel = NAN;
bool ledState = false;
bool pumpState = false;
bool fanState = false;

String ssid;
String wifiPw;
String siotUid;
String siotDevKey;
uint8_t tempSlot;
uint8_t humidSlot;
uint8_t lightSlot;
uint8_t waterSlot;
uint8_t ledCtrlSlot;
uint8_t pumpCtrlSlot;
uint8_t fanCtrlSlot;

SensesiotClient protocol = SensesiotClient(siotUid, siotDevKey);
enum connect_state
{
  NO_CONNECT,
  WIFI_CONNECTED,
  MQTT_FAILED,
  MQTT_CONNECTED,
};
connect_state connectingState = NO_CONNECT;

lv_obj_t *textareaRef;

static void initEEPROM();
static void initUI2();
static void beginWifi();
static void setSwitchStateTo(lv_obj_t *target, bool state);
static void updateDataStatus();
static void controlLedTo(bool state);
static void controlPumpTo(bool state);
static void controlFanTo(bool state);
static void controlLedToggle();
static void controlPumpToggle();
static void controlFanToggle();
void toggleLedWithProtocol();
void togglePumpWithProtocol();
void toggleFanWithProtocol();
void updateSettingPage();
void boundEditText(lv_obj_t *target, lv_keyboard_mode_t mode, bool isPassword);
void validateEditText();
lv_obj_t *getSettingPageBackFromEnterText(lv_obj_t *textareaRef);
static bool checkSlotNotDuplicate(int value, lv_obj_t *target);
static bool checkCtrlSlotNotDuplicate(int value, lv_obj_t *target);
void confirmEditSetting();
static void updateEEPROM();

static void onControlCallback(uint8_t slot, const char *data);

static double getTemp();
static double getHumidity();
static double getLight();
static double getWaterLevel();
static uint8_t boolToDigitalState(bool state);
static void setHwLed(uint8_t state);
static void setHwPump(uint8_t state);
static void setHwFan(uint8_t state);

void setup()
{
  Serial.begin(115200);

#if !SENSOR_MOCKUP_DEMO
  Wire.setPins(PIN_SDA, PIN_SCL);
  hasShtc3 = shtc3.begin();

  pinMode(LED_RELAY_PIN, OUTPUT);
  pinMode(PUMP_RELAY_PIN, OUTPUT);
  pinMode(FAN_RELAY_PIN, OUTPUT);
  setHwLed(ledState);
  setHwPump(pumpState);
  setHwFan(fanState);
#endif

  initEEPROM();
  beginWifi();

  lv_init();
  ESP_ERROR_CHECK(esp_timer_create(&ticker_timer_args, &ticker_timer));
  ESP_ERROR_CHECK(esp_timer_start_periodic(ticker_timer, portTICK_RATE_MS * 1000));

  // Enable TFT
  tft.begin();
  tft.setRotation(1);

  // Enable Backlight
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, 1);

  // Start TouchScreen
  touchScreen.begin();

  // Display Buffer
  lv_disp_draw_buf_init(&disp_buf, buf, NULL, screenWidth * 10);

  /*Initialize the display*/
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &disp_buf;
  lv_disp_drv_register(&disp_drv);

  // Init Touchscreen
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = touchpad_read;
  lv_indev_drv_register(&indev_drv);

  ui_init();
  initUI2();
  lv_disp_load_scr(ui_PlantScreen);

  dataReadTs = millis();
  sendDataTs = millis();

  ESP_ERROR_CHECK(esp_timer_create(&ticker_handler_args, &handler_timer));
  ESP_ERROR_CHECK(esp_timer_start_periodic(handler_timer, 10 * portTICK_RATE_MS * 1000));

  ESP_ERROR_CHECK(esp_timer_create(&update_screen_args, &update_screen_timer));
  ESP_ERROR_CHECK(esp_timer_start_periodic(update_screen_timer, 100 * portTICK_RATE_MS * 1000));
}

void loop()
{
  protocol.loop();

  if (protocol.wifiStatus() == WL_CONNECTED)
  {
    if (connectingState == NO_CONNECT)
    {
      connectingState = WIFI_CONNECTED;
      protocol.connectMqtt();
    }
    else if (!protocol.ready())
    {
      connectingState = MQTT_FAILED;
      protocol.connectMqtt();
    }
    else if ((connectingState == WIFI_CONNECTED || connectingState == MQTT_FAILED) && protocol.ready())
    {
      connectingState = MQTT_CONNECTED;

      protocol.subscribeControl(ledCtrlSlot);
      protocol.subscribeControl(pumpCtrlSlot);
      protocol.subscribeControl(fanCtrlSlot);

      protocol.retainControl(ledCtrlSlot);
      protocol.retainControl(pumpCtrlSlot);
      protocol.retainControl(fanCtrlSlot);
    }
  }
  else if (protocol.wifiStatus() != WL_DISCONNECTED && protocol.wifiStatus() != WL_IDLE_STATUS)
  {
    beginWifi();
  }

  if (millis() - dataReadTs >= DATA_READ_DELAY)
  {
    dataReadTs = millis();

    hasShtc3 = shtc3.begin();

    temp = getTemp();
    humid = getHumidity();
    lightLux = getLight();
    waterLevel = getWaterLevel();

    // Serial.printf("t:%.2f, h:%.2f, l:%.2f, w:%.2f\n", temp, humid, lightLux, waterLevel);
  }

  if (millis() - sendDataTs >= SEND_DATA_DELAY && connectingState == MQTT_CONNECTED)
  {
    sendDataTs = millis();

    if (!isnan(temp))
    {
      protocol.setData(tempSlot, temp);
    }
    if (!isnan(humid))
    {
      protocol.setData(humidSlot, humid);
    }
    if (!isnan(lightLux))
    {
      protocol.setData(lightSlot, lightLux);
    }
    if (!isnan(waterLevel))
    {
      protocol.setData(waterSlot, waterLevel);
    }
  }

  delay(5);
}

static void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

  tft.startWrite();
  tft.setAddrWindow(area->x1, area->y1, w, h);
  tft.pushColors(&color_p->full, w * h, true);
  tft.endWrite();

  lv_disp_flush_ready(disp);
}

static void touchpad_read(lv_indev_drv_t *drv, lv_indev_data_t *data)
{
  TouchPoint touchPos = touchScreen.read();
  if (touchPos.touched)
  {
    data->state = LV_INDEV_STATE_PR;
    data->point.x = touchPos.xPos;
    data->point.y = touchPos.yPos;
  }
  else
  {
    data->state = LV_INDEV_STATE_REL;
  }
}

static void lv_tick_task(void *arg)
{
  lv_tick_inc(portTICK_RATE_MS);
}

static void lv_handler_task(void *arg)
{
  lv_task_handler();
}

static void update_screen_task(void *arg)
{
  if (lv_scr_act() == ui_PlantScreen)
  {
    updateDataStatus();

    lv_label_set_text(ui_PlantScreenTempValueLabel, isnan(temp) ? "-" : String(temp, 1).c_str());
    lv_label_set_text(ui_PlantScreenHumidValueLabel, isnan(humid) ? "-" : String(humid, 1).c_str());
    lv_label_set_text(ui_PlantScreenLightValueLabel, isnan(lightLux) ? "-" : String(lightLux, 0).c_str());

    String waterLevelStr = isnan(waterLevel) ? "-" : String(waterLevel, 0);
    if (!isnan(waterLevel))
    {
      waterLevelStr.concat("%");
    }
    lv_label_set_text(ui_PlantScreenWaterValueLabel, waterLevelStr.c_str());

    if (!isnan(waterLevel))
    {
      lv_bar_set_value(ui_PlantScreenWaterBar, waterLevel, LV_ANIM_ON);
    }
  }
}

static void initUI2()
{
  lv_label_set_text(ui_PlantScreenStatusLabel, "Connecting...");
  lv_bar_set_range(ui_PlantScreenWaterBar, 0, 100);
  lv_bar_set_value(ui_PlantScreenWaterBar, 0, LV_ANIM_ON);
  setSwitchStateTo(ui_PlantScreenLedSwitch, ledState);
  setSwitchStateTo(ui_PlantScreenPumpSwitch, pumpState);
  setSwitchStateTo(ui_PlantScreenFanSwitch, fanState);

  updateDataStatus();
}

static void initEEPROM()
{
  if (!EEPROM.begin(EEPROM_TOTAL_BYTES))
  {
    Serial.println("EEPROM init error");
    return;
  }

  uint64_t header = EEPROM.readULong64(EEPROM_HEADER_ADDR);

  if (header != EEPROM_HEADER_KEY)
  {
#ifdef EEPROM_WRITE
    EEPROM.writeULong64(EEPROM_HEADER_ADDR, EEPROM_HEADER_KEY);
#endif

    EEPROM.writeString(EEPROM_SSID_ADDR, "wifissid");
    EEPROM.writeString(EEPROM_WIFIPW_ADDR, "wifipw");
    EEPROM.writeString(EEPROM_SIOT_UID_ADDR, "sensesiot-uid");
    EEPROM.writeString(EEPROM_SIOT_DEVKEY_ADDR, "sensesiot-devkey");
    EEPROM.writeByte(EEPROM_TEMP_SLOT_ADDR, 1);
    EEPROM.writeByte(EEPROM_HUMID_SLOT_ADDR, 2);
    EEPROM.writeByte(EEPROM_LIGHT_SLOT_ADDR, 4);
    EEPROM.writeByte(EEPROM_WATER_SLOT_ADDR, 3);
    EEPROM.writeByte(EEPROM_LED_CTRL_SLOT_ADDR, 1);
    EEPROM.writeByte(EEPROM_PUMP_CTRL_SLOT_ADDR, 2);
    EEPROM.writeByte(EEPROM_FAN_CTRL_SLOT_ADDR, 3);
    EEPROM.commit();
  }

  // Read values
  ssid = EEPROM.readString(EEPROM_SSID_ADDR);
  wifiPw = EEPROM.readString(EEPROM_WIFIPW_ADDR);
  siotUid = EEPROM.readString(EEPROM_SIOT_UID_ADDR);
  siotDevKey = EEPROM.readString(EEPROM_SIOT_DEVKEY_ADDR);
  tempSlot = EEPROM.readByte(EEPROM_TEMP_SLOT_ADDR);
  humidSlot = EEPROM.readByte(EEPROM_HUMID_SLOT_ADDR);
  lightSlot = EEPROM.readByte(EEPROM_LIGHT_SLOT_ADDR);
  waterSlot = EEPROM.readByte(EEPROM_WATER_SLOT_ADDR);
  ledCtrlSlot = EEPROM.readByte(EEPROM_LED_CTRL_SLOT_ADDR);
  pumpCtrlSlot = EEPROM.readByte(EEPROM_PUMP_CTRL_SLOT_ADDR);
  fanCtrlSlot = EEPROM.readByte(EEPROM_FAN_CTRL_SLOT_ADDR);
}

static void beginWifi()
{
  protocol.setUserid(siotUid);
  protocol.setDevicekey(siotDevKey);
  protocol.setControlCallback(onControlCallback);
  protocol.begin(ssid.c_str(), wifiPw.length() > 0 ? wifiPw.c_str() : NULL);

  connectingState = NO_CONNECT;
}

static void setSwitchStateTo(lv_obj_t *target, bool state)
{
  if (state)
  {
    lv_obj_add_state(target, LV_STATE_CHECKED);
  }
  else
  {
    lv_obj_clear_state(target, LV_STATE_CHECKED);
  }
}

static void updateDataStatus()
{
  String status;

  switch (connectingState)
  {
  case NO_CONNECT:
    switch (protocol.wifiStatus())
    {
    case WL_IDLE_STATUS:
      status = String("WiFi Connecting...");
      break;
    case WL_DISCONNECTED:
      status = String("WiFi Disconnected");
      break;
    case WL_NO_SSID_AVAIL:
    case WL_CONNECT_FAILED:
      status = String("WiFi Connect Failed");
      break;
    default:
      status = String("WiFi Error");
      break;
    }
    break;
  case WIFI_CONNECTED:
    status = String("WiFi Connected");
    break;
  case MQTT_FAILED:
    status = String("Can't Connect SensesIoT");
    break;
  case MQTT_CONNECTED:
    status = String("SensesIoT Connected");
    break;
  }

  lv_label_set_text(ui_PlantScreenStatusLabel, status.c_str());
}

static void controlLedTo(bool state)
{
  ledState = state;
  setHwLed(ledState);
  setSwitchStateTo(ui_PlantScreenLedSwitch, ledState);
}

static void controlPumpTo(bool state)
{
  pumpState = state;
  setHwPump(pumpState);
  setSwitchStateTo(ui_PlantScreenPumpSwitch, pumpState);
}

static void controlFanTo(bool state)
{
  fanState = state;
  setHwFan(fanState);
  setSwitchStateTo(ui_PlantScreenFanSwitch, fanState);
}

static void controlLedToggle()
{
  controlLedTo(!ledState);
}

static void controlPumpToggle()
{
  controlPumpTo(!pumpState);
}

static void controlFanToggle()
{
  controlFanTo(!fanState);
}

void toggleLedWithProtocol()
{
  controlLedToggle();
  protocol.setControl(ledCtrlSlot, ledState ? CONTROL_STATE_ON : CONTROL_STATE_OFF);
}

void togglePumpWithProtocol()
{
  controlPumpToggle();
  protocol.setControl(pumpCtrlSlot, pumpState ? CONTROL_STATE_ON : CONTROL_STATE_OFF);
}

void toggleFanWithProtocol()
{
  controlFanToggle();
  protocol.setControl(fanCtrlSlot, fanState ? CONTROL_STATE_ON : CONTROL_STATE_OFF);
}

void updateSettingPage()
{
  lv_textarea_set_text(ui_SettingScreen1SsidTextArea, ssid.c_str());
  lv_textarea_set_text(ui_SettingScreen1WifiPwTextArea, wifiPw.c_str());
  lv_textarea_set_text(ui_SettingScreen1UidTextArea, siotUid.c_str());
  lv_textarea_set_text(ui_SettingScreen1DevKeyTextArea, siotDevKey.c_str());
  lv_textarea_set_text(ui_SettingScreen2TempSlotTextArea, String(tempSlot).c_str());
  lv_textarea_set_text(ui_SettingScreen2HumidSlotTextArea, String(humidSlot).c_str());
  lv_textarea_set_text(ui_SettingScreen2LightSlotTextArea, String(lightSlot).c_str());
  lv_textarea_set_text(ui_SettingScreen2WaterSlotTextArea, String(waterSlot).c_str());
  lv_textarea_set_text(ui_SettingScreen2LedSlotTextArea, String(ledCtrlSlot).c_str());
  lv_textarea_set_text(ui_SettingScreen2PumpSlotTextArea, String(pumpCtrlSlot).c_str());
  lv_textarea_set_text(ui_SettingScreen2FanSlotTextArea, String(fanCtrlSlot).c_str());
}

void boundEditText(lv_obj_t *target, lv_keyboard_mode_t mode, bool isPassword)
{
  textareaRef = target;
  lv_keyboard_set_textarea(ui_EditTextScreenKeyboard, ui_EditTextScreenTextArea);
  lv_textarea_set_text(ui_EditTextScreenTextArea, isPassword ? "" : lv_textarea_get_text(target));
  lv_keyboard_set_mode(ui_EditTextScreenKeyboard, mode);
}

void validateEditText()
{
  if (textareaRef)
  {
    bool valid = false;

    String data = String(lv_textarea_get_text(ui_EditTextScreenTextArea));
    int slotValue;
    if (textareaRef == ui_SettingScreen1SsidTextArea)
    {
      valid = data.length() > 0;
      data = data.substring(0, SSID_MAXLENGTH);
    }
    else if (textareaRef == ui_SettingScreen1WifiPwTextArea)
    {
      valid = true;
      data = data.substring(0, WIFIPW_MAXLENGTH);
    }
    else if (textareaRef == ui_SettingScreen1UidTextArea)
    {
      valid = data.length() > 0;
      data = data.substring(0, SIOT_UID_MAXLENGTH);
    }
    else if (textareaRef == ui_SettingScreen1DevKeyTextArea)
    {
      valid = data.length() > 0;
      data = data.substring(0, SIOT_DEVKEY_MAXLENGTH);
    }
    else if (textareaRef == ui_SettingScreen2TempSlotTextArea)
    {
      slotValue = data.toInt();
      valid = slotValue > 0 && checkSlotNotDuplicate(slotValue, ui_SettingScreen2TempSlotTextArea);
    }
    else if (textareaRef == ui_SettingScreen2HumidSlotTextArea)
    {
      slotValue = data.toInt();
      valid = slotValue > 0 && checkSlotNotDuplicate(slotValue, ui_SettingScreen2HumidSlotTextArea);
    }
    else if (textareaRef == ui_SettingScreen2LightSlotTextArea)
    {
      slotValue = data.toInt();
      valid = slotValue > 0 && checkSlotNotDuplicate(slotValue, ui_SettingScreen2LightSlotTextArea);
    }
    else if (textareaRef == ui_SettingScreen2WaterSlotTextArea)
    {
      slotValue = data.toInt();
      valid = slotValue > 0 && checkSlotNotDuplicate(slotValue, ui_SettingScreen2WaterSlotTextArea);
    }
    else if (textareaRef == ui_SettingScreen2LedSlotTextArea)
    {
      slotValue = data.toInt();
      valid = slotValue > 0 && checkCtrlSlotNotDuplicate(slotValue, ui_SettingScreen2LedSlotTextArea);
    }
    else if (textareaRef == ui_SettingScreen2PumpSlotTextArea)
    {
      slotValue = data.toInt();
      valid = slotValue > 0 && checkCtrlSlotNotDuplicate(slotValue, ui_SettingScreen2PumpSlotTextArea);
    }
    else if (textareaRef == ui_SettingScreen2FanSlotTextArea)
    {
      slotValue = data.toInt();
      valid = slotValue > 0 && checkCtrlSlotNotDuplicate(slotValue, ui_SettingScreen2FanSlotTextArea);
    }

    if (valid)
    {
      lv_textarea_set_text(textareaRef, data.c_str());
    }
  }
}

lv_obj_t *getSettingPageBackFromEnterText(lv_obj_t *textareaRef)
{
  if (textareaRef == ui_SettingScreen2TempSlotTextArea ||
      textareaRef == ui_SettingScreen2HumidSlotTextArea ||
      textareaRef == ui_SettingScreen2LightSlotTextArea ||
      textareaRef == ui_SettingScreen2WaterSlotTextArea ||
      textareaRef == ui_SettingScreen2LedSlotTextArea ||
      textareaRef == ui_SettingScreen2PumpSlotTextArea ||
      textareaRef == ui_SettingScreen2FanSlotTextArea)
  {
    return ui_SettingScreen2;
  }

  return ui_SettingScreen1;
}

static bool checkSlotNotDuplicate(int value, lv_obj_t *target)
{
  lv_obj_t *allTargets[] = {
      ui_SettingScreen2TempSlotTextArea,
      ui_SettingScreen2HumidSlotTextArea,
      ui_SettingScreen2LightSlotTextArea,
      ui_SettingScreen2WaterSlotTextArea,
  };

  int length = sizeof(allTargets) / sizeof(allTargets[0]);
  int checkValue;

  for (int i = 0; i < length; i++)
  {
    if (allTargets[i] != target)
    {
      checkValue = String(lv_textarea_get_text(allTargets[i])).toInt();
      if (checkValue == value)
      {
        return false;
      }
    }
  }

  return true;
}

static bool checkCtrlSlotNotDuplicate(int value, lv_obj_t *target)
{
  lv_obj_t *allTargets[] = {
      ui_SettingScreen2LedSlotTextArea,
      ui_SettingScreen2PumpSlotTextArea,
      ui_SettingScreen2FanSlotTextArea,
  };

  int length = sizeof(allTargets) / sizeof(allTargets[0]);
  int checkValue;

  for (int i = 0; i < length; i++)
  {
    if (allTargets[i] != target)
    {
      checkValue = String(lv_textarea_get_text(allTargets[i])).toInt();
      if (checkValue == value)
      {
        return false;
      }
    }
  }

  return true;
}

void confirmEditSetting()
{
  ssid = String(lv_textarea_get_text(ui_SettingScreen1SsidTextArea)).substring(0, SSID_MAXLENGTH);
  wifiPw = String(lv_textarea_get_text(ui_SettingScreen1WifiPwTextArea)).substring(0, WIFIPW_MAXLENGTH);
  siotUid = String(lv_textarea_get_text(ui_SettingScreen1UidTextArea)).substring(0, SIOT_UID_MAXLENGTH);
  siotDevKey = String(lv_textarea_get_text(ui_SettingScreen1DevKeyTextArea)).substring(0, SIOT_DEVKEY_MAXLENGTH);

  tempSlot = String(lv_textarea_get_text(ui_SettingScreen2TempSlotTextArea)).toInt();
  humidSlot = String(lv_textarea_get_text(ui_SettingScreen2HumidSlotTextArea)).toInt();
  lightSlot = String(lv_textarea_get_text(ui_SettingScreen2LightSlotTextArea)).toInt();
  waterSlot = String(lv_textarea_get_text(ui_SettingScreen2WaterSlotTextArea)).toInt();

  protocol.unsubscribeControl(ledCtrlSlot);
  protocol.unsubscribeControl(pumpCtrlSlot);
  protocol.unsubscribeControl(fanCtrlSlot);

  ledCtrlSlot = String(lv_textarea_get_text(ui_SettingScreen2LedSlotTextArea)).toInt();
  pumpCtrlSlot = String(lv_textarea_get_text(ui_SettingScreen2PumpSlotTextArea)).toInt();
  fanCtrlSlot = String(lv_textarea_get_text(ui_SettingScreen2FanSlotTextArea)).toInt();

  updateEEPROM();

  beginWifi();
}

static void updateEEPROM()
{
  // Init data
#ifdef EEPROM_WRITE
  EEPROM.writeULong64(EEPROM_HEADER_ADDR, EEPROM_HEADER_KEY);
#endif

  EEPROM.writeString(EEPROM_SSID_ADDR, ssid);
  EEPROM.writeString(EEPROM_WIFIPW_ADDR, wifiPw);
  EEPROM.writeString(EEPROM_SIOT_UID_ADDR, siotUid);
  EEPROM.writeString(EEPROM_SIOT_DEVKEY_ADDR, siotDevKey);
  EEPROM.writeByte(EEPROM_TEMP_SLOT_ADDR, tempSlot);
  EEPROM.writeByte(EEPROM_HUMID_SLOT_ADDR, humidSlot);
  EEPROM.writeByte(EEPROM_LIGHT_SLOT_ADDR, lightSlot);
  EEPROM.writeByte(EEPROM_WATER_SLOT_ADDR, waterSlot);
  EEPROM.writeByte(EEPROM_LED_CTRL_SLOT_ADDR, ledCtrlSlot);
  EEPROM.writeByte(EEPROM_PUMP_CTRL_SLOT_ADDR, pumpCtrlSlot);
  EEPROM.writeByte(EEPROM_FAN_CTRL_SLOT_ADDR, fanCtrlSlot);
  EEPROM.commit();
}

static void onControlCallback(uint8_t slot, const char *data)
{
  String dataStr = String(data);

  if (slot == ledCtrlSlot)
  {
    if (dataStr.equals("on"))
    {
      controlLedTo(HIGH);
    }
    else if (dataStr.equals("off"))
    {
      controlLedTo(LOW);
    }
    else if (dataStr.equals(""))
    {
      controlLedToggle();
    }
  }
  else if (slot == pumpCtrlSlot)
  {
    if (dataStr.equals("on"))
    {
      controlPumpTo(HIGH);
    }
    else if (dataStr.equals("off"))
    {
      controlPumpTo(LOW);
    }
    else if (dataStr.equals(""))
    {
      controlPumpToggle();
    }
  }
  else if (slot == fanCtrlSlot)
  {
    if (dataStr.equals("on"))
    {
      controlFanTo(HIGH);
    }
    else if (dataStr.equals("off"))
    {
      controlFanTo(LOW);
    }
    else if (dataStr.equals(""))
    {
      controlFanToggle();
    }
  }
}

#if SENSOR_MOCKUP_DEMO
static double getTemp()
{
  double t1 = millis() * 0.001;
  double temp = 20 + (10 * __dRandomT(t1));
  return temp;
}
static double getHumidity()
{
  double t1 = millis() * 0.001 + 50000;
  double humid = 50 + (50 * __dRandomT(t1));
  return humid;
}
static double getLight()
{
  double t1 = millis() * 0.001 + 70000;
  double humid = 10000 + (2000 * __dRandomT(t1));
  return humid;
}
static double getWaterLevel()
{
  double t1 = millis() * 0.001 + 20000;
  double humid = 50 + (50 * __dRandomT(t1));
  return humid;
}
#else
static double getTemp()
{
  if (hasShtc3 && shtc3.getEvent(&humidityEvent, &tempEvent))
  {
    return tempEvent.temperature;
  }
  else
  {
    return NAN;
  }
}
static double getHumidity()
{
  if (hasShtc3 && shtc3.getEvent(&humidityEvent, &tempEvent))
  {
    return humidityEvent.relative_humidity;
  }
  else
  {
    return NAN;
  }
}
static double getLight()
{
  return NAN;
}
static double getWaterLevel()
{
  int sensorValue = analogRead(SOIL_MOIST_PIN);

  // value transform
  if (sensorValue < SOIL_MOIST_VAL_MIN)
  {
    return 100;
  }
  else if (sensorValue > SOIL_MOIST_VAL_MAX)
  {
    return 0;
  }

  int divisor = (SOIL_MOIST_VAL_MAX - SOIL_MOIST_VAL_MIN);
  double result = (SOIL_MOIST_VAL_MAX - sensorValue) * 100.0f / divisor;

  return result;
}
#endif

static uint8_t boolToDigitalState(bool state)
{
  uint8_t onState = PIN_ACTIVE_LOW ? LOW : HIGH;
  uint8_t offState = PIN_ACTIVE_LOW ? HIGH : LOW;

  return state ? onState : offState;
}

#if SENSOR_MOCKUP_DEMO
static void setHwLed(uint8_t state)
{
  // IDLE
}
static void setHwPump(uint8_t state)
{
  // IDLE
}
static void setHwFan(uint8_t state)
{
  // IDLE
}
#else
static void setHwLed(uint8_t state)
{
  uint8_t actualState = boolToDigitalState(state);
  digitalWrite(LED_RELAY_PIN, actualState);
}
static void setHwPump(uint8_t state)
{
  uint8_t actualState = boolToDigitalState(state);
  digitalWrite(PUMP_RELAY_PIN, actualState);
}
static void setHwFan(uint8_t state)
{
  uint8_t actualState = boolToDigitalState(state);
  digitalWrite(FAN_RELAY_PIN, actualState);
}
#endif
