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
cmake_minimum_required(VERSION 3.13.2.0 FATAL_ERROR)

# Static Library
add_library(LIB STATIC mylib.cpp )

target_include_directories(
    LIB
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
    )

# main_sw Executable
add_executable(main_sw main_sw.cpp)
target_include_directories(
    main_sw
    PRIVATE
        ${PROJECT_BINARY_DIR}
    )

# link library
target_link_libraries(main_sw LIB)

# Install Binary
install(TARGETS main_sw DESTINATION Pixel-Art-Generator/build)

#Install Libs
install(TARGETS LIB DESTINATION Pixel-Art-Generator/lib)

