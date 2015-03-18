#include <stdio.h>
#include "calc.h"
#include <ctype.h>

int getop(char s[])
{
  int i, c;
  static int leftover_used = 0;
  static int leftover;

  if (leftover_used) {
    leftover_used = 0;
    c = leftover
  } else {
    c = getch();
  }

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;

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
    leftover_used = 1;
  }
  return NUMBER;
}
