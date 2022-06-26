#include "lionfish.h"


int main() {
  printf("\n\nWelcome to Joshua E. Balan's lionfish analysis device! \n\nBefore use please read the README.md as well as the research paper of the effort to write this lovely tool! Knowlege of the research conducted to create this product is imperitive to use its operations. With that in mind, would you like to: \n\n[1]. Add new lionfish to index?\n[2].Perform operations on already-entered dataset, including exporting sorted data?\nOr\n[3].Exit the tool?\n\n**Note: type the numbers in the brackets and press ENTER to make your choice!**\n");
  int x = 0;
  char burner =  ' ';
  scanf("%d", &x);
  if (x == 3) {
    return 0;
  }
  else if (x == 2) {
    printf("This function is not built yet! Please pardon our dust and come back later!\n");
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
    scanf("%c", &burner);
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
    int verif = 0;
    char diet[51] = { 0 };
    int finalconf = 0;
    for (int i = 0; i < count; i++) {
      while (finalconf == 0) {
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
        printf("How long is the lionfish without its tail?\n");
        scanf("%f", &tailless);
        while (breaker == 1) {
          printf("Does this fish have supraorbital tentacles(\"noodles\")? [0/1]\n");
          scanf("%d", &noodles);
          printf("Does this fish have a beard? [0/1]\n");
          scanf("%d", &beard);
          if (beard == 1) {
            printf("This is a male[sex 2] fish, so eggs will be marked with a 0. Is this correct? [0/1]\n");
            scanf("%d", &verif);
            if (verif != 0) {
              //eggs is already 0!
              sex = 2;
            }
            else {
              printf("Does this fish have an egg sac? [0/1]\n");
              scanf("%d", &eggs);
              printf("What sex is the fish? [2/3]\n");
              scanf("%d", &sex);
            }
          }
          if (beard == 0) {
            printf("This is a female[sex 3] fish, so eggs will be marked with a 1. Is this correct? [Press 0 to object, otherwise press any other key to continue...]\n");
            scanf("%d", &verif);
            if (verif != 0) {
              eggs = 1;
              sex = 2;
            }
            else {
              printf("Does this fish have an egg sac? [0/1]\n");
              scanf("%d", &eggs);
              printf("What sex is the fish? [2/3]\n");
              scanf("%d", &sex);
            }
          }
          if (((sex != 2) && (sex != 3)) || ((eggs != 0) && (eggs != 1)) || ((beard != 0) && (beard != 1))) {
            printf("Looks like there was an issue with the input in this step. Let's try again!\n");
          }
          else {
            breaker = 0;
          }
        }
        printf("Is this fish considered juvenile?[0/1]\n");
        scanf("%d", &juv);
        printf("Finally, please describe the stomach contents of lionfish #%d.\n", i);
        scanf("%50s\n", diet);
        printf("You have listed that lionfish #%d has:\nLength with tail %.2f;\nLength without %.2f;\nNoodle value %d;\nBeard value %d;\nSex value %d;\nEgg value %d;\nJuvenile status %d;\nDiet description of \"%s\".\n\n If all of the following is correct, press [1]. If not, press [0] to reset this fish.\n", i, with_tail, tailless, noodles, beard, sex, eggs, juv, diet);
        scanf("%d",  &finalconf);
      }
      if (finalconf != 0) {
        new_list[i]->has_noodles = noodles;
        new_list[i]->has_eggs = eggs;
        new_list[i]->has_beard = beard;
        new_list[i]->length_tailless = tailless;
        new_list[i]->juvenile = juv;
        new_list[i]->length_with_tail = with_tail;
        strcpy(new_list[i]->diet, diet);
        new_list[i]->sex = sex;
        printf("Data successfully entered for lionfish #%d!\n", i);
      }
      append_to_master(new_list, "test.csv", count);
    }
    printf("Press any key to exit!\n");
    scanf("%c", &burner);
    return 1;
  }
}


