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
#include "csv_write.h"
#include "util.h"

#include <stdio.h>



void CSV_WriteFile(void)
{
    FILE  *outputFile;
    uint32_t imgHeight = sysInfo.headerInfo.imgHeight;
    uint32_t imgWidth = sysInfo.headerInfo.imgWidth;

    // open csv output file
    printf(HORIZONTAL_RULE);
    printf("| Writing into CSV output file...\n");
    outputFile = fopen(sysInfo.outputFileName, "w");
    if (outputFile != NULL)
    {
        for (uint32_t i=imgHeight-1; i > 0; i--)
        {
            for (uint32_t j = imgWidth-1; j > 0; j--)
            {
                //printf("|%3d|", pixelArray[i][j].red_pixel);
                fprintf(outputFile, "|%3d", pixelArray[i][j].red_pixel);
            }
            for (uint32_t j = imgWidth-1; j > 0; j--)
            {
                //printf("|%3d|", pixelArray[i][j].green_pixel);
                fprintf(outputFile, "|%3d", pixelArray[i][j].green_pixel);
            }
            for (uint32_t j = imgWidth-1; j > 0; j--)
            {
                //printf("|%3d|", pixelArray[i][j].blue_pixel);
                fprintf(outputFile, "|%3d", pixelArray[i][j].blue_pixel);
            }
            fprintf(outputFile, "\n");
            printf("%d\n", i);
        }
        fclose(outputFile);
    }
    else 
    {
        printf(" | ERROR! Failed to open CSV output file.");
    }
}