#include "Orwell.h"
#include "Fixie/Vector3.h"

namespace Vector3Test {
  using namespace Orwell::Assertions;
  using namespace Fixie;

  void testInit() {
    Vector3 v1(3, 4, 5);
    assertEqual(3, v1[0]);
    assertEqual(4, v1[1]);
    assertEqual(5, v1[2]);

    Vector3 v2(1.5, 2.6, 3.7);
    assertInDelta(1.5, 0.005, v2[0]);
    assertInDelta(2.6, 0.005, v2[1]);
    assertInDelta(3.7, 0.005, v2[2]);

    Vector3 v3(Num(3), Num(4), Num(5));
    assertEqual(3, v3[0]);
    assertEqual(4, v3[1]);
    assertEqual(5, v3[2]);
  }

  void testAddition() {
    Vector3 v1;
    Vector3 v2;
    Vector3 sum;

    v1 = { 3, 4, 5 };
    v2 = { 11, 6.7, 1 };
    sum = v1+v2;
    assertEqual(14, sum[0]);
    assertInDelta(10.7, 0.001, sum[1]);
    assertEqual(6, sum[2]);

    v1 = { 3, 4, 5 };
    v2 = { -3, -4, -5 };
    sum = v1+v2;
    assertEqual(0, sum[0]);
    assertEqual(0, sum[1]);
    assertEqual(0, sum[2]);
  }

  void testSubtraction() {
    Vector3 v1;
    Vector3 v2;
    Vector3 sum;

    v1 = { 3, 4, 5 };
    v2 = { 11, 6.7, 1 };
    sum = v1-v2;
    assertEqual(-8, sum[0]);
    assertInDelta(-2.7, 0.001, sum[1]);
    assertEqual(4, sum[2]);

    v1 = { 3, 4, 5 };
    v2 = { -3, -4, -5 };
    sum = v1-v2;
    assertEqual(6, sum[0]);
    assertEqual(8, sum[1]);
    assertEqual(10, sum[2]);
  }

  void testMultiplication() {
    Vector3 v(2, 6, 10);
    Vector3 r = v*4;

    assertEqual(8, r[0]);
    assertEqual(24, r[1]);
    assertEqual(40, r[2]);
  }

  void testDivision() {
    Vector3 v;
    Vector3 quotient;

    v = { 3, 4, 5 };
    quotient = v/3.3;
    assertInDelta(0.90909, 0.002, quotient[0]);
    assertInDelta(1.21212, 0.002, quotient[1]);
    assertInDelta(1.51515, 0.002, quotient[2]);

    v = { -7, 1.1, 91.9 };
    quotient = v/-6.1;
    assertInDelta(1.14754, 0.002, quotient[0]);
    assertInDelta(-0.18032, 0.002, quotient[1]);
    assertInDelta(-15.0655, 0.002, quotient[2]);
  }

  void testDot() {
    Vector3 a;
    Vector3 b;
    Num dotProduct;

    a = { 1, 2, 3 };
    b = { 4, -5, 6 };
    dotProduct = Vector3::dot(a, b);
    assertEqual(12, dotProduct);

    a = { 2, -3, 7 };
    b = { -4, 2, -4 };
    dotProduct = Vector3::dot(a, b);
    assertEqual(-42, dotProduct);

  }

  void testCross() {
    Vector3 a;
    Vector3 b;
    Vector3 crossProduct;

    a = { 3, -3, 1 };
    b = { 4, 9, 2 };
    crossProduct = Vector3::cross(a, b);
    assertEqual(-15, crossProduct[0]);
    assertEqual(-2, crossProduct[1]);
    assertEqual(39, crossProduct[2]);

    a = { 2, 1, -3 };
    b = { 0, 4, 5 };
    crossProduct = Vector3::cross(a, b);
    assertEqual(17, crossProduct[0]);
    assertEqual(-10, crossProduct[1]);
    assertEqual(8, crossProduct[2]);
  }

  void testLength() {
    Vector3 v;
    Num length;

    v = { 3, 2, 8 };
    length = v.calcLength();
    assertInDelta(8.77496, 0.002, length);

    v = { -7.9, 7, 2 };
    length = v.calcLength();
    assertInDelta(10.74290, 0.002, length);
  }

  void testSquaredLength() {
    Vector3 v;
    Num squaredLength;

    v = { 3, -4, 7.7 };
    squaredLength = v.calcSquaredLength();
    assertInDelta(84.29, 0.005, squaredLength);

    v = { 4, 81, -3.1 };
    squaredLength = v.calcSquaredLength();
    assertInDelta(6586.61, 0.005, squaredLength);
  }

  void testNormalize() {
    Vector3 v;

    v = { 9, -4, 1.7 };
    v = Vector3::normalize(v);
    assertInDelta(0.90049, 0.005, v[0]);
    assertInDelta(-0.40022, 0.005, v[1]);
    assertInDelta(0.17009, 0.005, v[2]);

    v = { -2, 7, 23 };
    v = Vector3::normalize(v);
    assertInDelta(-0.082902, 0.005, v[0]);
    assertInDelta(0.29015, 0.005, v[1]);
    assertInDelta(0.95338, 0.005, v[2]);
  }

  void setup() {
    unsigned group = Orwell::createGroup("FixieVector3Test");
    Orwell::addTest(group, testInit, "Init");
    Orwell::addTest(group, testAddition, "Addition");
    Orwell::addTest(group, testSubtraction, "Subtraction");
    Orwell::addTest(group, testMultiplication, "Multiplication");
    Orwell::addTest(group, testDivision, "Division");
    Orwell::addTest(group, testLength, "Length");
    Orwell::addTest(group, testSquaredLength, "SquaredLength");
    Orwell::addTest(group, testNormalize, "Normalize");
    Orwell::addTest(group, testDot, "Dot");
    Orwell::addTest(group, testCross, "Cross");
  }
}
