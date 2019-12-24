#include "nic.h"

uint16_t MIN_ENCODER_INDEX = ENC_VOL;
uint16_t MAX_ENCODER_INDEX = _MAX_ENCODER_MODES - 1;
volatile uint16_t encoder_mode = ENC_VOL;

__attribute__ ((weak))
void handle_encoder_mode(bool clockwise) {
}


void set_encoder_mode(uint16_t next_mode) {
  if (next_mode > MAX_ENCODER_INDEX || next_mode < MIN_ENCODER_INDEX) {
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
layer_state_t layer_state_set_user(layer_state_t state) {
  if (get_highest_layer(state) == _ADJUST) {
    return state;
  }

  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
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

    case WINDOWS:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_WINDOWS);
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

  if (keycode >= MIN_ENCODER_INDEX && keycode <= MAX_ENCODER_INDEX) {
    set_encoder_mode(keycode);

    // Exit adjust layer on key up, only for encoder actions.
    if (!record->event.pressed) {
      layer_off(_ADJUST);
    }
  }

  return process_record_keymap(keycode, record);
}


__attribute__ ((weak))
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
