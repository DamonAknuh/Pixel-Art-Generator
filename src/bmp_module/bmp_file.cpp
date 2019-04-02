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

#include "project.h"
#include "bmp_defines.h"
#include "util.h"

#include <stdio.h>
#include <fstream>
#include <string.h>
#include <stdbool.h>
#include "bmp_driver.hpp"

bmpFile_c::bmpFile_c()
{
    printf("\nStarting Pixel-Art Conversion...\n");
    fp = fopen(sysInfo.inputFileName, "rb");
    assert(fp != NULL);
}

/**
 * PLACE HOLDER FOR FUNCTION INFORMATION
 * 
 * @todo: aknuh add function infromation
 */
void bmpFileParser_c::ParseImageInfo()
{
    char tempBuffer[4];
    uint32_t tempInt;

    printf(HORIZONTAL_RULE);
    printf("| Reading File Header Information...\n|\n");

    // FILE SIZE
    fseek(fp, 0 , SEEK_END);
    tempInt = ftell(fp);
    printf("|    INFO: File Size: %d (Bytes)\n", tempInt);
    bmpHeaderData.fileSize = tempInt;

    // DATA OFFSET
    fseek(fp, 10, 0);
    fread(tempBuffer, 4, 4, fp);
    tempInt = Util_Byte4_to_int(tempBuffer);
    printf("|    INFO: DATA Offset: %d (Bytes Offset)\n", tempInt); 
    bmpHeaderData.dataOffset = tempInt;

    // IMAGE WIDTH
    fseek(fp, 18, 0);
    fread(tempBuffer, 4, 4, fp);
    tempInt = Util_Byte4_to_int(tempBuffer);
    printf("|    INFO: Image Width: %d (Pixels)\n", tempInt); 
    bmpHeaderData.imgWidth = tempInt;

    // IMAGE HEIGHT
    fseek(fp, 22, 0);
    fread(tempBuffer, 4, 4, fp);
    tempInt = Util_Byte4_to_int(tempBuffer);
    printf("|    INFO: Image Height: %d (Pixels)\n", tempInt); 
    bmpHeaderData.imgHeight = tempInt;
    
    // RESOLUTION
    printf("|    INFO: Image Resolution: %dx%d (Pixels^2)\n",
            bmpHeaderData.imgWidth, bmpHeaderData.imgHeight ); 

    
}

/**
 * PLACE HOLDER FOR FUNCTION INFORMATION
 * 
 * @todo: aknuh add function infromation
 */
void bmpFileParser_c::StorePixelArray()
{
    
}

/**
 * PLACE HOLDER FOR FUNCTION INFORMATION
 * 
 * @todo: aknuh add function infromation
 */
void bmpFileParser_c::ComputePixelArt()
{
    
}

/**
 * PLACE HOLDER FOR FUNCTION INFORMATION
 * 
 * @todo: aknuh add function infromation
 */
bmpFileParser_c::bmpFileParser_c()
{
    ParseImageInfo();
    StorePixelArray();
    ComputePixelArt();
}

/**
 * Parses the BMP file information, and converts 
 * the written information into useful array structures. 
 * 
 */
void bmp_parse()
{
    bmpFileParser_c bmpFileParser; 
}

/**
 * Writes the BMP file information of the file image.  
 */
void bmp_write()
{

}
