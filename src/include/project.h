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

#include <assert.h>
#include <stdint.h>
#include <stdbool.h>
#include "bmp_defines.hpp"
#include "jpeg_defines.hpp"

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

// Definitions

#define HORIZONTAL_RULE "_____________________________________\n"
#define MAX_FILE_LENGTH 30
#define PATH_SIZE 11

#define PATH_TO_IMAGES "./images/"
#define DEFAULT_INPUT_FILE "in_default.bmp"
#define DEFAULT_OUTPUT_FILE "out_default.bmp"

#define BMP_FILE 0
#define JPEG_FILE 1

// typedef and structures. 

/**
 * This is the structure to contain pixel information. 
 */
typedef struct
{
    uint8_t red_pixel;      // to store red pixel intensity
    uint8_t green_pixel;    // to store green pixel intensity
    uint8_t blue_pixel;     // to store blue pixel intensity
    uint8_t misc_info;      // to store misc. pixel infromation
}pixel_t;

/**
 * This structure contains system information used for global 
 * project management. 
 */
typedef struct 
{
    bool inputMode;             //< either BMP_FILE or JPEG_FILE
    bool outputMode;            //< either BMP_FILE or JPEG_FILE
    char inputFileName[MAX_FILE_LENGTH+PATH_SIZE]; 
    char outputFileName[MAX_FILE_LENGTH+PATH_SIZE];
} sysInfo_t;
// extern this system variable for global usage. 
extern sysInfo_t sysInfo;

#ifdef __cplusplus
}
#endif //__cplusplus

#endif // __PROJECT_H
