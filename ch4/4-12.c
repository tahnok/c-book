#include <stdio.h>
#include <stdlib.h>

int itoa(int n, char s[])
{
  int offset = 0;
  if( n / 10) {
    offset = itoa(n / 10, s);
  } else {
    if (n < 0) {
      s[offset++] = '-';
    }
  }


  s[offset++] = abs(n) % 10 + '0';
  s[offset] = '\0';
  return offset;
}

int main()
{
  char temp[100];
  int i = 24128410;
  itoa(i, temp);
  printf("%s\n", temp);
}
