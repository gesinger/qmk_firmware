#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0000
#define DEVICE_VER      0x0001
#define MANUFACTURER    gesinger
#define PRODUCT         dragonwell
#define DESCRIPTION     split 30 percent ortholinear keyboard with column stagger and perpendicular thumb

/* key matrix size */
#define MATRIX_ROWS 3
#define MATRIX_COLS 10

#define MATRIX_ROW_PINS { F6, B1, F7 }
#define MATRIX_COL_PINS { D4, B4, E6, D7, C6, B3, B2, B6, F4, F5 }
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

#endif
