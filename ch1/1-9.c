#include <stdio.h>

main()
{
  int c, seen_space = 0;
  while((c = getchar()) != EOF) {
    if(c == ' ') {
      if(seen_space) {
        continue;
      }
      else {
        seen_space = 1;
      }
    }
    else {
      seen_space = 0;
    }
    putchar(c);
  }
}
