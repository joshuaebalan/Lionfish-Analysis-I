#include "lionfish.h"
#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
/*
 * This function reads in a file(note 30-04-2022: assuming data is in .csv
 * foramt, I will end up changing the key string upon aquisition of the data),
 * then returns an array of pointers to dynamically allocated lionfish_t
 * structures, unordered. Returns NULL on failure.
 */

lionfish_t **read_table_file(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }
  else {
    fseek(fp, 0L, SEEK_END);
    int f_length = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    char diet_buf[100] = { 0 };
    char sex_buf [50] = { 0 };
    float length = 0.0;
    float mass = 0.0;
    char time[200] = { 0 };
    int status = 5;
    lionfish_t **master = malloc(8 * f_length);
    assert(master != NULL); 
    int counter = 0;
    while (status == 5) {
      status = fscanf(fp, 
             "insert key: sex: %49[^ ],diet report: %99[^ ],length %f,mass %f, %199[^\n]\n",
	     sex_buf, diet_buf, &length, &mass, time);
      if ((status != 5) && (status != EOF)) {
	return NULL;
      }
      if (status == EOF) {
	return master;
      }
      lionfish_t *new = malloc(sizeof(struct lionfish));
      assert(new != NULL);
      new->length = length;
      new->mass = mass;
      new->sex = enumerate_sex(sex_buf);
      new->diet = malloc(strlen(diet_buf) + 1);
      assert(new->diet != NULL);
      strcpy(new->diet, diet_buf);
      new->time_caught = malloc(sizeof(struct time));
      assert(new->time_caught != NULL);
      new->time_caught = read_from_writing(time);
      master[counter] = new;
      counter++;
    }
    return master;
  }
}
/*
 * This set of functions preps a set of integers for graphing in an external program,
 * such as Excel or Google Sheets. One works with a single dependent variable, and one works with two.
 */
int write_csv_generated_2_param(int len, char *name, char *lbl1, char *lbl2, int *data1, int *data2) {
  FILE *fp = fopen(name, "w+");
  if (fp == NULL) {
    return BAD_TBL_WRITE;
  }
  fprintf(fp, "%s,%s\n", lbl1, lbl2);
  for (int i = 0; i < len; i++) {
    fprintf(fp, "%d,%d\n", data1[i], data2[i]);
  }
  return OK;
} /* write_csv_generated_2_param() */

int write_csv_generated_3_param(int len, char *name, char *lbl1, char *lbl2, char *lbl3, int *data1, int *data2, int *data3) {
  FILE *fp = fopen(name, "w+");
  if (fp == NULL) {
    return BAD_TBL_WRITE;
  }
  fprintf(fp, "%s,%s,%s\n", lbl1, lbl2, lbl3);
  for (int i = 0; i < len; i++) {
    fprintf(fp, "%d,%d,%d\n", data1[i], data2[i], data3[i]);
  }
  return OK;
} /* write_csv_generated_3_param() */
