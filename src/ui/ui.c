// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.2.0
// LVGL VERSION: 8.2.0
// PROJECT: Plant_Screen

#include "ui.h"
#include "ui_helpers.h"

// PROJECT: Plant_Screen

///////////////////// VARIABLES ////////////////////
lv_obj_t *ui_PlantScreen;
lv_obj_t *ui_PlantScreenTempPanel;
lv_obj_t *ui_PlantScreenTempLabel;
lv_obj_t *ui_PlantScreenTempValueLabel;
lv_obj_t *ui_PlantScreenTempUnitLabel;
lv_obj_t *ui_PlantScreenHumidPanel;
lv_obj_t *ui_PlantScreenHumidLabel;
lv_obj_t *ui_PlantScreenHumidValueLabel;
lv_obj_t *ui_PlantScreenHumidUnitLabel;
lv_obj_t *ui_PlantScreenLightPanel;
lv_obj_t *ui_PlantScreenLightLabel;
lv_obj_t *ui_PlantScreenLightValueLabel;
lv_obj_t *ui_PlantScreenLightUnitLabel;
void ui_event_DataScreenSettingBtn(lv_event_t *e);
lv_obj_t *ui_DataScreenSettingBtn;
lv_obj_t *ui_DatsScreenSettingLabel;
lv_obj_t *ui_PlantScreenWaterPanel;
lv_obj_t *ui_PlantScreenWaterLabel;
lv_obj_t *ui_PlantScreenWaterBar;
lv_obj_t *ui_PlantScreenWaterValueLabel;
lv_obj_t *ui_PlantScreenSwitchPanel;
lv_obj_t *ui_PlantScreenLedPanel;
lv_obj_t *ui_PlantScreenLedLabel;
void ui_event_PlantScreenLedSwitch(lv_event_t *e);
lv_obj_t *ui_PlantScreenLedSwitch;
lv_obj_t *ui_PlantScreenPumpPanel;
lv_obj_t *ui_PlantScreenPumpLabel;
void ui_event_PlantScreenPumpSwitch(lv_event_t *e);
lv_obj_t *ui_PlantScreenPumpSwitch;
lv_obj_t *ui_PlantScreenFanPanel;
lv_obj_t *ui_PlantScreenFanLabel;
void ui_event_PlantScreenFanSwitch(lv_event_t *e);
lv_obj_t *ui_PlantScreenFanSwitch;
lv_obj_t *ui_PlantScreenStatusLabel;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
#error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP != 0
#error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_DataScreenSettingBtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        toSettingPage(e);
    }
}
void ui_event_PlantScreenLedSwitch(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        toggleLedSwitch(e);
    }
}
void ui_event_PlantScreenPumpSwitch(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        togglePumpSwitch(e);
    }
}
void ui_event_PlantScreenFanSwitch(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        toggleFanSwitch(e);
    }
}

///////////////////// SCREENS ////////////////////
void ui_PlantScreen_screen_init(void)
{
    ui_PlantScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_PlantScreen, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_PlantScreenTempPanel = lv_obj_create(ui_PlantScreen);
    lv_obj_set_width(ui_PlantScreenTempPanel, 100);
    lv_obj_set_height(ui_PlantScreenTempPanel, 115);
    lv_obj_set_x(ui_PlantScreenTempPanel, -50);
    lv_obj_set_y(ui_PlantScreenTempPanel, -85);
    lv_obj_set_align(ui_PlantScreenTempPanel, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_PlantScreenTempPanel, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_PlantScreenTempPanel, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PlantScreenTempPanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_PlantScreenTempPanel, lv_color_hex(0xFFEFEF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PlantScreenTempPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PlantScreenTempLabel = lv_label_create(ui_PlantScreenTempPanel);
    lv_obj_set_width(ui_PlantScreenTempLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_PlantScreenTempLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_PlantScreenTempLabel, 0);
    lv_obj_set_y(ui_PlantScreenTempLabel, -35);
    lv_obj_set_align(ui_PlantScreenTempLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PlantScreenTempLabel, "Temp");

    ui_PlantScreenTempValueLabel = lv_label_create(ui_PlantScreenTempPanel);
    lv_obj_set_width(ui_PlantScreenTempValueLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_PlantScreenTempValueLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_PlantScreenTempValueLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PlantScreenTempValueLabel, "-");
    lv_obj_set_style_text_font(ui_PlantScreenTempValueLabel, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PlantScreenTempUnitLabel = lv_label_create(ui_PlantScreenTempPanel);
    lv_obj_set_width(ui_PlantScreenTempUnitLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_PlantScreenTempUnitLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_PlantScreenTempUnitLabel, 0);
    lv_obj_set_y(ui_PlantScreenTempUnitLabel, 35);
    lv_obj_set_align(ui_PlantScreenTempUnitLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PlantScreenTempUnitLabel, "C");

    ui_PlantScreenHumidPanel = lv_obj_create(ui_PlantScreen);
    lv_obj_set_width(ui_PlantScreenHumidPanel, 100);
    lv_obj_set_height(ui_PlantScreenHumidPanel, 115);
    lv_obj_set_x(ui_PlantScreenHumidPanel, 55);
    lv_obj_set_y(ui_PlantScreenHumidPanel, -85);
    lv_obj_set_align(ui_PlantScreenHumidPanel, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_PlantScreenHumidPanel, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_PlantScreenHumidPanel, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PlantScreenHumidPanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_PlantScreenHumidPanel, lv_color_hex(0xE4F1FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PlantScreenHumidPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PlantScreenHumidLabel = lv_label_create(ui_PlantScreenHumidPanel);
    lv_obj_set_width(ui_PlantScreenHumidLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_PlantScreenHumidLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_PlantScreenHumidLabel, 0);
    lv_obj_set_y(ui_PlantScreenHumidLabel, -35);
    lv_obj_set_align(ui_PlantScreenHumidLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PlantScreenHumidLabel, "Humidity");

    ui_PlantScreenHumidValueLabel = lv_label_create(ui_PlantScreenHumidPanel);
    lv_obj_set_width(ui_PlantScreenHumidValueLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_PlantScreenHumidValueLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_PlantScreenHumidValueLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PlantScreenHumidValueLabel, "-");
    lv_obj_set_style_text_font(ui_PlantScreenHumidValueLabel, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PlantScreenHumidUnitLabel = lv_label_create(ui_PlantScreenHumidPanel);
    lv_obj_set_width(ui_PlantScreenHumidUnitLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_PlantScreenHumidUnitLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_PlantScreenHumidUnitLabel, 0);
    lv_obj_set_y(ui_PlantScreenHumidUnitLabel, 35);
    lv_obj_set_align(ui_PlantScreenHumidUnitLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PlantScreenHumidUnitLabel, "%RH");

    ui_PlantScreenLightPanel = lv_obj_create(ui_PlantScreen);
    lv_obj_set_width(ui_PlantScreenLightPanel, 100);
    lv_obj_set_height(ui_PlantScreenLightPanel, 115);
    lv_obj_set_x(ui_PlantScreenLightPanel, 160);
    lv_obj_set_y(ui_PlantScreenLightPanel, -85);
    lv_obj_set_align(ui_PlantScreenLightPanel, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_PlantScreenLightPanel, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_PlantScreenLightPanel, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PlantScreenLightPanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_PlantScreenLightPanel, lv_color_hex(0xFFFAE3), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PlantScreenLightPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PlantScreenLightLabel = lv_label_create(ui_PlantScreenLightPanel);
    lv_obj_set_width(ui_PlantScreenLightLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_PlantScreenLightLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_PlantScreenLightLabel, 0);
    lv_obj_set_y(ui_PlantScreenLightLabel, -35);
    lv_obj_set_align(ui_PlantScreenLightLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PlantScreenLightLabel, "Light");

    ui_PlantScreenLightValueLabel = lv_label_create(ui_PlantScreenLightPanel);
    lv_obj_set_width(ui_PlantScreenLightValueLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_PlantScreenLightValueLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_PlantScreenLightValueLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PlantScreenLightValueLabel, "-");
    lv_obj_set_style_text_font(ui_PlantScreenLightValueLabel, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PlantScreenLightUnitLabel = lv_label_create(ui_PlantScreenLightPanel);
    lv_obj_set_width(ui_PlantScreenLightUnitLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_PlantScreenLightUnitLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_PlantScreenLightUnitLabel, 0);
    lv_obj_set_y(ui_PlantScreenLightUnitLabel, 35);
    lv_obj_set_align(ui_PlantScreenLightUnitLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PlantScreenLightUnitLabel, "Lux");

    ui_DataScreenSettingBtn = lv_btn_create(ui_PlantScreen);
    lv_obj_set_width(ui_DataScreenSettingBtn, 90);
    lv_obj_set_height(ui_DataScreenSettingBtn, 40);
    lv_obj_set_x(ui_DataScreenSettingBtn, 185);
    lv_obj_set_y(ui_DataScreenSettingBtn, 125);
    lv_obj_set_align(ui_DataScreenSettingBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_DataScreenSettingBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_DataScreenSettingBtn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags

    ui_DatsScreenSettingLabel = lv_label_create(ui_DataScreenSettingBtn);
    lv_obj_set_width(ui_DatsScreenSettingLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_DatsScreenSettingLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_DatsScreenSettingLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_DatsScreenSettingLabel, "Setting");

    ui_PlantScreenWaterPanel = lv_obj_create(ui_PlantScreen);
    lv_obj_set_width(ui_PlantScreenWaterPanel, 100);
    lv_obj_set_height(ui_PlantScreenWaterPanel, 235);
    lv_obj_set_x(ui_PlantScreenWaterPanel, -155);
    lv_obj_set_y(ui_PlantScreenWaterPanel, -25);
    lv_obj_set_align(ui_PlantScreenWaterPanel, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_PlantScreenWaterPanel, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_PlantScreenWaterPanel, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PlantScreenWaterPanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_PlantScreenWaterPanel, lv_color_hex(0xECECEC), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PlantScreenWaterPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PlantScreenWaterLabel = lv_label_create(ui_PlantScreenWaterPanel);
    lv_obj_set_width(ui_PlantScreenWaterLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_PlantScreenWaterLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_PlantScreenWaterLabel, 0);
    lv_obj_set_y(ui_PlantScreenWaterLabel, -95);
    lv_obj_set_align(ui_PlantScreenWaterLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PlantScreenWaterLabel, "Water");

    ui_PlantScreenWaterBar = lv_bar_create(ui_PlantScreenWaterPanel);
    lv_bar_set_value(ui_PlantScreenWaterBar, 25, LV_ANIM_OFF);
    lv_obj_set_width(ui_PlantScreenWaterBar, 75);
    lv_obj_set_height(ui_PlantScreenWaterBar, 150);
    lv_obj_set_align(ui_PlantScreenWaterBar, LV_ALIGN_CENTER);
    lv_obj_set_style_radius(ui_PlantScreenWaterBar, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PlantScreenWaterBar, lv_color_hex(0xE7E3E7), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PlantScreenWaterBar, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PlantScreenWaterBar, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_PlantScreenWaterBar, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_PlantScreenWaterValueLabel = lv_label_create(ui_PlantScreenWaterPanel);
    lv_obj_set_width(ui_PlantScreenWaterValueLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_PlantScreenWaterValueLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_PlantScreenWaterValueLabel, 0);
    lv_obj_set_y(ui_PlantScreenWaterValueLabel, 95);
    lv_obj_set_align(ui_PlantScreenWaterValueLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PlantScreenWaterValueLabel, "-");

    ui_PlantScreenSwitchPanel = lv_obj_create(ui_PlantScreen);
    lv_obj_set_width(ui_PlantScreenSwitchPanel, 310);
    lv_obj_set_height(ui_PlantScreenSwitchPanel, 115);
    lv_obj_set_x(ui_PlantScreenSwitchPanel, 55);
    lv_obj_set_y(ui_PlantScreenSwitchPanel, 35);
    lv_obj_set_align(ui_PlantScreenSwitchPanel, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_PlantScreenSwitchPanel, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_PlantScreenSwitchPanel, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PlantScreenSwitchPanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_PlantScreenSwitchPanel, lv_color_hex(0xECECEC), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PlantScreenSwitchPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PlantScreenLedPanel = lv_obj_create(ui_PlantScreenSwitchPanel);
    lv_obj_set_width(ui_PlantScreenLedPanel, 275);
    lv_obj_set_height(ui_PlantScreenLedPanel, 25);
    lv_obj_set_align(ui_PlantScreenLedPanel, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_PlantScreenLedPanel, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_PlantScreenLedPanel, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PlantScreenLedPanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_PlantScreenLedPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PlantScreenLedPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PlantScreenLedPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_PlantScreenLedPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_PlantScreenLedPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_PlantScreenLedPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_PlantScreenLedPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PlantScreenLedLabel = lv_label_create(ui_PlantScreenLedPanel);
    lv_obj_set_width(ui_PlantScreenLedLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_PlantScreenLedLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_PlantScreenLedLabel, -64);
    lv_obj_set_y(ui_PlantScreenLedLabel, -24);
    lv_obj_set_align(ui_PlantScreenLedLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PlantScreenLedLabel, "LED");

    ui_PlantScreenLedSwitch = lv_switch_create(ui_PlantScreenLedPanel);
    lv_obj_set_width(ui_PlantScreenLedSwitch, 50);
    lv_obj_set_height(ui_PlantScreenLedSwitch, 25);
    lv_obj_set_x(ui_PlantScreenLedSwitch, 146);
    lv_obj_set_y(ui_PlantScreenLedSwitch, 3);
    lv_obj_set_align(ui_PlantScreenLedSwitch, LV_ALIGN_CENTER);

    ui_PlantScreenPumpPanel = lv_obj_create(ui_PlantScreenSwitchPanel);
    lv_obj_set_width(ui_PlantScreenPumpPanel, 275);
    lv_obj_set_height(ui_PlantScreenPumpPanel, 25);
    lv_obj_set_align(ui_PlantScreenPumpPanel, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_PlantScreenPumpPanel, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_PlantScreenPumpPanel, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PlantScreenPumpPanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_PlantScreenPumpPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PlantScreenPumpPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PlantScreenPumpPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_PlantScreenPumpPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_PlantScreenPumpPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_PlantScreenPumpPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_PlantScreenPumpPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PlantScreenPumpLabel = lv_label_create(ui_PlantScreenPumpPanel);
    lv_obj_set_width(ui_PlantScreenPumpLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_PlantScreenPumpLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_PlantScreenPumpLabel, -64);
    lv_obj_set_y(ui_PlantScreenPumpLabel, -24);
    lv_obj_set_align(ui_PlantScreenPumpLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PlantScreenPumpLabel, "Pump");

    ui_PlantScreenPumpSwitch = lv_switch_create(ui_PlantScreenPumpPanel);
    lv_obj_set_width(ui_PlantScreenPumpSwitch, 50);
    lv_obj_set_height(ui_PlantScreenPumpSwitch, 25);
    lv_obj_set_x(ui_PlantScreenPumpSwitch, 146);
    lv_obj_set_y(ui_PlantScreenPumpSwitch, 3);
    lv_obj_set_align(ui_PlantScreenPumpSwitch, LV_ALIGN_CENTER);

    ui_PlantScreenFanPanel = lv_obj_create(ui_PlantScreenSwitchPanel);
    lv_obj_set_width(ui_PlantScreenFanPanel, 275);
    lv_obj_set_height(ui_PlantScreenFanPanel, 25);
    lv_obj_set_align(ui_PlantScreenFanPanel, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_PlantScreenFanPanel, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_PlantScreenFanPanel, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PlantScreenFanPanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_PlantScreenFanPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PlantScreenFanPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PlantScreenFanPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_PlantScreenFanPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_PlantScreenFanPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_PlantScreenFanPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_PlantScreenFanPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PlantScreenFanLabel = lv_label_create(ui_PlantScreenFanPanel);
    lv_obj_set_width(ui_PlantScreenFanLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_PlantScreenFanLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_PlantScreenFanLabel, -64);
    lv_obj_set_y(ui_PlantScreenFanLabel, -24);
    lv_obj_set_align(ui_PlantScreenFanLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PlantScreenFanLabel, "Fan");

    ui_PlantScreenFanSwitch = lv_switch_create(ui_PlantScreenFanPanel);
    lv_obj_set_width(ui_PlantScreenFanSwitch, 50);
    lv_obj_set_height(ui_PlantScreenFanSwitch, 25);
    lv_obj_set_x(ui_PlantScreenFanSwitch, 146);
    lv_obj_set_y(ui_PlantScreenFanSwitch, 3);
    lv_obj_set_align(ui_PlantScreenFanSwitch, LV_ALIGN_CENTER);

    ui_PlantScreenStatusLabel = lv_label_create(ui_PlantScreen);
    lv_obj_set_width(ui_PlantScreenStatusLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_PlantScreenStatusLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_PlantScreenStatusLabel, -30);
    lv_obj_set_y(ui_PlantScreenStatusLabel, 125);
    lv_obj_set_align(ui_PlantScreenStatusLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PlantScreenStatusLabel, "Connecting...");

    lv_obj_add_event_cb(ui_DataScreenSettingBtn, ui_event_DataScreenSettingBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PlantScreenLedSwitch, ui_event_PlantScreenLedSwitch, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PlantScreenPumpSwitch, ui_event_PlantScreenPumpSwitch, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PlantScreenFanSwitch, ui_event_PlantScreenFanSwitch, LV_EVENT_ALL, NULL);
}

// PROJECT: Plant_Screen_2

///////////////////// VARIABLES ////////////////////
lv_obj_t *ui_SettingScreen1;
lv_obj_t *ui_SettingScreen1Label;
lv_obj_t *ui_SettingScreen1Panel;
lv_obj_t *ui_SettingScreen1SsidLabel;
lv_obj_t *ui_SettingScreen1SsidTextArea;
void ui_event_SettingScreen1SsidEditBtn(lv_event_t *e);
lv_obj_t *ui_SettingScreen1SsidEditBtn;
lv_obj_t *ui_SettingScreen1SsidEditImg;
lv_obj_t *ui_SettingScreen1WifiPwLabel;
lv_obj_t *ui_SettingScreen1WifiPwTextArea;
void ui_event_SettingScreen1WifiPwEditBtn(lv_event_t *e);
lv_obj_t *ui_SettingScreen1WifiPwEditBtn;
lv_obj_t *ui_SettingScreen1WifiPwImg;
lv_obj_t *ui_SettingScreen1UidLabel;
lv_obj_t *ui_SettingScreen1UidTextArea;
lv_obj_t *ui_SettingScreen1DevKeyLabel;
void ui_event_SettingScreen1UidEditBtn(lv_event_t *e);
lv_obj_t *ui_SettingScreen1UidEditBtn;
lv_obj_t *ui_SettingScreen1UidImg;
lv_obj_t *ui_SettingScreen1DevKeyTextArea;
void ui_event_SettingScreen1DevKeyEditBtn(lv_event_t *e);
lv_obj_t *ui_SettingScreen1DevKeyEditBtn;
lv_obj_t *ui_SettingScreen1DevKeyImg;
void ui_event_SettingScreen1ConfirmBtn(lv_event_t *e);
lv_obj_t *ui_SettingScreen1ConfirmBtn;
lv_obj_t *ui_SettingScreen1ConfirmLabel;
void ui_event_SettingScreen1CancelBtn(lv_event_t *e);
lv_obj_t *ui_SettingScreen1CancelBtn;
lv_obj_t *ui_SettingScreen1CancelLabel;
void ui_event_SettingScreen1NextBtn(lv_event_t *e);
lv_obj_t *ui_SettingScreen1NextBtn;
lv_obj_t *ui_SettingScreen1NextLabel;
lv_obj_t *ui_EditTextScreen;
lv_obj_t *ui_EditTextScreenPanel;
lv_obj_t *ui_EditTextScreenTextArea;
lv_obj_t *ui_EditTextScreenKeyboard;
void ui_event_EditTextScreenConfirmBtn(lv_event_t *e);
lv_obj_t *ui_EditTextScreenConfirmBtn;
lv_obj_t *ui_EditTextScreenConfirmLabel;
void ui_event_EditTextScreenCancelBtn(lv_event_t *e);
lv_obj_t *ui_EditTextScreenCancelBtn;
lv_obj_t *ui_EditTextScreenCancelLabel;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
#error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP != 0
#error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_SettingScreen1SsidEditBtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        toEditSsid(e);
    }
}
void ui_event_SettingScreen1WifiPwEditBtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        toEditWifiPw(e);
    }
}
void ui_event_SettingScreen1UidEditBtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        toEditUid(e);
    }
}
void ui_event_SettingScreen1DevKeyEditBtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        toEditDevKey(e);
    }
}
void ui_event_SettingScreen1ConfirmBtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        settingConfirm(e);
    }
}
void ui_event_SettingScreen1CancelBtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        settingCancel(e);
    }
}
void ui_event_SettingScreen1NextBtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        nextSettingPage(e);
    }
}
void ui_event_EditTextScreenConfirmBtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        enterTextConfirm(e);
    }
}
void ui_event_EditTextScreenCancelBtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        enterTextCancel(e);
    }
}

///////////////////// SCREENS ////////////////////
void ui_SettingScreen1_screen_init(void)
{
    ui_SettingScreen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_SettingScreen1, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_SettingScreen1Label = lv_label_create(ui_SettingScreen1);
    lv_obj_set_width(ui_SettingScreen1Label, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreen1Label, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreen1Label, 0);
    lv_obj_set_y(ui_SettingScreen1Label, -125);
    lv_obj_set_align(ui_SettingScreen1Label, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SettingScreen1Label, "Setting (1/2)");
    lv_obj_set_style_text_font(ui_SettingScreen1Label, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingScreen1Panel = lv_obj_create(ui_SettingScreen1);
    lv_obj_set_width(ui_SettingScreen1Panel, 450);
    lv_obj_set_height(ui_SettingScreen1Panel, 195);
    lv_obj_set_x(ui_SettingScreen1Panel, 0);
    lv_obj_set_y(ui_SettingScreen1Panel, -5);
    lv_obj_set_align(ui_SettingScreen1Panel, LV_ALIGN_CENTER);
    lv_obj_set_scrollbar_mode(ui_SettingScreen1Panel, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_scroll_dir(ui_SettingScreen1Panel, LV_DIR_VER);
    lv_obj_set_style_bg_color(ui_SettingScreen1Panel, lv_color_hex(0xECECEC), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SettingScreen1Panel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingScreen1SsidLabel = lv_label_create(ui_SettingScreen1Panel);
    lv_obj_set_width(ui_SettingScreen1SsidLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreen1SsidLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreen1SsidLabel, 0);
    lv_obj_set_y(ui_SettingScreen1SsidLabel, -60);
    lv_obj_set_align(ui_SettingScreen1SsidLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_SettingScreen1SsidLabel, "Wifi SSID");

    ui_SettingScreen1SsidTextArea = lv_textarea_create(ui_SettingScreen1Panel);
    lv_obj_set_width(ui_SettingScreen1SsidTextArea, 280);
    lv_obj_set_height(ui_SettingScreen1SsidTextArea, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreen1SsidTextArea, 95);
    lv_obj_set_y(ui_SettingScreen1SsidTextArea, -60);
    lv_obj_set_align(ui_SettingScreen1SsidTextArea, LV_ALIGN_LEFT_MID);
    lv_textarea_set_placeholder_text(ui_SettingScreen1SsidTextArea, "Placeholder...");
    lv_textarea_set_one_line(ui_SettingScreen1SsidTextArea, true);
    lv_obj_clear_flag(ui_SettingScreen1SsidTextArea, LV_OBJ_FLAG_CLICKABLE); /// Flags
    lv_obj_set_style_pad_left(ui_SettingScreen1SsidTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_SettingScreen1SsidTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_SettingScreen1SsidTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_SettingScreen1SsidTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingScreen1SsidEditBtn = lv_btn_create(ui_SettingScreen1Panel);
    lv_obj_set_width(ui_SettingScreen1SsidEditBtn, 32);
    lv_obj_set_height(ui_SettingScreen1SsidEditBtn, 32);
    lv_obj_set_x(ui_SettingScreen1SsidEditBtn, 190);
    lv_obj_set_y(ui_SettingScreen1SsidEditBtn, -60);
    lv_obj_set_align(ui_SettingScreen1SsidEditBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreen1SsidEditBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_SettingScreen1SsidEditBtn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags

    ui_SettingScreen1SsidEditImg = lv_img_create(ui_SettingScreen1SsidEditBtn);
    lv_img_set_src(ui_SettingScreen1SsidEditImg, &ui_img_pen_square_png);
    lv_obj_set_width(ui_SettingScreen1SsidEditImg, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreen1SsidEditImg, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_SettingScreen1SsidEditImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreen1SsidEditImg, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_SettingScreen1SsidEditImg, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_SettingScreen1WifiPwLabel = lv_label_create(ui_SettingScreen1Panel);
    lv_obj_set_width(ui_SettingScreen1WifiPwLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreen1WifiPwLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreen1WifiPwLabel, 0);
    lv_obj_set_y(ui_SettingScreen1WifiPwLabel, -20);
    lv_obj_set_align(ui_SettingScreen1WifiPwLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_SettingScreen1WifiPwLabel, "Password");

    ui_SettingScreen1WifiPwTextArea = lv_textarea_create(ui_SettingScreen1Panel);
    lv_obj_set_width(ui_SettingScreen1WifiPwTextArea, 280);
    lv_obj_set_height(ui_SettingScreen1WifiPwTextArea, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreen1WifiPwTextArea, 95);
    lv_obj_set_y(ui_SettingScreen1WifiPwTextArea, -20);
    lv_obj_set_align(ui_SettingScreen1WifiPwTextArea, LV_ALIGN_LEFT_MID);
    lv_textarea_set_placeholder_text(ui_SettingScreen1WifiPwTextArea, "Placeholder...");
    lv_textarea_set_one_line(ui_SettingScreen1WifiPwTextArea, true);
    lv_textarea_set_password_mode(ui_SettingScreen1WifiPwTextArea, true);
    lv_obj_clear_flag(ui_SettingScreen1WifiPwTextArea, LV_OBJ_FLAG_CLICKABLE); /// Flags
    lv_obj_set_style_pad_left(ui_SettingScreen1WifiPwTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_SettingScreen1WifiPwTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_SettingScreen1WifiPwTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_SettingScreen1WifiPwTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingScreen1WifiPwEditBtn = lv_btn_create(ui_SettingScreen1Panel);
    lv_obj_set_width(ui_SettingScreen1WifiPwEditBtn, 32);
    lv_obj_set_height(ui_SettingScreen1WifiPwEditBtn, 32);
    lv_obj_set_x(ui_SettingScreen1WifiPwEditBtn, 190);
    lv_obj_set_y(ui_SettingScreen1WifiPwEditBtn, -20);
    lv_obj_set_align(ui_SettingScreen1WifiPwEditBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreen1WifiPwEditBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_SettingScreen1WifiPwEditBtn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags

    ui_SettingScreen1WifiPwImg = lv_img_create(ui_SettingScreen1WifiPwEditBtn);
    lv_img_set_src(ui_SettingScreen1WifiPwImg, &ui_img_pen_square_png);
    lv_obj_set_width(ui_SettingScreen1WifiPwImg, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreen1WifiPwImg, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_SettingScreen1WifiPwImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreen1WifiPwImg, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_SettingScreen1WifiPwImg, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_SettingScreen1UidLabel = lv_label_create(ui_SettingScreen1Panel);
    lv_obj_set_width(ui_SettingScreen1UidLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreen1UidLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreen1UidLabel, 0);
    lv_obj_set_y(ui_SettingScreen1UidLabel, 20);
    lv_obj_set_align(ui_SettingScreen1UidLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_SettingScreen1UidLabel, "Senses UID");

    ui_SettingScreen1UidTextArea = lv_textarea_create(ui_SettingScreen1Panel);
    lv_obj_set_width(ui_SettingScreen1UidTextArea, 280);
    lv_obj_set_height(ui_SettingScreen1UidTextArea, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreen1UidTextArea, 95);
    lv_obj_set_y(ui_SettingScreen1UidTextArea, 20);
    lv_obj_set_align(ui_SettingScreen1UidTextArea, LV_ALIGN_LEFT_MID);
    lv_textarea_set_placeholder_text(ui_SettingScreen1UidTextArea, "Placeholder...");
    lv_textarea_set_one_line(ui_SettingScreen1UidTextArea, true);
    lv_obj_clear_flag(ui_SettingScreen1UidTextArea, LV_OBJ_FLAG_CLICKABLE); /// Flags
    lv_obj_set_style_pad_left(ui_SettingScreen1UidTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_SettingScreen1UidTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_SettingScreen1UidTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_SettingScreen1UidTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingScreen1DevKeyLabel = lv_label_create(ui_SettingScreen1Panel);
    lv_obj_set_width(ui_SettingScreen1DevKeyLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreen1DevKeyLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreen1DevKeyLabel, 0);
    lv_obj_set_y(ui_SettingScreen1DevKeyLabel, 60);
    lv_obj_set_align(ui_SettingScreen1DevKeyLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_SettingScreen1DevKeyLabel, "Device Key");

    ui_SettingScreen1UidEditBtn = lv_btn_create(ui_SettingScreen1Panel);
    lv_obj_set_width(ui_SettingScreen1UidEditBtn, 32);
    lv_obj_set_height(ui_SettingScreen1UidEditBtn, 32);
    lv_obj_set_x(ui_SettingScreen1UidEditBtn, 190);
    lv_obj_set_y(ui_SettingScreen1UidEditBtn, 20);
    lv_obj_set_align(ui_SettingScreen1UidEditBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreen1UidEditBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_SettingScreen1UidEditBtn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags

    ui_SettingScreen1UidImg = lv_img_create(ui_SettingScreen1UidEditBtn);
    lv_img_set_src(ui_SettingScreen1UidImg, &ui_img_pen_square_png);
    lv_obj_set_width(ui_SettingScreen1UidImg, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreen1UidImg, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_SettingScreen1UidImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreen1UidImg, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_SettingScreen1UidImg, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_SettingScreen1DevKeyTextArea = lv_textarea_create(ui_SettingScreen1Panel);
    lv_obj_set_width(ui_SettingScreen1DevKeyTextArea, 280);
    lv_obj_set_height(ui_SettingScreen1DevKeyTextArea, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreen1DevKeyTextArea, 95);
    lv_obj_set_y(ui_SettingScreen1DevKeyTextArea, 60);
    lv_obj_set_align(ui_SettingScreen1DevKeyTextArea, LV_ALIGN_LEFT_MID);
    lv_textarea_set_placeholder_text(ui_SettingScreen1DevKeyTextArea, "Placeholder...");
    lv_textarea_set_one_line(ui_SettingScreen1DevKeyTextArea, true);
    lv_obj_clear_flag(ui_SettingScreen1DevKeyTextArea, LV_OBJ_FLAG_CLICKABLE); /// Flags
    lv_obj_set_style_pad_left(ui_SettingScreen1DevKeyTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_SettingScreen1DevKeyTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_SettingScreen1DevKeyTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_SettingScreen1DevKeyTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingScreen1DevKeyEditBtn = lv_btn_create(ui_SettingScreen1Panel);
    lv_obj_set_width(ui_SettingScreen1DevKeyEditBtn, 32);
    lv_obj_set_height(ui_SettingScreen1DevKeyEditBtn, 32);
    lv_obj_set_x(ui_SettingScreen1DevKeyEditBtn, 190);
    lv_obj_set_y(ui_SettingScreen1DevKeyEditBtn, 60);
    lv_obj_set_align(ui_SettingScreen1DevKeyEditBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreen1DevKeyEditBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_SettingScreen1DevKeyEditBtn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags

    ui_SettingScreen1DevKeyImg = lv_img_create(ui_SettingScreen1DevKeyEditBtn);
    lv_img_set_src(ui_SettingScreen1DevKeyImg, &ui_img_pen_square_png);
    lv_obj_set_width(ui_SettingScreen1DevKeyImg, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreen1DevKeyImg, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_SettingScreen1DevKeyImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreen1DevKeyImg, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_SettingScreen1DevKeyImg, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_SettingScreen1ConfirmBtn = lv_btn_create(ui_SettingScreen1);
    lv_obj_set_width(ui_SettingScreen1ConfirmBtn, 90);
    lv_obj_set_height(ui_SettingScreen1ConfirmBtn, 40);
    lv_obj_set_x(ui_SettingScreen1ConfirmBtn, -60);
    lv_obj_set_y(ui_SettingScreen1ConfirmBtn, 125);
    lv_obj_set_align(ui_SettingScreen1ConfirmBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreen1ConfirmBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_SettingScreen1ConfirmBtn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags

    ui_SettingScreen1ConfirmLabel = lv_label_create(ui_SettingScreen1ConfirmBtn);
    lv_obj_set_width(ui_SettingScreen1ConfirmLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreen1ConfirmLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_SettingScreen1ConfirmLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SettingScreen1ConfirmLabel, "Confirm");

    ui_SettingScreen1CancelBtn = lv_btn_create(ui_SettingScreen1);
    lv_obj_set_width(ui_SettingScreen1CancelBtn, 90);
    lv_obj_set_height(ui_SettingScreen1CancelBtn, 40);
    lv_obj_set_x(ui_SettingScreen1CancelBtn, 60);
    lv_obj_set_y(ui_SettingScreen1CancelBtn, 125);
    lv_obj_set_align(ui_SettingScreen1CancelBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreen1CancelBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_SettingScreen1CancelBtn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_bg_color(ui_SettingScreen1CancelBtn, lv_color_hex(0xFF5959), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SettingScreen1CancelBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingScreen1CancelLabel = lv_label_create(ui_SettingScreen1CancelBtn);
    lv_obj_set_width(ui_SettingScreen1CancelLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreen1CancelLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_SettingScreen1CancelLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SettingScreen1CancelLabel, "Cancel");

    ui_SettingScreen1NextBtn = lv_btn_create(ui_SettingScreen1);
    lv_obj_set_width(ui_SettingScreen1NextBtn, 40);
    lv_obj_set_height(ui_SettingScreen1NextBtn, 40);
    lv_obj_set_x(ui_SettingScreen1NextBtn, 200);
    lv_obj_set_y(ui_SettingScreen1NextBtn, -125);
    lv_obj_set_align(ui_SettingScreen1NextBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreen1NextBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_SettingScreen1NextBtn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags

    ui_SettingScreen1NextLabel = lv_label_create(ui_SettingScreen1NextBtn);
    lv_obj_set_width(ui_SettingScreen1NextLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreen1NextLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_SettingScreen1NextLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SettingScreen1NextLabel, ">");

    lv_obj_add_event_cb(ui_SettingScreen1SsidEditBtn, ui_event_SettingScreen1SsidEditBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SettingScreen1WifiPwEditBtn, ui_event_SettingScreen1WifiPwEditBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SettingScreen1UidEditBtn, ui_event_SettingScreen1UidEditBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SettingScreen1DevKeyEditBtn, ui_event_SettingScreen1DevKeyEditBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SettingScreen1ConfirmBtn, ui_event_SettingScreen1ConfirmBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SettingScreen1CancelBtn, ui_event_SettingScreen1CancelBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SettingScreen1NextBtn, ui_event_SettingScreen1NextBtn, LV_EVENT_ALL, NULL);
}
void ui_EditTextScreen_screen_init(void)
{
    ui_EditTextScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_EditTextScreen, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_EditTextScreenPanel = lv_obj_create(ui_EditTextScreen);
    lv_obj_set_width(ui_EditTextScreenPanel, 450);
    lv_obj_set_height(ui_EditTextScreenPanel, 240);
    lv_obj_set_x(ui_EditTextScreenPanel, 0);
    lv_obj_set_y(ui_EditTextScreenPanel, -25);
    lv_obj_set_align(ui_EditTextScreenPanel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_EditTextScreenPanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_EditTextScreenPanel, lv_color_hex(0xECECEC), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_EditTextScreenPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_EditTextScreenTextArea = lv_textarea_create(ui_EditTextScreenPanel);
    lv_obj_set_width(ui_EditTextScreenTextArea, 430);
    lv_obj_set_height(ui_EditTextScreenTextArea, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_EditTextScreenTextArea, 0);
    lv_obj_set_y(ui_EditTextScreenTextArea, -10);
    lv_obj_set_align(ui_EditTextScreenTextArea, LV_ALIGN_TOP_MID);
    lv_textarea_set_placeholder_text(ui_EditTextScreenTextArea, "Placeholder...");
    lv_textarea_set_one_line(ui_EditTextScreenTextArea, true);
    lv_obj_set_style_pad_left(ui_EditTextScreenTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_EditTextScreenTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_EditTextScreenTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_EditTextScreenTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_EditTextScreenKeyboard = lv_keyboard_create(ui_EditTextScreenPanel);
    lv_obj_set_width(ui_EditTextScreenKeyboard, 440);
    lv_obj_set_height(ui_EditTextScreenKeyboard, 185);
    lv_obj_set_x(ui_EditTextScreenKeyboard, 0);
    lv_obj_set_y(ui_EditTextScreenKeyboard, 15);
    lv_obj_set_align(ui_EditTextScreenKeyboard, LV_ALIGN_BOTTOM_MID);

    ui_EditTextScreenConfirmBtn = lv_btn_create(ui_EditTextScreen);
    lv_obj_set_width(ui_EditTextScreenConfirmBtn, 90);
    lv_obj_set_height(ui_EditTextScreenConfirmBtn, 40);
    lv_obj_set_x(ui_EditTextScreenConfirmBtn, -60);
    lv_obj_set_y(ui_EditTextScreenConfirmBtn, 125);
    lv_obj_set_align(ui_EditTextScreenConfirmBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_EditTextScreenConfirmBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_EditTextScreenConfirmBtn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags

    ui_EditTextScreenConfirmLabel = lv_label_create(ui_EditTextScreenConfirmBtn);
    lv_obj_set_width(ui_EditTextScreenConfirmLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_EditTextScreenConfirmLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_EditTextScreenConfirmLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_EditTextScreenConfirmLabel, "Confirm");

    ui_EditTextScreenCancelBtn = lv_btn_create(ui_EditTextScreen);
    lv_obj_set_width(ui_EditTextScreenCancelBtn, 90);
    lv_obj_set_height(ui_EditTextScreenCancelBtn, 40);
    lv_obj_set_x(ui_EditTextScreenCancelBtn, 60);
    lv_obj_set_y(ui_EditTextScreenCancelBtn, 125);
    lv_obj_set_align(ui_EditTextScreenCancelBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_EditTextScreenCancelBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_EditTextScreenCancelBtn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_bg_color(ui_EditTextScreenCancelBtn, lv_color_hex(0xFF5959), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_EditTextScreenCancelBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_EditTextScreenCancelLabel = lv_label_create(ui_EditTextScreenCancelBtn);
    lv_obj_set_width(ui_EditTextScreenCancelLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_EditTextScreenCancelLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_EditTextScreenCancelLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_EditTextScreenCancelLabel, "Cancel");

    lv_obj_add_event_cb(ui_EditTextScreenConfirmBtn, ui_event_EditTextScreenConfirmBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_EditTextScreenCancelBtn, ui_event_EditTextScreenCancelBtn, LV_EVENT_ALL, NULL);
}

// PROJECT: Plant_Screen_3

///////////////////// VARIABLES ////////////////////
lv_obj_t *ui_SettingScreen2;
lv_obj_t *ui_SettingScreen2Label;
lv_obj_t *ui_SettingScreen2Panel;
lv_obj_t *ui_SettingScreen2SlotLabel;
lv_obj_t *ui_SettingScreen2TempSlotLabel;
lv_obj_t *ui_SettingScreen2TempSlotTextArea;
void ui_event_SettingScreen2TempSlotEditBtn(lv_event_t *e);
lv_obj_t *ui_SettingScreen2TempSlotEditBtn;
lv_obj_t *ui_SettingScreen2TempSlotEditImg;
lv_obj_t *ui_SettingScreen2HumidSlotLabel;
lv_obj_t *ui_SettingScreen2HumidSlotTextArea;
void ui_event_SettingScreen2HumidSlotEditBtn(lv_event_t *e);
lv_obj_t *ui_SettingScreen2HumidSlotEditBtn;
lv_obj_t *ui_SettingScreen2HumidSlotEditImg;
lv_obj_t *ui_SettingScreen2LightSlotLabel;
lv_obj_t *ui_SettingScreen2LightSlotTextArea;
lv_obj_t *ui_SettingScreen2WaterSlotLabel;
void ui_event_SettingScreen2LightSlotEditBtn(lv_event_t *e);
lv_obj_t *ui_SettingScreen2LightSlotEditBtn;
lv_obj_t *ui_SettingScreen2LightSlotEditImg;
lv_obj_t *ui_SettingScreen2WaterSlotTextArea;
void ui_event_SettingScreen2WaterSlotEditBtn(lv_event_t *e);
lv_obj_t *ui_SettingScreen2WaterSlotEditBtn;
lv_obj_t *ui_SettingScreen2WaterSlotEditImg;
lv_obj_t *ui_SettingScreen2CSlotLabel;
lv_obj_t *ui_SettingScreen2LedSlotTextArea;
lv_obj_t *ui_SettingScreen2LedSlotLabel;
void ui_event_SettingScreen2TempSlotEditBtn1(lv_event_t *e);
lv_obj_t *ui_SettingScreen2TempSlotEditBtn1;
lv_obj_t *ui_SettingScreen2TempSlotEditImg1;
lv_obj_t *ui_SettingScreen2PumpSlotLabel;
lv_obj_t *ui_SettingScreen2PumpSlotTextArea;
void ui_event_SettingScreen2PumpSlotEditBtn(lv_event_t *e);
lv_obj_t *ui_SettingScreen2PumpSlotEditBtn;
lv_obj_t *ui_SettingScreen2PumpSlotEditImg;
lv_obj_t *ui_SettingScreen2FanSlotLabel;
lv_obj_t *ui_SettingScreen2FanSlotTextArea;
void ui_event_SettingScreen2FanSlotEditBtn(lv_event_t *e);
lv_obj_t *ui_SettingScreen2FanSlotEditBtn;
lv_obj_t *ui_SettingScreen2FanSlotEditImg;
void ui_event_SettingScreen2ConfirmBtn(lv_event_t *e);
lv_obj_t *ui_SettingScreen2ConfirmBtn;
lv_obj_t *ui_SettingScreen2ConfirmLabel;
void ui_event_SettingScreen2CancelBtn(lv_event_t *e);
lv_obj_t *ui_SettingScreen2CancelBtn;
lv_obj_t *ui_SettingScreen2CancelLabel;
void ui_event_SettingScreen2PrevBtn(lv_event_t *e);
lv_obj_t *ui_SettingScreen2PrevBtn;
lv_obj_t *ui_SettingScreen2PrevLabel;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
#error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP != 0
#error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_SettingScreen2TempSlotEditBtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        toEditTempSlot(e);
    }
}
void ui_event_SettingScreen2HumidSlotEditBtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        toEditHumidSlot(e);
    }
}
void ui_event_SettingScreen2LightSlotEditBtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        toEditLightSlot(e);
    }
}
void ui_event_SettingScreen2WaterSlotEditBtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        toEditWaterSlot(e);
    }
}
void ui_event_SettingScreen2TempSlotEditBtn1(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        toEditLedSlot(e);
    }
}
void ui_event_SettingScreen2PumpSlotEditBtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        toEditPumpSlot(e);
    }
}
void ui_event_SettingScreen2FanSlotEditBtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        toEditFanSlot(e);
    }
}
void ui_event_SettingScreen2ConfirmBtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        settingConfirm(e);
    }
}
void ui_event_SettingScreen2CancelBtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        settingCancel(e);
    }
}
void ui_event_SettingScreen2PrevBtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        prevSettingPage(e);
    }
}

///////////////////// SCREENS ////////////////////
void ui_SettingScreen2_screen_init(void)
{
    ui_SettingScreen2 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_SettingScreen2, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_SettingScreen2Label = lv_label_create(ui_SettingScreen2);
    lv_obj_set_width(ui_SettingScreen2Label, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreen2Label, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreen2Label, 0);
    lv_obj_set_y(ui_SettingScreen2Label, -125);
    lv_obj_set_align(ui_SettingScreen2Label, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SettingScreen2Label, "Setting (2/2)");
    lv_obj_set_style_text_font(ui_SettingScreen2Label, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingScreen2Panel = lv_obj_create(ui_SettingScreen2);
    lv_obj_set_width(ui_SettingScreen2Panel, 450);
    lv_obj_set_height(ui_SettingScreen2Panel, 195);
    lv_obj_set_x(ui_SettingScreen2Panel, 1);
    lv_obj_set_y(ui_SettingScreen2Panel, -5);
    lv_obj_set_align(ui_SettingScreen2Panel, LV_ALIGN_CENTER);
    lv_obj_set_scrollbar_mode(ui_SettingScreen2Panel, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_scroll_dir(ui_SettingScreen2Panel, LV_DIR_VER);
    lv_obj_set_style_bg_color(ui_SettingScreen2Panel, lv_color_hex(0xECECEC), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SettingScreen2Panel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingScreen2SlotLabel = lv_label_create(ui_SettingScreen2Panel);
    lv_obj_set_width(ui_SettingScreen2SlotLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreen2SlotLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreen2SlotLabel, 0);
    lv_obj_set_y(ui_SettingScreen2SlotLabel, -80);
    lv_obj_set_align(ui_SettingScreen2SlotLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_SettingScreen2SlotLabel, "Slot Config");

    ui_SettingScreen2TempSlotLabel = lv_label_create(ui_SettingScreen2Panel);
    lv_obj_set_width(ui_SettingScreen2TempSlotLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreen2TempSlotLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreen2TempSlotLabel, 0);
    lv_obj_set_y(ui_SettingScreen2TempSlotLabel, -45);
    lv_obj_set_align(ui_SettingScreen2TempSlotLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_SettingScreen2TempSlotLabel, "Temp ");

    ui_SettingScreen2TempSlotTextArea = lv_textarea_create(ui_SettingScreen2Panel);
    lv_obj_set_width(ui_SettingScreen2TempSlotTextArea, 75);
    lv_obj_set_height(ui_SettingScreen2TempSlotTextArea, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreen2TempSlotTextArea, 65);
    lv_obj_set_y(ui_SettingScreen2TempSlotTextArea, -45);
    lv_obj_set_align(ui_SettingScreen2TempSlotTextArea, LV_ALIGN_LEFT_MID);
    lv_textarea_set_placeholder_text(ui_SettingScreen2TempSlotTextArea, "Slot...");
    lv_textarea_set_one_line(ui_SettingScreen2TempSlotTextArea, true);
    lv_obj_clear_flag(ui_SettingScreen2TempSlotTextArea, LV_OBJ_FLAG_CLICKABLE); /// Flags
    lv_obj_set_style_pad_left(ui_SettingScreen2TempSlotTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_SettingScreen2TempSlotTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_SettingScreen2TempSlotTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_SettingScreen2TempSlotTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingScreen2TempSlotEditBtn = lv_btn_create(ui_SettingScreen2Panel);
    lv_obj_set_width(ui_SettingScreen2TempSlotEditBtn, 32);
    lv_obj_set_height(ui_SettingScreen2TempSlotEditBtn, 32);
    lv_obj_set_x(ui_SettingScreen2TempSlotEditBtn, -30);
    lv_obj_set_y(ui_SettingScreen2TempSlotEditBtn, -45);
    lv_obj_set_align(ui_SettingScreen2TempSlotEditBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreen2TempSlotEditBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_SettingScreen2TempSlotEditBtn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags

    ui_SettingScreen2TempSlotEditImg = lv_img_create(ui_SettingScreen2TempSlotEditBtn);
    lv_img_set_src(ui_SettingScreen2TempSlotEditImg, &ui_img_pen_square_png);
    lv_obj_set_width(ui_SettingScreen2TempSlotEditImg, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreen2TempSlotEditImg, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_SettingScreen2TempSlotEditImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreen2TempSlotEditImg, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_SettingScreen2TempSlotEditImg, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_SettingScreen2HumidSlotLabel = lv_label_create(ui_SettingScreen2Panel);
    lv_obj_set_width(ui_SettingScreen2HumidSlotLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreen2HumidSlotLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreen2HumidSlotLabel, 0);
    lv_obj_set_y(ui_SettingScreen2HumidSlotLabel, -5);
    lv_obj_set_align(ui_SettingScreen2HumidSlotLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_SettingScreen2HumidSlotLabel, "Humid");

    ui_SettingScreen2HumidSlotTextArea = lv_textarea_create(ui_SettingScreen2Panel);
    lv_obj_set_width(ui_SettingScreen2HumidSlotTextArea, 75);
    lv_obj_set_height(ui_SettingScreen2HumidSlotTextArea, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreen2HumidSlotTextArea, 65);
    lv_obj_set_y(ui_SettingScreen2HumidSlotTextArea, -5);
    lv_obj_set_align(ui_SettingScreen2HumidSlotTextArea, LV_ALIGN_LEFT_MID);
    lv_textarea_set_placeholder_text(ui_SettingScreen2HumidSlotTextArea, "Slot...");
    lv_textarea_set_one_line(ui_SettingScreen2HumidSlotTextArea, true);
    lv_obj_clear_flag(ui_SettingScreen2HumidSlotTextArea, LV_OBJ_FLAG_CLICKABLE); /// Flags
    lv_obj_set_style_pad_left(ui_SettingScreen2HumidSlotTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_SettingScreen2HumidSlotTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_SettingScreen2HumidSlotTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_SettingScreen2HumidSlotTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingScreen2HumidSlotEditBtn = lv_btn_create(ui_SettingScreen2Panel);
    lv_obj_set_width(ui_SettingScreen2HumidSlotEditBtn, 32);
    lv_obj_set_height(ui_SettingScreen2HumidSlotEditBtn, 32);
    lv_obj_set_x(ui_SettingScreen2HumidSlotEditBtn, -30);
    lv_obj_set_y(ui_SettingScreen2HumidSlotEditBtn, -5);
    lv_obj_set_align(ui_SettingScreen2HumidSlotEditBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreen2HumidSlotEditBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_SettingScreen2HumidSlotEditBtn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags

    ui_SettingScreen2HumidSlotEditImg = lv_img_create(ui_SettingScreen2HumidSlotEditBtn);
    lv_img_set_src(ui_SettingScreen2HumidSlotEditImg, &ui_img_pen_square_png);
    lv_obj_set_width(ui_SettingScreen2HumidSlotEditImg, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreen2HumidSlotEditImg, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_SettingScreen2HumidSlotEditImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreen2HumidSlotEditImg, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_SettingScreen2HumidSlotEditImg, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_SettingScreen2LightSlotLabel = lv_label_create(ui_SettingScreen2Panel);
    lv_obj_set_width(ui_SettingScreen2LightSlotLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreen2LightSlotLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreen2LightSlotLabel, 0);
    lv_obj_set_y(ui_SettingScreen2LightSlotLabel, 35);
    lv_obj_set_align(ui_SettingScreen2LightSlotLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_SettingScreen2LightSlotLabel, "Light");

    ui_SettingScreen2LightSlotTextArea = lv_textarea_create(ui_SettingScreen2Panel);
    lv_obj_set_width(ui_SettingScreen2LightSlotTextArea, 75);
    lv_obj_set_height(ui_SettingScreen2LightSlotTextArea, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreen2LightSlotTextArea, 65);
    lv_obj_set_y(ui_SettingScreen2LightSlotTextArea, 35);
    lv_obj_set_align(ui_SettingScreen2LightSlotTextArea, LV_ALIGN_LEFT_MID);
    lv_textarea_set_placeholder_text(ui_SettingScreen2LightSlotTextArea, "Slot...");
    lv_textarea_set_one_line(ui_SettingScreen2LightSlotTextArea, true);
    lv_obj_clear_flag(ui_SettingScreen2LightSlotTextArea, LV_OBJ_FLAG_CLICKABLE); /// Flags
    lv_obj_set_style_pad_left(ui_SettingScreen2LightSlotTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_SettingScreen2LightSlotTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_SettingScreen2LightSlotTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_SettingScreen2LightSlotTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingScreen2WaterSlotLabel = lv_label_create(ui_SettingScreen2Panel);
    lv_obj_set_width(ui_SettingScreen2WaterSlotLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreen2WaterSlotLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreen2WaterSlotLabel, 0);
    lv_obj_set_y(ui_SettingScreen2WaterSlotLabel, 75);
    lv_obj_set_align(ui_SettingScreen2WaterSlotLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_SettingScreen2WaterSlotLabel, "Water");

    ui_SettingScreen2LightSlotEditBtn = lv_btn_create(ui_SettingScreen2Panel);
    lv_obj_set_width(ui_SettingScreen2LightSlotEditBtn, 32);
    lv_obj_set_height(ui_SettingScreen2LightSlotEditBtn, 32);
    lv_obj_set_x(ui_SettingScreen2LightSlotEditBtn, -30);
    lv_obj_set_y(ui_SettingScreen2LightSlotEditBtn, 35);
    lv_obj_set_align(ui_SettingScreen2LightSlotEditBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreen2LightSlotEditBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_SettingScreen2LightSlotEditBtn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags

    ui_SettingScreen2LightSlotEditImg = lv_img_create(ui_SettingScreen2LightSlotEditBtn);
    lv_img_set_src(ui_SettingScreen2LightSlotEditImg, &ui_img_pen_square_png);
    lv_obj_set_width(ui_SettingScreen2LightSlotEditImg, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreen2LightSlotEditImg, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_SettingScreen2LightSlotEditImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreen2LightSlotEditImg, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_SettingScreen2LightSlotEditImg, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_SettingScreen2WaterSlotTextArea = lv_textarea_create(ui_SettingScreen2Panel);
    lv_obj_set_width(ui_SettingScreen2WaterSlotTextArea, 75);
    lv_obj_set_height(ui_SettingScreen2WaterSlotTextArea, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreen2WaterSlotTextArea, 65);
    lv_obj_set_y(ui_SettingScreen2WaterSlotTextArea, 75);
    lv_obj_set_align(ui_SettingScreen2WaterSlotTextArea, LV_ALIGN_LEFT_MID);
    lv_textarea_set_placeholder_text(ui_SettingScreen2WaterSlotTextArea, "Slot...");
    lv_textarea_set_one_line(ui_SettingScreen2WaterSlotTextArea, true);
    lv_obj_clear_flag(ui_SettingScreen2WaterSlotTextArea, LV_OBJ_FLAG_CLICKABLE); /// Flags
    lv_obj_set_style_pad_left(ui_SettingScreen2WaterSlotTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_SettingScreen2WaterSlotTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_SettingScreen2WaterSlotTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_SettingScreen2WaterSlotTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingScreen2WaterSlotEditBtn = lv_btn_create(ui_SettingScreen2Panel);
    lv_obj_set_width(ui_SettingScreen2WaterSlotEditBtn, 32);
    lv_obj_set_height(ui_SettingScreen2WaterSlotEditBtn, 32);
    lv_obj_set_x(ui_SettingScreen2WaterSlotEditBtn, -30);
    lv_obj_set_y(ui_SettingScreen2WaterSlotEditBtn, 75);
    lv_obj_set_align(ui_SettingScreen2WaterSlotEditBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreen2WaterSlotEditBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_SettingScreen2WaterSlotEditBtn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags

    ui_SettingScreen2WaterSlotEditImg = lv_img_create(ui_SettingScreen2WaterSlotEditBtn);
    lv_img_set_src(ui_SettingScreen2WaterSlotEditImg, &ui_img_pen_square_png);
    lv_obj_set_width(ui_SettingScreen2WaterSlotEditImg, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreen2WaterSlotEditImg, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_SettingScreen2WaterSlotEditImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreen2WaterSlotEditImg, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_SettingScreen2WaterSlotEditImg, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_SettingScreen2CSlotLabel = lv_label_create(ui_SettingScreen2Panel);
    lv_obj_set_width(ui_SettingScreen2CSlotLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreen2CSlotLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreen2CSlotLabel, 220);
    lv_obj_set_y(ui_SettingScreen2CSlotLabel, -80);
    lv_obj_set_align(ui_SettingScreen2CSlotLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_SettingScreen2CSlotLabel, "Control Slot Config");

    ui_SettingScreen2LedSlotTextArea = lv_textarea_create(ui_SettingScreen2Panel);
    lv_obj_set_width(ui_SettingScreen2LedSlotTextArea, 75);
    lv_obj_set_height(ui_SettingScreen2LedSlotTextArea, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreen2LedSlotTextArea, 290);
    lv_obj_set_y(ui_SettingScreen2LedSlotTextArea, -45);
    lv_obj_set_align(ui_SettingScreen2LedSlotTextArea, LV_ALIGN_LEFT_MID);
    lv_textarea_set_placeholder_text(ui_SettingScreen2LedSlotTextArea, "Slot...");
    lv_textarea_set_one_line(ui_SettingScreen2LedSlotTextArea, true);
    lv_obj_clear_flag(ui_SettingScreen2LedSlotTextArea, LV_OBJ_FLAG_CLICKABLE); /// Flags
    lv_obj_set_style_pad_left(ui_SettingScreen2LedSlotTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_SettingScreen2LedSlotTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_SettingScreen2LedSlotTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_SettingScreen2LedSlotTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingScreen2LedSlotLabel = lv_label_create(ui_SettingScreen2Panel);
    lv_obj_set_width(ui_SettingScreen2LedSlotLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreen2LedSlotLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreen2LedSlotLabel, 220);
    lv_obj_set_y(ui_SettingScreen2LedSlotLabel, -45);
    lv_obj_set_align(ui_SettingScreen2LedSlotLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_SettingScreen2LedSlotLabel, "LED");

    ui_SettingScreen2TempSlotEditBtn1 = lv_btn_create(ui_SettingScreen2Panel);
    lv_obj_set_width(ui_SettingScreen2TempSlotEditBtn1, 32);
    lv_obj_set_height(ui_SettingScreen2TempSlotEditBtn1, 32);
    lv_obj_set_x(ui_SettingScreen2TempSlotEditBtn1, 190);
    lv_obj_set_y(ui_SettingScreen2TempSlotEditBtn1, -45);
    lv_obj_set_align(ui_SettingScreen2TempSlotEditBtn1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreen2TempSlotEditBtn1, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_SettingScreen2TempSlotEditBtn1, LV_OBJ_FLAG_SCROLLABLE);    /// Flags

    ui_SettingScreen2TempSlotEditImg1 = lv_img_create(ui_SettingScreen2TempSlotEditBtn1);
    lv_img_set_src(ui_SettingScreen2TempSlotEditImg1, &ui_img_pen_square_png);
    lv_obj_set_width(ui_SettingScreen2TempSlotEditImg1, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreen2TempSlotEditImg1, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_SettingScreen2TempSlotEditImg1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreen2TempSlotEditImg1, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_SettingScreen2TempSlotEditImg1, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_SettingScreen2PumpSlotLabel = lv_label_create(ui_SettingScreen2Panel);
    lv_obj_set_width(ui_SettingScreen2PumpSlotLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreen2PumpSlotLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreen2PumpSlotLabel, 220);
    lv_obj_set_y(ui_SettingScreen2PumpSlotLabel, -5);
    lv_obj_set_align(ui_SettingScreen2PumpSlotLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_SettingScreen2PumpSlotLabel, "Pump");

    ui_SettingScreen2PumpSlotTextArea = lv_textarea_create(ui_SettingScreen2Panel);
    lv_obj_set_width(ui_SettingScreen2PumpSlotTextArea, 75);
    lv_obj_set_height(ui_SettingScreen2PumpSlotTextArea, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreen2PumpSlotTextArea, 290);
    lv_obj_set_y(ui_SettingScreen2PumpSlotTextArea, -5);
    lv_obj_set_align(ui_SettingScreen2PumpSlotTextArea, LV_ALIGN_LEFT_MID);
    lv_textarea_set_placeholder_text(ui_SettingScreen2PumpSlotTextArea, "Slot...");
    lv_textarea_set_one_line(ui_SettingScreen2PumpSlotTextArea, true);
    lv_obj_clear_flag(ui_SettingScreen2PumpSlotTextArea, LV_OBJ_FLAG_CLICKABLE); /// Flags
    lv_obj_set_style_pad_left(ui_SettingScreen2PumpSlotTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_SettingScreen2PumpSlotTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_SettingScreen2PumpSlotTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_SettingScreen2PumpSlotTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingScreen2PumpSlotEditBtn = lv_btn_create(ui_SettingScreen2Panel);
    lv_obj_set_width(ui_SettingScreen2PumpSlotEditBtn, 32);
    lv_obj_set_height(ui_SettingScreen2PumpSlotEditBtn, 32);
    lv_obj_set_x(ui_SettingScreen2PumpSlotEditBtn, 190);
    lv_obj_set_y(ui_SettingScreen2PumpSlotEditBtn, -5);
    lv_obj_set_align(ui_SettingScreen2PumpSlotEditBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreen2PumpSlotEditBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_SettingScreen2PumpSlotEditBtn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags

    ui_SettingScreen2PumpSlotEditImg = lv_img_create(ui_SettingScreen2PumpSlotEditBtn);
    lv_img_set_src(ui_SettingScreen2PumpSlotEditImg, &ui_img_pen_square_png);
    lv_obj_set_width(ui_SettingScreen2PumpSlotEditImg, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreen2PumpSlotEditImg, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_SettingScreen2PumpSlotEditImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreen2PumpSlotEditImg, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_SettingScreen2PumpSlotEditImg, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_SettingScreen2FanSlotLabel = lv_label_create(ui_SettingScreen2Panel);
    lv_obj_set_width(ui_SettingScreen2FanSlotLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreen2FanSlotLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreen2FanSlotLabel, 220);
    lv_obj_set_y(ui_SettingScreen2FanSlotLabel, 35);
    lv_obj_set_align(ui_SettingScreen2FanSlotLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_SettingScreen2FanSlotLabel, "Fan");

    ui_SettingScreen2FanSlotTextArea = lv_textarea_create(ui_SettingScreen2Panel);
    lv_obj_set_width(ui_SettingScreen2FanSlotTextArea, 75);
    lv_obj_set_height(ui_SettingScreen2FanSlotTextArea, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SettingScreen2FanSlotTextArea, 290);
    lv_obj_set_y(ui_SettingScreen2FanSlotTextArea, 35);
    lv_obj_set_align(ui_SettingScreen2FanSlotTextArea, LV_ALIGN_LEFT_MID);
    lv_textarea_set_placeholder_text(ui_SettingScreen2FanSlotTextArea, "Slot...");
    lv_textarea_set_one_line(ui_SettingScreen2FanSlotTextArea, true);
    lv_obj_clear_flag(ui_SettingScreen2FanSlotTextArea, LV_OBJ_FLAG_CLICKABLE); /// Flags
    lv_obj_set_style_pad_left(ui_SettingScreen2FanSlotTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_SettingScreen2FanSlotTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_SettingScreen2FanSlotTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_SettingScreen2FanSlotTextArea, 7, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingScreen2FanSlotEditBtn = lv_btn_create(ui_SettingScreen2Panel);
    lv_obj_set_width(ui_SettingScreen2FanSlotEditBtn, 32);
    lv_obj_set_height(ui_SettingScreen2FanSlotEditBtn, 32);
    lv_obj_set_x(ui_SettingScreen2FanSlotEditBtn, 190);
    lv_obj_set_y(ui_SettingScreen2FanSlotEditBtn, 35);
    lv_obj_set_align(ui_SettingScreen2FanSlotEditBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreen2FanSlotEditBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_SettingScreen2FanSlotEditBtn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags

    ui_SettingScreen2FanSlotEditImg = lv_img_create(ui_SettingScreen2FanSlotEditBtn);
    lv_img_set_src(ui_SettingScreen2FanSlotEditImg, &ui_img_pen_square_png);
    lv_obj_set_width(ui_SettingScreen2FanSlotEditImg, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreen2FanSlotEditImg, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_SettingScreen2FanSlotEditImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreen2FanSlotEditImg, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_SettingScreen2FanSlotEditImg, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_SettingScreen2ConfirmBtn = lv_btn_create(ui_SettingScreen2);
    lv_obj_set_width(ui_SettingScreen2ConfirmBtn, 90);
    lv_obj_set_height(ui_SettingScreen2ConfirmBtn, 40);
    lv_obj_set_x(ui_SettingScreen2ConfirmBtn, -60);
    lv_obj_set_y(ui_SettingScreen2ConfirmBtn, 125);
    lv_obj_set_align(ui_SettingScreen2ConfirmBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreen2ConfirmBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_SettingScreen2ConfirmBtn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags

    ui_SettingScreen2ConfirmLabel = lv_label_create(ui_SettingScreen2ConfirmBtn);
    lv_obj_set_width(ui_SettingScreen2ConfirmLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreen2ConfirmLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_SettingScreen2ConfirmLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SettingScreen2ConfirmLabel, "Confirm");

    ui_SettingScreen2CancelBtn = lv_btn_create(ui_SettingScreen2);
    lv_obj_set_width(ui_SettingScreen2CancelBtn, 90);
    lv_obj_set_height(ui_SettingScreen2CancelBtn, 40);
    lv_obj_set_x(ui_SettingScreen2CancelBtn, 60);
    lv_obj_set_y(ui_SettingScreen2CancelBtn, 125);
    lv_obj_set_align(ui_SettingScreen2CancelBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreen2CancelBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_SettingScreen2CancelBtn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_bg_color(ui_SettingScreen2CancelBtn, lv_color_hex(0xFF5959), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SettingScreen2CancelBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingScreen2CancelLabel = lv_label_create(ui_SettingScreen2CancelBtn);
    lv_obj_set_width(ui_SettingScreen2CancelLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreen2CancelLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_SettingScreen2CancelLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SettingScreen2CancelLabel, "Cancel");

    ui_SettingScreen2PrevBtn = lv_btn_create(ui_SettingScreen2);
    lv_obj_set_width(ui_SettingScreen2PrevBtn, 40);
    lv_obj_set_height(ui_SettingScreen2PrevBtn, 40);
    lv_obj_set_x(ui_SettingScreen2PrevBtn, -200);
    lv_obj_set_y(ui_SettingScreen2PrevBtn, -125);
    lv_obj_set_align(ui_SettingScreen2PrevBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingScreen2PrevBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_SettingScreen2PrevBtn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags

    ui_SettingScreen2PrevLabel = lv_label_create(ui_SettingScreen2PrevBtn);
    lv_obj_set_width(ui_SettingScreen2PrevLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SettingScreen2PrevLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_SettingScreen2PrevLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SettingScreen2PrevLabel, "<");

    lv_obj_add_event_cb(ui_SettingScreen2TempSlotEditBtn, ui_event_SettingScreen2TempSlotEditBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SettingScreen2HumidSlotEditBtn, ui_event_SettingScreen2HumidSlotEditBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SettingScreen2LightSlotEditBtn, ui_event_SettingScreen2LightSlotEditBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SettingScreen2WaterSlotEditBtn, ui_event_SettingScreen2WaterSlotEditBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SettingScreen2TempSlotEditBtn1, ui_event_SettingScreen2TempSlotEditBtn1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SettingScreen2PumpSlotEditBtn, ui_event_SettingScreen2PumpSlotEditBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SettingScreen2FanSlotEditBtn, ui_event_SettingScreen2FanSlotEditBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SettingScreen2ConfirmBtn, ui_event_SettingScreen2ConfirmBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SettingScreen2CancelBtn, ui_event_SettingScreen2CancelBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SettingScreen2PrevBtn, ui_event_SettingScreen2PrevBtn, LV_EVENT_ALL, NULL);
}

void ui_init(void)
{
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                              false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_PlantScreen_screen_init();
    ui_SettingScreen1_screen_init();
    ui_EditTextScreen_screen_init();
    ui_SettingScreen2_screen_init();
}
