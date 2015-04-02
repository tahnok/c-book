#include <stdio.h>
#include <string.h>

int strend(char *s, char *t)
{
  int len = strlen(t);
  while(*s++)
    ;
  printf("%s, %s\n", s, t);
  for( ; *s ; s++, t++) {
    if (*s != *t) {
      return 0;
    }
  }
  return 1;
}

int main()
{
  char foobar[] = "foobar";
  char foo[] = "foo";
  char bar[] = "bar";
  printf("should be 0: %d\n", strend(foobar, foo));
  printf("should be 1: %d\n", strend(foobar, bar));

}
