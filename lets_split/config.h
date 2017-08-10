#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../rev2/config.h"

#undef RGBLED_NUM

#define TAPPING_TERM 200
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 8
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17

#define USE_SERIAL
#define EE_HANDS

#define randadd 53
#define randmul 181
#define randmod 167

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#endif
