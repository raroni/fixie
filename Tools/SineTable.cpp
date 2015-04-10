#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "Fixie/Num.h"

int main() {
  static const uint16_t degress = 1024;
  for(uint16_t i=0, j=1; i<degress; ++i, ++j) {
    double angle = (static_cast<double>(i)/degress) * 2 * M_PI;
    double sine = sin(angle);
    Fixie::Num num = sine;
    printf("%d", num.raw);
    if(i != degress-1) {
      printf(",");
      if(j != 8) {
        printf(" ");
      } else {
        j = 0;
        printf("\n");
      }
    }
  }
  printf("\n");
}
