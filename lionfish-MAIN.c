#ifndef LIONFISHMAIN 
int main();
#endif
#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include "lionfish.h"


int main() {
  printf("Welcome to Joshua E. Balan's lionfish analysis device! \n\nBefore use please read the README.md as well as the research paper of the effort to write this lovely tool! Knowlege of the research conducted to create this product is imperitive to use its operations. With that in mind, would you like to: \n\n [1]. Add new lionfish to index?\n[2].Perform operations on already-entered dataset, including exporting sorted data?\nOr\n[3].Exit the tool?\n\n**Note: type the numbers in the brackets and press ENTER to make your choice!**\n");
  int x = 0;
  char burner =  ' ';
  scanf("%d", &x);
  if (x == 3) {
    return 0;
  }
  else if (x == 1) {
    printf("Add 10 lionfish? [0/1]\n");
    scanf("%d", &x);
    int count = 10;
    if (x == 0) {
      printf("How many lionfish would you like to add to the MASTER.csv file?\n\n(Please type an integer and press ENTER...\n");
      scanf("%d", &count);
    }
    int table = 0;
    printf("How many lionfish are there on the table total? (Not just the ones being dissected!)\n");
    scanf("%d", &table);
    float conf = (float)count / table;
    printf("Assigning a confidence index of %.2f to these fish. OK?\n\n[press ENTER to continue...]\n", conf);
    scanf("%c", burner);
    int breaker = 0;
    unsigned int day = 0;
    unsigned int month = 0;
    unsigned int year = 0;
    while (breaker == 0) {
      printf("What is today's date? Please reply in MM/DD/YYYY!\n");
      int c = scanf("%d/%d/%d", &month, &day, &year);
      if (c != 3) {
        printf("Looks like something's not quite right with the date you entered. Please try again!\n\n[Press ENTER to continue...]");
        scanf("%c", &burner);
      }
      else {
        breaker = 1;
      }
    }
    lionfish_t ** new_list = malloc(sizeof(struct lionfish) * count);
    assert(new_list != NULL);
    float with_tail = 0.0;
    float tailless = 0.0;
    int noodles = 0;
    int beard = 0;
    int eggs = 0;
    int juv = 0;
    int sex = 0;
    for (int i = 0; i < count; i++) {
      printf("Entering lionfish #%d...[press ENTER to continue...]\n", (i + 1));
      scanf("%c", &burner);
      new_list[i]->time_caught->day = day;
      new_list[i]->time_caught->month = month;
      new_list[i]->time_caught->year = year;
      new_list[i]->confidence = conf;
      char *diet = malloc(51);
      assert(diet != NULL);
      printf("How long is this lionfish with its tail attached?\n");
      scanf("%f", &with_tail);
      new_list[i]->length_with_tail = with_tail;
      printf("How long is the lionfish without its tail?\n");
      scanf("%f", &tailless);
      new_list[i]->length_tailless = tailless;
      



