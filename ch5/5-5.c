#include <stdio.h>

void strncopy(char s[], char t[], int n)
{
  for(int i = 0; i < n; i++) {
    *s++ = *t++;
  }
  *s = '\0';
}

void strncat2(char s[], char t[], int n)
{
  while(*s++ != '\0')
    ;
  s--;
  for(int i = 0; i < n; i++) {
    *s++ = *t++;
  }
  *s = '\0';

}

int strncmp2(char s[], char t[], int n)
{
  for(int i = 0; i < n; i++) {
    if(s[i] != t[i]) {
      return s[i] - t[i];
    }
  }
  return 0;
}

int main()
{
  char foo[100];
  char bar[] = "foobar";
  strncopy(foo, bar, 2);
  printf("%s\n", foo);
  strncopy(foo, bar, 6);
  printf("%s\n", foo);

  strncat2(foo, bar, 2);
  printf("%s\n", foo);
  strncat2(foo, bar, 6);
  printf("%s\n", foo);

  int n = strncmp2(foo, bar, 2);
  printf("%d\n", n);
  n = strncmp2(foo, bar, 6);
  printf("%d\n", n);
  n = strncmp2(foo, bar, 12);
  printf("%d\n", n);
}
