// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.2.0
// LVGL VERSION: 8.2.0
// PROJECT: Plant_Screen

#include <Arduino.h>
#include "ui.h"

extern lv_obj_t *textareaRef;

extern void toggleLedWithProtocol();
extern void togglePump1WithProtocol();
extern void togglePump2WithProtocol();
extern void updateSettingPage();
extern void boundEditText(lv_obj_t *target, lv_keyboard_mode_t mode, bool isPassword);
extern void validateEditText();
extern lv_obj_t *getSettingPageBackFromEnterText(lv_obj_t *textareaRef);
extern void confirmEditSetting();

// PROJECT: Plant_Screen

void toSettingPage(lv_event_t *e)
{
  updateSettingPage();
  lv_scr_load_anim(ui_SettingScreen1, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}

void toggleLedSwitch(lv_event_t *e)
{
  toggleLedWithProtocol();
}

void togglePump1Switch(lv_event_t *e)
{
  togglePump1WithProtocol();
}

void togglePump2Switch(lv_event_t *e)
{
  togglePump2WithProtocol();
}

// PROJECT: Plant_Screen_2

void toEditSsid(lv_event_t *e)
{
  boundEditText(ui_SettingScreen1SsidTextArea, LV_KEYBOARD_MODE_TEXT_LOWER, false);
  lv_scr_load_anim(ui_EditTextScreen, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}

void toEditWifiPw(lv_event_t *e)
{
  boundEditText(ui_SettingScreen1WifiPwTextArea, LV_KEYBOARD_MODE_TEXT_LOWER, true);
  lv_scr_load_anim(ui_EditTextScreen, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}

void toEditUid(lv_event_t *e)
{
  boundEditText(ui_SettingScreen1UidTextArea, LV_KEYBOARD_MODE_TEXT_LOWER, false);
  lv_scr_load_anim(ui_EditTextScreen, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}

void toEditDevKey(lv_event_t *e)
{
  boundEditText(ui_SettingScreen1DevKeyTextArea, LV_KEYBOARD_MODE_TEXT_LOWER, false);
  lv_scr_load_anim(ui_EditTextScreen, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}

void settingConfirm(lv_event_t *e)
{
  confirmEditSetting();
  lv_scr_load_anim(ui_PlantScreen, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
  // ESP.restart();
}

void settingCancel(lv_event_t *e)
{
  lv_scr_load_anim(ui_PlantScreen, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}

void nextSettingPage(lv_event_t *e)
{
  lv_scr_load_anim(ui_SettingScreen2, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}

void enterTextConfirm(lv_event_t *e)
{
  validateEditText();

  lv_obj_t *target = getSettingPageBackFromEnterText(textareaRef);
  textareaRef = NULL;
  if (target)
  {
    lv_scr_load_anim(target, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
  }
}

void enterTextCancel(lv_event_t *e)
{
  lv_obj_t *target = getSettingPageBackFromEnterText(textareaRef);
  textareaRef = NULL;
  if (target)
  {
    lv_scr_load_anim(target, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
  }
}

// PROJECT: Plant_Screen_3

void toEditTempSlot(lv_event_t *e)
{
  boundEditText(ui_SettingScreen2TempSlotTextArea, LV_KEYBOARD_MODE_NUMBER, false);
  lv_scr_load_anim(ui_EditTextScreen, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}

void toEditHumidSlot(lv_event_t *e)
{
  boundEditText(ui_SettingScreen2HumidSlotTextArea, LV_KEYBOARD_MODE_NUMBER, false);
  lv_scr_load_anim(ui_EditTextScreen, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}

void toEditLightSlot(lv_event_t *e)
{
  boundEditText(ui_SettingScreen2LightSlotTextArea, LV_KEYBOARD_MODE_NUMBER, false);
  lv_scr_load_anim(ui_EditTextScreen, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}

void toEditWaterSlot(lv_event_t *e)
{
  boundEditText(ui_SettingScreen2WaterSlotTextArea, LV_KEYBOARD_MODE_NUMBER, false);
  lv_scr_load_anim(ui_EditTextScreen, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}

void toEditLedSlot(lv_event_t *e)
{
  boundEditText(ui_SettingScreen2LedSlotTextArea, LV_KEYBOARD_MODE_NUMBER, false);
  lv_scr_load_anim(ui_EditTextScreen, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}

void toEditPump1Slot(lv_event_t *e)
{
  boundEditText(ui_SettingScreen2Pump1SlotTextArea, LV_KEYBOARD_MODE_NUMBER, false);
  lv_scr_load_anim(ui_EditTextScreen, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}

void toEditPump2Slot(lv_event_t *e)
{
  boundEditText(ui_SettingScreen2Pump2SlotTextArea, LV_KEYBOARD_MODE_NUMBER, false);
  lv_scr_load_anim(ui_EditTextScreen, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}

void prevSettingPage(lv_event_t *e)
{
  lv_scr_load_anim(ui_SettingScreen1, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}
