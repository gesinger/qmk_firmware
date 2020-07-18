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

enum custom_keycodes {
  KC_DOTCLN = SAFE_RANGE,
  KC_COMMSCLN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_TOP] = LAYOUT(
    KC_Q, KC_W, KC_E, KC_R, KC_T,                                KC_Y, KC_U, KC_I, KC_O, KC_P,
    KC_A, KC_S, KC_D, KC_F, KC_G,                                KC_H, KC_J, KC_K, KC_L, KC_SCLN,
    SFT_T(KC_Z), CTL_T(KC_X), ALT_T(KC_C), CMD_T(KC_V), KC_B,    KC_N, CMD_T(KC_M), ALT_T(KC_COMM), CTL_T(KC_DOT), SFT_T(KC_SLSH),
    LT(_COMMANDS, KC_SPC), LT(_NUMS, KC_SPC)
  ),

  [_NUMS] = LAYOUT(
    KC_ESC, KC_GRV, _____, _____, _____,     KC_QUOT, KC_MINS, KC_EQL, KC_PLUS, KC_BSPC,
    KC_1, KC_2, KC_3, KC_4, KC_5,            KC_6, KC_7, KC_8, KC_9, KC_0,
    _____, _____, _____, _____, _____,       _____, _____, ALT_T(KC_LBRC), CTL_T(KC_RBRC), SFT_T(KC_BSLASH),
    _____, _____
  ),

  [_COMMANDS] = LAYOUT(
    XXXXX, XXXXX, APPL, APPR, KC_BTN2, KC_BRIU, KC__MUTE, FINEVOLDN, FINEVOLUP, RESET,
    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN1, KC_ESC, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
    XXXXX, XXXXX, TABL, TABR, XXXXX, KC_BRID, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
    _____, KC_ENT
  ),

};

bool shift_held(void) {
  return (get_mods() & MOD_BIT(KC_LSHIFT)) || (get_mods() & MOD_BIT(KC_RSHIFT));
};

void custom_shift(keyrecord_t *record, uint16_t key, uint16_t shift_key, bool keep_shift) {
  if (record->event.pressed) {
    if (shift_held()) {
      uint8_t shift_kc = KC_LSFT;
      if (keyboard_report->mods & MOD_BIT(KC_RSFT)) {
        shift_kc = KC_RSFT;
      }
      // shift will mod the keycode on its own
      if (!keep_shift) {
        unregister_code(shift_kc);
      }
      register_code(shift_key);
      register_code(shift_kc);
    } else {
      register_code(key);
    }
  } else {
    unregister_code(shift_key);
    unregister_code(key);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // TODO https://github.com/qmk/qmk_firmware/pull/2900
    case KC_DOTCLN:
      custom_shift(record, KC_DOT, KC_COLN, true);
      return false;
    case KC_COMMSCLN:
      custom_shift(record, KC_COMM, KC_SCLN, false);
      return false;
  }
  return true;
};
