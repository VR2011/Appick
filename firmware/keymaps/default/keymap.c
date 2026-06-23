// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include <string.h>

enum custom_keycodes {
    BRAVE = SAFE_RANGE,
    DISCORD,
    STEAM,
    SPOTIFY
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT(
BRAVE,   DISCORD,
STEAM,   SPOTIFY
)
};

char current_app[20] = "APPICK";
uint32_t app_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
if (!record->event.pressed) {
return true;
}
switch (keycode) {
    case BRAVE:
        strcpy(current_app, "Opening Brave");
        app_timer = timer_read32();
        tap_code(KC_F13);
        return false;

    case DISCORD:
        strcpy(current_app, "Opening Discord");
        app_timer = timer_read32();
        tap_code(KC_F14);
        return false;

    case STEAM:
        strcpy(current_app, "Opening Steam");
        app_timer = timer_read32();
        tap_code(KC_F15);
        return false;

    case SPOTIFY:
        strcpy(current_app, "Opening Spotify");
        app_timer = timer_read32();
        tap_code(KC_F16);
        return false;
}

return true;

}

#ifdef OLED_ENABLE
bool oled_task_user(void) {
if (timer_elapsed32(app_timer) > 3000) {
    strcpy(current_app, "APPICK");
}

oled_clear();

oled_write_ln_P(PSTR("APPICK"), false);
oled_write_ln_P(PSTR("------"), false);
oled_write_ln(current_app, false);

return false;
}
#endif
