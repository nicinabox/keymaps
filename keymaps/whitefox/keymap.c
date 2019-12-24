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
    [_QWERTY] = LAYOUT(
        KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, XXXXXXX , KC_BSPC,  KC_MPLY,
        KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,            KC_VOLU,
        KC_LCTL,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,XXXXXXX,KC_ENT,             KC_VOLD,
        KC_LSFT,XXXXXXX,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,     KC_UP,         _______,
        RAISE,  KC_LALT,KC_LGUI,               KC_SPC,           KC_RGUI, LOWER, XXXXXXX,                   KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_RAISE] = LAYOUT(
        _______,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, XXXXXXX, KC_DEL,    KC_MPLY,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_PSCR,KC_SLCK,KC_PAUS,_______,            KC_VOLU,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,            KC_VOLD,
        KC_CAPS,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     KC_PGUP,       _______,
        _______,_______,_______,               _______,          _______,_______,XXXXXXX,                   KC_HOME, KC_PGDN, KC_END
    ),

    [_ADJUST] = LAYOUT(
        _______,_______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______, XXXXXXX, _______, _______,
        RESET,  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______,_______,
        _______,_______,_______,               _______,          _______,_______,XXXXXXX,     _______,_______,_______
    ),
};
