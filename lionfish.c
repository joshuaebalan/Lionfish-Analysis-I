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
    //printf("first fish size: %f\n", master[0]->length_with_tail);
    //printf("Total noodle percentage: %2f", compute_noodle_percentage(master, 638));
    //int desired_sex = 3;
    printf("Writing to file 'sex_dist.csv...\n");
    write_csv_sex_dist(master, "sex_dist.csv");
    printf("Done!\n");
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
/*
 * I mainly used this function as plug & play to gather the noodle statistics.
 * I would simply alter the variables in the if block for the parameters that I wanted.
 */

double compute_noodle_percentage(lionfish_t** given, int size) {
  double total = 0.0;
  int pop = 0;
  for (int i = 0; i < size; i++) {
    if ((given[i]->juvenile == 1) && (given[i]->sex == 2)) {
      //Line 88 is meant for debugging in the .csv file for if I put in impossible parameters, such as having a noodle value that is not 0 or 1.
      printf("noodles: %d, beard: %d, sex: %d, number: %d\n", given[i]->has_noodles, given[i]->has_beard, given[i]->sex, i);
      pop++;
      total = total + given[i]->has_noodles;
    }
  }
  printf("Total applicable: %d\n", pop);
  if (pop > 0) {
    return (100 * (total / pop));
  }
  else {
    return 0.0;
  }
}

double compute_noodle_percentage_by_fish_size_and_sex(lionfish_t** given, int file_size, double size_wanted, int sex, int *popp) {
  double total = 0.0;
  int pop = 0;
  for (int i = 0; i < file_size; i++) {
    if ((given[i]->length_tailless < (size_wanted + 0.25)) && (given[i]->length_tailless > (size_wanted - 0.25)) && (given[i]->sex == sex)) {
      //Line 88 is meant for debugging in the .csv file for if I put in impossible parameters, such as having a noodle value that is not 0 or 1.
      //printf("noodles: %d, beard: %d, sex: %d, number: %d\n", given[i]->has_noodles, given[i]->has_beard, given[i]->sex, i);
      pop++;
      total = total + given[i]->has_noodles;
    }
  }
  //printf("Total applicable: %d\n", pop);
  if (pop == 0) {
    (*popp) = 0;
    return 0.0;
  }
  else {
    (*popp) = pop;
    return (100 * (total / pop));
  }
}

double compute_female_percentage_by_time(lionfish_t** given, int file_size, int month, int year, int *popp) {
  double total = 0.0;
  int pop = 0;
  for (int i = 0; i < file_size; i++) {
    if ((given[i]->time_caught->year == year) && (given[i]->time_caught->month == month)) {
      //Line 88 is meant for debugging in the .csv file for if I put in impossible parameters, such as having a noodle value that is not 0 or 1.
      //printf("noodles: %d, beard: %d, sex: %d, number: %d\n", given[i]->has_noodles, given[i]->has_beard, given[i]->sex, i);
      pop++;
      if (given[i]->sex == 3) {
        total = total + 1.0;
      }
    }
  }
  //printf("Total applicable: %d\n", pop);
  if (pop == 0) {
    (*popp) = 0;
    return 0.0;
  }
  else {
    (*popp) = pop;
    return (100 * (total / pop));
  }
}
