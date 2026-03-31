// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] = { ENCODER_CCW_CW(UG_HUED, UG_HUEU),  ENCODER_CCW_CW(UG_SATD, UG_SATU)  },
    [2] = { ENCODER_CCW_CW(UG_VALD, UG_VALU),  ENCODER_CCW_CW(UG_SPDD, UG_SPDU)  },
    [3] = { ENCODER_CCW_CW(UG_PREV, UG_NEXT),  ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};
#endif

#ifdef OLED_ENABLE
bool oled_task_user(void) {
// Modifier status
    uint8_t mods = get_mods();
    oled_write_P(PSTR("Mods: "), false);
    
    oled_write_P(mods & MOD_MASK_CTRL ? PSTR("CTL ") : PSTR("    "), false);
    oled_write_P(mods & MOD_MASK_SHIFT ? PSTR("SFT ") : PSTR("    "), false);
    oled_write_P(mods & MOD_MASK_ALT ? PSTR("ALT ") : PSTR("    "), false);
    
    oled_write_ln_P(PSTR(""), false); // empty line
    

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    
    return false;
}
#endif



#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬
     * │EC │ B │ E │
     * ├───┼───┼───┼
     * │ T │ A │ G │
     * ├───┼───┼───┼
     * │CPY│PST│UND│
     * ├───┼───┼───┼
     *
     */
    [0] = LAYOUT(
        KC_NO,   KC_B,   KC_E, 
        KC_T,   KC_A,   KC_G,  
        KC_COPY,   KC_PASTE,  KC_UNDO 
    )
};
