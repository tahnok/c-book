#include <stdio.h>

/* print Celsius-Fahrenheit table
 fahr = 0,20, ..., 300 */

main ()
{
  float fahr, celsius;
  float lower, upper, step;

  lower = 0;      /* lower limit temperature scale */
  upper = 300;    /* upper limit */
  step = 20;      /* step size */

  fahr = lower;
  printf("  c |    f \n");
  printf("-----------\n");
  while (celsius <= upper) {
    fahr = (celsius * (9.0 / 5.0)) + 32.0;
    printf("%3.0f %6.1f\n", celsius, fahr);
    celsius = celsius + step;
  }
}
