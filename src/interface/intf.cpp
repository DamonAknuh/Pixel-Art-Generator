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
#include "intf.h"
#include "intf_drv.hpp"
#include "csv_write.h"
#include "util.h"

#include <cstdio>
#include <fstream>
#include <cstring>
#include <cstdbool>


fileIntf_i::fileIntf_i() :
    imgMask(5, FILT_PixelArt)
{
    printf("\nStarting Pixel-Art Conversion...\n");
    inputFile = fopen(sysInfo.inputFileName, "rb");
    assert(inputFile != NULL);
}

/**
 * This function will initialize the global pixelArray variable with the correct size.
 * The size information is gathered from information in the input file header.
 * 
 * @requires that the inputfile header data is parsed.
 */
void fileIntf_i::File_AllocatePixelArray()
{
    uint32_t len = sysInfo.headerInfo.imgHeight * sizeof(pixel_t*);

    // Allocate memory for pointer array of img width size. 
    pixelArray = (pixel_t**)malloc(len);
    if (pixelArray == NULL)
    {
        printf("| ERROR! Failed to allocate space for pixel array\n|\n");
        assert(0);
    }

    // Iterate over the pointer array and allocate memory for each pointer.
    for (uint32_t i = 0; i < sysInfo.headerInfo.imgHeight; i++)
    {
        pixelArray[i] = (pixel_t*)malloc(sysInfo.headerInfo.imgWidth * sizeof(pixel_t));
        
        if (pixelArray[i] == NULL)
        {
            printf("| ERROR! Failed to allocate space for pixel array\n|\n");
            assert(0);
        }
    }
}

/**
 * This function is responsible for apply the specified filter to 
 * a specific pixel given by (x,y) coordinates.
 * 
 * @param imgW   current pixel width coordinate
 * @param imgH   current pixel height coordinate
 * 
 * @returns pixel   resultant pixel after filter applied. 
 * 
 * @note: this algorithm was inspired by a similiar one found below:
 * https://lodev.org/cgtutor/filtering.html
 */
pixel_t fileIntf_i::File_ApplyFilter(int32_t imgW, int32_t imgH)
{
    pixel_t result;
    int32_t tempImgHeight = sysInfo.headerInfo.imgHeight;
    int32_t tempImgWidth  = sysInfo.headerInfo.imgWidth;
    int8_t  sizeFilter = imgMask.filterSize;
    double  factor     = imgMask.factor;
    double  bias       = imgMask.bias;
 
    double red   = 0.0;
    double green = 0.0;
    double blue  = 0.0; 

    // Apply image filter, by summing the multplication of pixelData against the applied filter values.
    for (int32_t filterY = 0; filterY < sizeFilter; filterY++)
    {
        for (int32_t filterX = 0; filterX < sizeFilter ; filterX++)
        {   
            // It is true the added "tempImgWidth" term 'could' be simplied out, but it is needed
            // to prevent any negative values from occuring. 
            int32_t tempImgX  = ((imgW - (sizeFilter / 2) + filterX) + tempImgWidth)  % tempImgWidth;
            int32_t tempImgY  = ((imgH - (sizeFilter / 2) + filterY) + tempImgHeight) % tempImgHeight;

            red   += ((double) pixelArray[tempImgY][tempImgX].red_pixel)   * imgMask.filter[filterX][filterY];
            green += ((double) pixelArray[tempImgY][tempImgX].green_pixel) * imgMask.filter[filterX][filterY];
            blue  += ((double) pixelArray[tempImgY][tempImgX].blue_pixel)  * imgMask.filter[filterX][filterY];
        }
    }

    // Values need to be limited to accepted pixel range. 
    result.red_pixel   = Util_BandPass_Filter((red   * factor) + bias, 0, 255);
    result.green_pixel = Util_BandPass_Filter((green * factor) + bias, 0, 255);
    result.blue_pixel  = Util_BandPass_Filter((blue  * factor) + bias, 0, 255);

    return result;

}


/**
 * High level decision for which bmp/jpeg driver to use to parse image 
 * pixel data. Will then call down into the correct implementation for  
 * provided file.
 * 
 */
uint32_t Intf_Parse()
{
    switch(sysInfo.bitMask.inputMode)
    {
        case 0:
            BMP_Parse();
            break;

        case 1:
            JPEG_Parse(); // @todo: implement jpeg portion of project. 
            break;
        default:
            printf("| ERROR! Unsupported input file mode");

    }
    return 1;
}

/**
 * This function holds High level logic for which bmp/jpeg driver to 
 * use to write the new file. 
 *
 * @todo: implement
 */
uint32_t Intf_Write()
{
    switch(sysInfo.bitMask.outputMode)
    {
        case 0:
            BMP_Write();
            break;

        case 1:
            ///todo: implement jpeg write functionality
            break;
        case 2:
            CSV_WriteFile();
            break; 
        default:
            printf("| ERROR! Unsupported output file mode");
    }
    free(pixelArray);
    return 1;
}
