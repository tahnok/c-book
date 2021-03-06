#include <stdio.h>
#include <limits.h>

int getline2(char line[], int maxline);
void copy(char to[], char from[]);

main()
{
  unsigned int len;
  unsigned int max;
  char line[UINT_MAX];
  char longest[UINT_MAX];

  max = 0;
  while ((len = getline2(line, UINT_MAX)) > 0)
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  if (max > 0)
    printf("Longest line is %d chars\n", max);
    printf("It is:\n%s", longest);
  return 0;
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
