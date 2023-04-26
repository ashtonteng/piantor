// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │ - │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Sft│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │Sft├───┐           ┌───┤Ent│
      *               └───┤Bsp├───┐   ┌───┤Spc├───┘
      *                   └───┤GUI│   │   ├───┘
      *                       └───┘   └───┘
      */
    [0] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                            KC_LSFT, KC_BSPC, KC_LGUI,           MO(1),  KC_SPC,  KC_ENT
    ),
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │   │ ' │ [ │ < │       │ > │ ] │ " │ ` │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │ = │ + │ ( │ { │       │ } │ ) │ - │ _ │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │ | │ \ │ ~ │ / │       │Lef│Dow│Up │Rig│   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
    [1] = LAYOUT_split_3x6_3(
        KC_NO,    KC_NO,    KC_NO,        KC_QUOT,     KC_LBRC,    S(KC_COMM),                        S(KC_DOT),     KC_RBRC,    S(KC_QUOT),  KC_GRV,         KC_NO,    KC_NO,
        KC_NO,    KC_NO,    KC_EQL,       S(KC_EQL),   S(KC_9),    S(KC_LBRC),                        S(KC_RBRC),    S(KC_0),    KC_MINUS,    S(KC_MINUS),    KC_NO,    KC_NO,
        KC_NO,    KC_NO,    S(KC_BSLS),   KC_BSLS,     KC_GRV,     KC_SLSH,                           KC_LEFT,       KC_DOWN,    KC_UP,       KC_RIGHT,       KC_NO,    KC_NO,
                                                       KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │ 7 │ 8 │ 9 │ + │       │   │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │ 4 │ 5 │ 6 │ - │       │   │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │ 1 │ 2 │ 3 │ . │       │   │   │   │   │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
    [0] = LAYOUT_split_3x6_3(
        KC_NO,   KC_NO,    KC_7,    KC_8,    KC_9,    S(KC_EQL),                            KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,   KC_NO,    KC_4,    KC_5,    KC_6,    KC_MINS,                              KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,   KC_NO,    KC_1,    KC_2,    KC_3,    KC_DOT,                               KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                                             KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS,  KC_TRNS,  KC_TRNS
    )
};