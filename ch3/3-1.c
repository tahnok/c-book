#include <stdio.h>
#include <time.h>

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
  int low, high, mid;
  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low+high) / 2;
    if (x < v[mid])
      high = mid - 1;
    else if (x > v[mid])
      low = mid + 1;
    else    /* found match */
      return mid;
  }
  return -1; /* no match */
}

int binsearch2(int x, int v[], int n)
{
  int low, high, mid;
  low = 0;
  high = n - 1;
  while (low <= high && v[mid] != x) {
    if (x < v[mid])
      high = mid - 1;
    else
      low = mid + 1;
    mid = (low+high) / 2;
  }
  return v[mid] == x ? mid : -1;
}

int main()
{
  int array_size = 100000;
  int array[array_size];
  clock_t time_taken;
  for(int i = 0; i < array_size; i++)
    array[i] = i;

  time_taken = clock();
  for(int i = 0; i < array_size; i++)
    binsearch(i, array, array_size);
  printf("binsearch took %lu clocks\n", clock() - time_taken);

  time_taken = clock();
  for(int i = 0; i < array_size; i++)
    binsearch2(i, array, array_size);
  printf("binsearch2 took %lu clocks\n", clock() - time_taken);
}


/*
 * Our binary search makes two tests inside the loop,
 * when one would suffice (at the price of more tests outside.)
 * Write a version with only one test inside the loop
 * and measure the difference in run-time.
 */
