#include "nic.h"
#include "encoder.h"

uint16_t MIN_ENCODER_INDEX = ENC_VOL;
uint16_t MAX_ENCODER_INDEX = _MAX_ENCODER_MODES - 1;
volatile uint16_t encoder_mode = ENC_VOL;

__attribute__ ((weak))
void handle_encoder_mode(bool clockwise) {
}


void set_encoder_mode(uint16_t next_mode) {
  if (encoder_mode > MAX_ENCODER_INDEX || encoder_mode < MIN_ENCODER_INDEX) {
    return;
  }

  encoder_mode = next_mode;
}


void cycle_encoder_mode(bool clockwise) {
  if (clockwise) {
    set_encoder_mode(encoder_mode + 1);
  } else {
    set_encoder_mode(encoder_mode - 1);
  }
}


__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}


__attribute__ ((weak))
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

  return process_record_keymap(keycode, record);
}
