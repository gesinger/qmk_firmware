#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _TOP 0
#define _NUMS 1
#define _SYMBOLS 2
#define _COMMANDS 3

#define FINEVOLUP LSFT(LALT(KC__VOLUP))
#define FINEVOLDN LSFT(LALT(KC__VOLDOWN))
#define APPR LCMD(KC_TAB)
#define APPL LCMD(LSFT(KC_TAB))
#define TABR LCTL(KC_TAB)
#define TABL LCTL(LSFT(KC_TAB))

// Fillers to make layering more clear
#define _____ KC_TRNS
#define XXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_TOP] = LAYOUT(
    XXXXX, LT(_SYMBOLS, KC_W), LT(_NUMS, KC_F), KC_P, KC_B, KC_K, KC_L, LT(_NUMS, KC_U), LT(_SYMBOLS, KC_Y), XXXXX,
    KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O,
    // TODO https://github.com/qmk/qmk_firmware/pull/2900 for ;/, ./: in place of </>
    XXXXX, ALT_T(KC_D), CMD_T(KC_C), XXXXX, SFT_T(KC_BSPC), CMD_T(KC_SPC), XXXXX, CMD_T(KC_V), KC_H, XXXXX
  ),
  // Q J Z X    V 

  [_NUMS] = LAYOUT(
    KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    CTL_T(KC_1), ALT_T(KC_2), CMD_T(KC_3), SFT_T(KC_4), KC_5, KC_6, SFT_T(KC_7), CMD_T(KC_8), ALT_T(KC_9), CTL_T(KC_0),
    // TODO KC_LT, KC_GT swap with shifted first layer , and .
    _____, _____, KC_ENT, _____, _____, _____, _____, KC_ENT, _____, _____
  ),

  [_SYMBOLS] = LAYOUT(
    XXXXX, XXXXX, XXXXX, XXXXX, KC_TILD, XXXXX, KC_EQL, KC_PLUS, KC_MINS, KC_NUBS,
    KC_COLN, KC_SCLN, KC_QUOT, KC_DQT, KC_GRV, XXXXX, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR,
    _____, _____, KC_ESC, _____, _____, _____, KC_LBRC, KC_RBRC, KC_UNDS, KC_PIPE
  ),

  [_COMMANDS] = LAYOUT(
    XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, KC__MUTE, FINEVOLDN, FINEVOLUP, XXXXX, RESET,
    XXXXX, XXXXX, APPL, APPR, XXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, XXXXX,
    KC_HOME, XXXXX, TABL, TABR, _____, _____, KC_PGDN, KC_PGUP, KC_END, KC_BRID
  ),

};
