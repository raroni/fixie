#include "Orwell.h"
#include "Fixie/Matrix4.h"

namespace Matrix4Test {
  using namespace Orwell::Assertions;
  using namespace Fixie;

  void testSetGet() {
    Matrix4 m;
    m[0] = 3;
    assertEqual(3, m[0]);

    m[1] = -6;
    assertEqual(-6, m[1]);

    m[2] = 5.4;
    assertInDelta(5.4, 0.002, m[2]);

    m[3] = 0;
    assertEqual(0, m[3]);

    m[4] = Num(99);
    assertEqual(99, m[4]);
  }

  void testIdentity() {
    Matrix4 m = Matrix4::identity();
    assertEqual(1, m[0]);
    assertEqual(0, m[1]);
    assertEqual(0, m[2]);
    assertEqual(0, m[3]);
    assertEqual(0, m[4]);
    assertEqual(1, m[5]);
    assertEqual(0, m[6]);
    assertEqual(0, m[7]);
    assertEqual(0, m[8]);
    assertEqual(0, m[9]);
    assertEqual(1, m[10]);
    assertEqual(0, m[11]);
    assertEqual(0, m[12]);
    assertEqual(0, m[13]);
    assertEqual(0, m[14]);
    assertEqual(1, m[15]);
  }

  void testMultiplication() {
    Matrix4 a(4, 64, 5, 8, 87, 32, -1, 2, 2, 8, 4, 0, 3, -5, 9, 1);
    Matrix4 b(23, 5, 5, 3, 4, 7, 44, 3, 9, 5, -9, 7, 7, 6, 0, 5);
    Matrix4 r = a*b;

    assertEqual(546, r[0]);
    assertEqual(1657, r[1]);
    assertEqual(157, r[2]);
    assertEqual(197, r[3]);
    assertEqual(722, r[4]);
    assertEqual(817, r[5]);
    assertEqual(216, r[6]);
    assertEqual(49, r[7]);
    assertEqual(474, r[8]);
    assertEqual(629, r[9]);
    assertEqual(67, r[10]);
    assertEqual(89, r[11]);
    assertEqual(565, r[12]);
    assertEqual(615, r[13]);
    assertEqual(74, r[14]);
    assertEqual(73, r[15]);
  }

  void setup() {
    unsigned group = Orwell::createGroup("FixieMatrix4Test");
    Orwell::addTest(group, testSetGet, "SetGet");
    Orwell::addTest(group, testIdentity, "Identity");
    Orwell::addTest(group, testMultiplication, "Multiplication");
  }
}
