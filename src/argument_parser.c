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
#include "argument_parser.h"

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>


extern sysInfo_t sysInfo;
#define UNUSED(expr) do { (void)(expr); } while (0)

bool checkFileMode(char fileName[MAX_FILE_LENGTH])
{
    printf(" ~ Checking File Format %s", fileName);
    return BMP_FILE;
}

void setMode(bool inMode, bool outMode)
{
    printf("  INFO: Using Input Mode:   %d\n", inMode);
    sysInfo.inputMode = inMode;
    printf("  INFO: Using Output Mode:  %d\n", outMode);
    sysInfo.outputMode = outMode;
}

void VerifyFiles(char inFile[MAX_FILE_LENGTH], char outFile[MAX_FILE_LENGTH])
{
    printf(" ~ Checking %s \n", inFile);

    FILE *fp = NULL;

    // CHECK INPUT FILE
    fp = fopen(inFile, "r");
    if  (fp != NULL)
    {
        printf("  INFO: Using Input File:  %s\n", inFile);
        strcpy(sysInfo.inputFileName,  inFile);
        fclose(fp );
    }
    else
    {
        puts("ERROR! Could Not Verify that specified Input file is present...");
        assert (0); // ASSERT! NO DEFAULT INPUT FILE IN DIRECTORY
    }
    printf(" ~ Checking %s \n", outFile);
    // CHECK OUTPUT FILE
    fp = fopen(outFile, "r");
    if ( fp != NULL )
    {
        printf("  INFO: Using Output File: %s\n", outFile);
        strcpy(sysInfo.outputFileName, outFile);
        fclose(fp );
    }
    else 
    {
        puts("ERROR! Could Not Verify that specified Output file is present...");
        assert(0); // ASSERT! NO DEFAULT OUTPUT FILE IN DIRECTORY
    }
}


void ParseArguments(int argc, char const *argv[])
{
    char inFilePath[MAX_FILE_LENGTH] = PATH_TO_IMAGES;
    char outFilePath[MAX_FILE_LENGTH] = PATH_TO_IMAGES;
    printf(HORIZONTAL_RULE);
    printf("Checking Parameters...\n");

    switch (argc)
    {
        case 1:  // Input file NOT specified, output file NOT specified. 
            strcat(inFilePath, DEFAULT_INPUT_FILE);
            strcat(outFilePath, DEFAULT_OUTPUT_FILE);
            VerifyFiles(inFilePath, outFilePath );
            setMode(BMP_FILE, BMP_FILE);
            break;

        case 2:  // Input file IS specified, output file NOT specified.
            assert( strlen(argv[1]) < ( MAX_FILE_LENGTH ) );  // ASSERT! FILENAME LENGTH TOO BIG
            strcat(inFilePath, argv[1]);
            strcat(outFilePath, DEFAULT_OUTPUT_FILE);
            VerifyFiles(inFilePath, outFilePath );
            setMode(BMP_FILE, checkFileMode(outFilePath));
            break; 

        default: // Input file IS specified, output file IS specified.
            assert( strlen(argv[1]) < ( MAX_FILE_LENGTH ) ); // ASSERT! FILENAME LENGTH TOO BIG
            assert( strlen(argv[2]) < ( MAX_FILE_LENGTH ) ); // ASSERT! FILENAME LENGTH TOO BIG
            strcat(inFilePath, argv[1]);
            strcat(outFilePath, argv[2]);
            VerifyFiles(inFilePath, outFilePath);
            setMode(checkFileMode(inFilePath), checkFileMode(outFilePath));
            break;
    }
    printf("Finished Parameter Check!\n");
    printf(HORIZONTAL_RULE);
}

