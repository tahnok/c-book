#include <stdio.h>
#include "calc.h"
#include <ctype.h>

int getop(char s[])
{
  int i, c;
  static int leftover = EOF;;

  if (leftover != EOF) {
    c = leftover;
    leftover = EOF;
  } else {
    c = getch();
  }

  while (c == ' ' || c == '\t') {
    c = getch();
  }

  s[0] = c;
  s[1] = '\0';
  if (!isdigit(c) && c != '.')
    return c;
  i = 0;
  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if (c != EOF) {
    leftover = c;
  }
  return NUMBER;
}
