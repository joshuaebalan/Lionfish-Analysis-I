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
    //printf("Writing to file 'sex_dist.csv...\n");
    //write_csv_sex_dist(master, "sex_dist.csv");
    //printf("Done!\n");
    calculate_length_data(master, 638);
  }
  return OK;
}

void calculate_length_data(lionfish_t** given, int size) {
  double min_male = 1000.0;
  double max_male = 0.0;
  double min_female = 1000.0;
  double max_female = 0.0;
  double total_male = 0.0;
  double total_female = 0.0;
  double min_male_tail = 1000.0;
  double max_male_tail = 0.0;
  double min_female_tail = 1000.0;
  double max_female_tail = 0.0;
  double temp_tail = 0.0;
  double total_tail_male = 0.0;
  double total_tail_female = 0.0;
  int male_count = 0;
  int female_count = 0;
  for (int i = 0; i < size; i++) {
    if (given[i]->juvenile != 0) {
      continue;
    }
    else if (given[i]->sex == 2) {
      male_count++;
      if (given[i]->length_with_tail < given[i]->length_tailless) {
        printf("Bad Tail on #%d!\n", i);
      }
      temp_tail = (given[i]->length_with_tail - given[i]->length_tailless);
      if (given[i]->length_tailless < min_male) {
        min_male = given[i]->length_tailless;
      }
      if (given[i]->length_tailless > max_male) {
        max_male = given[i]->length_tailless;
      }
      if (temp_tail < min_male_tail) {
        min_male_tail = temp_tail;
      }
      if (temp_tail > max_male_tail) {
        max_male_tail = temp_tail;
      }
      total_male = total_male + given[i]->length_tailless;
      total_tail_male = total_tail_male + temp_tail;
    }
    else if (given[i]->sex == 3) {
      female_count++;
      temp_tail = (given[i]->length_with_tail - given[i]->length_tailless);
      if (temp_tail < 0) {
        printf("Bad tail on #%d!\n", i);
      }
      if (given[i]->length_tailless > max_female) {
        max_female = given[i]->length_tailless;
      }
      if (given[i]->length_tailless < min_female) {
        min_female = given[i]->length_tailless;
      }
      if (temp_tail > max_female_tail) {
        max_female_tail = temp_tail;
      }
      if (temp_tail < min_female_tail) {
        min_female_tail = temp_tail;
      }
      total_female = total_female + given[i]->length_tailless;
      total_tail_female = total_tail_female + temp_tail;
    }
    else {
      printf("Something's wrong!\n"); //Should never be reached
    }
  }
  if ((male_count != 0) && (female_count != 0)) {
  double average_male = (total_male / male_count);
  double average_female = (total_female / female_count);
  double average_tail_male = (total_tail_male / male_count);
  double average_tail_female = (total_tail_female / female_count);
  printf("Bodies(Without Tail):\n");
  printf("Males: min(adult) = %f, max = %f, average = %f, out of %d applicable.\n", min_male, max_male, average_male, male_count);
  printf("Females: min(adult) = %f, max = %f, average = %f, out of %d.\n", min_female, max_female, average_female, female_count);
  printf("\nTails:\n");
  printf("Males: min = %f, max = %f, average = %f.\n", min_male_tail, max_male_tail, average_tail_male);
  printf("Females: min = %f, max = %f, average = %f.\n", min_female_tail, max_female_tail, average_tail_female);
  }
  else {
    printf("No males or no females to analyze!\n");
  }
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
