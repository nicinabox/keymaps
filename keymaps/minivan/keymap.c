#include "nic.h"
#include QMK_KEYBOARD_H

enum {
  SFT_CAPS = 0,
  VOLD_MUTE = 2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_arrow(
    HYPER_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, LT(_LOWER, KC_QUOT),
    TD(SFT_CAPS), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP, KC_BSLS,
    LOWER, KC_LALT, KC_LGUI,        KC_ENTER, KC_SPC,        RAISE,         KC_LEFT,  KC_DOWN,  KC_RIGHT
  ),

  [_LOWER] = LAYOUT_arrow(
    S(KC_GRV),  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    _______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
    _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, S(KC_SLSH), _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_RAISE] = LAYOUT_arrow(
    KC_GRV,  KC_1,  KC_2,  KC_3,   KC_4,   KC_5,   KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, _______,
    _______, _______, _______, _______, _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT,  KC_SLSH, KC_BSLS,
    _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_NORMAN] = LAYOUT_arrow(
    _______,  KC_Q,    KC_W,    KC_D,    KC_F,    KC_K,    KC_J,    KC_U,    KC_R,    KC_L,    KC_SCLN,  _______,
    _______,  KC_A,    KC_S,    KC_E,    KC_T,    KC_G,    KC_Y,    KC_N,    KC_I,    KC_O,    KC_H,     KC_QUOT,
    _______,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_P,    KC_M,    KC_COMM, KC_DOT,  _______,  _______,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_ADJUST] = LAYOUT_arrow(
    RESET,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,  _______,
    _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,     _______,
    _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,  _______,  _______,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______
  ),
};

const uint16_t PROGMEM fn_actions[] = {
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [SFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
  [VOLD_MUTE] = ACTION_TAP_DANCE_DOUBLE(KC_VOLD, KC_MUTE)
};
