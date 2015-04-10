#ifndef FIXIE_QUATERNION_H
#define FIXIE_QUATERNION_H

#include "Fixie/Num.h"
#include "Fixie/Vector3.h"

namespace Fixie {
  class Quaternion {
  public:
    Quaternion();
    Quaternion(Num real, Vector3 imaginaries);
    Num real;
    Vector3 imaginaries;
    static Quaternion identity();
  };
}

#endif
