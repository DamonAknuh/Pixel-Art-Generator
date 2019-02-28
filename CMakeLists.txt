##########################################################################################
#                                                                                        #
# Copyright (c) 2019 Damon Hunka                                                         #
#                                                                                        #
# Permission is hereby granted, free of charge, to any person obtaining a copy           #
# of this software and associated documentation files (the "Software"), to deal          #
# in the Software without restriction, including without limitation the rights           #
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell              #
# copies of the Software, and to permit persons to whom the Software is                  #
# furnished to do so, subject to the following conditions:                               #
#                                                                                        #
# The above copyright notice and this permission notice shall be included in all         #
# copies or substantial portions of the Software.                                        #
#                                                                                        #
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR             #
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,               #
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE            #
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER                 #
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,          #
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE          #
# SOFTWARE.                                                                              #
#                                                                                        #
##########################################################################################

# set minimum version of cmake
cmake_minimum_required(VERSION 3.13.2.0 FATAL_ERROR)

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
  message(FATAL_ERROR
    "Please clean your source tree and try again -- In-source builds are not allowed. ")
endif()

# Set Project
project(PIXEL-ART-GENERATOR VERSION 0.0.0.1
                  DESCRIPTION "Pixel Art Generator for .bmp and .jpeg image formats"
                  LANGUAGES C CXX ASM
)

# Compiler setting and Messages
message(STATUS "~~~~~~~~| Compiler Information |~~~~~~~~")
message(STATUS "Operating System: " "${CMAKE_SYSTEM}"            )
message(STATUS "Compiler loaded : " "${CMAKE_C_COMPILER_LOADED}" )
message(STATUS "Compiler type   : " "${CMAKE_C_COMPILER_ID}"     )
message(STATUS "I am building   : " "${CMAKE_PROJECT_NAME}"      )
message(STATUS "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")

include(GNUInstallDirs)

if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -Wall -Wno-unknown-pragmas -Wno-sign-compare -Woverloaded-virtual -Wwrite-strings -Wno-unused")
    set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g3")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
    set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

# Add Subdirectories
add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(include)

endif()


