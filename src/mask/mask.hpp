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


#ifndef __MASK_H
 #define __MASK_H

 #ifdef __cplusplus 
 #include "project.h"

/*************************************************************************************************/
/*                            IMAGE FILTER MODES                                                 */
/*************************************************************************************************/

/**
 * This enum denotes the varies support modes in which you can apply to images. 
 */
typedef enum
{
    FILT_PixelArt = 0,
    FILT_Sharpen,
    FILT_Blur,
    FILT_Edge,
}imageFilters_e;

/*************************************************************************************************/
/*                            IMAGE MASK CLASS                                                   */
/*************************************************************************************************/

/**
 * This class is the mask constructor and management class used to store various filters used to
 * modify the image. 
 */
class mask_c
{
    public:
    mask_c();
    mask_c(uint8_t size, imageFilters_e filter);
    uint8_t filterSize;
    imageFilters_e selectedFilter; 
    double** filter;
    uint8_t factor;
    double bias;

    private: 
    void PixelArtFilterInit();
    void BlurFilterInit();
    void EdgeFilterInit();
    void SharpenInit();
    void AllocateFilterArray(uint8_t size);
    void InitializeFilter(imageFilters_e filter);

};

 #endif // __cplusplus
#endif // __MASK_H