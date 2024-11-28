// copy from qmk_userspace/hsgw/combo

#include "combo_util.h"

bool process_record_combo_keycode(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CMB_TG_SFT:
            if (record->event.pressed) {
                if (get_mods() & MOD_BIT(KC_RSFT)) {
                    unregister_mods(MOD_BIT(KC_RSFT));
                } else {
                    register_mods(MOD_BIT(KC_RSFT));
                }
            }
            return false;
        case CMB_TG_CTL:
            if (record->event.pressed) {
                if (get_mods() & MOD_BIT(KC_RCTL)) {
                    unregister_mods(MOD_BIT(KC_RCTL));
                } else {
                    register_mods(MOD_BIT(KC_RCTL));
                }
            }
            return false;
        case CMB_TG_ALT:
            if (record->event.pressed) {
                if (get_mods() & MOD_BIT(KC_RALT)) {
                    unregister_mods(MOD_BIT(KC_RALT));
                } else {
                    register_mods(MOD_BIT(KC_RALT));
                }
            }
            return false;
        case CMB_TG_GUI:
            if (record->event.pressed) {
                if (get_mods() & MOD_BIT(KC_RGUI)) {
                    unregister_mods(MOD_BIT(KC_RGUI));
                } else {
                    register_mods(MOD_BIT(KC_RGUI));
                }
            }
            return false;
        case CMB_PANIC:
            if (record->event.pressed) {
                clear_mods();
            }
            return false;
        default:
            return true;
    }
}
