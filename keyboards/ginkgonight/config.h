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
#define MATRIX_ROWS 4
#define MATRIX_COLS 8

/* key matrix pins */
#define MATRIX_ROW_PINS { B5, B4, B3, A15 }
#define MATRIX_COL_PINS { A6, A7, B0, B1, A0, A1, A2, A3 }
#define UNUSED_PINS

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
