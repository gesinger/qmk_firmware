#include QMK_KEYBOARD_H

#define _TOP 0
#define _NUMS 1

#define _____ KC_TRNS
#define XXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_TOP] = LAYOUT(
    ALT_T(KC_V), KC_W, KC_F, KC_P, KC_L, KC_U, KC_G, ALT_T(KC_K),
    KC_A, KC_R, CTL_T(KC_S), CMD_T(KC_T), CMD_T(KC_N), CTL_T(KC_E), KC_I, KC_O,
    KC_B, KC_C, KC_D, SFT_T(KC_BSPC), LT(_NUMS, KC_SPC), KC_M, KC_H, KC_Y
  ),

  [_NUMS] = LAYOUT(
    ALT_T(KC_7), KC_8, KC_9, KC_EQL, KC_Q, KC_J, KC_X, ALT_T(KC_Z),
    KC_4, KC_5, CTL_T(KC_6), CMD_T(KC_0), CMD_T(KC_ENT), CTL_T(KC_TAB), KC_LEAD, KC_ESC,
    KC_1, KC_2, KC_3, _____, _____, _____, _____, _____
  ),

};
