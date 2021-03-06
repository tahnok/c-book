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
  int i, sign, digit;
  char chardigit;
  sign = n;
  i = 0;
  do { /* generate digits in reverse order */
    digit = abs(n % b);
    if(digit < 10) {
      chardigit = digit + '0';
    } else {
      chardigit = (digit - 10) + 'a';
    }
    s[i++] = chardigit;
  } while (n /= b);
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
 reverse(s);
}

int main()
{
  char number[1000];
  int n = 1;
  int base = 16;
  itob(n, number, base);
  printf("%d, %s\n", n, number);

}
