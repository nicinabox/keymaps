#include "nic.h"
#include "layout.h"

#define SPACEFN LT(RAISE_LAYER, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QWERTY_LAYER] = LAYOUT_hhkb_blocked(
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_DEL,
    KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC, KC_BSPC,
    CTL_ESC,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,  KC_QUOT, KC_ENT,
    KC_LSFT,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT, LOWER,
                          KC_LALT,  KC_LGUI,    SPACEFN,   KC_MEH, RAISE
  ),

  [LOWER_LAYER] = LAYOUT_hhkb_blocked(
    _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, _______,
    _______,  _______,   _______,   _______,  _______,  _______,   _______,   _______,   _______,   _______,   _______,   KC_UP, _______, _______,
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_HOME,   KC_PGUP,   KC_LEFT,  KC_RIGHT, _______,
    KC_CAPS,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_END,  KC_PGDN,  KC_DOWN, _______,   _______,
                          _______, _______,      _______,     _______, _______
  ),

  [RAISE_LAYER] = LAYOUT_hhkb_blocked(
    _______, _______, _______, SCR, SCR_SEL, SCR_SEL_CP, _______, _______, KC_MPRV, KC_MPLY,  KC_MNXT, KC_VOLD, KC_VOLU, _______, _______,
    _______,  _______,   _______,   _______,  _______,  _______,   _______,   _______,   KC_UP,   _______,   _______,   _______, _______, _______,
    LOCK,     _______,   _______,   _______,   _______,   _______,   _______,   KC_LEFT,   KC_DOWN,   KC_RIGHT,   _______,  _______, _______,
    _______,   _______,   _______,   _______,   _______,   TMUX,   _______,   _______,   _______,  _______,  _______, _______,   _______,
                          _______, _______,      _______,     _______, _______
  ),

  [ADJUST_LAYER] = LAYOUT_hhkb_blocked(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    QK_BOOT,  _______,   _______,   _______,  _______,  _______,   _______,   _______,   _______,   _______,   _______,   _______, _______, _______,
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______, _______,
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______, _______,   _______,
                          _______, _______,      _______,     _______, _______
  ),
};
