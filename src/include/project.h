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
#include "bmp_defines.h"
#include "jpeg_defines.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/*************************************************************************************************/
/*                            MACRO DEFINTIONS                                                   */
/*************************************************************************************************/


/*************************************************************************************************/
/*                            GLOBAL DEFINTIONS                                                  */
/*************************************************************************************************/

#define HORIZONTAL_RULE "_______________________________________________\n"
#define MAX_FILE_LENGTH 40
#define PATH_SIZE 11

#define PATH_TO_IMAGES "./images/"
#define DEFAULT_INPUT_FILE "image_2.bmp"
#define DEFAULT_OUTPUT_FILE "image_out.bmp"
// #define DEFAULT_OUTPUT_FILE "out_default.bmp"

#define BMP_FILE 0
#define JPEG_FILE 1

/*************************************************************************************************/
/*                            TYPEDEFS & STRUCTURES                                              */
/*************************************************************************************************/

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

// extern this system variable for global usage. 
extern pixel_t **pixelArray;

/**
 * This is the structure to contain file information extracted from
 * the file image header data.
 */
typedef struct
{
    uint32_t fileSize;          //< Image file size (Bytes)
    uint32_t dataOffset;        //< Start of Pixel DATA (Byte offset)
    uint32_t imgWidth;          //< Image pixel width  (Pixels)
    uint32_t imgHeight;         //< Image pixel height (Pixels)
    uint32_t rowRawSizeBytes;   //< Row size including padding (Bytes)
    uint32_t arraySizeBytes;    //< total pixel array size (Bytes)
    uint32_t arrayElements;     //< Raw array size need to hold total pixel array 
    uint32_t colourPlanes;      //< TODO FILL
    uint32_t compression;       //< TODO FILL
    uint32_t difference;        //< This is padding value of the pixel array (Bytes)
    uint32_t bitsPerPix;        //< Bits per Pixel in the image eg 24,32
    uint32_t pixelBits;         //< Number of values each pixel has.
} headerInfo_t;

/**
 * This structure contains system information used for global project management. 
 */
typedef struct 
{
    union 
    {
        struct
        {
            uint32_t inputMode  : 1;  //< either BMP_FILE or JPEG_FILE
            uint32_t outputMode : 2;  //< either BMP_FILE (0), JPEG_FILE (1), CSV_FILE (2)
            uint32_t rsvd       : 30; //< Reserved bit field for further developement
        }bitMask;
        uint32_t allBits;
    };
    char inputFileName[MAX_FILE_LENGTH+PATH_SIZE];  //<  Output file name
    char outputFileName[MAX_FILE_LENGTH+PATH_SIZE]; //<  Output file name
    headerInfo_t headerInfo;                        //< File header information
} sysInfo_t;

// extern this system variable for global usage. 
extern sysInfo_t sysInfo;

#ifdef __cplusplus
}
#endif //__cplusplus

#endif // __PROJECT_H
