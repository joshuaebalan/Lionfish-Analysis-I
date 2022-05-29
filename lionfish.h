#ifndef LIONFISH_H
#define LIONFISH_H

/* named constants */

#define OK	(10000)  //returned on proper function execution
#define NO (0) //See README.md
#define YES (1) //See README.md
#define MALE   (2) //See README.md
#define FEMALE	(3) //See 'README.md'
#define EARLIER (4) //See 'relate_time()'
#define LATER (5) //See 'relate_time()'
#define EQUAL (6) //See 'relate_time()'
/* error codes */

#define DIGESTED (-1) //See README.md
#define UH_OH   (-10000) //if a point in the program is reached that shouldn't be
#define BAD_TBL_READ (-2) //error in reading a text(i.e. CSV) file
#define BAD_TBL_WRITE (-3) //error in writing to a text file in tables form.
#define BAD_BIN_READ (-4) //error in reading from a binary file
#define BAD_BIN_WRITE (-5) //error in writing to a binary file

typedef struct lionfish {
  int sex;
  char *diet;
  float length_with_tail;
  float length_tailless;
  int has_noodles;
  int has_eggs;
  int has_beard;
  int juvenile;
  float confidence;
  struct time *time_caught;
} lionfish_t;

typedef struct time {
  unsigned int year;
  unsigned int month;
  unsigned int day;
} catch_t; 
/* functions inside lionfish.c */

int main();
int relate_time(catch_t *, catch_t *);
int enumerate_sex(char *);
catch_t *read_from_writing(char *);

double compute_noodle_percentage(lionfish_t**, int);
double compute_noodle_percentage_by_fish_size_and_sex(lionfish_t**, int, double, int, int* );
double compute_female_percentage_by_time(lionfish_t**, int, int, int, int*);
void calculate_length_data(lionfish_t**, int);
/* functions inside lionfish_IO.c */

lionfish_t **read_table_file(char *);
int write_csv_noodle_dist_with_sex(lionfish_t**, char*, int);
int write_csv_sex_dist(lionfish_t**, char*);
#endif //LIONFISH_H
