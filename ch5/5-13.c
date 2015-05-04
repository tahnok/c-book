#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  int num_lines;
  if (argc == 1) {
    num_lines = 10;
  } else if (argc == 2) {
    argv++;
    num_lines = atoi(*argv);
    if (num_lines < 1) {
      printf("must provide a positive number of lines to buffer\n");
      exit(1);
    }
  } else {
    printf("DERP\n");
    exit(1);
  }

  char lines[num_lines][100];

  int counter = 0;
  while(fgets(lines[counter], 100, stdin) != NULL) {
    counter = counter + 1 % num_lines;
  }
  int old_counter = counter;
  counter++;
  while(old_counter != counter) {
    printf("%s\n", lines[counter]);
    counter = counter + 1 % num_lines;
  }
}
