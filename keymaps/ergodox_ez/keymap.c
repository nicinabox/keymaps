#include "nic.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ergodox(
  KC_EQUAL,           KC_1,     KC_2,     KC_3,     KC_4,   KC_5,   KC_ESC,
  KC_TAB,             KC_Q,     KC_W,     KC_E,     KC_R,   KC_T,   LOWER,
  CTL_ESC,            KC_A,     KC_S,     KC_D,     KC_F,   KC_G,
  KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,   KC_B,   KC_GRAVE,
  KC_CAPS,            KC_MEH,  KC_HYPR,  KC_LGUI,  KC_LALT,

                                          KC_HOME,  KC_END,
                                                    KC_PGUP,
                                 KC_BSPC, KC_DEL, KC_PGDOWN,


    _______,         KC_6,      KC_7,     KC_8,      KC_9,      KC_0,    KC_MINUS,
    KC_LBRC,         KC_Y,      KC_U,     KC_I,      KC_O,      KC_P,    KC_RBRC,
                     KC_H,      KC_J,     KC_K,      KC_L,      KC_SCLN, KC_QUOTE,
    KC_BSLS,         KC_N,      KC_M,     KC_COMMA,  KC_DOT,    KC_SLSH, KC_RSFT,
                                RAISE,    KC_LEFT,   KC_DOWN,   KC_UP,   KC_RIGHT,

    KC_MPLY,  KC_MNXT,
    KC_VOLU,
    KC_VOLD,  KC_ENT, KC_SPC
),

[_LOWER] = LAYOUT_ergodox(
  _______,          _______,  _______,  SCR,  SCR_SEL, SCR_SEL_CP,                          _______,
  LGUI(KC_BSPACE),  _______,  _______,  _______,  _______,          _______,                _______,
  _______,          _______,  _______,  _______,  _______,          _______,                _______,
  _______,          _______,  _______,  _______,  _______,          _______,
  _______,          _______,  _______,  _______,  TMUX,

                                                _______,  _______,
                                                          _______,
                                      _______,  _______,  _______,


  _______,  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  _______,
            _______,  KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,  KC_BSLS,
  _______,  _______,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_PIPE,
                      _______,  _______,  _______,  _______,  _______,

  _______, _______,
  _______,
  _______, _______, _______
),

[_RAISE] = LAYOUT_ergodox(
  _______,  _______,_______,_______,_______,_______,_______,
  _______,  _______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,

                        _______,  _______,
                                  _______,
                _______, _______, _______,


  _______,  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  KC_PGUP,  KC_HOME,  KC_UP,    KC_END,   _______,  _______,
            KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RIGHT, _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,
                      _______,  _______,  _______,  _______,  _______,

  KC_MPRV,_______,
  _______,
  KC_MUTE,_______,_______
),

[_NUMPAD] = LAYOUT_ergodox(
  _______,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,_______,
  _______,KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,_______,
  _______,KC_F11 ,KC_F12 ,_______,_______,_______,
  _______,_______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,

                        _______,  _______,
                                  _______,
                _______, _______, _______,

  _______,  _______,  _______,  KC_SLSH,  KC_ASTR,    _______,   _______,
  _______,  KC_UP,    KC_7,     KC_8,     KC_9,       KC_MINUS,  _______,
            KC_DOWN,  KC_4,     KC_5,     KC_6,       KC_PLUS,   _______,
  _______,  _______,  KC_1,     KC_2,     KC_3,       _______,   _______,
                      KC_0,     KC_0,     KC_DOT,     _______,   _______,

  _______, _______,
  _______,
  _______, _______, _______
),

[_ADJUST] = LAYOUT_ergodox(
  _______,  _______,_______,_______,_______,_______,_______,
  RESET,  _______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,

                        _______,  _______,
                                  _______,
                _______, _______, _______,


  _______,  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,
            _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,
                      _______,  _______,  _______,  _______,  _______,

  _______,_______,
  _______,
  _______,_______,_______
),
};


void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }

};
