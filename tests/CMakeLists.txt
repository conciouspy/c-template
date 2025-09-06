# Copyright (c) 2025, github/conciouspy
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.

cmake_minimum_required(VERSION 3.22.1)

include_directories(litmus)

#-----Dummy Tests-------------------------
# TEMPLATE: Change the sources variable name.
# TEMPLATE: Make sure src/tests.c is included.
set(dummy_test_sources src/tests.c
                       src/dummy_tests.c)
# TEMPLATE: Change the executable name.
# TEMPLATE: Change the target name.
# TEMPLATE: Change the test name.
add_executable(dummy_tests ${dummy_test_sources})
target_include_directories(dummy_tests PUBLIC ../include)
target_link_libraries(dummy_tests
	PUBLIC ${PROJECT_NAME}lib)
#----------------------------------------

# TEMPLATE: DECLARE a new Test.
add_test(
    NAME dummy_tests
    COMMAND dummy_tests
)

# TEMPLATE: create a new custom target 'mc' for memory checks.
# TEMPLATE: Change the executable name in the COMMAND.
add_custom_target(mc
    COMMENT "################Running memory checks on test suites.#############"
    COMMAND /usr/bin/valgrind --tool=memcheck --gen-suppressions=all --leak-check=full --leak-resolution=med --track-origins=yes --vgdb=no ./dummy_tests
    WORKING_DIRECTORY ${working_directory}
   # COMMAND /usr/bin/valgrind --tool=memcheck --gen-suppressions=all --leak-check=full --leak-resolution=med --track-origins=yes --vgdb=no ./array_tests
   # WORKING_DIRECTORY ${working_directory}
  )

# TEMPLATE: (MAC OS uses leaks.) create a new custom target 'macmc' for memory checks.
# TEMPLATE: (MAC OS uses leaks.) Change the executable name in the COMMAND.
add_custom_target(macmc
  COMMENT "################Running memory checks on test suites.#############"
  COMMAND /usr/bin/leaks --atExit --list -- ./dummy_tests
  WORKING_DIRECTORY ${working_directory}
  # COMMAND /usr/bin/leaks --atExit --list -- ./array_tests
  # WORKING_DIRECTORY ${working_directory}
)
