#include <stdio.h>
#include <stdlib.h>

void error(char *msg) {
  printf("%s\n", msg);
  exit(-1);
}

int main(int argc, char **argv)
{
  int num_lines;
  if (argc == 1) {
    num_lines = 10;
  } else if (argc == 2) {
    argv++;
    if (**argv != '-') {
      error("invalid format: use -n where n is number of lines to show");
    }
    (*argv)++;
    num_lines = atoi(*argv);
    if (num_lines < 1) {
      error("must provide a positive number of lines to buffer\n");
    }
  } else {
    error("DERP\n");
  }

  char lines[num_lines][100];

  int counter = 0;
  while(fgets(lines[counter], 100, stdin) != NULL) {
    counter = (counter + 1) % num_lines;
  }
  for(int i; i < num_lines; i++) {
    printf("%s", lines[counter]);
    counter = (counter + 1) % num_lines;
  }
}
