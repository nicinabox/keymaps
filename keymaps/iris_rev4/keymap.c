#include "nic.h"
#include QMK_KEYBOARD_H

enum custom_keymap_keycodes {
  KC_ENC_VOL = NEW_SAFE_RANGE,
  KC_ENC_MS_WHEEL,
  KC_ENC_ARROWS_V,
  KC_ENC_ARROWS_H,
  KC_ENC_RGB_HUE,
};

enum encoder_actions {
  ENC_VOL,
  ENC_MS_WHEEL,
  ENC_ARROWS_V,
  ENC_ARROWS_H,
  ENC_RGB_HUE,
};

uint8_t MIN_ENCODER_INDEX = ENC_VOL;
uint8_t MAX_ENCODER_INDEX = ENC_RGB_HUE;
uint8_t encoder_action = ENC_VOL;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LOWERTAB, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,   KC_P ,  KC_LBRC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,  KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,           KC_ENT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_DEL,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI,  KC_LALT,  KC_BSPC,                  KC_ENT , KC_SPC , RAISE
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       _______, _______, _______, KC_SCR, KC_SCR_SEL, KC_CP_SCR_SEL,                    _______, KC_7,    KC_8,    KC_9,    KC_ASTR , KC_MINS,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       _______, KC_F9   , KC_F10 , KC_F11 , KC_F12 , _______,                           _______, KC_4,    KC_5,    KC_6,    KC_SLSH , KC_PLUS,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       _______, KC_F5   , KC_F6  , KC_F7  , KC_F8  , _______,                            _______, KC_1,    KC_2,    KC_3,    _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_CAPS , KC_F1  , KC_F2  , KC_F3  , KC_F4  , _______, _______,         _______, _______, KC_0,   KC_0,    KC_DOT,   _______,  _______,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      _______, _______, KC_DEL,                   _______, _______, _______
                                  // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_EQL,  _______, _______, KC_SCR, KC_SCR_SEL, KC_CP_SCR_SEL,                    KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD, KC_VOLU , KC_PLUS,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       _______,   _______, _______, _______, _______, _______,                            KC_PGUP, KC_HOME, KC_UP,  KC_END , _______, KC_RBRC,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       _______ , _______, _______, _______, _______, _______,                            KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, _______, KC_BSLS,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,  LOWER,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      _______, _______, KC_DEL,                   _______, _______, _______
                                  // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, KC_ENC_VOL, KC_ENC_MS_WHEEL, KC_ENC_ARROWS_V, KC_ENC_ARROWS_H, KC_ENC_RGB_HUE,    _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RESET,   _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, RGB_MOD , RGB_HUD, RGB_SAD, RGB_VAD,_______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

void do_encoder_action(bool clockwise) {
  switch (encoder_action) {
    case ENC_VOL:
      if (clockwise) {
        tap_code(KC_VOLU);
      } else {
        tap_code(KC_VOLD);
      }
      break;
    case ENC_MS_WHEEL:
      if (clockwise) {
        tap_code(KC_MS_WH_DOWN);
      } else {
        tap_code(KC_MS_WH_UP);
      }
      break;
    case ENC_ARROWS_V:
      if (clockwise) {
        tap_code(KC_DOWN);
      } else {
        tap_code(KC_UP);
      }
      break;
    case ENC_ARROWS_H:
      if (clockwise) {
        tap_code(KC_RIGHT);
      } else {
        tap_code(KC_LEFT);
      }
      break;
    case ENC_RGB_HUE:
      if (clockwise) {
        rgblight_increase_hue();
      } else {
        rgblight_decrease_hue();
      }
      break;
  }
}

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_ENC_VOL:
      encoder_action = ENC_VOL;
      break;
    case KC_ENC_MS_WHEEL:
      encoder_action = ENC_MS_WHEEL;
      break;
    case KC_ENC_ARROWS_V:
      encoder_action = ENC_ARROWS_V;
      break;
    case KC_ENC_ARROWS_H:
      encoder_action = ENC_ARROWS_H;
      break;
    case KC_ENC_RGB_HUE:
      encoder_action = ENC_RGB_HUE;
      break;
  }

  return true;
}

void encoder_update_user(uint8_t index, bool anticlockwise) {
  bool clockwise = !anticlockwise;

  if (biton32(layer_state) == _ADJUST) {
    if (!clockwise && encoder_action > MIN_ENCODER_INDEX) {
      encoder_action--;
    }
    else if (clockwise && encoder_action < MAX_ENCODER_INDEX) {
      encoder_action++;
    }

    return;
  }

  return do_encoder_action(clockwise);
}
