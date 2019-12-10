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
    ALT_T(KC_Q), KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, ALT_T(KC_TAB),
    CTL_T(KC_A), CMD_T(KC_R), LT(_NUMS, KC_S), LT(_SYMBOLS, KC_T), KC_G, KC_M, LT(_SYMBOLS, KC_N), LT(_NUMS, KC_E), CMD_T(KC_I), CTL_T(KC_O),
    KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMMSCLN, KC_DOTCLN, KC_ENT,
    SFT_T(KC_BSPC), LT(_COMMANDS, KC_SPC)
  ),

  [_NUMS] = LAYOUT(
    KC_LALT, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, KC_MINS, KC_EQL, KC_PLUS, KC_RALT,
    CTL_T(KC_1), CMD_T(KC_2), KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, CMD_T(KC_9), CTL_T(KC_0),
    _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,
    _____, _____
  ),

  [_SYMBOLS] = LAYOUT(
    XXXXX, XXXXX, KC_LPRN, KC_RPRN, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
    KC_LCTL, CMD_T(KC_UNDS), KC_LCBR, KC_RCBR, KC_TILD, KC_GRV, KC_DQT, KC_QUOT, CMD_T(KC_QUES), CTL_T(KC_EXLM),
    _____, KC_PIPE, KC_LBRC, KC_RBRC, _____, KC_BSLS, KC_SLSH, KC_LT, KC_GT, _____,
    _____, _____
  ),

  [_COMMANDS] = LAYOUT(
    XXXXX, XXXXX, APPL, APPR, KC_BTN2, KC_BRIU, KC__MUTE, FINEVOLDN, FINEVOLUP, RESET,
    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN1, KC_ESC, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
    XXXXX, XXXXX, TABL, TABR, XXXXX, KC_BRID, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
    _____, _____
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

layer_state_t layer_state_set_user(layer_state_t state) {
  writePinLow(C6);
  writePinLow(D7);
  writePinLow(B5);
  writePinLow(B6);

  switch (get_highest_layer(state)) {
  case _NUMS:
		writePinHigh(C6);
    break;
  case _SYMBOLS:
		writePinHigh(D7);
    break;
  case _COMMANDS:
		writePinHigh(B6);
    break;
	default: //  for any other layers, or the default layer
		break;
	}

  return state;
}
