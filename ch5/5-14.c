#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../libs/readlines.c"
#include "../libs/writelines.c"
#include "../libs/reverselines.c"

#define MAXLINES 5000 /* max #lines to be sorted */
char *lineptr[MAXLINES]; /* pointers to text lines */


int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void reverselines(char *lineptr[], int nlines);
void qsort2(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);

/* sort input lines */
int main(int argc, char *argv[])
{
  int nlines; /* number of input lines read */
  int numeric = 0; /* 1 if numeric sort */
  int reverse = 0; /* 1 if reverse sort */

  if (argc >= 2) {
    while(argc--) {
      if(strcmp(argv[argc], "-n") == 0)
        numeric = 1;
      if(strcmp(argv[argc], "-r") == 0)
        reverse = 1;
    }
  }
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
  {
    qsort2((void**) lineptr, 0, nlines-1,
        (int (*)(void*,void*))(numeric ? numcmp : strcmp));
    if(reverse)
      reverselines(lineptr, nlines);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("input too big to sort\n");
    return 1;
  }
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort2(void *v[], int left, int right,
    int (*comp)(void *, void *))
{
  int i, last;
  void swap(void *v[], int, int);
  if (left >= right)     /* do nothing if array contains */
    return;              /* fewer than two elements */
  swap(v, left, (left +  right)/2);
  last = left;
  for (i = left+1; i <= right; i++)
    if ((*comp)(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort2(v, left, last-1, comp);
  qsort2(v, last+1, right, comp);
}

void swap(void *v[], int i, int j) {
  void *temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

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

