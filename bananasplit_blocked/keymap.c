#include "layout.h"

#include QMK_KEYBOARD_H

#define DEFAULT_LAYER 0
#define EXTRAS_LAYER  1
#define MOD_LAYER     2

#define HYPR_TAB ALL_T(KC_TAB)
#define SPACEFN LT(EXTRAS_LAYER, KC_SPC)
#define CTL_ESC CTL_T(KC_ESC)
#define SCR LGUI(LSFT(KC_4))
#define CP_SCR LGUI(LCTL(LSFT(KC_4)))
#define TMUX LCTL(KC_B)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DEFAULT_LAYER] = LAYOUT_hhkb_blocked( \
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_DEL, \
    HYPR_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC, KC_BSPC, \
    CTL_T(KC_ESC),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,  KC_QUOT, KC_ENT, \
    KC_LSFT,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT, MO(MOD_LAYER), \
                          KC_LALT,  KC_LGUI,    SPACEFN,   KC_RGUI, KC_RALT \
  ),

  [EXTRAS_LAYER] = LAYOUT_hhkb_blocked( \
    _______, _______, _______, _______, SCR, CP_SCR, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______,  _______,   _______,   _______,  _______,  _______,   _______,   _______,   KC_UP,   _______,   _______,   _______, _______, _______, \
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_LEFT,   KC_DOWN,   KC_RIGHT,   _______,  _______, _______, \
    _______,   _______,   _______,   _______,   _______,   TMUX,   _______,   _______,   _______,  _______,  _______, _______,   _______, \
                          _______, _______,      _______,     _______, _______ \
  ),

  [MOD_LAYER] = LAYOUT_hhkb_blocked( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______,  _______,   _______,   _______,  RESET,  _______,   _______,   _______,   _______,   _______,   _______,   _______, _______, _______, \
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______, _______, \
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______, _______,   _______, \
                          _______, _______,      _______,     _______, _______ \
  ),
};

const uint16_t PROGMEM fn_actions[] = {
};
