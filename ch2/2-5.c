#include <stdio.h>

int any(char s1[], char s2[]) {
  int loc = -1;
  for(int i = 0; s1[i] != '\0' && loc == -1; i++) {
    for(int j = 0; s2[j] != '\0' && loc == -1; j++) {
      if(s1[i] == s2[j])
        loc = i;
    }
  }
  return loc;
}

int main()
{
  char string[] = "the quick brown fox jumps over the lazy dog";
  char test1[] = "ezi";
  char test2[] = "t";
  char test3[] = "q";
  char test4[] = "Q";

  printf("%i\n", any(string,test1));
  printf("%i\n", any(string,test2));
  printf("%i\n", any(string,test3));
  printf("%i\n", any(string,test4));
}
