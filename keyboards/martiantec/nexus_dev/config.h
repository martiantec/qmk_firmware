/*
Copyright 2019 MartianTec

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

#include "config_common.h"

/* USB device descriptor parameters */
#define VENDOR_ID    0xFEED
#define PRODUCT_ID   0x0000
#define DEVICE_VER   0x0001
#define MANUFACTURER MartianTec
#define PRODUCT      Nexus Dev
#define DESCRIPTION  Full-size keyboard with dirtproof housing and custom conductive domes

/* Key matrix configuration */
#define DIODE_DIRECTION ROW2COL
#define MATRIX_COLS     4
#define MATRIX_ROWS     4
#define MATRIX_COL_PINS { F0, F1, F4, F5 }
#define MATRIX_ROW_PINS { F6, F7, E6, E2 }
// #define UNUSED_PINS     { D4, D6, E0, E1, E2, E3, E4, E5, E6, E7, F1 }

/* Pin configuration */
// #define BLUETOOTH_RESET_PIN D5
#define LED_NUM_LOCK_PIN    D7
#define LED_CAPS_LOCK_PIN   C6
#define LED_SCROLL_LOCK_PIN C7

/* Keypress configuration */
#define DEBOUNCE   5
#define FORCE_NKRO

// /* Backlight configuration */
// #define BACKLIGHT_LEVELS 7
// #define DRIVER_ADDR_1    0b1010000
// #define DRIVER_ADDR_2    0b1010000
// #define DRIVER_COUNT     1
// #define DRIVER_LED_TOTAL 35

/* Battery monitor configuration */
#define BATTERY_MONITOR_ADDR 0x6C

/* Mouse keys configuration */
#define MOUSEKEY_DELAY             50
#define MOUSEKEY_INTERVAL          15
#define MOUSEKEY_MAX_SPEED         4
#define MOUSEKEY_TIME_TO_MAX       50
#define MOUSEKEY_WHEEL_MAX_SPEED   1
#define MOUSEKEY_WHEEL_TIME_TO_MAX 50

/* Tapping configuration */
#define PERMISSIVE_HOLD
#define TAPPING_TERM    200
#define TAPPING_TOGGLE  2

/* Optimizations */
#define NO_ACTION_FUNCTION
#define NO_ACTION_MACRO
