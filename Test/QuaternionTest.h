#include "Orwell.h"
#include "Fixie/Quaternion.h"

namespace QuaternionTest {
  using namespace Orwell::Assertions;
  using namespace Fixie;

  void testInit() {
    Quaternion q(1, { 2, 3, 4 });
    assertEqual(1, q.real);
    assertEqual(2, q.imaginaries[0]);
    assertEqual(3, q.imaginaries[1]);
    assertEqual(4, q.imaginaries[2]);
  }

  void testIdentity() {
    Quaternion q = Quaternion::identity();
    assertEqual(1, q.real);
    assertEqual(0, q.imaginaries[0]);
    assertEqual(0, q.imaginaries[1]);
    assertEqual(0, q.imaginaries[2]);
  }

  void setup() {
    unsigned group = Orwell::createGroup("FixieQuaternionTest");
    Orwell::addTest(group, testInit, "Init");
    Orwell::addTest(group, testIdentity, "Identity");
  }
}
