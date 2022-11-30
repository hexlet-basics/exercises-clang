#include <stdio.h>

void km_to_mi(void) {
  // BEGIN
  float km, mi;
  float lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  km = lower;

  while (km <= upper) {
    mi = km * 0.621;
    printf("%.2f : %.2f\n", km, mi);
    km = km + step;
  }
  // END
}
