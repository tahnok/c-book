#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define MAX 10

int getch(void);
void ungetch(int);
/* getint: get next integer from input into *pn */

int getfloat(float *pn)
{
  int c, sign, i;
  float fractional = 0.0;
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
  if (i == 0 && *pn == 0) {
    ungetch(c);
    return 0;
  }
  if (c == '.') {
    c = getch();
    for(i = 0, fractional = 0.0; isdigit(c); i++, c = getch()) {
      fractional = 10 * fractional + (c - '0');
    }
    *pn = *pn + (fractional / pow(10.0, i));
  }

  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}

int main()
{
  float f;
  getfloat(&f);
  printf("%f\n", f);
}


int bufp = 0;
int buf[MAX];

int getch(void)
{
    return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp < MAX)
          buf[bufp++] = c;
}
