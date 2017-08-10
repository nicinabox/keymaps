#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

#define PREVENT_STUCK_MODIFIERS

#define TAPPING_TERM 200

#define RGB_DI_PIN B2     // The pin your RGB strip is wired to
#define RGBLIGHT_TIMER
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 12
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 10
#define RGBLIGHT_VAL_STEP 10

#define randadd 53
#define randmul 181
#define randmod 167

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#endif
