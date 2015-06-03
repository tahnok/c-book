#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* max #lines to be sorted */
char *lineptr[MAXLINES]; /* pointers to text lines */


int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort2(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);

/* sort input lines */
int main(int argc, char *argv[])
{
  int nlines; /* number of input lines read */
  int numeric = 0; /* 1 if numeric sort */
  int reverse = 0; /* 1 if reverse sort */

  if (argc > 1) {
    while(argc--) {
      printf("argv: %d\n", argc);
    }
  }
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
  {
    qsort2((void**) lineptr, 0, nlines-1,
        (int (*)(void*,void*))(numeric ? numcmp : strcmp));
    writelines(lineptr, nlines);
    return 0;
  } else
  {
    printf("input too big to sort\n"); return 1;
  }
}

#include <stdlib.h>
/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
  double v1, v2;
  v1 = atof(s1);
  v2 = atof(s2);
  if (v1 < v2)
    return -1;
  else if (v1 > v2)
    return 1;
  else
    return 0;
}

void swap(void *v[], int i, int j) {
  void *temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
