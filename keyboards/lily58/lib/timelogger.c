#include <stdio.h>
#include "timer.h"
#include "lily58.h"

char timelog_str[24] = {};
unsigned long start_time = 0;
unsigned long elapsed_time = 0;

void start_timelog(void) {
  start_time = timer_read();
}

const char *read_timelog(void) {
  elapsed_time = timer_elapsed(start_time);
  // snprintf(timelog_str, sizeof(timelog_str), "%u", elapsed_time);
  return timelog_str;
}
