// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// MACROS

enum custom_keycodes {
  UPDIR = SAFE_RANGE,
  RPIPE,
  // Other keycodes...
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case UPDIR:  // Types ../ to go up a directory on the shell.
      if (record->event.pressed) {
        SEND_STRING("../");
      }
      return false;

    case RPIPE:  // Types triple equal ===
      if (record->event.pressed) {
        SEND_STRING("%>%");
      }
      return false;

    // Other macros...
  }
  return true;
}

// KEYMAP

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │ - │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Esc│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Sft│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │Sft├───┐           ┌───┤Ent│
      *               └───┤Bsp├───┐   ┌───┤Spc├───┘
      *                   └───┤GUI│   │   ├───┘
      *                       └───┘   └───┘
      */
    [0] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                            KC_LSFT, KC_BSPC, KC_LGUI,           MO(1),  KC_SPC,  KC_ENT
    ),
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │   │ ' │ [ │ < │       │ > │ ] │ " │ ` │M0 │PUP│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │ = │ + │ ( │ { │       │ } │ ) │ - │ _ │M1 │PDN│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼─-─┼───┤
      * │   │   │ | │ \ │ ~ │ / │       │Lef│Dow│Up │Rig│M2 │CAP│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
    [1] = LAYOUT_split_3x6_3(
        KC_NO,    KC_NO,    KC_NO,        KC_QUOT,     KC_LBRC,    S(KC_COMM),                        S(KC_DOT),     KC_RBRC,    S(KC_QUOT),  KC_GRV,         UPDIR,    KC_PGUP,
        KC_NO,    KC_NO,    KC_EQL,       S(KC_EQL),   S(KC_9),    S(KC_LBRC),                        S(KC_RBRC),    S(KC_0),    KC_MINUS,    S(KC_MINUS),    RPIPE,    KC_PGDN,
        KC_NO,    KC_NO,    S(KC_BSLS),   KC_BSLS,     KC_GRV,     KC_SLSH,                           KC_LEFT,       KC_DOWN,    KC_UP,       KC_RIGHT,       KC_NO,    KC_CAPS,
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
    [2] = LAYOUT_split_3x6_3(
        KC_NO,   KC_NO,    KC_7,    KC_8,    KC_9,    S(KC_EQL),                            KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,   KC_NO,    KC_4,    KC_5,    KC_6,    KC_MINS,                              KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,   KC_NO,    KC_1,    KC_2,    KC_3,    KC_DOT,                               KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                                             KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS,  KC_TRNS,  KC_TRNS
    )
};

// COMBOS

const uint16_t PROGMEM mo_layer2_combo[] = {KC_SPC, KC_ENT, COMBO_END};
const uint16_t PROGMEM s_kc1_combo[] = {KC_Q, KC_A, COMBO_END};
const uint16_t PROGMEM s_kc2_combo[] = {KC_W, KC_S, COMBO_END};
const uint16_t PROGMEM s_kc3_combo[] = {KC_E, KC_D, COMBO_END};
const uint16_t PROGMEM s_kc4_combo[] = {KC_R, KC_F, COMBO_END};
const uint16_t PROGMEM s_kc5_combo[] = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM s_kc6_combo[] = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM s_kc7_combo[] = {KC_U, KC_J, COMBO_END};
const uint16_t PROGMEM s_kc8_combo[] = {KC_I, KC_K, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(mo_layer2_combo, MO(2)),
    COMBO(s_kc1_combo, S(KC_1)),
    COMBO(s_kc2_combo, S(KC_2)),
    COMBO(s_kc3_combo, S(KC_3)),
    COMBO(s_kc4_combo, S(KC_4)),
    COMBO(s_kc5_combo, S(KC_5)),
    COMBO(s_kc6_combo, S(KC_6)),
    COMBO(s_kc7_combo, S(KC_7)),
    COMBO(s_kc8_combo, S(KC_8)),
};
