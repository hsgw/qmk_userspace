// copy from qmk_userspace/hsgw/combo

#pragma once

#include QMK_KEYBOARD_H

#ifndef CMB_KEYCODE_START
    #define CMB_KEYCODE_START QK_USER
#endif

enum CMB_keycode {
    CMB_TG_SFT = CMB_KEYCODE_START,
    CMB_TG_ALT,
    CMB_TG_CTL,
    CMB_TG_GUI,
    CMB_PANIC,
    CMB_SAFE_RANGE
};

bool process_record_combo_keycode(uint16_t keycode, keyrecord_t *record);
