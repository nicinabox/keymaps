#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define DEFAULT 0
#define NORMAN 1
#define LOWER 2
#define NUMPAD 3
#define NAV 4

#define CTL_ESC CTL_T(KC_ESC)
#define TMUX LCTL(KC_B)
#define HPR_TAB ALL_T(KC_TAB)
#define ALT_TAB LALT_T(KC_TAB)
#define GUI_DEL LT(KC_LGUI, KC_DEL)
#define SCR LGUI(LSFT(KC_3))
#define SCR_SEL LGUI(LSFT(KC_4))
#define CP_SCR_SEL LGUI(LCTL(LSFT(KC_4)))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[DEFAULT] = LAYOUT_ergodox(
  KC_EQUAL,           KC_1,     KC_2,     KC_3,     KC_4,   KC_5,   KC_ESC,
  ALT_TAB,            KC_Q,     KC_W,     KC_E,     KC_R,   KC_T,   KC_HYPR,
  CTL_ESC,            KC_A,     KC_S,     KC_D,     KC_F,   KC_G,
  KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,   KC_B,   KC_GRAVE,
  KC_CAPS,            _______,  KC_LALT,  KC_LGUI,  MO(LOWER),

                                          KC_HOME,  KC_END,
                                                    KC_PGUP,
                                KC_BSPACE, GUI_DEL, KC_PGDOWN,


    TG(NORMAN),      KC_6,      KC_7,     KC_8,      KC_9,      KC_0,      KC_MINUS,
    KC_LBRC,         KC_Y,      KC_U,     KC_I,      KC_O,      KC_P,      KC_RBRC,
                     KC_H,      KC_J,     KC_K,      KC_L,      KC_SCOLON, KC_QUOTE,
    MEH_T(KC_BSLS),  KC_N,      KC_M,     KC_COMMA,  KC_DOT,    KC_SLASH,  KC_RSHIFT,
                                MO(NAV),  KC_LEFT,   KC_DOWN,    KC_UP,    KC_RIGHT,

    KC_MEDIA_PLAY_PAUSE,  KC_MEDIA_NEXT_TRACK,
    KC_AUDIO_VOL_UP,
    KC_AUDIO_VOL_DOWN,  KC_ENT, KC_SPC
),

[NORMAN] = LAYOUT_ergodox(
  _______,  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  KC_Q,     KC_W,     KC_D,     KC_F,     KC_K,     _______,
  _______,  KC_A,     KC_S,     KC_E,     KC_T,     KC_G,
  _______,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     _______,
  _______,  _______,  _______,  _______,  _______,

                                          _______,  _______,
                                                    _______,
                                _______,   _______,  _______,


    _______,  _______,  _______,  _______,  _______,  _______,   _______,
    _______,  KC_J,     KC_U,     KC_R,     KC_L,     KC_SCOLON, _______,
              KC_Y,     KC_N,     KC_I,     KC_O,     KC_H,      _______,
    _______,  KC_P,     KC_M,     KC_COMMA, KC_DOT,   KC_SLASH,  _______,
                        _______,  _______,  _______,  _______,   _______,

    _______,  _______,
    _______,
    _______,  _______, _______
),

[LOWER] = LAYOUT_ergodox(
  _______,          _______,  _______,  SCR,  SCR_SEL, CP_SCR_SEL,  _______,
  LGUI(KC_BSPACE),  _______,  _______,  _______,  _______, _______, _______,
  _______,          _______,  _______,  _______,  _______, _______,
  _______,          _______,  _______,  _______,  _______, TMUX,    _______,
  _______,          _______,  _______,  _______,  _______,

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

[NUMPAD] = LAYOUT_ergodox(
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

[NAV] = LAYOUT_ergodox(
  _______,  _______,_______,_______,_______,_______,RESET,
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


};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch(id) {
      case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
    }
    return MACRO_NONE;
};

void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
