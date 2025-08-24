/**
 * This is a file copied from the internet. Aids in writing simple but complete
 * unit test cases, for your C/C++ projects.
 */
#include "tests.h"
#include <stdarg.h>
#include <stdio.h>

int run_tests(unsigned int count, ...) {
  va_list args;
  va_start(args, count);
  unsigned int success = 0;
  for (unsigned int i = 0; i < count; i++) {
    TEST_FN fn = va_arg(args, TEST_FN);
    if (fn()) {
      success++;
    }
  }
  printf("%s%d/%d OK%s\n", KGRN, success, count, KNRM);
  if (count - success) {
    printf("%s%d/%d Not OK%s\n", KRED, (count - success), count, KNRM);
    return 1;
  }
  return 0;
}
