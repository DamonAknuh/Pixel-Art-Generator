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
#include "mask.hpp"

#include <cstdio>
#include <fstream>
#include <cstring>
#include <cstdbool>


/**
 * This will allocate the space on the heap used for the filter array. 
 */
void mask_c::AllocateFilterArray(uint8_t size)
{
    uint32_t len = size * sizeof(double*);

    // Allocate memory for pointer array of img width size. 
    filter = (double**)malloc(len);
    if (filter == NULL)
    {
        printf("| ERROR! Failed to allocate space for filter\n|\n");
        assert(0);
    }

    // Iterate over the pointer array and allocate memory for each pointer.
    for (uint32_t i = 0; i < sysInfo.headerInfo.imgHeight; i++)
    {
        filter[i] = (double*)malloc(sysInfo.headerInfo.imgWidth * sizeof(double));
        
        if (filter[i] == NULL)
        {
            printf("| ERROR! Failed to allocate space for filter\n|\n");
            assert(0);
        }
    }
}

void mask_c::PixelArtFilterInit()
{
        
    for ( uint32_t i = 0; i < filterSize; i++)
    {
        for (uint32_t j = 0; j < filterSize; j++)
        {
            filter[i][j] = 1;
            
        }
    }
}

void mask_c::BlurFilterInit()
{
    for ( uint32_t i = 0; i < filterSize; i++)
    {
        for (uint32_t j = 0; j < filterSize; j++)
        {
            if ( i + j > filterSize)
            {
                filter[i][j] = 1;
            }
            else 
            {
                filter[i][j] = 0;
            }
        }
    }
    factor = 0.08;
    bias = 0.0;

}

void mask_c::EdgeFilterInit()
{
    for ( uint32_t i = 0; i < filterSize; i++)
    {
        for (uint32_t j = 0; j < filterSize; j++)
        {
            if ( i = j)
            {
                filter[i][j] = (filterSize * filterSize) - 1;
            }
            else 
            {
                filter[i][j] = -1;
            }
        }
    }
    factor = 1.08;
    bias = 0.0;
}

void mask_c::SharpenInit()
{
    for ( uint32_t i = 0; i < filterSize; i++)
    {
        for (uint32_t j = 0; j < filterSize; j++)
        {
            if ( i = j)
            {
                filter[i][j] = (filterSize * filterSize) - 1;
            }
            else 
            {
                filter[i][j] = -1;
            }
        }
    }
    factor = 0.08;
    bias = 0.0;
}

void mask_c::InitializeFilter(imageFilters_e filter)
{
    switch(filter)
    {
        case FILT_PixelArt:
            PixelArtFilterInit();
            break;
        case FILT_Blur:
            BlurFilterInit();
            break;
        case FILT_Edge:
            EdgeFilterInit();
            break;
        case FILT_Sharpen:
            SharpenInit();
            break;

        default:
            printf("| ERROR! Unsupported filter type!\n|\n");

    }
}

/**
 * This function is the default constructor of the class. It will constuct a NxN image 
 * filter mask based on the following defaults.
 * 
 * default mask: FILT_pixelArt
 * default size: 5x5
 */
mask_c::mask_c() :
    filterSize(5)
{
    AllocateFilterArray(5);

    InitializeFilter(FILT_PixelArt);

}

mask_c::mask_c(uint8_t size, imageFilters_e filter) :
    filterSize(size)
{
    AllocateFilterArray(size);

    InitializeFilter(filter);


}