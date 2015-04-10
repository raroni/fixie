#ifndef ORWELL_H
#define ORWELL_H

#include <assert.h>
#include <string.h>
#include <stdio.h>

namespace Orwell {
  const static unsigned maxNameLength = 32;
  const static unsigned maxGroups = 32;
  char groupNames[maxGroups][maxNameLength];
  unsigned groupCount = 0;

  typedef void (*TestFunction)();
  const static unsigned maxTests = 1024;
  TestFunction testFunctions[maxTests];
  char testNames[maxTests][maxNameLength];
  unsigned testSuites[maxTests];
  unsigned testFunctionsCount = 0;

  unsigned createGroup(const char *name) {
    assert(groupCount != maxGroups);
    strncpy(groupNames[groupCount], name, maxNameLength);
    return groupCount++;
  }

  unsigned currentTest;

  void addTest(unsigned group, TestFunction func, const char *name) {
    assert(testFunctionsCount != maxTests);
    strncpy(testNames[testFunctionsCount], name, maxNameLength);
    testFunctions[testFunctionsCount] = func;
    testSuites[testFunctionsCount] = group;
    testFunctionsCount++;
  }

  void start() {
    for(currentTest=0; testFunctionsCount>currentTest; currentTest++) {
      testFunctions[currentTest]();
    }
    printf("Orwell done.\n");
  }

  void reportFailure(const char *failure) {
    unsigned group = testSuites[currentTest];
    printf("%s::%s\n", groupNames[group], testNames[currentTest]);
    printf("%s\n\n", failure);
  }

  namespace Assertions {
    void assertEqual(int32_t expected, int32_t actual) {
      if(actual != expected) {
        char message[64];
        sprintf(message, "%d was not %d.", actual, expected);
        reportFailure(message);
      }
    }

    void assertInDelta(double expected, double delta, double actual) {
      if(expected-delta > actual || expected+delta < actual) {
        char message[256];
        sprintf(message, "%f was not within %f+-%f.", actual, expected, delta);
        reportFailure(message);
      }
    }

    void assertFalse(bool result) {
      if(result != false) {
        char message[64];
        sprintf(message, "%d was not false.", result);
        reportFailure(message);
      }
    }

    void assertTrue(bool result) {
      if(result != true) {
        char message[64];
        sprintf(message, "%d was not true.", result);
        reportFailure(message);
      }
    }
  }
}

#endif
