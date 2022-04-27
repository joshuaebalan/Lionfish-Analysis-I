#include "lionfish-test.h"
#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  return OK;
}

int relate_time(lionfish_t *a, lionfish_t *b) {
  if (a->time_caught->id > b->time_caught->id) {
    return GREATER;
  }
  else if (a->time_caught->id < b->time_caught->id) {
    return LESSER;
  }
  else if (a->time_caught->id == b->time_caught->id) {
    return EQUAL;
  }
  else {
    return UH-OH;
  }
}

int compile_time(catch_t *catch) {
  float tot = 0.0;
  tot = tot + (float)catch->year;
  tot = tot + ((float)catch->month / 12);
  if (catch->year % 4 == 0) {
    tot = tot + ((float)catch->day / 366);
  }
  else {
    tot = tot + ((float)catch->day / 365);
  }
  catch->id = tot;
  return OK;
}
