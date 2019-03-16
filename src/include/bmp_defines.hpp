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

#ifndef __BMP_DEFINES_H
#define __BMP_DEFINES_H

// Might need to wrap this in cpp defines. 
#include <iostream>
#include <string>
#include <cstring>
#include <stdint.h>

#include "project.h"

/**
 * PLACE HOLDER FOR CLASS INFORMATION
 * 
 * @inheritance: base class; 
 * @TODO: aknuh add struct infromation
 */
class bmpFile_c 
{
    public:
    bmpFile_c();

    private:

    bmpHeaderData_t bmpHeaderData;

};

/**
 * PLACE HOLDER FOR CLASS INFORMATION
 * 
 * @inheritance: private from bmpFile_c
 * @TODO: aknuh add struct infromation
 */
class bmpFileParser_c : private bmpFile_c
{
    public:
    bmpFileParser_c();
};

/**
 * PLACE HOLDER FOR TYPEDEF INFORMATION
 * 
 * @TODO: aknuh add struct infromation
 * @TODO: aknuh change to uint32_t types. 
 */
typedef struct {
  unsigned int ROW_SIZE; // Row size including padding.
  int ARRAY_SIZE; // TOTAL pixel array size
  int DIFFERENCE;
  unsigned int BITS_PER_PIX; //BITS PER PIXEL IN THE IMAGE eg 24,32
  unsigned int FILE_SIZE; // Image file size
  unsigned int DATA_START; // start of Pixel DATA
  unsigned int IMG_WIDTH; // Image pixel width
  unsigned int IMG_HEIGHT; //image pixel height
  unsigned int NUM_VALUES; // number of values each pixel has.
} bmpHeaderData_t;

/**
 * PLACE HOLDER FOR FUNCTION INFORMATION
 * 
 * @TODO: aknuh add struct infromation
 */
void bmp_parse();


#endif // __BMP_DEFINES_H
