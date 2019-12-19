#pragma once
#include QMK_KEYBOARD_H

#include "quantum.h"

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  BSPCDEL,
  NEW_SAFE_RANGE,
};

enum userspace_layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _F_KEYS,
    _ADJUST,
    _NORMAN,
    _GAMEPAD,
};

#define KC_BSDEL BSPCDEL
#define KC_LOWERTAB LT(_LOWER, KC_TAB)

#define KC_TMUX LCTL(KC_B)
#define KC_CTL_ESC CTL_T(KC_ESC)
#define KC_ALT_TAB LALT_T(KC_TAB)
#define KC_GUI_CAPS RGUI_T(KC_CAPS)
#define KC_DEL_ALT LALT_T(KC_DEL)

#define KC_SCR LGUI(LSFT(KC_3))
#define KC_SCR_SEL LGUI(LSFT(KC_4))
#define KC_CP_SCR_SEL LGUI(LCTL(LSFT(KC_4)))
