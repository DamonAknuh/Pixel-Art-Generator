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

#ifndef __INTF_H
#define __INTF_H

#include "project.h"

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

/*************************************************************************************************/
/*                                   INTERFACE FUNCTIONS                                         */
/*************************************************************************************************/

/**
 * High level decision for which bmp/jpeg driver to use to parse image 
 * pixel data. Will then call down into the correct implementation for  
 * provided file.
 * 
 */
uint32_t Intf_Parse();

/**
 * This function holds High level logic for which bmp/jpeg driver to 
 * use to write the new file. 
 *
 */
uint32_t Intf_Write();

#ifdef __cplusplus
}
#endif //__cplusplus

#endif // __INTF_H