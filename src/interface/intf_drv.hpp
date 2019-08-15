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

#ifndef __INTF_DRV_H
#define __INTF_DRV_H

#include "project.h"
#include <fstream>


#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#include "mask.hpp"
/**
 * PLACE HOLDER FOR CLASS INFORMATION
 * 
 * @inheritance: base class interface
 * @TODO: aknuh add class infromation
 */
class fileIntf_i
{
    public:
    fileIntf_i();
    ~fileIntf_i()
    {
        fclose(inputFile);
    }
    
    virtual void File_ParseHeaderInfo()   = 0;
    virtual void File_ParsePixelData()    = 0;
    virtual void File_FilterPixelArray()  = 0;

    pixel_t File_ApplyFilter(uint32_t imgW, uint32_t imgH);
    void File_InitializePixelArray();
    //virtual void File_WritePixelData();

    protected:
    FILE *inputFile;
    FILE *outputFile;
    mask_c imgMask; 

};

#ifdef __cplusplus
}
#endif //__cplusplus

#endif // __INTF_DRV_H
