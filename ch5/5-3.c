#include <stdio.h>

void strcat3(char *s, char *t)
{
  while(*s++)
    ;
  s--;
  while(*t) {
    *s++ = *t++;
  }
}

int main()
{
  char foo[100] = "foo";
  char bar[] = "bar";
  strcat3(foo, bar);
  printf("%s\n", foo);

}
