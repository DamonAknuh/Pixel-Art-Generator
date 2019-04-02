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


#ifndef __UTIL_H
#define __UTIL_H
#include "project.h"

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

/**
 * 4 Byte (1 dword) util function returns uin32_t data byte. 
 * NOTE: 32 bits.
 */
static inline uint32_t Util_Byte4_to_int(const char DATA[4])
{
    uint32_t result = 0;
    unsigned char *temp = (unsigned char*)(&DATA[0]);
    result += temp[3];
    result = (result << 8) + temp[2];
    result = (result << 8) + temp[1];
    result = (result << 8) + temp[0];
    return result;
}

/**
 * 2 Byte util function returns uin32_t data byte. 
 * NOTE: 16 bits. 
 */
static inline uint32_t Util_Byte2_to_int(const char DATA[2])
{
    uint32_t result = 0;
    unsigned char *temp = (unsigned char*)(&DATA[0]);
    result += temp[1];
    result = (result << 8) + temp[0];
    return result;
}

/**
 * Byte util function returns uin32_t data byte. 
 * NOTE: 8 bits. 
 */
static inline uint32_t Util_Byte_to_int(const unsigned char DATA)
{
    uint32_t result = 0;
    result += DATA;
    return result;
}

#ifdef __cplusplus
}
#endif //__cplusplus

#endif // __UTIL_H