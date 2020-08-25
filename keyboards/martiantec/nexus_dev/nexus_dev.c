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
#include "nexus_dev.h"

// #ifdef RGB_MATRIX_ENABLE
//     #include "drivers/issi/is31fl3737.h"
//
// const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
//     {0, I_1, I_2, I_3}, {0, I_4, I_5, I_6}, {0, I_7, I_8, I_9}, {0, I_10, I_11, I_12},
//     {0, H_1, H_2, H_3}, {0, H_4, H_5, H_6}, {0, H_7, H_8, H_9}, {0, H_10, H_11, H_12},
//     {0, G_1, G_2, G_3}, {0, G_4, G_5, G_6}, {0, G_7, G_8, G_9}, {0, G_10, G_11, G_12},
//     {0, F_1, F_2, F_3}, {0, F_4, F_5, F_6}, {0, F_7, F_8, F_9}, {0, F_10, F_11, F_12},
//     {0, E_1, E_2, E_3}, {0, E_4, E_5, E_6}, {0, E_7, E_8, E_9}, {0, E_10, E_11, E_12},
//     {0, D_1, D_2, D_3}, {0, D_4, D_5, D_6}, {0, D_7, D_8, D_9}, {0, D_10, D_11, D_12},
//     {0, C_1, C_2, C_3}, {0, C_4, C_5, C_6}, {0, C_7, C_8, C_9}, {0, C_10, C_11, C_12},
//     {0, B_1, B_2, B_3}, {0, B_4, B_5, B_6}, {0, B_7, B_8, B_9}, {0, B_10, B_11, B_12},
//     {0, A_1, A_2, A_3}, {0, A_4, A_5, A_6}, {0, A_7, A_8, A_9},
// };

// led_config_t g_led_config = {{
//     {   6,   7,   8,   9,  10,  11 },
//     {  12,  13,  14,  15,  16,  17 },
//     {  24,  25,  26,  27,  28,  29 },
//     {  30,  31,  32,  33,  34,  35 },
// }, {
//     {   0,   0 }, {  20,   0 }, {  40,   0 }, {  61,   0 }, {  81,   0 }, { 101,   0 }, { 122,   0 }, { 142,   0 }, { 162,   0 }, { 183,   0 }, { 203,   0 }, { 223,   0 },
//     {   0,  21 }, {  20,  21 }, {  40,  21 }, {  61,  21 }, {  81,  21 }, { 101,  21 }, { 122,  21 }, { 142,  21 }, { 162,  21 }, { 183,  21 }, { 203,  21 }, { 223,  21 },
//     {   0,  42 }, {  20,  42 }, {  40,  42 }, {  61,  42 }, {  81,  42 }, { 101,  42 }, { 122,  42 }, { 142,  42 }, { 162,  42 }, { 183,  42 }, { 203,  42 },
// }, {
//     4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
//     4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
//     4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
// }};
// #endif

void matrix_init_kb(void) {
// #ifdef RGB_MATRIX_ENABLE
//     rgb_matrix_enable();
//     rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
//     rgb_matrix_sethsv(0, 0, 255);
// #endif
    matrix_init_user();
    led_init_ports();
}

void led_init_ports(void) {
    setPinOutput(LED_NUM_LOCK_PIN);
    setPinOutput(LED_CAPS_LOCK_PIN);
    setPinOutput(LED_SCROLL_LOCK_PIN);
}

bool led_update_kb(led_t led_state) {
    if (led_update_user(led_state)) {
        // On is low
        writePin(LED_NUM_LOCK_PIN,    !led_state.num_lock);
        writePin(LED_CAPS_LOCK_PIN,   !led_state.caps_lock);
        writePin(LED_SCROLL_LOCK_PIN, !led_state.scroll_lock);
    }
    return true;
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user(keycode, record)) {
        return false;
    }

// #if !defined(UNICODE_ENABLE) && !defined(UNICODEMAP_ENABLE)
//     // Double-press compensation for spacebar actions
//     if (keycode & DPC_MASK) {
//         static uint16_t dpc_time;
//         static bool dpc_pressed;
//         // Allow only one press to be registered within DPC_PERIOD
//         if (timer_elapsed(dpc_time) > DPC_PERIOD || dpc_pressed != record->event.pressed) {
//             (record->event.pressed ? register_code16 : unregister_code16)(keycode & ~DPC_MASK);
//             dpc_time = timer_read();
//             dpc_pressed = record->event.pressed;
//         }
//         return false;
//     }
// #endif

    return true;
}
