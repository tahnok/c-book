#include <stdio.h>
#define MAXLENGTH 1000

int getline2(char line[], int maxline);
void copy(char to[], char from[]);
int clean(char string[], int length);

main()
{
  int len;
  int cleaned_len;
  char line[MAXLENGTH];
  char longest[MAXLENGTH];

  cleaned_len = 0;
  while ((len =  getline2(line, MAXLENGTH)) > 0)
  {
    if(clean(line, len) > 0)
      printf("%s", line);
  }
  return 0;
}

/* getline2: read a line into s, return length */
int getline2(char s[], int lim)
{
  int c, i;
  int char_yet = 0;

  for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    s[i] = c;
  if (c == '\n'){
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

int clean(char string[], int length)
{
  char current;
  for(int pos = length - 2; pos > 0; pos--) {
    current = string[pos];
    if(current == ' ' || current == '\t') {
      string[pos] = '\n';
      string[pos+1] = '\0';
      length--;
    } else {
      return length;
    }
  }
  return length;
}
