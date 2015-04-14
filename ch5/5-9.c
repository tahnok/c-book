#include <stdio.h>

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
  int i, leap;
  char *p;

  leap = year%4 == 0 && (year%100 != 0 || year%400 == 0);
  p = &daytab[leap][1];
  for (i = 1; i < month; i++) {
    day += *p;
    p++;
  }
  return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday) {
  int i, leap;
  char *p;
  leap = year%4 == 0 && (year%100 != 0 || year%400 == 0);

  p = &daytab[leap][1];
  for (i = 1; yearday > daytab[leap][i]; i++) {
    yearday -= *p;
    p++;
  }
  *pmonth = i;
  *pday = yearday;
}

int main()
{
  printf("%d\n", day_of_year(2015, 4, 14));
  int day, month;
  month_day(2015, 104, &day, &month);
  printf("%d %d\n", day, month);

}
