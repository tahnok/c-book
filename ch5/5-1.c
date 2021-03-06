#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
/* getint: get next integer from input into *pn */

int getint(int *pn)
{
  int c, sign, i;
  while (isspace(c = getch())) /* skip white space */ ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c); /* it is not a number */
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
    c = getch();
  for(i = 0, *pn = 0; isdigit(c); i++, c = getch()) {
    *pn = 10 * *pn + (c - '0');
  }
  if (i ==0 && *pn == 0) {
    ungetch(c);
    return 0;
  }
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}
