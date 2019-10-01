#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0001
#define DEVICE_VER      0x0001
#define MANUFACTURER    gesinger
#define PRODUCT         dragonwell
#define DESCRIPTION     24 key split column stagger keyboard with perpendicular thumb key

/* key matrix size */
#define MATRIX_ROWS 3
#define MATRIX_COLS 8

#define MATRIX_ROW_PINS { A0, A1, A2 }
#define MATRIX_COL_PINS { A3, A4, A14, A13, A7, A6, A5, B1 }

/* COL2ROW, ROW2COL, or CUSTOM_MATRIX */
#define DIODE_DIRECTION COL2ROW

#define DEBOUNCING_DELAY 5

#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

/* mousekey config from ergodox */
#define MOUSEKEY_INTERVAL 20
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED 7
#define MOUSEKEY_WHEEL_DELAY 0

#define LEADER_TIMEOUT 1000

#endif
