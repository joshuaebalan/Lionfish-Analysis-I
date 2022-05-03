#ifndef LIONFISH_H
#define LIONFISH_H

/* named constants */

#define OK	(0)  //returned on proper function execution
#define LATER   (2) //See 'relate_time()'
#define EQUAL	(3) //See 'relate_time()'
#define EARLIER (4) //See 'relate_time()'
#define MALE (101)
#define FEMALE (102)
#define UNIDENTIFIED (103)

/* mode sepcifiers for group_time() */
#define YEAR (2000) //search for fish in specified year
#define MONTH (2001) //search for fish in specified month
#define DAY (2002) //search for fish in specified day

/* error codes */
#define UH_OH   (-1) //if a point in the program is reached that shouldn't be
#define BAD_TBL_READ (-2) //error in reading a text(i.e. CSV) file
#define BAD_TBL_WRITE (-3) //error in writing to a text file in tables form.
#define BAD_BIN_READ (-4) //error in reading from a binary file
#define BAD_BIN_WRITE (-5) //error in writing to a binary file
#define NO_FISH_FOUND (-6) //if a search function can't find anything

/* applicable structures */
typedef struct lionfish {
  int sex;
  char *diet;
  float length;
  float mass;
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
int group_time(int, unsigned int, int, lionfish_t**, lionfish_t***);
/* functions inside lionfish_IO.c */

lionfish_t **read_table_file(char *);
#endif //LIONFISH_H
