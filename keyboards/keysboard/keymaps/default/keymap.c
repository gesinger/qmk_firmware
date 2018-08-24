#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _TOP 0
#define _NUMS 1
#define _SPECIAL 2
#define _ADJUST 16

enum custom_keycodes {
  TOP = SAFE_RANGE,
  NUMS,
  SPECIAL,
  ADJUST
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Top
 *
 * ,---------------,  ,--------------------,
 * | NUMS  | SHIFT |  |  mVOLUP  |  VOLUP  |
 * |---------------+  |--------------------+
 * | MUTE  |  ALT  |  | mVOLDOWN | VOLDOWN |
 * |---------------,  |------+-------------,
 */
[_TOP] = LAYOUT( \
  NUMS,     KC_LSHIFT,   LSFT(LALT(KC__VOLUP)),   KC__VOLUP,  \
  KC__MUTE, KC_LALT,     LSFT(LALT(KC__VOLDOWN)), KC__VOLDOWN \
),

[_NUMS] = LAYOUT( \
  SPECIAL, KC_0,   KC_2, KC_4, \
  TOP,     KC_1,   KC_3, KC_5  \
),

[_SPECIAL] = LAYOUT( \
  ADJUST, KC_6,   KC_8, KC_ENTER, \
  NUMS,   KC_7,   KC_9, KC_BSPACE \
),

[_ADJUST] = LAYOUT( \
  TOP,   RESET,   KC_NO, KC_1, \
  KC_NO, DEBUG,   KC_NO, KC_0 \
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TOP:
      if (record->event.pressed) {
        layer_on(_TOP);
        layer_off(_NUMS);
        layer_off(_SPECIAL);
        layer_off(_ADJUST);
      }
      return false;
      break;
    case NUMS:
      if (record->event.pressed) {
        layer_on(_NUMS);
        layer_off(_TOP);
        layer_off(_SPECIAL);
        layer_off(_ADJUST);
      }
      return false;
      break;
    case SPECIAL:
      if (record->event.pressed) {
        layer_on(_SPECIAL);
        layer_off(_TOP);
        layer_off(_NUMS);
        layer_off(_ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
        layer_off(_TOP);
        layer_off(_NUMS);
        layer_off(_SPECIAL);
      }
      return false;
      break;
  }
  return true;
}
