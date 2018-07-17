#include "bananasplit.h"

#define DEFAULT_LAYER   0
#define WIN_LAYER       1
#define THUMB_LAYER     2
#define NORMAN_LAYER    3
#define NUMS_LAYER      4
#define MOD_LAYER       5
#define WIN_THUMB_LAYER 6

#define CTL_ESC CTL_T(KC_ESC)
#define HYPR_TAB ALL_T(KC_TAB)
#define SCR LGUI(LSFT(KC_4))
#define CP_SCR LGUI(LCTL(LSFT(KC_4)))
#define TMUX LCTL(KC_B)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DEFAULT_LAYER] = LAYOUT_hhkb_arrow(
    KC_GRV,    KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_DEL,
    HYPR_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC, KC_BSPC,
    CTL_ESC,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,  KC_QUOT, KC_ENT,
    KC_LSFT,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,  KC_DOT,  RSFT_T(KC_SLSH),  KC_UP, TG(WIN_LAYER),
    KC_CAPS,  KC_LALT,  KC_LGUI,  GUI_T(KC_SPC),      MO(THUMB_LAYER),      KC_SPC,  KC_LGUI, KC_RALT,  KC_LEFT, KC_DOWN, KC_RIGHT
  ),

  [WIN_LAYER] = LAYOUT_hhkb_arrow(
    KC_ESC,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_GRV,
    KC_TAB,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_LCTL,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_LSFT,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_CAPS,  KC_LGUI,  KC_LALT,  KC_SPC,      MO(WIN_THUMB_LAYER),      _______,  KC_LALT, KC_LGUI,  _______, _______, _______
  ),

  [WIN_THUMB_LAYER] = LAYOUT_hhkb_arrow(
    KC_GRV,  KC_F1,  KC_F2,  KC_F3, KC_F4, KC_F5, KC_F6, KC_F7,  KC_F8,   KC_F9,  KC_F10, KC_F11, KC_F12, KC_VOLD, KC_VOLU,
    _______,  _______,  _______,  _______,  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, _______, _______,
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, _______,  _______, _______,
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,    _______,     _______,  _______,  KC_PGUP, _______,
    _______,  _______,  _______, _______,      _______,         _______,               _______, _______,  KC_HOME, KC_PGDN, KC_END
  ),

  [THUMB_LAYER] = LAYOUT_hhkb_arrow(
    MO(MOD_LAYER),  _______,  _______,  _______, SCR, CP_SCR,   _______,  _______,  KC_MPRV,   KC_MPLY,  KC_MNXT, KC_VOLD, KC_VOLU, _______, _______,
    _______,  KC_F1,  KC_F2,  KC_F3,  KC_F4,   _______,   _______,   KC_UNDS,   KC_PLUS,   KC_LCBR,   KC_RCBR,   _______, _______, KC_DEL,
    _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,   _______,   KC_MINS,   KC_EQL,   KC_LBRC, KC_RBRC,  _______, TG(NORMAN_LAYER),
    _______,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   TMUX,   _______,   _______,    _______,     _______,  KC_PPLS,  KC_PGUP, KC_INS,
    _______,  _______,  _______, _______,      _______,         _______,               _______, _______,  KC_HOME, KC_PGDN, KC_END
  ),

  [NUMS_LAYER] = LAYOUT_hhkb_arrow(
    _______,  _______,  _______,  _______, _______,   _______,   _______,  KC_P7,  KC_P8,   KC_P9,  KC_PSLS, _______, _______, _______, _______,
    _______,  KC_F1,  KC_F2,  KC_F3,  KC_F4,   _______,   _______,   KC_P4,   KC_P5,   KC_P6,     KC_PAST,   _______, _______, _______,
    _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,   _______,   KC_P1,   KC_P2,   KC_P3,   KC_PMNS,  _______, _______,
    _______,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,   _______,   KC_P0,    KC_PEQL,   KC_PDOT,  KC_PPLS,  _______, _______,
    _______,  _______,  _______, _______,      _______,      _______,  _______, _______,  _______, _______, _______
  ),

  [NORMAN_LAYER] = LAYOUT_hhkb_arrow(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,  _______,   _______,   KC_D,   KC_F,   KC_K,   KC_J,   KC_U,   KC_R,   KC_L,   KC_SCLN,   _______, _______, _______,
    _______,   _______,   _______,   KC_E,   KC_T,  _______,   KC_Y,   KC_N,   KC_I,   KC_O,   KC_H,  _______, _______,
    _______,   _______,   _______,   _______,   _______,   _______,   KC_P,   _______,   _______,  _______,  _______,  _______, _______,
    _______,  _______,  _______, _______,      _______,      _______,  _______, _______,  _______, _______, _______
  ),

  [MOD_LAYER] = LAYOUT_hhkb_arrow(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,  _______,   _______,   _______,  RESET,  _______,   _______,   _______,   _______,   _______,   _______,   _______, _______, _______,
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______, _______,
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______,  _______, _______,
    _______,  _______,  _______, _______,      _______,      _______,  _______, _______,  _______, _______, _______
  ),
};

const uint16_t PROGMEM fn_actions[] = {
};
