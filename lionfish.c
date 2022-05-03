#include "lionfish.h"
#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("compiles successfully!\n");
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
  return UNIDENTIFIED;
}

catch_t *read_from_writing(char *given) {
  printf("%s\n", given);
  return NULL;
}

/*
 * This function aids in the splitting of large lists of lionfish_t
 * structure pointers and sorting them into groups of similarly dated structures.
 * The first parameter chooses what kind of time to group by: DAY for day, MONTH
 * for month, and YEAR for year.  
 * IMPORTANT OPERATION NOTE: function only looks at the parameter described. For example,
 * if sorting by month, date of 29-03-2022 will be in the same list as date of 13-03-2010, so
 * it is recommended to sort by broadest search parameters first. 
 */

int group_time(int mode, unsigned int identifier, int list_length, lionfish_t **raw, lionfish_t ***sorted) {
  int fish_found = 0;
  int cur_fish = 0;
  lionfish_t **temp_sorted = *(sorted);
  for (int i = 0; i < list_length; i++) {
    switch (mode) {
      case YEAR: {
        if (raw[i]->time_caught->year == identifier) {
          temp_sorted[cur_fish] = raw[i];
          fish_found++;
          continue;
        }
      }
      case MONTH: {
        if (raw[i]->time_caught->month == identifier) {
          temp_sorted[cur_fish] = raw[i];
          cur_fish++;
          continue;
        }
      }
      case DAY: {
        if (raw[i]->time_caught->month == identifier) {
          temp_sorted[cur_fish] = raw[i];
          cur_fish++;
          continue;
        }
      }
    }
  }
  if (fish_found != 0) {
    *(sorted) = temp_sorted;
    return fish_found;
  }
  else {
    return NO_FISH_FOUND;
  }
}
