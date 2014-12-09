#include <stdio.h>
#define MAX 1000

void reverse(char to[], char from[], int len);
int getline2(char line[], int maxline);
void copy(char to[], char from[]);

main()
{
  unsigned int len;
  unsigned int max;
  char line[MAX];
  char reversed[MAX];

  max = 0;
  while ((len = getline2(line, MAX)) > 0)
  {
    reverse(reversed, line, len);
    printf("%s", reversed);
  }
}

void reverse(char to[], char from[], int len)
{
  int pos;
  for(pos = 0; pos < len; pos++) {
    to[pos] = from[len - 1 - pos];
  }
}

/* getline2: read a line into s, return length */
int getline2(char s[], int lim)
{
  int c, i;

  for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    s[i] = c;
  if (c == '\n'){
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void copy(char to[], char from[])
{
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
