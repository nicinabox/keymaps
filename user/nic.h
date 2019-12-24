#pragma once
#include QMK_KEYBOARD_H

#include "quantum.h"

enum userspace_keycodes {
  QWERTY = SAFE_RANGE,
  WINDOWS,
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
  _MAX_ENCODER_MODES,
  USER_SAFE_RANGE,
};

enum userspace_layers {
  _QWERTY = 0,
  _WINDOWS,
  _GAMEPAD,
  _NUMPAD,
  _F_KEYS,
  _LOWER,
  _RAISE,
  _ADJUST,
  USER_SAFE_LAYER,
};

uint16_t MIN_ENCODER_INDEX;
uint16_t MAX_ENCODER_INDEX;
volatile uint16_t encoder_mode;

void set_encoder_mode(uint16_t);
void cycle_encoder_mode(bool);

#define LOWER_TAB   LT(_LOWER, KC_TAB)
#define HYPER_TAB   ALL_T(KC_TAB)

#define ALT_TAB     LALT_T(KC_TAB)
#define ALT_DEL     LALT_T(KC_DEL)

#define TMUX        LCTL(KC_B)
#define LOCK        LGUI(LCTL(KC_Q))

#define CTL_ESC     CTL_T(KC_ESC)
#define GUI_CAPS    RGUI_T(KC_CAPS)
#define RSFT_SLSH   RSFT_T(KC_SLSH)

#define SCR         LGUI(LSFT(KC_3))
#define SCR_SEL     LGUI(LSFT(KC_4))
#define SCR_SEL_CP  LGUI(LCTL(LSFT(KC_4)))
