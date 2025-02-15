#include "kc60.h"

#define QWERTY 0
#define SPACEFN 1
#define F_ROW 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QWERTY] = KEYMAP(
      KC_ESC,   KC_1,     KC_2,     KC_3,    KC_4,     KC_5,     KC_6,     KC_7,    KC_8,  KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  \
      KC_TAB,   KC_Q,     KC_W,     KC_E,    KC_R,     KC_T,     KC_Y,     KC_U,    KC_I,  KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  \
      KC_LCTL,  KC_A,     KC_S,     KC_D,    KC_F,     KC_G,     KC_H,     KC_J,    KC_K,  KC_L,     KC_SCLN,  KC_QUOT,  KC_NO,    KC_ENT,   \
      KC_LSFT,  KC_NO,    KC_Z,     KC_X,    KC_C,     KC_V,     KC_B,     KC_N,    KC_M,  KC_COMM,  KC_DOT,   KC_SLSH,  KC_NO,    KC_RSFT,  \
      MEH_T(KC_CAPS),  KC_LALT,  KC_LGUI,                     FUNC(1),                               KC_NO,    KC_RGUI,  KC_RALT,  FUNC(2), KC_TRNS \
  ),

  [SPACEFN] = KEYMAP(
    KC_TRNS,   KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_MPRV,    KC_MPLY,  KC_MNXT,     KC_MUTE,   KC_VOLD,  KC_VOLU,   KC_DELETE,  \
    KC_TRNS,   KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_PGUP,     KC_TRNS,    KC_UP,  KC_TRNS,     KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS,  \
    KC_TRNS,   KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_PGDN,     KC_LEFT,    KC_DOWN,  KC_RIGHT,     KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,   \
    KC_TRNS,   KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,  \
    KC_TRNS,   KC_TRNS,     KC_TRNS,                     KC_TRNS,                                       KC_NO,    KC_TRNS,  KC_TRNS,  KC_TRNS,  QK_BOOT \
  ),

  [F_ROW] = KEYMAP(
    KC_TRNS,   KC_F1,       KC_F2,       KC_F3,      KC_F4,       KC_F5,       KC_F6,       KC_F7,      KC_F8,  KC_F9,     KC_F10,     KC_F11,  KC_F12,   KC_TRNS,  \
    KC_TRNS,   KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_UP,  KC_TRNS,     KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS,  \
    KC_TRNS,   KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_LEFT,    KC_DOWN,  KC_RIGHT,     KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,   \
    KC_TRNS,   KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,  \
    KC_TRNS,   KC_TRNS,     KC_TRNS,                     KC_TRNS,                                       KC_NO,    KC_TRNS,  KC_TRNS,  KC_TRNS,  QK_BOOT \
  ),
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_DEFAULT_LAYER_SET(QWERTY),
  [1] = ACTION_LAYER_TAP_KEY(SPACEFN, KC_SPC),
  [2] = ACTION_LAYER_MOMENTARY(F_ROW),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  return MACRO_NONE;
};
