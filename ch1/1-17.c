#include <stdio.h>
#define MAXLENGTH 1000

int getline2(char line[], int maxline);

main()
{
  int len;
  char line[MAXLENGTH];
  char longest[MAXLENGTH];

  while ((len = getline2(line, MAXLENGTH)) > 0)
  {
    if (len > 80) {
      printf("%s", line);
    }
  }
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
