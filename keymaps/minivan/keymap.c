#include "nic.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY_LAYER] = LAYOUT_arrow(
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        CTL_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, LT(LOWER_LAYER, KC_QUOT),
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, KC_BSLS,
        LOWER, KC_LALT, KC_LGUI, KC_ENTER, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_RIGHT),

    [LOWER_LAYER] = LAYOUT_arrow(
        S(KC_GRV), KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
        _______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_MS_BTN1,
        _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, S(KC_SLSH), KC_MS_BTN2,
        _______, _______, _______, _______, _______, _______, _______, _______, _______),

    [RAISE_LAYER] = LAYOUT_arrow(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL,
        _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, _______,
        KC_CAPS, _______, _______, _______, _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, KC_SLSH, KC_BSLS,
        _______, _______, _______, _______, _______, _______, _______, _______, _______),

    [ADJUST_LAYER] = LAYOUT_arrow(
        QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______),
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
