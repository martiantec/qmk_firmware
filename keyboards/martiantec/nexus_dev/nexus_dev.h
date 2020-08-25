/* Copyright 2019 MartianTec
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include "quantum.h"

#define LAYOUT( \
    k00, k01, k02, k03, \
    k10, k11, k12, k13, \
    k20, k21, k22, k23, \
    k30, k31, k32, k33  \
) { \
    { k00,   k01,   k02,   k03   }, \
    { k10,   k11,   k12,   k13   }, \
    { k20,   k21,   k22,   k23   }, \
    { k30,   k31,   k32,   k33   }, \
}

/*
#define LAYOUT( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C,      k0E, k0F, k0G,                     \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, k1D, k1E, k1F, k1G, k1H, k1I, k1J, k1K, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B, k2C, k2D, k2E, k2F, k2G, k2H, k2I, k2J, k2K, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B,      k3C,                k3H, k3I, k3J, k3K, \
    k40,      k41, k42, k43, k44, k45, k46, k47, k48, k49, k4A,      k4B,      k4F,      k4H, k4I, k4J, k5K, \
    k50, k51, k52,           k53,           k56,           k57, k58, k59, k5E, k5F, k5G, k5H,      k5J       \
) { \
    { k00,   k01,   k02,   k03,   k04,   k05,   k06,   k07,   k08,   k09,   k0A,   k0B,   k0C,   KC_NO,  k0E,   k0F,   k0G,   KC_NO, KC_NO, KC_NO, KC_NO }, \
    { k10,   k11,   k12,   k13,   k14,   k15,   k16,   k17,   k18,   k19,   k1A,   k1B,   k1C,   k1D,    k1E,   k1F,   k1G,   k1H,   k1I,   k1J,   k1K   }, \
    { k20,   k21,   k22,   k23,   k24,   k25,   k26,   k27,   k28,   k29,   k2A,   k2B,   k2C,   k2D,    k2E,   k2F,   k2G,   k2H,   k2I,   k2J,   k2K   }, \
    { k30,   k31,   k32,   k33,   k34,   k35,   k36,   k37,   k38,   k39,   k3A,   k3B,   k3C,   KC_NO,  KC_NO, KC_NO, KC_NO, k3H,   k3I,   k3J,   k3K   }, \
    { k40,   k41,   k42,   k43,   k44,   k45,   k46,   k47,   k48,   k49,   k4A,   k4B,   KC_NO, KC_NO,  KC_NO, k4F,   KC_NO, k4H,   k4I,   k4J,   KC_NO }, \
    { k50,   k51,   k52,   k53,   KC_NO, KC_NO, k56,   k57,   k58,   k59,   KC_NO, KC_NO, KC_NO, KC_NO,  k5E,   k5F,   k5G,   k5H,   KC_NO, k5J,   k5K   }, \
}

#if !defined(UNICODE_ENABLE) && !defined(UNICODEMAP_ENABLE)
    #define DPC_MASK 0x8000
    #ifndef DPC_PERIOD
        #define DPC_PERIOD 20
    #endif
    #define DPC(kc) ((kc) | DPC_MASK)

    #define LAYOUT_DPC( \
        k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C,      k0E, k0F, k0G,                     \
        k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, k1D, k1E, k1F, k1G, k1H, k1I, k1J, k1K, \
        k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B, k2C, k2D, k2E, k2F, k2G, k2H, k2I, k2J, k2K, \
        k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B,      k3C,                k3H, k3I, k3J, k3K, \
        k40,      k41, k42, k43, k44, k45, k46, k47, k48, k49, k4A,      k4B,      k4F,      k4H, k4I, k4J, k5K, \
        k50, k51, k52,                k53,                     k57, k58, k59, k5E, k5F, k5G, k5H,      k5J       \
    ) { \
        { k00,   k01,   k02,   k03,   k04,   k05,   k06,   k07,   k08,   k09,   k0A,   k0B,   k0C,   KC_NO,  k0E,   k0F,   k0G,   KC_NO, KC_NO, KC_NO, KC_NO }, \
        { k10,   k11,   k12,   k13,   k14,   k15,   k16,   k17,   k18,   k19,   k1A,   k1B,   k1C,   k1D,    k1E,   k1F,   k1G,   k1H,   k1I,   k1J,   k1K   }, \
        { k20,   k21,   k22,   k23,   k24,   k25,   k26,   k27,   k28,   k29,   k2A,   k2B,   k2C,   k2D,    k2E,   k2F,   k2G,   k2H,   k2I,   k2J,   k2K   }, \
        { k30,   k31,   k32,   k33,   k34,   k35,   k36,   k37,   k38,   k39,   k3A,   k3B,   k3C,   KC_NO,  KC_NO, KC_NO, KC_NO, k3H,   k3I,   k3J,   k3K   }, \
        { k40,   k41,   k42,   k43,   k44,   k45,   k46,   k47,   k48,   k49,   k4A,   k4B,   KC_NO, KC_NO,  KC_NO, k4F,   KC_NO, k4H,   k4I,   k4J,   KC_NO }, \
        { k50,   k51,   k52, DPC(k53),KC_NO,KC_NO,DPC(k53),k57,   k58,   k59,   KC_NO, KC_NO, KC_NO, KC_NO,  k5E,   k5F,   k5G,   k5H,   KC_NO, k5J,   k5K   }, \
    }
#else
    #pragma message "Double-press compensation not supported together with UNICODE/UNICODEMAP"
#endif
*/
