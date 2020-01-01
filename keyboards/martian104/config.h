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
#define PRODUCT      Martian104
#define DESCRIPTION  Full-size keyboard with dirtproof housing and custom conductive domes

/* Key matrix configuration */
#define DIODE_DIRECTION ROW2COL
#define MATRIX_COLS     21
#define MATRIX_ROWS     6
#define MATRIX_COL_PINS { A0, A1, A2, A3, A4, A5, A6, A7, B0, B4, B5, B6, B7, C0, C1, C2, C3, C4, C5, C6, C7 }
#define MATRIX_ROW_PINS { F7, F6, F5, F4, F3, F2 }
#define UNUSED_PINS     { D4, D6, E0, E1, E2, E3, E4, E5, E6, E7, F1 }

/* Keypress configuration */
#define DEBOUNCE   5
#define FORCE_NKRO

/* Backlight configuration */
#define BACKLIGHT_LEVELS  7
#define DRIVER_ADDR_1     0b1010000
#define DRIVER_ADDR_2     0b1010000
#define DRIVER_COUNT      1
#define DRIVER_LED_TOTAL  35
#define LED_CAPS_LOCK_PIN D7

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
