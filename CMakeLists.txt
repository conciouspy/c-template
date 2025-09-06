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

# setting the minimum cmake version.
cmake_minimum_required(VERSION 3.22.1)

# our project.
project(c-template C)

# sticking with gcc as this is compatible with valgrind.
set(CMAKE_C_COMPILER "/usr/bin/gcc")

# this generates the json needed by clangd to be structure aware of the current product.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# C11 seems to be a decent version to work with.
set(CMAKE_C_STANDARD 11)

# some additional flags which I always include.
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -Wall -pthread")

# marking our include directory
include_directories(include)

# This helps to include the sourcelist.cmake file from the current directory.
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR})

include(sourcelist)

# target definitions now.
add_executable(${PROJECT_NAME}  ${main_exe_sources})

add_library(${PROJECT_NAME}lib  ${main_lib_sources})

target_include_directories(${PROJECT_NAME} PUBLIC 
                           "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
                           "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")

# cache variables for installation destinations.
include(GNUInstallDirs)

set_target_properties(${PROJECT_NAME}lib
         PROPERTIES
         CMAKE_C_STANDARD 11
         )

install(TARGETS ${PROJECT_NAME}lib
        EXPORT ${PROJECT_NAME}libTargets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        )

install(FILES ${header_files} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})

install(EXPORT ${PROJECT_NAME}libTargets
        FILE ${PROJECT_NAME}libTargets.cmake
        NAMESPACE ${PROJECT_NAME}lib::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}lib
    )


# For generating config file for package management.
include(CMakePackageConfigHelpers)

configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
       "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}libConfig.cmake"
       INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}lib
)

install(FILES 
        "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}libConfig.cmake"
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}lib
)

#testing configurations.
enable_testing()

add_subdirectory(tests)
