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


 #ifdef __cplusplus 
 #include "bmp_defines.h"
 #include "intf_drv.hpp"

/**
 * PLACE HOLDER FOR CLASS INFORMATION
 * 
 * @inheritance: public from fileIntf_i
 * @TODO: aknuh add class infromation
 */
class bmpFileDriver_c : public fileIntf_i
{
    public:
    bmpFileDriver_c();
    void File_ParseHeaderInfo();    ///< Parses image header information
    void File_ParsePixelData();     ///< Stores Pixel Array and information
    void File_FilterPixelArray();   ///< Manipulates the bmp file into pixel Art.
    void File_WritePixelData();
    
    private:
    bmpHeaderData_t bmpHeaderData;
};

 #endif // __cplusplus
#endif // __BMP_DRIVER_H


