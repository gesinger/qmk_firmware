#ifndef KABOCHA_H
#define KABOCHA_H

#include "quantum.h"

#define LAYOUT( \
    A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, \
    B0, B1, B2, B3, B4, B5, B6, B7, B8, B9, \
    C0, C1, C2, C3, C4, C5, C6, C7, C8, C9, \
    D0, D1, D2, D3, D4, D5, D6, D7, D8, D9 \
) { \
    { A0, A1, A2, A3, A4, A5, A6, A7, A8, A9 }, \
    { B0, B1, B2, B3, B4, B5, B6, B7, B8, B9 }, \
    { C0, C1, C2, C3, C4, C5, C6, C7, C8, C9 }, \
    { D0, D1, D2, D3, D4, D5, D6, D7, D8, D9 } \
}

#endif
