#ifndef REV1_H
#define REV1_H

#include "../keysboard.h"

//void promicro_bootloader_jmp(bool program);
#include "quantum.h"

//void promicro_bootloader_jmp(bool program);

// readability
#define ___ KC_NO

#define LAYOUT( \
  L00, L01,    R01, R00, \
  L10, L11,    R11, R10 \
  ) \
  { \
    { L00, L01 }, \
    { L10, L11 }, \
    { R01, R00 }, \
    { R11, R10 } \
  }

#endif
