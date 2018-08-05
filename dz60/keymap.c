#include QMK_KEYBOARD_H
#include "layout.h"

#define ______ KC_TRNS
#define XXXXXX KC_NO

#define CTL_ESC CTL_T(KC_ESC)
#define TMUX LCTL(KC_B)
#define HPR_TAB ALL_T(KC_TAB)
#define ALT_TAB LALT_T(KC_TAB)
#define GUI_DEL LT(KC_LGUI, KC_DEL)
#define SCR LGUI(LSFT(KC_3))
#define SCR_SEL LGUI(LSFT(KC_4))
#define CP_SCR_SEL LGUI(LCTL(LSFT(KC_4)))
#define SFT_SLSH RSFT_T(KC_SLSH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------------------------------------------------------.
   * | ` ~ |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \  | Del |
   * |-----------------------------------------------------------------------------------------+
   * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |  Bksp  |
   * |-----------------------------------------------------------------------------------------+
   * | Ctrl    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
   * |-----------------------------------------------------------------------------------------+
   * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |    RSh/?  |  U  | Caps|
   * |-----------------------------------------------------------------------------------------+
   * | Fn |  Alt  |  Cmd  |              Space                         | Cmd |  L  |  D  |  R  |
   * `-----------------------------------------------------------------------------------------'
   */

  LAYOUT_60_arrows(
      KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_DEL,
      ALT_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
      CTL_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, SFT_SLSH, KC_UP, KC_CAPS,
      MO(1), KC_LALT, KC_LGUI,        KC_SPC,               KC_RGUI, KC_LEFT, KC_DOWN, KC_RIGHT
  ),

  /* FN Layer
   * ,-----------------------------------------------------------------------------------------.
   * | Esc |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |   RESET   |
   * |-----------------------------------------------------------------------------------------+
   * |        |RBB T|RGB M| Hue+| Hue-| Sat+| Sat-| Val+| Val-|     |     |      |      |      |
   * |-----------------------------------------------------------------------------------------+
   * |         |     |     |    |     |     |     |     |     |     |     |     |             |
   * |-----------------------------------------------------------------------------------------+
   * |           |     |     |     |     |     |     |     |     |     |     |     |     |     |
   * |-----------------------------------------------------------------------------------------+
   * |      |       |       |                                   |     |      |     |     |     |
   * `-----------------------------------------------------------------------------------------'
   */

  LAYOUT_60_arrows(
      ______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_F11, KC_F12, ______, RESET,
      ______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, ______, ______, ______, ______, ______, ______, ______, ______, ______,
      ______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, ______, ______, ______, ______, ______, ______, ______,
      ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,
      ______, ______, ______, ______, ______, ______, ______, ______
    ),
};

const uint16_t PROGMEM fn_actions[] = {
};
