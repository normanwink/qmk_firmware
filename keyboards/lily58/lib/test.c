
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "lily58.h"

char layer_state_str[24];

const char *nw_test(void) {
  snprintf(layer_state_str, sizeof(layer_state_str), "Test");
  return layer_state_str;
}
