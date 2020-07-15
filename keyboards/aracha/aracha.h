#ifndef ARACHA_H
#define ARACHA_H

#include "quantum.h"

// readability
#define ___ KC_NO

// top: physical layout, electrical matrix to physical keys
// bottom: rows x cols with blanks where nothing
#define LAYOUT( \
    K63, K01, K06, K11, K16, K20, K24, K28, K30, K35, K39, K43, K47, K52,      K58, \
    K64, K02, K07, K12, K17, K21, K25,      K31, K36, K40, K44, K48, K53, K56, K59, \
    K65, K03, K08, K13, K18, K22, K26,      K32, K37, K41, K45, K49, K54,      K60, \
    K66, K04, K09, K14, K19, K23, K27,      K33, K38, K42, K46, K50,           K61, \
    K67, K05, K10, K15,                K29, K34,                K51, K55, K57, K62  \
) { \
  { K63, K01, K06, K11, K16, K20, K24, K28 }, \
  { K64, K02, K07, K12, K17, K21, K25, ___ }, \
  { K65, K03, K08, K13, K18, K22, K26, ___ }, \
  { K66, K04, K09, K14, K19, K23, K27, ___ }, \
  { K67, K05, K10, K15, ___, ___, ___, K29 }, \
  { K30, K35, K39, K43, K47, K52, ___, K58 }, \
  { K31, K36, K40, K44, K48, K53, K56, K59 }, \
  { K32, K37, K41, K45, K49, K54, ___, K60 }, \
  { K33, K38, K42, K46, K50, ___, ___, K61 }, \
  { K34, ___, ___, ___, K51, K55, K57, K62 }  \
}

#endif
