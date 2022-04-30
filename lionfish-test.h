#ifndef LIONFISH_TEST_H
#define LIONFISH_TEST_H

/* named constants */

#define OK	(0)  //returned on proper function execution
#define LATER   (2) //See 'relate_time()'
#define EQUAL	(3) //See 'relate_time()'
#define EARLIER (4) //See 'relate_time()'

/* error codes */

#define UH_OH   (-1) //if a point in the program is reached that shouldn't be
#define BAD_TBL_READ (-2) //error in reading a text(i.e. CSV) file
#define BAD_TBL_WRITE (-3) //error in writing to a text file in tables form.
#define BAD_BIN_READ (-4) //error in reading from a binary file
#define BAD_BIN_WRITE (-5) //error in writing to a binary file

typedef struct lionfish {
  enum {MALE, FEMALE, UNIDENTIFIED} sex;
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
/* functions inside lionfish-test.c */

int main();
int relate_time(catch_t *, catch_t *);

/* functions inside lionfish_file_conv.c */
#endif //LIONFISH_TEST_H
