/********************************************************************************************                                                                                       
    Copyright (c) 2019 Damon Hunka                                                          
                                                                                           
    Permission is hereby granted, free of charge, to any person obtaining a copy            
    of this software and associated documentation files (the "Software"), to deal           
    in the Software without restriction, including without limitation the rights            
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell               
    copies of the Software, and to permit persons to whom the Software is                   
    furnished to do so, subject to the following conditions:                                
                                                                                          
    The above copyright notice and this permission notice shall be included in all          
    copies or substantial portions of the Software.                                         
                                                                                         
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR              
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,                
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE             
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER                  
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,           
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE           
    SOFTWARE.                                                                               
**************************************************************************************************/

#ifndef __PROJECT_H
#define __PROJECT_H
#include <stdbool.h>

#define SUPPRESS_UNUSED(expr) do { (void)(expr); } while (0)
#include "bmp_defines.h"
#include "jpeg_defines.h"

#define HORIZONTAL_RULE "_____________________________________\n"
#define MAX_FILE_LENGTH 30
#define PATH_SIZE 11
#define PATH_TO_IMAGES "./images/"
#define DEFAULT_INPUT_FILE "in_default.bmp"
#define DEFAULT_OUTPUT_FILE "out_default.bmp"
#define BMP_FILE 0
#define JPEG_FILE 1
typedef struct 
{
    bool inputMode; //< either BMP_FILE or JPEG_FILE
    bool outputMode; //< either BMP_FILE or JPEG_FILE
    char inputFileName[MAX_FILE_LENGTH+PATH_SIZE];
    char outputFileName[MAX_FILE_LENGTH+PATH_SIZE];
} sysInfo_t;


#endif // __PROJECT_H
