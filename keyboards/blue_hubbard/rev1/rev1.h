#ifndef REV1_H
#define REV1_H

#include "../oats.h"

//void promicro_bootloader_jmp(bool program);
#include "quantum.h"

//void promicro_bootloader_jmp(bool program);

// readability
#define ___ KC_NO

#define LAYOUT( \
  L00, L01, L02, L03, L04,    R04, R03, R02, R01, R00, \
  L10, L11, L12, L13, L14,    R14, R13, R12, R11, R10, \
  L20, L21, L22, L23, L24,    R24, R23, R22, R21, R20, \
            L32, L33, L34,    R34, R33, R32 \
  ) \
  { \
    { L00, L01, L02, L03, L04 }, \
    { L10, L11, L12, L13, L14 }, \
    { L20, L21, L22, L23, L24 }, \
    { ___, ___, L32, L33, L34 }, \
    { R00, R01, R02, R03, R04 }, \
    { R10, R11, R12, R13, R14 }, \
    { R20, R21, R22, R23, R24 }, \
    { ___, ___, R32, R33, R34 } \
  }

#endif
