#include <stdio.h>

main()
{
  int c, state, wordlength;
  int histogram[20];
  c = state = wordlength = 0;
  for(int i = 0; i < 20; i++) {
    histogram[i] = 0;
  }

  while((c = getchar()) != EOF) {
    if(c == ' ' || c == '\n' || c == '\t') {
      histogram[wordlength]++;
      wordlength = 0;
    } else {
      ++wordlength;
    }
  }

  printf("Histogram:\n");
  for(int i = 1; i < 20; i++) {
    printf("length %2d:", i);
    for(int j = 0; j < histogram[i]; j++) {
      putchar('*');
    }
    putchar('\n');
  }
}
