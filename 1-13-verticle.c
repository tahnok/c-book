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

  int max_val = 0;
  for(int i = 1; i < 20; i++) {
    if(histogram[i] > max_val) {
      max_val = histogram[i];
    }
  }

  printf("max val %d", max_val);
  printf("Histogram:\n");
  for(int height = max_val; height > 0; height--) {
    for(int i = 1; i < 20; i++) {
      if(histogram[i] >= height) {
        putchar('0' + i);
      } else {
        putchar(' ');
      }
      putchar(' ');
    }
    putchar('\n');
  }
  putchar('\n');
  for(int i = 1; i < 20; i++) {
    printf("length %2d:", i);
    for(int j = 0; j < histogram[i]; j++) {
      putchar('*');
    }
    putchar('\n');
  }
}
