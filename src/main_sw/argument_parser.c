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
#include <string.h>
#include <stdbool.h>

/**
 * Check file extension to set file mode. 
 * 
 * @param fileName name of file to get ext from
 * 
 * @return extension mode
 */
uint8_t CheckFileMode(char fileName[MAX_FILE_LENGTH])
{
    printf("| Checking Input Extension\n");
    uint8_t mode;
    char* ext = strrchr(fileName,'.');

    printf("|     `-> Extension found: %s\n", ext);
    if ( ext == NULL )
    {
        puts("| ERROR! Cannot find file format\n");
        assert(0);  // file is not an .jpeg || .bmp || .csv file format. 
    }
    else if (strcmp( ext , ".bmp") == 0) 
    {
        mode = 0; 
    }
    else if (strcmp( ext , ".jpeg") == 0) 
    {
        mode = 1;
    }
    else if (strcmp( ext , ".csv") == 0) 
    {
        mode = 2;
    }
    else 
    {
        puts("| ERROR! Unsupported file format\n");
        assert(0);  // file is not an .jpeg || .bmp || .csv file format. 
    }
    printf("|    INFO: Using Output Mode:   %d\n", mode);
    return mode;
}

/**
 * Verify file attributes and parameters.
 * 
 * CHECK: file present
 * CHECK: file extensions. 
 */
void VerifyFiles(char inFile[MAX_FILE_LENGTH], char outFile[MAX_FILE_LENGTH])
{
    FILE *fp = NULL;
    uint8_t mode; 

    // CHECK INPUT FILE
    printf("| Input File: %s \n", inFile);
    fp = fopen(inFile, "r");
    if  (fp != NULL)
    {
        mode = CheckFileMode(inFile); 
        strcpy(sysInfo.inputFileName,  inFile);
        sysInfo.bitMask.inputMode = mode; 
        fclose(fp );
    }
    else
    {
        puts("| ERROR! Could Not Verify that specified Input file is present...");
        assert (0); // ASSERT! NO DEFAULT INPUT FILE IN DIRECTORY
    }

    // CHECK OUTPUT FILE
    printf("|\n| Output File %s \n", outFile);
    fp = fopen(outFile, "w"); // creates file aswell.
    if ( fp != NULL )
    {
        mode = CheckFileMode(outFile); 
        strcpy(sysInfo.outputFileName, outFile);
        sysInfo.bitMask.outputMode = mode; 
        fclose(fp );
    }
    else 
    {
        puts("| ERROR! Could Not Verify that specified Output file is present...");
        assert(0); // ASSERT! NO DEFAULT OUTPUT FILE IN DIRECTORY
    }
}

/**
 * Parses command line entry arguments. 
 * @todo: consider returning error status instead of assertion
 * @todo: check that default file is not overruning with compile time check
 */
void Parse_Arguments(int argc, char const *argv[])
{
    char inFilePath[MAX_FILE_LENGTH] = PATH_TO_IMAGES;
    char outFilePath[MAX_FILE_LENGTH] = PATH_TO_IMAGES;
    printf(HORIZONTAL_RULE);
    printf("| Checking Parameters...\n|\n");

    switch (argc)
    {
        case 1:  // Input file NOT specified, output file NOT specified. 
            strcat(inFilePath, DEFAULT_INPUT_FILE);
            strcat(outFilePath, DEFAULT_OUTPUT_FILE);
            VerifyFiles(inFilePath, outFilePath );
            break;

        case 2:  // Input file IS specified, output file NOT specified.
            assert( strlen(argv[1]) < ( MAX_FILE_LENGTH ) );  // ASSERT! FILENAME LENGTH TOO BIG
            strcat(inFilePath, argv[1]);
            strcat(outFilePath, DEFAULT_OUTPUT_FILE);
            VerifyFiles(inFilePath, outFilePath );
            break; 

        default: // Input file IS specified, output file IS specified.
            assert( strlen(argv[1]) < ( MAX_FILE_LENGTH ) ); // ASSERT! FILENAME LENGTH TOO BIG
            assert( strlen(argv[2]) < ( MAX_FILE_LENGTH ) ); // ASSERT! FILENAME LENGTH TOO BIG
            strcat(inFilePath, argv[1]);
            strcat(outFilePath, argv[2]);
            VerifyFiles(inFilePath, outFilePath);
            break;
    }
    printf("|\n| Finished Parameter Check!\n|");
    printf(HORIZONTAL_RULE);
}

