#pragma once

#include QMK_KEYBOARD_H

enum {
    AR_TG_SFT = SAFE_RANGE,
    AR_TG_ALT,
    AR_TG_CTL,
    AR_TG_GUI,
    AR_PANIC,
    AR_SAFE_RANGE
};

bool process_record_artsey(uint16_t keycode, keyrecord_t *record);
