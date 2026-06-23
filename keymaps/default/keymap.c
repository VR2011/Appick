// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* [][] TL - Brave | TR - Discord 
    *  [][] BL - Steam | BR - Spotify
    */
                                                                                   

// This keymap, by itself, will only press F13, F14, F15, and F16. These keys won't do anything without the AHK script.
    [0] = LAYOUT(
        KC_F13, KC_F14,
        KC_F15, KC_F16
    )
};
