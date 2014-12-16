#include <stdio.h>
#define TAB_SIZE 2

main()
{
  int c;
  while((c = getchar()) != EOF) {
    if (c == '\t') {
      for(int i = 0; i < TAB_SIZE; i++) {
        putchar(' ');
      }
    } else {
      putchar(c);
    }
  }

}
