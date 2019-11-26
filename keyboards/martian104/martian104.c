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
#include "martian104.h"

#ifdef LED_MATRIX_ENABLE
    #include "drivers/issi/is31fl3731_single.h"

const is31_led g_is31_leds[LED_DRIVER_LED_TOTAL] = {
    {0, C1_1}, {0, C1_2}, {0, C1_3}, {0, C1_4}, {0, C1_5}, {0, C1_6}, {0, C1_7}, {0, C1_8}, {0, C1_9}, {0, C1_10}, {0, C1_11}, {0, C1_12},
    {0, C2_1}, {0, C2_2}, {0, C2_3}, {0, C2_4}, {0, C2_5}, {0, C2_6}, {0, C2_7}, {0, C2_8}, {0, C2_9}, {0, C2_10}, {0, C2_11}, {0, C2_12},
    {0, C3_1}, {0, C3_2}, {0, C3_3}, {0, C3_4}, {0, C3_5}, {0, C3_6}, {0, C3_7}, {0, C3_8}, {0, C3_9}, {0, C3_10}, {0, C3_11}, {0, C3_12},
    {0, C4_1}, {0, C4_2}, {0, C4_3}, {0, C4_4}, {0, C4_5}, {0, C4_6}, {0, C4_7}, {0, C4_8}, {0, C4_9}, {0, C4_10}, {0, C4_11}, {0, C4_12},
    {0, C5_1}, {0, C5_2}, {0, C5_3}, {0, C5_4}, {0, C5_5}, {0, C5_6}, {0, C5_7}, {0, C5_8}, {0, C5_9}, {0, C5_10}, {0, C5_11}, {0, C5_12},
    {0, C6_1}, {0, C6_2}, {0, C6_3}, {0, C6_4}, {0, C6_5}, {0, C6_6}, {0, C6_7}, {0, C6_8}, {0, C6_9}, {0, C6_10}, {0, C6_11}, {0, C6_12},
    {0, C7_1}, {0, C7_2}, {0, C7_3}, {0, C7_4}, {0, C7_5}, {0, C7_6}, {0, C7_7}, {0, C7_8}, {0, C7_9}, {0, C7_10}, {0, C7_11}, {0, C7_12},
    {0, C8_1}, {0, C8_2}, {0, C8_3}, {0, C8_4}, {0, C8_5}, {0, C8_6}, {0, C8_7}, {0, C8_8}, {0, C8_9}, {0, C8_10}, {0, C8_11}, {0, C8_12},
    {0, C9_1}, {0, C9_2}, {0, C9_3}, {0, C9_4}, {0, C9_5}, {0, C9_6}, {0, C9_7}, {0, C9_8},
};
#endif
