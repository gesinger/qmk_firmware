#ifndef BILOBA_H
#define BILOBA_H

#include "quantum.h"

// readability
#define __ KC_NO

#define LAYOUT( \
    A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, \
    B0, B1, B2, B3, B4, B5, B6, B7, B8, B9, \
    C0, C1, C2, C3, C4, C5, C6, C7, C8, C9 \
) { \
    { A0, A1, A2, A3, A4, A5, A6, A7, A8, A9 }, \
    { B0, B1, B2, B3, B4, B5, B6, B7, B8, B9 }, \
    { C0, C1, C2, C3, C4, C5, C6, C7, C8, C9 } \
}

#endif
