// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.2.0
// LVGL VERSION: 8.2.0
// PROJECT: Plant_Screen

#ifndef _PLANT_SCREEN_UI_H
#define _PLANT_SCREEN_UI_H

#ifdef __cplusplus
extern "C"
{
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

    // PROJECT: Plant_Screen

    extern lv_obj_t *ui_PlantScreen;
    extern lv_obj_t *ui_PlantScreenTempPanel;
    extern lv_obj_t *ui_PlantScreenTempLabel;
    extern lv_obj_t *ui_PlantScreenTempValueLabel;
    extern lv_obj_t *ui_PlantScreenTempUnitLabel;
    extern lv_obj_t *ui_PlantScreenHumidPanel;
    extern lv_obj_t *ui_PlantScreenHumidLabel;
    extern lv_obj_t *ui_PlantScreenHumidValueLabel;
    extern lv_obj_t *ui_PlantScreenHumidUnitLabel;
    extern lv_obj_t *ui_PlantScreenLightPanel;
    extern lv_obj_t *ui_PlantScreenLightLabel;
    extern lv_obj_t *ui_PlantScreenLightValueLabel;
    extern lv_obj_t *ui_PlantScreenLightUnitLabel;
    void ui_event_DataScreenSettingBtn(lv_event_t *e);
    extern lv_obj_t *ui_DataScreenSettingBtn;
    extern lv_obj_t *ui_DatsScreenSettingLabel;
    extern lv_obj_t *ui_PlantScreenWaterPanel;
    extern lv_obj_t *ui_PlantScreenWaterLabel;
    extern lv_obj_t *ui_PlantScreenWaterBar;
    extern lv_obj_t *ui_PlantScreenWaterValueLabel;
    extern lv_obj_t *ui_PlantScreenSwitchPanel;
    extern lv_obj_t *ui_PlantScreenLedPanel;
    extern lv_obj_t *ui_PlantScreenLedLabel;
    void ui_event_PlantScreenLedSwitch(lv_event_t *e);
    extern lv_obj_t *ui_PlantScreenLedSwitch;
    extern lv_obj_t *ui_PlantScreenPumpPanel;
    extern lv_obj_t *ui_PlantScreenPumpLabel;
    void ui_event_PlantScreenPumpSwitch(lv_event_t *e);
    extern lv_obj_t *ui_PlantScreenPumpSwitch;
    extern lv_obj_t *ui_PlantScreenFanPanel;
    extern lv_obj_t *ui_PlantScreenFanLabel;
    void ui_event_PlantScreenFanSwitch(lv_event_t *e);
    extern lv_obj_t *ui_PlantScreenFanSwitch;
    extern lv_obj_t *ui_PlantScreenStatusLabel;

    void toSettingPage(lv_event_t *e);
    void toggleLedSwitch(lv_event_t *e);
    void togglePumpSwitch(lv_event_t *e);
    void toggleFanSwitch(lv_event_t *e);

    // PROJECT: Plant_Screen_2

    extern lv_obj_t *ui_SettingScreen1;
    extern lv_obj_t *ui_SettingScreen1Label;
    extern lv_obj_t *ui_SettingScreen1Panel;
    extern lv_obj_t *ui_SettingScreen1SsidLabel;
    extern lv_obj_t *ui_SettingScreen1SsidTextArea;
    void ui_event_SettingScreen1SsidEditBtn(lv_event_t *e);
    extern lv_obj_t *ui_SettingScreen1SsidEditBtn;
    extern lv_obj_t *ui_SettingScreen1SsidEditImg;
    extern lv_obj_t *ui_SettingScreen1WifiPwLabel;
    extern lv_obj_t *ui_SettingScreen1WifiPwTextArea;
    void ui_event_SettingScreen1WifiPwEditBtn(lv_event_t *e);
    extern lv_obj_t *ui_SettingScreen1WifiPwEditBtn;
    extern lv_obj_t *ui_SettingScreen1WifiPwImg;
    extern lv_obj_t *ui_SettingScreen1UidLabel;
    extern lv_obj_t *ui_SettingScreen1UidTextArea;
    extern lv_obj_t *ui_SettingScreen1DevKeyLabel;
    void ui_event_SettingScreen1UidEditBtn(lv_event_t *e);
    extern lv_obj_t *ui_SettingScreen1UidEditBtn;
    extern lv_obj_t *ui_SettingScreen1UidImg;
    extern lv_obj_t *ui_SettingScreen1DevKeyTextArea;
    void ui_event_SettingScreen1DevKeyEditBtn(lv_event_t *e);
    extern lv_obj_t *ui_SettingScreen1DevKeyEditBtn;
    extern lv_obj_t *ui_SettingScreen1DevKeyImg;
    void ui_event_SettingScreen1ConfirmBtn(lv_event_t *e);
    extern lv_obj_t *ui_SettingScreen1ConfirmBtn;
    extern lv_obj_t *ui_SettingScreen1ConfirmLabel;
    void ui_event_SettingScreen1CancelBtn(lv_event_t *e);
    extern lv_obj_t *ui_SettingScreen1CancelBtn;
    extern lv_obj_t *ui_SettingScreen1CancelLabel;
    void ui_event_SettingScreen1NextBtn(lv_event_t *e);
    extern lv_obj_t *ui_SettingScreen1NextBtn;
    extern lv_obj_t *ui_SettingScreen1NextLabel;
    extern lv_obj_t *ui_EditTextScreen;
    extern lv_obj_t *ui_EditTextScreenPanel;
    extern lv_obj_t *ui_EditTextScreenTextArea;
    extern lv_obj_t *ui_EditTextScreenKeyboard;
    void ui_event_EditTextScreenConfirmBtn(lv_event_t *e);
    extern lv_obj_t *ui_EditTextScreenConfirmBtn;
    extern lv_obj_t *ui_EditTextScreenConfirmLabel;
    void ui_event_EditTextScreenCancelBtn(lv_event_t *e);
    extern lv_obj_t *ui_EditTextScreenCancelBtn;
    extern lv_obj_t *ui_EditTextScreenCancelLabel;

    void toEditSsid(lv_event_t *e);
    void toEditWifiPw(lv_event_t *e);
    void toEditUid(lv_event_t *e);
    void toEditDevKey(lv_event_t *e);
    void settingConfirm(lv_event_t *e);
    void settingCancel(lv_event_t *e);
    void nextSettingPage(lv_event_t *e);
    void enterTextConfirm(lv_event_t *e);
    void enterTextCancel(lv_event_t *e);

    LV_IMG_DECLARE(ui_img_pen_square_png); // assets\pen_square.png

    // PROJECT: Plant_Screen_3

    extern lv_obj_t *ui_SettingScreen2;
    extern lv_obj_t *ui_SettingScreen2Label;
    extern lv_obj_t *ui_SettingScreen2Panel;
    extern lv_obj_t *ui_SettingScreen2SlotLabel;
    extern lv_obj_t *ui_SettingScreen2TempSlotLabel;
    extern lv_obj_t *ui_SettingScreen2TempSlotTextArea;
    void ui_event_SettingScreen2TempSlotEditBtn(lv_event_t *e);
    extern lv_obj_t *ui_SettingScreen2TempSlotEditBtn;
    extern lv_obj_t *ui_SettingScreen2TempSlotEditImg;
    extern lv_obj_t *ui_SettingScreen2HumidSlotLabel;
    extern lv_obj_t *ui_SettingScreen2HumidSlotTextArea;
    void ui_event_SettingScreen2HumidSlotEditBtn(lv_event_t *e);
    extern lv_obj_t *ui_SettingScreen2HumidSlotEditBtn;
    extern lv_obj_t *ui_SettingScreen2HumidSlotEditImg;
    extern lv_obj_t *ui_SettingScreen2LightSlotLabel;
    extern lv_obj_t *ui_SettingScreen2LightSlotTextArea;
    extern lv_obj_t *ui_SettingScreen2WaterSlotLabel;
    void ui_event_SettingScreen2LightSlotEditBtn(lv_event_t *e);
    extern lv_obj_t *ui_SettingScreen2LightSlotEditBtn;
    extern lv_obj_t *ui_SettingScreen2LightSlotEditImg;
    extern lv_obj_t *ui_SettingScreen2WaterSlotTextArea;
    void ui_event_SettingScreen2WaterSlotEditBtn(lv_event_t *e);
    extern lv_obj_t *ui_SettingScreen2WaterSlotEditBtn;
    extern lv_obj_t *ui_SettingScreen2WaterSlotEditImg;
    extern lv_obj_t *ui_SettingScreen2CSlotLabel;
    extern lv_obj_t *ui_SettingScreen2LedSlotTextArea;
    extern lv_obj_t *ui_SettingScreen2LedSlotLabel;
    void ui_event_SettingScreen2TempSlotEditBtn1(lv_event_t *e);
    extern lv_obj_t *ui_SettingScreen2TempSlotEditBtn1;
    extern lv_obj_t *ui_SettingScreen2TempSlotEditImg1;
    extern lv_obj_t *ui_SettingScreen2PumpSlotLabel;
    extern lv_obj_t *ui_SettingScreen2PumpSlotTextArea;
    void ui_event_SettingScreen2PumpSlotEditBtn(lv_event_t *e);
    extern lv_obj_t *ui_SettingScreen2PumpSlotEditBtn;
    extern lv_obj_t *ui_SettingScreen2PumpSlotEditImg;
    extern lv_obj_t *ui_SettingScreen2FanSlotLabel;
    extern lv_obj_t *ui_SettingScreen2FanSlotTextArea;
    void ui_event_SettingScreen2FanSlotEditBtn(lv_event_t *e);
    extern lv_obj_t *ui_SettingScreen2FanSlotEditBtn;
    extern lv_obj_t *ui_SettingScreen2FanSlotEditImg;
    void ui_event_SettingScreen2ConfirmBtn(lv_event_t *e);
    extern lv_obj_t *ui_SettingScreen2ConfirmBtn;
    extern lv_obj_t *ui_SettingScreen2ConfirmLabel;
    void ui_event_SettingScreen2CancelBtn(lv_event_t *e);
    extern lv_obj_t *ui_SettingScreen2CancelBtn;
    extern lv_obj_t *ui_SettingScreen2CancelLabel;
    void ui_event_SettingScreen2PrevBtn(lv_event_t *e);
    extern lv_obj_t *ui_SettingScreen2PrevBtn;
    extern lv_obj_t *ui_SettingScreen2PrevLabel;

    void toEditTempSlot(lv_event_t *e);
    void toEditHumidSlot(lv_event_t *e);
    void toEditLightSlot(lv_event_t *e);
    void toEditWaterSlot(lv_event_t *e);
    void toEditLedSlot(lv_event_t *e);
    void toEditPumpSlot(lv_event_t *e);
    void toEditFanSlot(lv_event_t *e);
    void settingConfirm(lv_event_t *e);
    void settingCancel(lv_event_t *e);
    void prevSettingPage(lv_event_t *e);

    LV_IMG_DECLARE(ui_img_pen_square_png); // assets\pen_square.png

    void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
