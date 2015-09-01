/* in place reveral of an array of strings */
void reverselines(char *lineptr[], int numlines)
{
  char *temp;
  int i;
  int opposite;

  for (i = 0; i < numlines; i++) {
    opposite = numlines - i;
    temp = lineptr[i];
    lineptr[i] = lineptr[opposite];
    lineptr[opposite] = temp;
  }
}
