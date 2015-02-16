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

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
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

void printbits(unsigned int counter)
{
  for(int x = 0; x < 33; x++){
    printf("%u", (counter >> (32 - x)) & 1);
  }
  printf(": %u", counter);
  printf("\n");
}

int main()
{
  char number[1000];
  itoa(INT_MIN, number);
  printf("%d, %s\n", INT_MIN, number);
}

/*
 * problem is that -INT_MIN == INT_MIN
 * since -INT_MIN is larger than INT_MAX, it stays INT_MIN
 */
