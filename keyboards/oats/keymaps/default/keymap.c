#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _TOP 0
#define _NUMS 1
#define _SPECIAL 2

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
  KC_Q, KC_W, KC_E, KC_R, KC_T, \
  KC_Y, KC_U, KC_I, KC_O, KC_P, \

  LT(NUMS, KC_A), CTL_T(KC_S),  ALT_T(KC_D), LCMD_T(KC_F), SFT_T(KC_G), \
  SFT_T(KC_H),    RCMD_T(KC_J), ALT_T(KC_K), CTL_T(KC_L),  LT(NUMS, KC_SCLN), \

  KC_Z, KC_X, KC_C,    KC_V,   KC_B, \
  KC_N, KC_M, KC_COMM, KC_DOT, KC_QUES, \

  TG(NUMS), KC_LSFT, KC_BSPC, \
  KC_ENT,   KC_SPC,  KC_TAB \
),

[_NUMS] = LAYOUT( \
  KC_SLSH, KC_7, KC_8, KC_9, KC_MINS,   KC_EXLM, KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV, \

  LT(SPECIAL, KC_ASTR), CTL_T(KC_4),     ALT_T(KC_5),    LCMD_T(KC_6),   SFT_T(KC_PLUS), \
  SFT_T(KC_EQL),        RCMD_T(KC_QUOT), ALT_T(KC_LPRN), CTL_T(KC_RPRN), LT(SPECIAL, KC_AMPR), \

  KC_0, KC_1, KC_2, KC_3, KC_EQL,    KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, \
  TG(SPECIAL), TG(NUMS), KC_BSPC,    KC_ENT, KC_SPC, KC_TAB \
),

[_SPECIAL] = LAYOUT( \
  KC_ACL2, KC_ESC,    BL_DEC,   BL_INC,   KC_MS_BTN1,   XXXXXXX, LSFT(LALT(KC__VOLDOWN)), LSFT(LALT(KC__VOLUP)), XXXXXXX, KC__VOLUP, \
  KC_ACL1, KC_MS_L,   KC_MS_D,  KC_MS_U,  KC_MS_R,      KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC__VOLDOWN, \
  KC_ACL0, KC_LCTL,   MOD_LALT, KC_RCMD,  KC_MS_BTN2,   KC_HOME, KC_PGDN, KC_UP, KC_END, KC__MUTE, \
  KC_ESC,  TG(SPECIAL), KC_BSPC,                        KC_ENT, KC_SPC, KC_TAB \
),

};
