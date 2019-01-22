#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  RAISE,
  LOWER = LT(_LOWER, KC_DEL),
  ADJUST,
};

#define KC_ KC_TRNS
#define KC________ KC_TRNS

#define KC_RGB_TOG RGB_TOG
#define KC_RGB_MOD RGB_MOD
#define KC_RGB_HUI RGB_HUI
#define KC_RGB_HUD RGB_HUD
#define KC_RGB_SAI RGB_SAI
#define KC_RGB_SAD RGB_SAD
#define KC_RGB_VAI RGB_VAI
#define KC_RGB_VAD RGB_VAD
#define KC_RGB_M_P RGB_M_P
#define KC_RGB_M_B RGB_M_B
#define KC_RGB_M_R RGB_M_R
#define KC_RGB_M_K RGB_M_K
#define KC_RGB_M_X RGB_M_X

#define KC_RESET RESET
#define KC_DEBUG DEBUG

#define KC_RASE RAISE
#define KC_LOWR LOWER
#define KC_CTL_ESC CTL_T(KC_ESC)
#define KC_ALT_TAB LALT_T(KC_TAB)
#define KC_GUI_CAPS RGUI_T(KC_CAPS)
#define KC_TMUX LCTL(KC_B)
#define KC_DEL_ALT LALT_T(KC_DEL)
#define KC_SCR LGUI(LSFT(KC_3))
#define KC_SCR_SEL LGUI(LSFT(KC_4))
#define KC_CP_SCR_SEL LGUI(LCTL(LSFT(KC_4)))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     GRV , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9 , 0  ,MINS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T ,                Y  , U  , I , O ,  P  ,LBRC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     CTL_ESC, A  , S  , D  , F  , G  ,              H , J , K , L , SCLN , QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  , LOWR,    ENT , N  , M  ,COMM,DOT ,SLSH, GUI_CAPS,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LGUI,LALT,BSPC,     ENT ,SPC , RASE
  //                  `----+----+----'        `----+----+----'
  ),

  [_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     PLUS,    ,    ,SCR ,SCR_SEL,CP_SCR_SEL,          ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,TMUX,     ,        ,    ,    ,    ,    ,    ,RSFT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,     ,    ,            ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_RAISE] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     EQL , F1 , F2 , F3 , F4 , F5 ,               MPRV,MPLY,MNXT,VOLD,VOLU,PLUS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         , F6 , F7 , F8 , F9 ,F10 ,               PGUP,HOME, UP, END ,    ,RBRC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         , F11, F12,    ,    ,    ,               PGDN,LEFT,DOWN,RIGHT,   ,BSLS,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    ,    ,LEFT,DOWN,UP,RIGHT ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_ADJUST] = LAYOUT_kc(
  //,--------+--------+--------+--------+--------+--------.                          ,--------+--------+--------+--------+--------+--------.
     _______ , RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_K, RGB_M_X,                           _______ , _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______,                           _______ , _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      RESET  , DEBUG  , RGB_HUD, RGB_SAD, RGB_VAD, _______,                           _______ , _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------.        ,--------|--------+--------+--------+--------+--------+--------|
     _______ , _______, _______, _______, _______, _______, _______,         _______ , _______, _______, _______, _______, _______, _______,
  //`--------+--------+--------+----+---+--------+--------+--------/        \--------+--------+--------+---+----+--------+--------+--------'
                                      _______, _______, _______,                  _______, _______, _______
  //                                `--------+--------+--------'                `--------+--------+--------'
  )

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
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
