#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _TOP 0

enum custom_keycodes {
  TOP = SAFE_RANGE,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_TOP] = LAYOUT( \
  KC_Q, KC_W, KC_E, KC_R, KC_T,   KC_Y, KC_U, KC_I, KC_O, KC_P, \
  KC_A, KC_S, KC_D, KC_F, KC_G,   KC_H, KC_J, KC_K, KC_L, KC_SCOLON, \
  KC_Z, KC_X, KC_C, KC_V, KC_B,   KC_N, KC_M, KC_COMMA, KC_DOT, KC_QUESTION, \
  DEBUG, KC_SPACE, KC_LSHIFT,     KC_BSPACE, KC_ENTER, KC_TAB \
),

};
