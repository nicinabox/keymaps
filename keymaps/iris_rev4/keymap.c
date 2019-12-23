#include "nic.h"
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LOWERTAB, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,   KC_P ,  KC_LBRC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,  KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   TG(_ADJUST),      KC_ENT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_DEL,
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
     _______, ENC_VOL, ENC_MS_WH, ENC_ARROWS_V, ENC_ARROWS_H, ENC_RGB_HUE,            ENC_RGB_MODE, ENC_RGB_VAL, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RESET,   _______, _______, _______, _______, _______,                            RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, RGB_MOD , RGB_HUD, RGB_SAD, RGB_VAD,_______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

void handle_encoder_mode(bool clockwise) {
  switch (encoder_mode) {
    case ENC_VOL:
      if (clockwise) {
        tap_code(KC_VOLU);
      } else {
        tap_code(KC_VOLD);
      }
      break;
    case ENC_MS_WH:
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
    case ENC_RGB_MODE:
      if (clockwise) {
        rgblight_step();
      } else {
        rgblight_step_reverse();
      }
      break;
    case ENC_RGB_VAL:
      if (clockwise) {
        rgblight_increase_val();
      } else {
        rgblight_decrease_val();
      }
      break;
  }
}

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  if (keycode >= MIN_ENCODER_INDEX && keycode <= MAX_ENCODER_INDEX) {
    set_encoder_mode(keycode);

    // Exit adjust layer on key up, only for encoder actions.
    if (!record->event.pressed) {
      layer_off(_ADJUST);
    }
  }

  return true;
}

void encoder_update_user(uint8_t index, bool anticlockwise) {
  // TODO: clockwise direction is backwards. Update when fixed.
  bool clockwise = !anticlockwise;
  uint8_t layer = biton32(layer_state);

  // Allow encoder to be used to choose encoder mode
  if (layer == _ADJUST) {
    cycle_encoder_mode(clockwise);
    return;
  }

  // Alternate encoder mode (like shift encoder)
  if (layer == _RAISE) {
    if (clockwise) {
      tap_code(KC_MS_WH_DOWN);
    } else {
      tap_code(KC_MS_WH_UP);
    }
    return;
  }

  return handle_encoder_mode(clockwise);
}
