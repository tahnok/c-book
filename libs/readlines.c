#include <strings.h>
#include <stdlib.h>

#include "getline2.c"

#define MAXLEN 5000

int readlines(char *lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];
  nlines = 0;
  while ((len = getline2(line, MAXLEN)) > 0)
    if (nlines >= maxlines || (p = malloc(len)) == NULL)
      return -1;
    else {
      line[len-1] = '\0'; /* delete newline */ strcpy(p, line);
      lineptr[nlines++] = p;
    }
  return nlines;
}
