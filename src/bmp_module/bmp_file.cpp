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

#include <cstdio>
#include <fstream>
#include <cstring>
#include <cstdbool>
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
    uint32_t tempInt;

    printf(HORIZONTAL_RULE);
    printf("| Reading File Header Information...\n|\n");

    // FILE SIZE
    fseek(fp, 0 , SEEK_END);
    tempInt = ftell(fp);
    bmpHeaderData.fileSize = tempInt;

    // DATA OFFSET
    bmpHeaderData.dataOffset    = Util_Read_File(fp, DATAOFFSET, 4);

    // IMAGE WIDTH
    bmpHeaderData.imgWidth      = Util_Read_File(fp, IMGWIDTH, 4);

    // IMAGE HEIGHT
    bmpHeaderData.imgHeight     = Util_Read_File(fp, IMGHEIGHT, 4);
    
    // BITS/PIXEL
    bmpHeaderData.bitsPerPix    = Util_Read_File(fp, BITSPERPIXEL, 2);

    // COLOUR PLANES
    bmpHeaderData.colourPlanes  = Util_Read_File(fp, COLOURPLANES, 2);

    // COMPRESSION METHOD
    bmpHeaderData.compression   = Util_Read_File(fp, COMPRESSION, 4);
    
    // DIB HEADER
    tempInt = Util_Read_File(fp, DIBHEADER, 4);

    bmpHeaderData.rowSizeBytes = (((bmpHeaderData.bitsPerPix * bmpHeaderData.imgWidth) + 31 ) / 8);
    bmpHeaderData.difference   = bmpHeaderData.rowSizeBytes - (bmpHeaderData.imgWidth * 3);
    bmpHeaderData.arraySize    = bmpHeaderData.rowSizeBytes * abs(bmpHeaderData.imgHeight); //needed as image height can be negative

    // PRINT INFO
    printf("|    INFO: File Size:       %d (Bytes)\n",          bmpHeaderData.fileSize);
    printf("|    INFO: DATA Offset:     %d (Bytes Offset)\n",   bmpHeaderData.dataOffset);
    printf("|    INFO: Image Width:     %d (Pixels)\n",         bmpHeaderData.imgWidth);
    printf("|    INFO: Image Height:    %d (Pixels)\n",         bmpHeaderData.imgHeight); 
    printf("|    INFO: Image Area:      %dx%d (Pixels^2)\n",    bmpHeaderData.imgWidth, bmpHeaderData.imgHeight); 
    printf("|    INFO: Bits per pixel:  %d (Bits/Pixel)\n",     bmpHeaderData.bitsPerPix);        
    printf("|    INFO: Colour Planes:   %d (# of Colour Planes)\n", bmpHeaderData.colourPlanes);
    printf("|    INFO: Compression:     %d\n", bmpHeaderData.compression );
    printf("|    INFO: DIB Header Size: %d\n", tempInt);
    printf("|    INFO: Pixel Row Size:  %d\n", bmpHeaderData.rowSizeBytes);
    printf("|    INFO: Difference:      %d\n", bmpHeaderData.difference);
    printf("|    INFO: Array Size:      %d\n", bmpHeaderData.arraySize);
    printf("|\n| Finished Parsing File Header!\n|");
    printf(HORIZONTAL_RULE);
}

/**
 * Parse bmp pixel data, and store in a global pixel array variable.
 */
void bmpFileParser_c::StorePixelArray()
{
    printf(HORIZONTAL_RULE);
    printf("| Reading File Pixel Information...\n|\n");
    uint32_t location = bmpHeaderData.dataOffset;
    // Allocate memory for the entire pixel array. 
    pixelArray = (pixel_t**)malloc(bmpHeaderData.arraySize);

    for ( uint32_t i = 1; i <= bmpHeaderData.imgHeight; i++)
    {
        for (uint32_t j = 1; j <= bmpHeaderData.imgWidth; j++)
        {
            if (ftell(fp) < 0)
            {
                break;
            }
            pixelArray[i][j].red_pixel   = Util_Read_File(fp, location++, 1);
            pixelArray[i][j].green_pixel = Util_Read_File(fp, location++, 1);
            pixelArray[i][j].blue_pixel  = Util_Read_File(fp, location++, 1);
        }
        location = location + bmpHeaderData.difference;
    }
    printf("|\n| Finished Reading File Pixel Information!\n|");
    printf(HORIZONTAL_RULE);
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
