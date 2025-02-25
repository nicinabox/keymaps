#include "nic.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QWERTY_LAYER] = LAYOUT_planck_grid(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    CTL_ESC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT,
    _______,  KC_HYPR,  KC_LALT,  KC_LGUI,  LOWER,    KC_SPC,   KC_SPC,    RAISE,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT
  ),

  [RAISE_LAYER] = LAYOUT_planck_grid(
    KC_GRV,   KC_1,   KC_2,  KC_3,    KC_4,     KC_5,     KC_6,    KC_7,     KC_8,     KC_9,     KC_0,     _______,
    _______,  KC_4,   KC_5,  KC_6,    _______,  _______,  _______, KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_BSLS,
    KC_CAPS,  KC_7,   KC_8,  KC_9,    _______,  _______,  _______, _______,  _______,  KC_DOT,   _______,  _______,
    _______,  KC_0,   KC_0,  KC_DOT,  _______,  _______,  _______, _______,  KC_MPLY,  KC_VOLD,  KC_VOLU,  KC_MFFD
  ),

  [LOWER_LAYER] = LAYOUT_planck_grid(
    KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC, KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  _______,
    _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,   KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,  KC_PIPE,
    _______,  KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,  _______,  _______,  _______,  _______,  _______,
    _______,  KC_MEH,   _______,  _______,  _______,  _______,  _______, _______,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END
  ),

  [ADJUST_LAYER] = LAYOUT_planck_grid(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    QK_BOOT,    RGB_TOG,  RGB_HUI,  RGB_SAI,  RGB_VAI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  RGB_MOD,  RGB_HUD,  RGB_SAD,  RGB_VAD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  )
};
