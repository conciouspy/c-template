/**
 * @author: Ashutosh Nandan (ashutosh.nandan@outlook.com)
 */
#include "tests.h"
#include <stdlib.h>
#include <string.h>
#include "c-template/base.h"

TEST_BEGIN(dummy_test)
ASSERT(base_add(1, 1) == 2, "dummy test works fine.");
TEST_END

RUN_TESTS(dummy_test)
