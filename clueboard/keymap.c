#include "clueboard.h"

#define QWERTY_LAYER 0
#define F_LAYER 1

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap QWERTY_LAYER: (Base Layer) Default Layer
   * ,--------------------------------------------------------------------------.  ,----.
   * |Esc~|   1|   2|   3|   4|   5|   6|   7|   8|   9|   0|   -|   =|   \|  BS|  |PGUP|
   * |--------------------------------------------------------------------------|  |----|
   * |   Tab|   Q|   W|   E|   R|   T|   Y|   U|   I|   O|   P|   [|   ]|      \|  |PGDN|
   * |--------------------------------------------------------------------------|  `----'
   * |Capslck|   A|   S|   D|   F|   G|   H|   J|   K|   L|   ;|   '|   # |  Ent|
   * |-----------------------------------------------------------------------------.
   * |Shift|  BS|   Z|   X|   C|   V|   B|   N|   M|   ,|   .|   /|   BS|Shift|  UP|
   * |------------------------------------------------------------------------|----|----.
   * | Ctrl|  Gui|  Alt| MHen|    Space|    Space|  Hen|  Alt| Ctrl|  F_LAYER|LEFT|DOWN|RGHT|
   * `----------------------------------------------------------------------------------'
   */
[QWERTY_LAYER] = KEYMAP(
  KC_GRV,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSLS,  KC_DEL,          KC_MPLY, \
  KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSPC,                   KC_MNXT, \
  CTL_T(KC_ESC), KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN,  KC_QUOT,  XXXXXXX,  KC_ENT,                             \
  KC_LSFT, XXXXXXX, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,   KC_SLSH,   XXXXXXX, KC_RSFT,          KC_UP,            \
  KC_CAPS, MO(F_LAYER), KC_LALT, KC_LGUI,   KC_SPC,   KC_SPC,  KC_RGUI,  KC_RALT,  MO(F_LAYER), KC_RCTL,  KC_LEFT, KC_DOWN, KC_RGHT),

  /* Keymap F_LAYER: Function Layer
   * ,--------------------------------------------------------------------------.  ,----.
   * |   `|  F1|  F2|  F3|  F4|  F5|  F6|  F7|  F8|  F9| F10| F11| F12|    | Del|  |BLIN|
   * |--------------------------------------------------------------------------|  |----|
   * |      |    |    |    |    |    |    |    |PScr|SLck|Paus|    |    |       |  |BLDE|
   * |--------------------------------------------------------------------------|  `----'
   * |       |    | RESET_LAYER|    |    |    |    |    |    |    |    |    |     |     |
   * |-----------------------------------------------------------------------------.
   * |     |    |    |    |    |    |    |    |    |    |    |    |     |     |PGUP|
   * |------------------------------------------------------------------------|----|----.
   * |     |     |     |     |         |         |     |     |     |  F_LAYER|HOME|PGDN| END|
   * `----------------------------------------------------------------------------------'
   */
[F_LAYER] = KEYMAP(
  KC_GRV,  KC_F1,   KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______, _______,           KC_VOLU, \
  _______, _______, _______,_______,RESET,_______,_______,_______,KC_PSCR,KC_SLCK, KC_PAUS,  _______,  _______,  _______,                   KC_VOLD, \
  _______, _______, _______,_______,_______,_______,_______,_______,_______,_______, _______,  _______,  _______,  _______,                           \
  _______, _______, _______,_______,_______,_______,_______,_______,_______,_______, _______,  _______,  _______,  _______,          KC_PGUP,         \
  _______, _______, _______, _______,        _______,_______,                        _______,  _______,  _______,  MO(F_LAYER), KC_HOME, KC_PGDN, KC_END),
};
