#include QMK_KEYBOARD_H

#define _TOP 0
#define _LETTERS 1
#define _NUMS 2
#define _SYMBOLS 3
#define _MOUSE 4

#define _____ KC_TRNS
#define XXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_TOP] = LAYOUT(
    XXXXX, LALT_T(KC_W), KC_F, KC_P, KC_L, KC_U, LALT_T(KC_Y), XXXXX,
    SFT_T(KC_A), LT(_SYMBOLS, KC_R), CTL_T(KC_S), CMD_T(KC_T), CMD_T(KC_N), CTL_T(KC_E), LT(_SYMBOLS, KC_I), SFT_T(KC_O),
    XXXXX, KC_D, KC_C, OSL(_LETTERS), LT(_NUMS, KC_SPC), KC_M, KC_H, XXXXX
  ),

  [_LETTERS] = LAYOUT(
    XXXXX, KC_COLN, KC_SCLN, KC_QUOT, KC_DQUO, KC_LPRN, KC_RPRN, XXXXX,
    SFT_T(KC_X), LT(_SYMBOLS, KC_Q), CTL_T(KC_V), CMD_T(KC_G), CMD_T(KC_B), CTL_T(KC_K), LT(_SYMBOLS, KC_J), SFT_T(KC_Z),
    XXXXX, KC_LBRC, KC_RBRC, OSL(_SYMBOLS), KC_LEAD, KC_LCBR, KC_RCBR, XXXXX
  ),

  [_NUMS] = LAYOUT(
    XXXXX, KC_7, KC_8, KC_9, KC_4, KC_5, KC_6, XXXXX,
    KC_3, KC_2, CTL_T(KC_1), CMD_T(KC_0), CMD_T(KC_BSPC), CTL_T(KC_ENT), KC_TAB, KC_ESC,
    XXXXX, KC_PLUS, KC_EQL, _____, _____, KC_COMM, KC_DOT,  XXXXX
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

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_N) {
      SEND_STRING(SS_TAP(X_BSPACE));
    }
    SEQ_ONE_KEY(KC_E) {
      SEND_STRING(SS_TAP(X_BSPACE));
      SEND_STRING(SS_TAP(X_BSPACE));
    }
    SEQ_ONE_KEY(KC_I) {
      SEND_STRING(SS_TAP(X_BSPACE));
      SEND_STRING(SS_TAP(X_BSPACE));
      SEND_STRING(SS_TAP(X_BSPACE));
    }
    SEQ_ONE_KEY(KC_O) {
      SEND_STRING(SS_TAP(X_BSPACE));
      SEND_STRING(SS_TAP(X_BSPACE));
      SEND_STRING(SS_TAP(X_BSPACE));
      SEND_STRING(SS_TAP(X_BSPACE));
    }
  }
}
