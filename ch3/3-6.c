#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void reverse(char toreverse[])
{
  int pos, i, j;
  pos = 0;
  char temp;
  while(toreverse[pos++] != '\0');
  pos--;
  for(i = 0; i < pos / 2; i++) {
    j = pos - i - 1;
    temp = toreverse[i];
    toreverse[i] = toreverse[j];
    toreverse[j] = temp;
  }
}

/* itoa: convert n to characters in s of width w */
void itoa(int n, char s[], int w)
{
  int i, sign;
  sign = n;
  i = 0;
  do { /* generate digits in reverse order */
    s[i++]= abs(n % 10) +'0'; /*getnextdigit*/
    w--;
  } while (n /= 10);
  if (sign < 0)
    s[i++] = '-';
  while(w--)
    s[i++] = ' ';
  s[i] = '\0';
 reverse(s);
}

int main()
{
  char number[1000];
  int n = 400;
  int width = 5;
  itoa(n, number, width);
  printf("%d, %s\n", n, number);
}
