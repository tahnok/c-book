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

void itob(int n, char s[], int b)
{
  int i, sign;
  sign = n;
  i = 0;
  do { /* generate digits in reverse order */
    s[i++]= abs(n % b) +'0'; /*getnextdigit*/
  } while (n /= b);
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
 reverse(s);
}

int main()
{
  char number[1000];
  int n = 9;
  itob(n, number, 16);
  printf("%d, %s\n", n, number);

}
