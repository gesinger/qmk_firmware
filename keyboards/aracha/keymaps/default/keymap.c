#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _TOP 0
#define _COMMANDS 1

#define FINEVOLUP LSFT(LALT(KC__VOLUP))
#define FINEVOLDN LSFT(LALT(KC__VOLDOWN))
#define APPR LCMD(KC_TAB)
#define APPL LCMD(LSFT(KC_TAB))
#define TABR LCTL(KC_TAB)
#define TABL LCTL(LSFT(KC_TAB))
#define SLACKCLEAR LSFT(KC_ESC)

// Fillers to make layering more clear
#define _____ KC_TRNS
#define XXXXX KC_NO

enum custom_keycodes {
  KC_DOTCLN = SAFE_RANGE,
  KC_COMMSCLN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_TOP] = LAYOUT(
    KC_ESC,    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,       \
    KC__MUTE,  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,       \
    KC_LGUI,   KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,        \
    FINEVOLUP, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                   MO(_COMMANDS), \
    FINEVOLDN, KC_LCTL, KC_LALT, KC_LGUI,   MT(MOD_LSFT, KC_SPC),       LT(_COMMANDS, KC_SPC),                             KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT \
  ),

  [_COMMANDS] = LAYOUT(
    RESET, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, \
    _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, \
    _____, _____, _____, _____, _____, _____, SLACKCLEAR, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _____, _____,        _____, \
    _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,               _____, \
    _____, _____, _____, _____, MT(MOD_LGUI, KC_BSPC), _____,                      _____, _____, _____, _____
  ),
};
