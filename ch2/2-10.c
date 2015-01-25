
#include <stdio.h>

char lower(char input) {
  return (input >= 'A' && input <= 'Z') ? input - 'A' + 'a' : input;
}

int lower2(int c)
{
  if (c >= 'A' && c <= 'Z')
    return c + 'a' - 'A';
  else
    return c;
}

int main()
{
  for(int i = 0; i < 26; i++)
    printf("%c : %c\n", i+'A', lower(i+'A'));
}
