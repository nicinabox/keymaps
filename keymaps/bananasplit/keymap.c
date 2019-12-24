#include "nic.h"
#include QMK_KEYBOARD_H

enum keymap_keycodes {
  _WINDOWS_RAISE = USER_SAFE_LAYER
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_hhkb_arrow(
    KC_GRV,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSLS, KC_DEL,
    HYPER_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,     KC_LBRC, KC_RBRC,       KC_BSPC,
    CTL_ESC,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,  KC_QUOT, KC_ENT,
    KC_LSFT,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,  KC_DOT,  RSFT_SLSH,     KC_UP,   LOWER,
    KC_CAPS,  KC_LALT,  KC_LGUI,  KC_SPC,      RAISE,      KC_SPC,  KC_LGUI, KC_RALT,           KC_LEFT, KC_DOWN, KC_RIGHT
  ),

  [_RAISE] = LAYOUT_hhkb_arrow(
    MO(_ADJUST),  _______,  _______,  _______, SCR, SCR_SEL, SCR_SEL_CP,  _______,  KC_MPRV,   KC_MPLY,  KC_MNXT, KC_VOLD, KC_VOLU, _______, _______,
    _______,  KC_F1,  KC_F2,  KC_F3,  KC_F4,   _______,   _______,   KC_UNDS,   KC_PLUS,   KC_LCBR,   KC_RCBR,   _______, _______, KC_DEL,
    _______,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,   _______,   KC_MINS,   KC_EQL,   KC_LBRC, KC_RBRC,  _______, _______,
    _______,  KC_F9,   KC_F10,   KC_F11,   KC_F12,   TMUX,   _______,   _______,    _______,     _______,  KC_PPLS,  KC_PGUP, KC_INS,
    _______,  _______,  _______, _______,      _______,         _______,               _______, _______,    KC_HOME, KC_PGDN, KC_END
  ),

  [_WINDOWS] = LAYOUT_hhkb_arrow(
    KC_ESC,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_GRV,
    KC_TAB,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_LCTL,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_LSFT,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_CAPS,  KC_LGUI,  KC_LALT,  KC_SPC,      MO(_WINDOWS_RAISE),      _______,  KC_LALT, KC_LGUI,  _______, _______, _______
  ),

  [_WINDOWS_RAISE] = LAYOUT_hhkb_arrow(
    KC_GRV,  KC_F1,  KC_F2,  KC_F3, KC_F4, KC_F5, KC_F6, KC_F7,  KC_F8,   KC_F9,  KC_F10, KC_F11, KC_F12, KC_VOLD, KC_VOLU,
    _______,  _______,  _______, _______,  _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______, _______, KC_DEL,
    _______,  _______,  _______, _______,  _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______, _______,
    _______,  _______,  _______, _______,  _______,   _______,   _______,   _______,   _______,   _______,  _______,  KC_PGUP, _______,
    _______,  _______,  _______, _______,  _______,   _______,               _______, _______,             KC_HOME, KC_PGDN, KC_END
  ),

  [_ADJUST] = LAYOUT_hhkb_arrow(
    _______, TG(_WINDOWS), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    RESET,  _______,   _______,   _______,  _______,  _______,   _______,   _______,   _______,   _______,   _______,   _______, _______, _______,
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______, _______,
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______,  _______, _______,
    _______,  _______,  _______, _______,      _______,      _______,  _______, _______,  _______, _______, _______
  ),
};
