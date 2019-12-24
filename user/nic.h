#pragma once
#include QMK_KEYBOARD_H

#include "quantum.h"

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  BSPCDEL,
  _SAFE_RANGE,
};

enum userspace_layers {
  _QWERTY = 0,
  _WINDOWS,
  _LOWER,
  _RAISE,
  _NORMAN,
  _GAMEPAD,
  _NUMPAD,
  _F_KEYS,
  _ADJUST,
};

enum encoder_modes {
  ENC_VOL = _SAFE_RANGE,
  ENC_MS_WH,
  ENC_ARROWS_V,
  ENC_ARROWS_H,
  ENC_RGB_HUE,
  ENC_RGB_MODE,
  ENC_RGB_VAL,
  _MAX_ENCODER_MODES,
};

uint16_t MIN_ENCODER_INDEX;
uint16_t MAX_ENCODER_INDEX;
volatile uint16_t encoder_mode;

void set_encoder_mode(uint16_t);
void cycle_encoder_mode(bool);

#define KC_BSDEL BSPCDEL
#define KC_LOWERTAB LT(_LOWER, KC_TAB)
#define KC_HYPER_TAB ALL_T(KC_TAB)

#define KC_ALT_TAB LALT_T(KC_TAB)
#define KC_ALT_DEL LALT_T(KC_DEL)

#define KC_TMUX LCTL(KC_B)
#define KC_CTL_ESC CTL_T(KC_ESC)
#define KC_GUI_CAPS RGUI_T(KC_CAPS)
#define KC_RSFT_SLSH RSFT_T(KC_SLSH)

#define KC_SCR LGUI(LSFT(KC_3))
#define KC_SCR_SEL LGUI(LSFT(KC_4))
#define KC_CP_SCR_SEL LGUI(LCTL(LSFT(KC_4)))
