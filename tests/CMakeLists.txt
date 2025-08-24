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
