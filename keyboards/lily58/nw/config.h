/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2017 F_YUUCHI
Copyright 2020 Ben Roesner (keycapsss.com)
Copyright 2021 Norman Wink

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

#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0x7983
#define PRODUCT_ID      0x4C4C // "LL"
#define DEVICE_VER      0x0100
#define MANUFACTURER    normanwink
#define PRODUCT         Lily58
#define DESCRIPTION     Lily58 is 6×4+5keys column-staggered split keyboard with glowing keys and encoders.

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 10
#define MATRIX_COLS 6

// wiring of each half
#define MATRIX_ROW_PINS { C6, D7, E6, B4, B5 }
#define MATRIX_COL_PINS { F6, F7, B1, B3, B2, B6 }

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

#define SOFT_SERIAL_PIN D2

#define RGB_DI_PIN D3
#define RGBLED_NUM 72
#define RGBLED_SPLIT { 36, 36 }
#define RGBLIGHT_SPLIT
#define RGBLIGHT_LIMIT_VAL 120
#define RGB_DISABLE_TIMEOUT 15000
#define RGBLIGHT_SLEEP
// #define RGB_MATRIX_ENABLE
// #define RGB_DISABLE_WHEN_USB_SUSPENDED
#define USB_SUSPEND_WAKEUP_DELAY 200

#define OLED_TIMEOUT 10000
#define OLED_FADE_OUT
#define OLED_FADE_OUT_INTERVAL 3
#define OLED_UPDATE_INTERVAL 300

// #define RGBLIGHT_EFFECT_KNIGHT
// #define RGBLIGHT_MODE_KNIGHT 1

#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17

#define ENCODERS_PAD_A { D4 }
#define ENCODERS_PAD_B { F5 }
#define ENCODERS_PAD_A_RIGHT { F5 }
#define ENCODERS_PAD_B_RIGHT { D4 }
#define ENCODER_RESOLUTION 4
#define TAP_CODE_DELAY 7

// #define TAPPING_FORCE_HOLD
// #define TAPPING_TERM 100
