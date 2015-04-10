#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "Fixie/Num.h"

int main() {
  static const uint16_t precision = 1024;
  for(uint16_t i=0, j=1; i<precision; ++i, ++j) {
    double input = (static_cast<double>(i)/1024.0)*2-1;
    double arcCosine = acos(input);
    Fixie::Num num = arcCosine;
    printf("%d,", num.raw);
    if(i != precision-1) {
      if(j != 8) {
        printf(" ");
      } else {
        j = 0;
        printf("\n");
      }
    }
  }
  printf("\n0\n");
}
