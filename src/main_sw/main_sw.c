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

// project related includes.
#include "project.h"
#include "argument_parser.h"
#include "csv_defines.h"
#include "bmp_defines.h"
#include "jpeg_defines.h"
#include "intf.h"          // for intf_* functions

// standard library includes. 
#include <stdio.h>
#include <string.h>

// Declaration of global variables
sysInfo_t sysInfo;
pixel_t **pixelArray;

/**
 * Main software entry point. This function is used only to parse arguments, 
 * and as mini kernel. 
 * 
 */
int main(int argc, char const *argv[])
{
    int32_t status;
    printf(HORIZONTAL_RULE);
    printf("Welcome to the Pixel-Art-Generator!\n");
    printf(HORIZONTAL_RULE);

    // CHECK ALL ARGUMENTS AND SET SYS VARIABLES
    Parse_Arguments(argc, argv);

    // Read and parse files
    status = Intf_Parse();
    assert(status < 0);

    // Output file information into file. 
    status = Intf_Write();
    assert(status < 0);    

    // MAIN SOFTWARE ENTRY

    return 0;
}
