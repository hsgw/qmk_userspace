#pragma once

enum {
    AR_OSM_SFT = SAFE_RANGE,
    AR_OSM_ALT,
    AR_OSM_CTL,
};

bool process_record_artsey(uint16_t keycode, keyrecord_t *record);
