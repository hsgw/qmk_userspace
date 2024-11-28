// Copyright 2023 hsgw (Takuya Urakawa, Dm9Records, 5z6p.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// #include "users/hsgw/artsey/combos.h"
#include "users/hsgw/artsey_jis/combos.h"

combo_t key_combos[] = {__KEY_COMBOS_DEF__};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[CMB_BAS] = LAYOUT(
BAS_1_1,BAS_1_2,BAS_1_3,BAS_1_4, KC_BSPC,
BAS_2_1,BAS_2_2,BAS_2_3,BAS_2_4, KC_SPC
),

[CMB_NUM] = LAYOUT(
NUM_1_1,NUM_1_2,NUM_1_3,NUM_1_4, KC_BSPC,
NUM_2_1,NUM_2_2,NUM_2_3,NUM_2_4, KC_SPC
),


[CMB_SY1] = LAYOUT(
SY1_1_1,SY1_1_2,SY1_1_3,SY1_1_4, KC_BSPC,
SY1_2_1,SY1_2_2,SY1_2_3,SY1_2_4, KC_SPC
),

[CMB_CUS] = LAYOUT(
CUS_1_1,CUS_1_2,CUS_1_3,CUS_1_4, KC_BSPC,
CUS_2_1,CUS_2_2,CUS_2_3,CUS_2_4, KC_SPC
),

[CMB_SY2] = LAYOUT(
SY2_1_1,SY2_1_2,SY2_1_3,SY2_1_4, KC_BSPC,
SY2_2_1,SY2_2_2,SY2_2_3,SY2_2_4, KC_SPC
),

[CMB_MOU] = LAYOUT(
MOU_1_1,MOU_1_2,MOU_1_3,MOU_1_4, KC_BSPC,
MOU_2_1,MOU_2_2,MOU_2_3,MOU_2_4, KC_SPC
),

[CMB_NAV] = LAYOUT(
NAV_1_1,NAV_1_2,NAV_1_3,NAV_1_4, KC_BSPC,
NAV_2_1,NAV_2_2,NAV_2_3,NAV_2_4, KC_SPC
),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // first check combos
    if (process_record_combo_keycode(keycode, record) == false) {
        return false;
    }

    // then check other user keycodes
    return true;
}
