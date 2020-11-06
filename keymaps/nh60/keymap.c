#include "nic.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QWERTY_LAYER] = KEYMAP(
    KC_GRV,          KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_DEL,
    HYP_TAB,       KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
    CTL_ESC,         KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT, KC_Z,   KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_CAPS, _______,
                    KC_LALT, KC_LGUI,     LT(RAISE_LAYER, KC_SPC),      KC_RGUI, LOWER
  ),

  [RAISE_LAYER] = KEYMAP(
    _______, _______, _______, SCR, SCR_SEL, SCR_SEL_CP, _______,  _______,  KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD, KC_VOLU, _______, _______,
    _______, _______, _______, _______, _______,     _______,         KC_PGUP, _______, KC_UP, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,     _______,         KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______,
    KC_CAPS, _______, _______, _______, _______,     TMUX,         KC_HOME, KC_END, KC_INS, _______, _______, _______, _______,
                        _______, _______, _______,     _______,         _______
  ),

  [LOWER_LAYER] = KEYMAP(
    _______, KC_F1, KC_F2,  KC_F3,   KC_F4,   _______,   _______,  KC_P7,   KC_P8,   KC_P9,     KC_PSLS,    _______,   _______, _______, _______,
    _______, KC_F5, KC_F6,  KC_F7,   KC_F8,   _______, _______,    KC_P4,   KC_P5,   KC_P6,     KC_PAST, _______, _______, _______,
    KC_CAPS, KC_F9, KC_F10, KC_F11, KC_F12,   _______, _______,    KC_P1,   KC_P2,   KC_P3,     KC_PMNS, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_PEQL, KC_PDOT, KC_PPLS, _______, _______,
                                  _______, _______, _______, _______, _______
  ),

  [ADJUST_LAYER] = KEYMAP(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______,
    RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                    _______, _______, _______, _______, _______
  ),

};
