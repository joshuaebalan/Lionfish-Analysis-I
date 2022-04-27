#ifndef LIONFISH-TEST_H
#define LIONFISH-TEST_H

#define OK	(0)
#define MALE	(1)
#define FEMALE  (2)

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
} time_t; 

int main();
int relate_time(lionfish_t *, lionfish_t *);
int compile_time(time_t *);

