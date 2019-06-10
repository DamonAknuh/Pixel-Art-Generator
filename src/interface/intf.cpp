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

#include <cstdio>
#include <fstream>
#include <cstring>
#include <cstdbool>


fileIntf_i::fileIntf_i()
{
    printf("\nStarting Pixel-Art Conversion...\n");
    inputFile = fopen(sysInfo.inputFileName, "rb");
    assert(inputFile != NULL);
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
            bmp_parse();
            break;

        case 1:
            jpeg_parse(); // @todo: implement jpeg portion of project. 
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
            ///todo: implement bmp write functionality
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
