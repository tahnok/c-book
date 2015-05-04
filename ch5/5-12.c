#include <stdio.h>
#define TAB_SIZE 2

int main(int argc, char *argv[])
{
  char tabstops[100];
  int offset = 0;

  if (argc > 1) {
    argc--;
    argv++;
    while(argc) {
      tabstops[offset++] = *argv[0];
      argc--;
      argv++;
    }
    offset = '\0';
  } else {
    tabstops[0] = '\t';
    tabstops[1] = '\0';
  }

  int c;
  int found;
  while((c = getchar()) != EOF) {
    offset = 0;
    found = 0;
    while(tabstops[offset] != '\0') {
      if (c == tabstops[offset++]) {
        found = 1;
        break;
      }
    }
    if (found) {
      for(int i = 0; i < TAB_SIZE; i++) {
        putchar(' ');
      }
    } else {
      putchar(c);
    }
  }

}
