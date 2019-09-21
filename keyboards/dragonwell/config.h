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

#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

#endif
