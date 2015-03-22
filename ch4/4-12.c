#include <stdio.h>
#include <stdlib.h>

/* itoa: convert n to characters in s */
void itoa2(int n, char s[])
{
  int i, sign;
  sign = n;
  i = 0;
  do { /* generate digits in reverse order */
    s[i++]= abs(n % 10) +'0'; /*getnextdigit*/
  } while (n /= 10);
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
 reverse(s);
}

void printd(int n)
{
  if (n < 0) {
    putchar('-');
    n = -n;
  }

  if (n / 10)
    printd(n / 10);
  putchar(n % 10 + '0');
}

void itoa(int n, char s[])
{
  //todo
}

int main()
{
  char temp[100];
  int i = 20;
  itoa(i, temp);
  printf("%s\n", temp);
}
