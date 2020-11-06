#pragma once
#include QMK_KEYBOARD_H

#include "quantum.h"

enum userspace_keycodes
{
  QWERTY = SAFE_RANGE,
  WINDOWS,
  EXTEND,
  LOWER,
  RAISE,
  ADJUST,
  ENC_VOL,
  ENC_MS_WH,
  ENC_ARROWS_V,
  ENC_ARROWS_H,
  ENC_RGB_HUE,
  ENC_RGB_MODE,
  ENC_RGB_VAL,
  ENC_UNDO,
      _MAX_ENCODER_MODES,
  USER_SAFE_RANGE,
};

enum userspace_layers
{
  QWERTY_LAYER = 0,
  COLEMAK_LAYER,
  WINDOWS_LAYER,
  GAMEPAD_LAYER,
  NUMPAD_LAYER,
  F_KEYS_LAYER,
  EXTEND_LAYER,
  LOWER_LAYER,
  RAISE_LAYER,
  ADJUST_LAYER,
  USER_SAFE_LAYER,
};

extern uint16_t MIN_ENCODER_INDEX;
extern uint16_t MAX_ENCODER_INDEX;
extern volatile uint16_t encoder_mode;

void set_encoder_mode(uint16_t);
void cycle_encoder_mode(bool);

#define HYP_TAB     ALL_T(KC_TAB)

#define LO_TAB      LT(LOWER_LAYER, KC_TAB)
#define LO_Z        LT(LOWER_LAYER, KC_Z)
#define LO_SLSH     LT(LOWER_LAYER, KC_SLSH)

#define TG_ADJ      TG(ADJUST_LAYER)

#define ALT_TAB     LALT_T(KC_TAB)
#define ALT_DEL     LALT_T(KC_DEL)

#define TMUX        LCTL(KC_B)
#define CTL_ESC     CTL_T(KC_ESC)

#define RSFT_SLSH   RSFT_T(KC_SLSH)

#define GUI_CAPS    RGUI_T(KC_CAPS)
#define LOCK        LGUI(LCTL(KC_Q))
#define SCR         LGUI(LSFT(KC_3))
#define SCR_SEL     LGUI(LSFT(KC_4))
#define SCR_SEL_CP  LGUI(LCTL(LSFT(KC_4)))
