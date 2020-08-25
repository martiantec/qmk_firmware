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
#include QMK_KEYBOARD_H

#define FN      MO(L_FN)
#define FN_CAPS LT(L_FN, KC_CAPS)

// Clear mods, perform action, restore mods
#define CLEAN_MODS(action) {       \
        uint8_t mods = get_mods(); \
        clear_mods();              \
        action;                    \
        set_mods(mods);            \
    }

enum layers {
    L_BASE,
    L_FN,
};

enum custom_keycodes {
    CLEAR = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case CLEAR:
        if (record->event.pressed) {
            CLEAN_MODS(
                SEND_STRING(SS_LCTRL("a") SS_TAP(X_DELETE));
            )
        }
        break;
    }

    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_BASE] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,
        KC_NLCK, KC_4,    KC_5,    KC_6,
        KC_CAPS, KC_7,    KC_8,    KC_9,
        KC_SLCK, KC_0,    KC_SPC,  FN
    ),

    [L_FN] = LAYOUT(
        RESET,   _______, _______, _______,
        CLEAR,   _______, _______, _______,
        KC_BSPC, _______, _______, _______,
        KC_ENT,  _______, KC_LSFT, _______
    ),
};

// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//     /* Base layer
//      * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┐
//      * │Esc│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│       │PSc│SLk│Pau│
//      * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼─────┐ ├───┼───┼───┤ ┌───┬───┬───┬───┐
//      * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │Bspc │ │Ins│Hom│PgU│ │NLk│P= │P/ │P* │
//      * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
//      * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │ \ │ │Del│End│PgD│ │P7 │P8 │P9 │P- │
//      * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤ └───┴───┴───┘ ├───┼───┼───┼───┤
//      * │FnCaps│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │Enter │               │P4 │P5 │P6 │P+ │
//      * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──────┤     ┌───┐     ├───┼───┼───┼───┤
//      * │ LShift │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ RShift │     │ ↑ │     │P1 │P2 │P3 │   │
//      * ├─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴───┴┬──┴──┬┴──┬─────┤ ┌───┼───┼───┐ ├───┴───┼───┤PEn│
//      * │LCtrl│LGu│LAlt │          Space          │RAlt │Fn │RCtrl│ │ ← │ ↓ │ → │ │  P0   │P. │   │
//      * └─────┴───┴─────┴─────────────────────────┴─────┴───┴─────┘ └───┴───┴───┘ └───────┴───┴───┘
//      */
//     [L_BASE] = LAYOUT_DPC(
//         KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_PSCR, KC_SLCK, KC_PAUS,
//         KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_INS,  KC_HOME, KC_PGUP, KC_NLCK, KC_PEQL, KC_PSLS, KC_PAST,
//         KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,  KC_END,  KC_PGDN, KC_P7,   KC_P8,   KC_P9,   KC_PMNS,
//         FN_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,                             KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
//         KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,          KC_UP,            KC_P1,   KC_P2,   KC_P3,   KC_PENT,
//         KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                                      KC_RALT, FN,      KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_P0,            KC_PDOT
//     ),
//
//     /* Fn layer
//      * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┐
//      * │   │   │   │   │   │   │   │   │   │   │   │   │   │       │   │   │Mut│
//      * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼─────┐ ├───┼───┼───┤ ┌───┬───┬───┬───┐
//      * │   │   │   │   │   │   │   │   │   │   │   │   │   │Clear│ │Ply│Stp│Vo+│ │   │   │   │   │
//      * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
//      * │     │M2 │M↑ │M1 │M3 │   │   │   │   │   │   │   │   │   │ │Prv│Nxt│Vo-│ │   │   │   │   │
//      * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤ └───┴───┴───┘ ├───┼───┼───┼───┤
//      * │      │M← │M↓ │M→ │MW↑│   │   │   │   │   │   │   │      │               │   │   │   │   │
//      * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──────┤     ┌───┐     ├───┼───┼───┼───┤
//      * │        │M4 │M5 │MW←│MW→│   │   │   │   │   │   │        │     │PgU│     │   │   │   │   │
//      * ├─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴───┴┬──┴──┬┴──┬─────┤ ┌───┼───┼───┐ ├───┴───┼───┤Tab│
//      * │     │   │     │           MW↓           │     │   │     │ │Hom│PgD│End│ │       │   │   │
//      * └─────┴───┴─────┴─────────────────────────┴─────┴───┴─────┘ └───┴───┴───┘ └───────┴───┴───┘
//      */
//     [L_FN] = LAYOUT_DPC(
//         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, KC_MUTE,
//         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, CLEAR,   KC_MPLY, KC_MSTP, KC_VOLU, _______, _______, _______, _______,
//         _______, KC_BTN2, KC_MS_U, KC_BTN1, KC_BTN3, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MNXT, KC_VOLD, _______, _______, _______, _______,
//         _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U, _______, _______, _______, _______, _______, _______, _______,          _______,                            _______, _______, _______, _______,
//         _______,          KC_BTN4, KC_BTN5, KC_WH_L, KC_WH_R, _______, _______, _______, _______, _______, _______,          _______,          KC_PGUP,          _______, _______, _______, KC_TAB,
//         _______, _______, _______,                            KC_WH_D,                                     _______, _______, _______, KC_HOME, KC_PGDN, KC_END,  _______,          _______
//     ),
// };
