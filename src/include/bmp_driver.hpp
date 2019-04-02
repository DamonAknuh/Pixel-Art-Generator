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

#ifndef __BMP_DRIVER_H
#define __BMP_DRIVER_H

// Might need to wrap this in cpp defines.
 #ifdef __cplusplus 

#include "bmp_defines.h"

/**
 * PLACE HOLDER FOR CLASS INFORMATION
 * 
 * @inheritance: base class; 
 * @TODO: aknuh add class infromation
 */
class bmpFile_c 
{
    public:
    bmpFile_c();
    ~bmpFile_c()
    {
        fclose(fp);
    }


    ///@todo: dhunka 
    protected:
    FILE *fp;
    bmpHeaderData_t bmpHeaderData;
   
};

/**
 * PLACE HOLDER FOR CLASS INFORMATION
 * 
 * @inheritance: private from bmpFile_c
 * @TODO: aknuh add class infromation
 */
class bmpFileParser_c : private bmpFile_c
{
    public:

    bmpFileParser_c();      ///< Executes
     
    void ParseImageInfo();  ///< Parses image header information
    void StorePixelArray(); ///< Stores Pixel Array and information
    void ComputePixelArt(); ///< Manipulates the bmp file into pixel Art.

};




 #endif // __cplusplus
#endif // __BMP_DRIVER_H


