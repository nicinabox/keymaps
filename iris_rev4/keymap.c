#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define KC_CTL_ESC CTL_T(KC_ESC)
#define KC_ALT_TAB LALT_T(KC_TAB)
#define KC_GUI_CAPS RGUI_T(KC_CAPS)
#define KC_TMUX LCTL(KC_B)
#define KC_DEL_ALT LALT_T(KC_DEL)
#define KC_SCR LGUI(LSFT(KC_3))
#define KC_SCR_SEL LGUI(LSFT(KC_4))
#define KC_CP_SCR_SEL LGUI(LCTL(LSFT(KC_4)))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,  KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,           KC_ENT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, LOWER,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI,  KC_LALT,  KC_BSPC,                   KC_ENT , KC_SPC , RAISE
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_PLUS, KC_F1   , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                           _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,  _______,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      _______, _______, KC_DEL,                   _______, _______, _______
                                  // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_EQL,  _______, _______, KC_SCR, KC_SCR_SEL, KC_CP_SCR_SEL,                    KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD, KC_VOLU , KC_PLUS,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       RESET,   _______, _______, _______, _______, _______,                            KC_PGUP, KC_HOME, KC_UP,    KC_END , _______, KC_RBRC,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       _______ , _______, _______, _______, _______, _______,                            KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, _______, KC_BSLS,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, KC_LEFT, KC_DOWN,  KC_UP,  KC_RIGHT,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      _______, _______, KC_DEL,                   _______, _______, _______
                                  // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, RGB_MOD , RGB_HUD, RGB_SAD, RGB_VAD,_______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

void encoder_update_user(uint8_t index, bool anticlockwise) {
  switch (biton32(layer_state)) {
    case _QWERTY:
      if (anticlockwise) {
        register_code(KC_LSFT);
        register_code(KC_LALT);
        tap_code16(LSFT(LALT(KC_VOLD)));
        unregister_code(KC_LSFT);
        unregister_code(KC_LALT);
      } else {
        register_code(KC_LSFT);
        register_code(KC_LALT);
        tap_code16(LSFT(LALT(KC_VOLU)));
        unregister_code(KC_LSFT);
        unregister_code(KC_LALT);
      }
      break;
    case _LOWER:
      if (anticlockwise) {
        tap_code(KC_MS_WH_UP);
      } else {
        tap_code(KC_MS_WH_DOWN);
      }
      break;
    case _RAISE:
      if (anticlockwise) {
        tap_code(KC_DOWN);
      } else {
        tap_code(KC_UP);
      }
      break;
    case _ADJUST:
      if (anticlockwise) {
        rgblight_decrease_hue();
      } else {
        rgblight_increase_hue();
      }
      break;
  }
}
