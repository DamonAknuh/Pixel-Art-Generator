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
/*                       BMP TYPEDEFS & STRUCTURES                                               */
/*************************************************************************************************/

/**
 * PLACE HOLDER FOR TYPEDEF INFORMATION
 * 
 * @TODO: aknuh add struct infromation
 * @TODO: aknuh change to uint32_t types. 
 */
typedef struct {
    uint32_t fileSize;     //< Image file size (Bytes)
    uint32_t dataOffset;   //< Start of Pixel DATA (Byte offset)
    uint32_t imgWidth;     //< Image pixel width  (Pixels)
    uint32_t imgHeight;    //< Image pixel height (Pixels)
    uint32_t rowSizeBytes; //< Row size including padding (Bytes)
    uint32_t arraySize;    //< toal pixel array size (Bytes)
    uint32_t difference;  
    uint32_t bitsPerPix;   //< Bits per Pixel in the image eg 24,32
    uint32_t pixelBits;    //< Number of values each pixel has.
} bmpHeaderData_t;

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
