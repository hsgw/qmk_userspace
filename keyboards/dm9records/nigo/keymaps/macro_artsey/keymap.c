// Copyright 2023 hsgw (Takuya Urakawa, Dm9Records, 5z6p.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
// clang-format off

// First, define user layers and custom keycodes
enum layers {
    _BASE = 0,
    _2ND,
    _3RD,
    _4TH,
    LAYER_SAFE_RANGE
};

enum custom_keycodes {
    USR_PANIC = QK_USER,
    USR_ARTSEY,
    CUSTOM_KEYCODE_END
};

// Second, define start layer and keycode for combos
#define COMBO_LAYER_START LAYER_SAFE_RANGE
#define COMBO_KEYCODE_START CUSTOM_KEYCODE_END

// Third, include combos
#include "users/hsgw/artsey_jis/combos.h"

const uint16_t PROGMEM combo_to_Artsey[] = { KC_5, LT(_3RD, KC_6), COMBO_END};
const uint16_t PROGMEM combo_to_BASE[]   = { KC_BSPC, BAS_2_1, COMBO_END};
combo_t key_combos[] = {
    __KEY_COMBOS_DEF__,
    COMBO(combo_to_Artsey, TO(CMB_BAS)),
    COMBO(combo_to_BASE, TO(_BASE))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_1,          KC_2, KC_3, KC_4, KC_5,
        LT(_3RD, KC_6),KC_7, KC_8, KC_9, LT(_2ND,KC_0)
    ),

    [_2ND] = LAYOUT(
        KC_Q,          KC_W, KC_E, KC_R, KC_T,
        LT(_3RD, KC_Y),KC_U, KC_I, KC_O, _______
    ),

    [_3RD] = LAYOUT(
        KC_A,    KC_S, KC_D, KC_F, KC_G,
        _______, KC_J, KC_K, KC_L, LT(_2ND,KC_SCLN)
    ),

    [_4TH] = LAYOUT(
        QK_BOOT, QK_RBT, KC_NO, KC_NO, USR_PANIC,
        KC_NO,   KC_NO,  KC_NO, KC_NO, KC_NO
    ),

    [CMB_BAS] = LAYOUT(
        BAS_1_1,BAS_1_2,BAS_1_3,BAS_1_4, KC_BSPC,
        BAS_2_1,BAS_2_2,BAS_2_3,BAS_2_4, KC_SPC
    ),

    [CMB_NUM] = LAYOUT(
        NUM_1_1,NUM_1_2,NUM_1_3,NUM_1_4, _______,
        NUM_2_1,NUM_2_2,NUM_2_3,NUM_2_4, _______
    ),


    [CMB_SY1] = LAYOUT(
        SY1_1_1,SY1_1_2,SY1_1_3,SY1_1_4, _______,
        SY1_2_1,SY1_2_2,SY1_2_3,SY1_2_4, _______
    ),

    [CMB_CUS] = LAYOUT(
        CUS_1_1,CUS_1_2,CUS_1_3,CUS_1_4, _______,
        CUS_2_1,CUS_2_2,CUS_2_3,CUS_2_4, _______
    ),

    [CMB_SY2] = LAYOUT(
        SY2_1_1,SY2_1_2,SY2_1_3,SY2_1_4, _______,
        SY2_2_1,SY2_2_2,SY2_2_3,SY2_2_4, _______
    ),

    [CMB_MOU] = LAYOUT(
        MOU_1_1,MOU_1_2,MOU_1_3,MOU_1_4, _______,
        MOU_2_1,MOU_2_2,MOU_2_3,MOU_2_4, _______
    ),

    [CMB_NAV] = LAYOUT(
        NAV_1_1,NAV_1_2,NAV_1_3,NAV_1_4, _______,
        NAV_2_1,NAV_2_2,NAV_2_3,NAV_2_4, _______
    ),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (process_record_combo_keycode(keycode, record) == false) {
        return false;
    }
    switch (keycode) {
        case USR_PANIC:
            if (record->event.pressed) {
                clear_keyboard();
            }
            return false;
        default:
            return true;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _2ND, _3RD, _4TH);
}
