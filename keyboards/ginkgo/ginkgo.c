#include "ginkgo.h"

void matrix_init_kb(void) {
  setPinOutput(C6);
  setPinOutput(D7);
  setPinOutput(B5);
  setPinOutput(B6);

  writePinLow(C6);
  writePinLow(D7);
  writePinLow(B5);
  writePinLow(B6);

  matrix_init_user();
}
