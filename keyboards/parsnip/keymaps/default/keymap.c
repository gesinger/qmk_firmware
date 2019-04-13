#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _TOP 0
#define _NUMS 1
#define _SPECIAL 2
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

  // colemak mod dhm (mod dh with k and m switched for ortholinear keyboards)
  [_TOP] = LAYOUT(
    KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, TT(_COMMANDS),
    KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O,
    // TODO https://github.com/qmk/qmk_firmware/pull/2900 for ;/, ./: in place of </>
    KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH,

    KC_LCTL, TT(_SPECIAL), SFT_T(KC_BSPC), LCMD_T(KC_SPC), TT(_NUMS), KC_RCTL
  ),

  [_NUMS] = LAYOUT(
    XXXXX, KC_7, KC_8, KC_9, KC_BSLS, KC_ESC, KC_PIPE, KC_LBRC, KC_RBRC, XXXXX,
    KC_0, KC_4, KC_5, KC_6, KC_PLUS, KC_ENT, KC_QUOT, KC_LPRN, KC_RPRN, KC_MINS,
    // TODO KC_LT, KC_GT swap with shifted first layer , and .
    KC_GRV, KC_1, KC_2, KC_3, KC_EQL, KC_SCLN, KC_TAB, KC_LCBR, KC_RCBR, KC_COLN,
    _____, _____, _____, _____, _____, _____
  ),

  [_SPECIAL] = LAYOUT(
    KC_DEL, XXXXX, XXXXX, XXXXX, XXXXX, KC__MUTE, FINEVOLDN, FINEVOLUP, KC__VOLDOWN, KC__VOLUP,
    KC_LGUI, KC_GRAVE, APPL, APPR, XXXXX, KC_BRIU, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
    XXXXX, XXXXX, TABL, TABR, XXXXX, KC_BRID, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
    _____, _____, _____, _____, _____, _____
  ),

  [_COMMANDS] = LAYOUT(
    RESET, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
    XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
    XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
    _____, _____, _____, _____, _____, _____
  ),
};
