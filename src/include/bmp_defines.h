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

#include "project.h"

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

/*************************************************************************************************/
/*                            BMP SPECIFIC DEFINTIONS                                                  */
/*************************************************************************************************/

// the following defines are used as landmarks for various data in the .bmp file format. 
#define DATAOFFSET      10
#define IMGWIDTH        18
#define IMGHEIGHT       22
#define BITSPERPIXEL    0x1C
#define COLOURPLANES    0x1A
#define COMPRESSION     0x1E
#define DIBHEADER       0x0E

/*************************************************************************************************/
/*                       BMP TYPEDEFS & STRUCTURES                                               */
/*************************************************************************************************/



/*************************************************************************************************/
/*                                   BMP FUNCTIONS                                               */
/*************************************************************************************************/

/**
 * Parses the BMP file information, and converts 
 * the written information into useful array structures. 
 * 
 */
void bmp_parse();

/**
 * Writes the BMP file information of the file image.  
 */
void bmp_write();

#ifdef __cplusplus
}
#endif //__cplusplus

#endif // __BMP_DEFINES_H
