/*
Copyright 2018 Cole Markham

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_sethsv_noeeprom(HSV_PURPLE); // Default color
  rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL); // Default mode
}
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//Layer 0 - Base Layer (F21 + F23)

	[0] = LAYOUT(
		TO(1), KC_F16, KC_F17
		),

//Layer 1 - F23 + F24)
	[1] = LAYOUT(
		TO(2), KC_F18, KC_F19
		),

//Layer 2 - Bootloader mode + Reset
	[2] = LAYOUT(
		TO(0), QK_BOOTLOADER, EE_CLR
		),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  switch(biton32(state)) {
  case 1:
    // Rainbow mood
    rgblight_enable_noeeprom();
    rgblight_mode(RGBLIGHT_MODE_RAINBOW_MOOD);
    break;
  case 2:
    // Red
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_RED);
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    break;
  default:
    // Rainbow swirl
    rgblight_enable_noeeprom();
    rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
    break;
}
return state;
}
