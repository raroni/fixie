#include "Orwell.h"
#include "Fixie/Util.h"

namespace UtilTest {
  using namespace Orwell::Assertions;
  using namespace Fixie;

  void testFloor() {
    Num a;

    a = Util::floor(2.5);
    assertEqual(2, a);

    a = Util::floor(9.9);
    assertEqual(9, a);

    a = Util::floor(-2.3);
    assertEqual(-3, a);
  }

  void testSqrt() {
    Num a;

    a = Util::sqrt(25);
    assertEqual(5, a);

    a = Util::sqrt(2);
    assertInDelta(1.4142, 0.001, a);

    a = Util::sqrt(99);
    assertInDelta(9.9498, 0.001, a);
  }

  void setup() {
    unsigned group = Orwell::createGroup("FixieUtilTest");
    Orwell::addTest(group, testFloor, "floor");
    Orwell::addTest(group, testSqrt, "sqrt");
  }
}
