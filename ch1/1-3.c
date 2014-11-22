#include <stdio.h>

/* print Fahrenheit-Celsius table
 fahr = 0,20, ..., 300 */

main ()
{
  float fahr, celsius;
  float lower, upper, step;

  lower = 0;      /* lower limit temperature scale */
  upper = 300;    /* upper limit */
  step = 20;      /* step size */

  fahr = lower;
  printf("  f |    c \n");
  printf("-----------\n");
  while (fahr <= upper) {
    celsius = (5.0 / 9.0) * (fahr-32.0);
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}
