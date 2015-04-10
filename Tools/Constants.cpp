#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "Fixie/Num.h"

int main() {
  const Fixie::Num pi = M_PI;
  const Fixie::Num twoPi = M_PI*2;
  const Fixie::Num halfPi = M_PI*0.5;
  const Fixie::Num inverseTwoPi = 1.0 / (M_PI*2.0);

  printf("pi: %d\n", pi.raw);
  printf("twoPi: %d\n", twoPi.raw);
  printf("halfPi: %d\n", halfPi.raw);
  printf("inverseTwoPi: %d\n", inverseTwoPi.raw);
}
