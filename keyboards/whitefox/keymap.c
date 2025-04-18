/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "nic.h"

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY_LAYER] = LAYOUT(
        KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, XXXXXXX , KC_BSPC,  KC_DEL,
        KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,            SCR_SEL,
        CTL_ESC,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,XXXXXXX,KC_ENT,             SCR_SEL_CP,
        KC_LSFT,XXXXXXX,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,     KC_UP,         RAISE,
        KC_CAPS,  KC_LALT,KC_LGUI,               KC_SPC,           KC_RGUI, KC_RALT, XXXXXXX,                   KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [RAISE_LAYER] = LAYOUT(
        _______,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_VOLD, KC_VOLU, XXXXXXX, KC_DEL,  KC_MPLY,
        QK_BOOT,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,              KC_MNXT,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,            KC_MPRV,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______,       _______,
        _______,_______,_______,               _______,          _______,_______,XXXXXXX,                   _______, _______, _______
    ),
};
