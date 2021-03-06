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
#include "util.h"           // for file reading functions
#include "intf.h"           // for File_AllocatePixelArray

#include <cstdio>
#include <fstream>
#include <cstring>
#include <cstdbool>
#include "bmp_driver.hpp"
#include "intf_drv.hpp"

/**
 * This function parses the bmp files header information. The file header is where all 
 * information about the file properties is stored. 
 */
void bmpFileDriver_c::File_ParseHeaderInfo()
{
    uint32_t tempInt;

    printf(HORIZONTAL_RULE);
    printf("| Reading File Header Information...\n|\n");

    // FILE SIZE
    fseek(inputFile, 0 , SEEK_END);
    tempInt = ftell(inputFile);
    sysInfo.headerInfo.fileSize = tempInt;

    // DATA OFFSET
    sysInfo.headerInfo.dataOffset   = Util_Read_File(inputFile, DATAOFFSET, 4);

    // IMAGE WIDTH
    sysInfo.headerInfo.imgWidth     = Util_Read_File(inputFile, IMGWIDTH, 4);
    // IMAGE HEIGHT
    sysInfo.headerInfo.imgHeight    = Util_Read_File(inputFile, IMGHEIGHT, 4);
    
    // BITS/PIXEL
    sysInfo.headerInfo.bitsPerPix   = Util_Read_File(inputFile, BITSPERPIXEL, 2);

    // COLOUR PLANES
    sysInfo.headerInfo.colourPlanes = Util_Read_File(inputFile, COLOURPLANES, 2);

    // COMPRESSION METHOD
    sysInfo.headerInfo.compression  = Util_Read_File(inputFile, COMPRESSION, 4);
    
    // DIB HEADER
    tempInt = Util_Read_File(inputFile, DIBHEADER, 4);

    sysInfo.headerInfo.rowRawSizeBytes   = (((sysInfo.headerInfo.bitsPerPix * sysInfo.headerInfo.imgWidth) + 31 ) / 32) * 4;  /// Pixel data padded to dwords
    sysInfo.headerInfo.difference     = sysInfo.headerInfo.rowRawSizeBytes - (sysInfo.headerInfo.imgWidth * (sysInfo.headerInfo.bitsPerPix / 8) );
    sysInfo.headerInfo.arraySizeBytes = sysInfo.headerInfo.imgHeight * sysInfo.headerInfo.imgWidth * sizeof(pixel_t);
    sysInfo.headerInfo.arrayElements  = sysInfo.headerInfo.imgHeight * sysInfo.headerInfo.imgWidth;

    // PRINT INFO
    printf("|    INFO: File Size:       %d (Bytes)\n",          sysInfo.headerInfo.fileSize);
    printf("|    INFO: DATA Offset:     %d (Bytes Offset)\n",   sysInfo.headerInfo.dataOffset);
    printf("|    INFO: Image Width:     %d (Pixels)\n",         sysInfo.headerInfo.imgWidth);
    printf("|    INFO: Image Height:    %d (Pixels)\n",         sysInfo.headerInfo.imgHeight); 
    printf("|    INFO: Image Area:      %dx%d (Pixels^2)\n",    sysInfo.headerInfo.imgWidth, sysInfo.headerInfo.imgHeight); 
    printf("|    INFO: Bits per pixel:  %d (Bits/Pixel)\n",     sysInfo.headerInfo.bitsPerPix);        
    printf("|    INFO: Colour Planes:   %d (# of Colour Planes)\n", sysInfo.headerInfo.colourPlanes);
    printf("|    INFO: Compression:     %d\n", sysInfo.headerInfo.compression );
    printf("|    INFO: DIB Header Size: %d\n", tempInt);
    printf("|    INFO: Pixel Row Size:  %d\n", sysInfo.headerInfo.rowRawSizeBytes);
    printf("|    INFO: Difference:      %d\n", sysInfo.headerInfo.difference);
    printf("|    INFO: Array Size:      %d\n", sysInfo.headerInfo.arraySizeBytes);
    printf("|\n| Finished Parsing File Header!\n|");
    printf(HORIZONTAL_RULE);
}

/**
 * This function Parses the bmp file pixel data, and stores it all into a global
 * pixel array variable.
 */
void bmpFileDriver_c::File_ParsePixelData()
{
    uint32_t location = sysInfo.headerInfo.dataOffset;

    File_AllocatePixelArray();

    printf(HORIZONTAL_RULE);
    printf("| Reading BMP File Pixel Information...\n|\n");
    
    for (uint32_t i = 0; i < sysInfo.headerInfo.imgHeight; i++)
    {
        for (uint32_t j = 0; j < sysInfo.headerInfo.imgWidth; j++)
        {
            if (ftell(inputFile) < 0)
            {
                // read untill end of file
                printf("| WARNING! Reaching EOF prematurely");
                break;
            }
            pixelArray[i][j].red_pixel   = Util_Read_File(inputFile, location++, 1);
            pixelArray[i][j].green_pixel = Util_Read_File(inputFile, location++, 1);
            pixelArray[i][j].blue_pixel  = Util_Read_File(inputFile, location++, 1);
        }
        location = location + sysInfo.headerInfo.difference;
    }
    printf("|\n| Finished Reading File Pixel Information!\n|");
    printf(HORIZONTAL_RULE);
}

/**
 * This function will apply the specific filter to the pixel array data
 * will iterate over the pixels, and call Apply filter function to perform
 * pixel by pixel calculations
 */
void bmpFileDriver_c::File_FilterPixelArray()
{
    printf(HORIZONTAL_RULE);
    printf("| Applying selected filter to Pixel data...\n|\n");
    for (uint32_t imgH = 0; imgH < sysInfo.headerInfo.imgHeight; imgH++)
    {
        for (uint32_t imgW = 0; imgW < sysInfo.headerInfo.imgWidth; imgW++)
        {
            pixelArray[imgH][imgW] = File_ApplyFilter(imgW, imgH);
        }
    }

    printf("|\n| Applied selected filter successfully Pixel data!\n|");
    printf(HORIZONTAL_RULE);
}

/**
 * This function writes the pixel data into the bmp file. 
 */
void bmpFileDriver_c::File_WritePixelData()
{
    int8_t errorCode;
    uint32_t location = sysInfo.headerInfo.dataOffset;
    outputFile = fopen(sysInfo.outputFileName, "wb");

    errorCode = Util_Copy_File(inputFile, outputFile);
    if ( errorCode < 0)
    {
        assert(0);
    }

    printf(HORIZONTAL_RULE);
    printf("| Writing BMP File Pixel Information...\n|\n");
    
    for (uint32_t i = 0; i < sysInfo.headerInfo.imgHeight; i++)
    {
        for (uint32_t j = 0; j < sysInfo.headerInfo.imgWidth; j++)
        {
            if (ftell(outputFile) < 0)
            {
                // read untill end of file
                printf("| WARNING! Reaching EOF prematurely");
                break;
            }
            Util_Write_File(outputFile, pixelArray[i][j].red_pixel,   location++);
            Util_Write_File(outputFile, pixelArray[i][j].green_pixel, location++);
            Util_Write_File(outputFile, pixelArray[i][j].blue_pixel,  location++);
        }
        location = location + sysInfo.headerInfo.difference;
    }

    fclose(outputFile);
    printf("|\n| Finished Writing File Pixel Information!\n|");
    printf(HORIZONTAL_RULE);
}

/**
 * PLACE HOLDER FOR FUNCTION INFORMATION
 * 
 * @todo: aknuh add function infromation
 */
bmpFileDriver_c::bmpFileDriver_c()
{

}

/**
 * Parses the BMP file information, and converts 
 * the written information into useful array structures. 
 * 
 */
void BMP_Parse()
{
    bmpFileDriver_c * bmpFileDriver = bmpDriverHandle::Handler_GetInstance();

    bmpFileDriver->File_ParseHeaderInfo();
    //bmpFileDriver->File_ValidateHeaderInfo();
    bmpFileDriver->File_ParsePixelData();
    bmpFileDriver->File_FilterPixelArray();
}

void BMP_Write()
{
    bmpFileDriver_c * bmpFileDriver = bmpDriverHandle::Handler_GetInstance();

    bmpFileDriver->File_WritePixelData();

}
