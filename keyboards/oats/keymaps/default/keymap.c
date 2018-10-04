#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _TOP 0
#define _NUMS 1
#define _SPECIAL 2

#define FINEVOLUP LSFT(LALT(KC__VOLUP))
#define FINEVOLDN LSFT(LALT(KC__VOLDOWN))
#define TABR LCMD(KC_TAB)
#define TABL LSFT(LCMD(LSFT(KC_TAB)))

enum custom_keycodes {
  TOP = SAFE_RANGE,
  NUMS,
  SPECIAL,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_TOP] = LAYOUT( \
  KC_Q, KC_W, KC_E, KC_R, KC_T,   KC_Y, KC_U, KC_I,    KC_O,   KC_P, \

  CTL_T(KC_A), LCMD_T(KC_S), LT(_NUMS, KC_D), LT(_SPECIAL, KC_F), LALT_T(KC_G), \
    RALT_T(KC_H), LT(_SPECIAL, KC_J), LT(_NUMS, KC_K), RCMD_T(KC_L), CTL_T(KC_SCLN), \

  KC_Z, KC_X, KC_C, KC_V, KC_B,   KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, \

  XXXXXXX, SFT_T(KC_BSPC), XXXXXXX,   XXXXXXX, SFT_T(KC_SPC), XXXXXXX \
),

[_NUMS] = LAYOUT( \
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      KC_6,   KC_7,    KC_8,    KC_9,    KC_0, \
  KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_MINS,   KC_ENT, KC_DQUO, KC_QUOT, KC_LCBR, KC_RCBR, \
  KC_ASTR, KC_EXLM, KC_EQL,  KC_PLUS, KC_UNDS,   KC_AT,  KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, \

  _______, _______, _______,            _______, _______, _______ \
),

[_SPECIAL] = LAYOUT( \
  BL_DEC,  BL_INC,  XXXXXXX,  XXXXXXX, KC_MS_BTN1,   TABL,    TABR,    FINEVOLDN, FINEVOLUP, KC__VOLUP, \
  KC_ESC,  KC_MS_L, KC_MS_D,  KC_MS_U, KC_MS_R,      KC_LEFT, KC_DOWN, KC_UP,     KC_RIGHT,  KC__VOLDOWN, \
  XXXXXXX, XXXXXXX, KC_TAB,   KC_RCMD, KC_MS_BTN2,   KC_HOME, KC_PGDN, KC_PGUP,   KC_END,    KC__MUTE, \

  _______, _______, _______,                         _______, _______, _______ \
),

};
