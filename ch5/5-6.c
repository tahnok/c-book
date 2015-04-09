#include <stdio.h>
#include <string.h>
#define MAXLINES 5000 /* max #lines to be sorted */
char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines, char line[], int line_size);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

#define MAXLEN 1000 /* max length of any input line */
/* sort input lines */
int main()
{
  int nlines; /* number of input lines read */
  char line[MAXLEN];
  if ((nlines = readlines(lineptr, MAXLINES, line, MAXLEN)) >= 0) {
    qsort(lineptr, 0, nlines-1);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("error: input too big to sort\n"); return 1;
  }
}

char *alloc(int);

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

//Rewrite readlines to store lines in an array supplied by main,
//rather than calling alloc to maintain storage. How much faster is the program?

int readlines(char *lineptr[], int maxlines, char line[], int line_size) {
  int len, nlines;
  char *p;
  nlines = 0;
  while ((len = getline2(line, MAXLEN)) > 0)
    if (nlines >= maxlines)
      return -1;
    else {
      line[len-1] = '\0'; /* delete newline */ strcpy(p, line);
      lineptr[nlines++] = p;
    }
  return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines) {
  int i;
  for (i = 0; i < nlines; i++)
    printf("%s\n", lineptr[i]);
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
  int i, last;
  void swap(char *v[], int i, int j);
  if (left >= right) /* do nothing if array contains */
    return; /* fewer than two elements */
  swap(v, left, (left + right)/2); last = left;

  for (i = left+1; i <= right; i++)
    if (strcmp(v[i], v[left]) < 0)
      swap(v, ++last, i); swap(v, left, last);
  qsort(v, left, last-1);
  qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
  char *temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
