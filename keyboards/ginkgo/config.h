#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0000
#define DEVICE_VER      0x0001
#define MANUFACTURER    gesinger
#define PRODUCT         ginkgo night
#define DESCRIPTION     32 key ortholinear split with column stagger and thumb key

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 5

/* key matrix pins */
#define DIRECT_PINS { \
  { B4, E6, D7, C6, D2 }, \
  { F5, F4, D3, D4, B5 }, \
  { F6, F7, B1, B3, B2 }, \
  { NO_PIN, NO_PIN, NO_PIN, NO_PIN, B6 } \
}
#define DIRECT_PINS_RIGHT { \
  { F4, F5, F6, F7, B1 }, \
  { B3, B2, B6, D3, D2 }, \
  { B4, E6, D7, C6, D4 }, \
  { B5, NO_PIN, NO_PIN, NO_PIN, NO_PIN } \
}
#define UNUSED_PINS

#define USE_I2C

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/*required for RESET keycode to work on ProMicro*/
#define CATERINA_BOOTLOADER

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

/* from ergodox_ez mouse settings */
#define MOUSEKEY_INTERVAL       20
#define MOUSEKEY_DELAY          0
#define MOUSEKEY_TIME_TO_MAX    60
#define MOUSEKEY_MAX_SPEED      7
#define MOUSEKEY_WHEEL_DELAY 0

#endif
