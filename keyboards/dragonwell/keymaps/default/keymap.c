#include QMK_KEYBOARD_H

#define _TOP 0
#define _NUMS 1
#define _SYMBOLS 2
#define _MOUSE 3

#define _____ KC_TRNS
#define XXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_TOP] = LAYOUT(
    ALT_T(KC_V), KC_W, KC_F, KC_P, KC_L, KC_U, KC_Y, ALT_T(KC_K),
    LT(_MOUSE, KC_A), LT(_SYMBOLS, KC_R), CTL_T(KC_S), CMD_T(KC_T), CMD_T(KC_N), CTL_T(KC_E), LT(_SYMBOLS, KC_I), LT(_MOUSE, KC_O),
    KC_B, KC_D, KC_C, SFT_T(KC_BSPC), LT(_NUMS, KC_SPC), KC_M, KC_H, KC_G
  ),

  [_NUMS] = LAYOUT(
    ALT_T(KC_7), KC_8, KC_9, KC_EQL, KC_Q, KC_J, KC_X, ALT_T(KC_Z),
    KC_4, KC_5, CTL_T(KC_6), CMD_T(KC_0), CMD_T(KC_ENT), CTL_T(KC_TAB), KC_LEAD, KC_ESC,
    KC_1, KC_2, KC_3, _____, _____, _____, _____, _____
  ),

  [_SYMBOLS] = LAYOUT(
    ALT_T(KC_BSLS), KC_LCBR, KC_RCBR, KC_ASTR, KC_PLUS, KC_SCLN, KC_COLN, ALT_T(KC_AMPR),
    KC_SLSH, KC_LPRN, CTL_T(KC_RPRN), CMD_T(KC_UNDS), CMD_T(KC_MINS), CTL_T(KC_COMM), KC_DOT, KC_QUES,
    KC_PIPE, KC_LBRC, KC_RBRC, _____, _____, KC_DQUO, KC_QUOT, KC_EXLM
  ),

  [_MOUSE] = LAYOUT(
    _____, _____, _____, KC_BTN1, KC_BTN2, _____, _____, _____,
    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
    _____, _____, _____, _____, _____, _____, _____, _____
  ),

};
