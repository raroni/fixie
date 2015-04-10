#include "Orwell.h"
#include "NumTest.h"
#include "TrigTest.h"
#include "UtilTest.h"
#include "Vector3Test.h"
#include "Matrix4Test.h"
#include "QuaternionTest.h"

int main() {
  NumTest::setup();
  TrigTest::setup();
  UtilTest::setup();
  Vector3Test::setup();
  Matrix4Test::setup();
  QuaternionTest::setup();
  Orwell::start();
}
