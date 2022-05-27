#include "lionfish.h"
#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("compiles successfully!\n");
  printf("read MASTER?[0/1]\n");
  int read = 0;
  char buf = ' ';
  scanf("%d%c", &read, &buf);
  if (read != 0) {
    lionfish_t **master = read_table_file("MASTER_DATA.csv");
    if (master == NULL) {
      return UH_OH;
    }
    printf("first fish size: %f\n", master[0]->length_with_tail);
  }
  return OK;
}

/*
 * This function compares two catch_t structures and returns the appropriate
 * predefined value, EARLIER if fish a was caught before b, LATER vice versa,
 * and EQUAL if on the same day. As of this version, 29/04/2022, I am assuming
 * that ReefCI deos not record times down to the hour. If that does happen,
 * I will add an enumerated value for values of MORNING, AFTERNOON, etc. in lieu
 * of an integer hour in 24-hour time for ease of comparison(i.e. bar graphs)
 */

int relate_time(catch_t *a, catch_t *b) {
  if (a->year != b->year) {
    if (a->year < b->year) {
      return EARLIER;
    }
    else {
      return LATER;
    }
  }
  else {
    if (a->month != b->month) {
      if (a->month < b->month) {
        return EARLIER;
      }
      else {
        return LATER;
      }	
    }
    else {
      if (a->day == b->day) {
        return EQUAL;
      }
      else {
	if (a->day < b->day) {
	  return EARLIER;
	}
	else {
	  return LATER;
	}
      }
    }
  }
} /* relate_time() */

//These are work in progress functions needed for file reading.
int enumerate_sex(char *given) {
  printf("%s\n", given);
  return 3;
}

catch_t *read_from_writing(char *given) {
  printf("%s\n", given);
  return NULL;
}