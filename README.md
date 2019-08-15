# Pixel-Art-Generator
Pixel Art Generator
call the generated 

## Summary  
This program takes a .bmp image file and parses/stores the pixel data to apply various image filters. 

Future plans will enable more image filters ontop of other file output modes. 

For JPEG and PNG file operations this engine will utilize the libjpeg and libpng c libraries. See links to their individual documentations below. 

libjpeg: https://www.ijg.org/

libpng:  http://www.libpng.org/pub/png/libpng.html

## Todo:
- [x] - Infrastructure and Platform setup  
  - [x] - Flush out make system for  
  - [x] - Create Bare-bones main.c  
  - [x] - Create main header (project.h) file
  - [x] - Design, and create argument parser check and verification
- [x] - Interface Driver
  - [x] - Create intf.cpp and header file
  - [x] - create virtual function
  - [X] - Create csv output mode for debugging and visualization of pixel data
- [ ] - BMP File Parser
  - [x] - Create surrounding bmp file infrastructe and compile .cpp files
  - [ ] - Port Header file parser from other github project
  - [ ] - write file pixel parser to store pixel information
  - [ ] - write .bmp output file write functionality
- [ ] - JPEG File Parser
  - [x] - Create surrounding jpeg file infrastructe and compile .cpp files
  - [ ] - Port Header file parser from other github project
  - [ ] - write file pixel parser to store pixel information
  - [ ] - write .jpeg output file write functionality


### Input Modes
This project currently supports two different input file types (.bmp, and ~~.jpeg~~). 
This project supports three different output modes (~~.bmp, .jpeg,~~ .csv). CSV mode is used to debug 
and visualize raw pixel data output

## Building

build the program with the following command  

    user$ make PAG
  
    user$ .\PAG.elf [INPUTFILE_NAME] [OUTPUTFILE_NAME]

### Build Targets
The below list outlines the various targets you can make/compile within this project. 

 * PAG  -- Main build target for project
 * test_PAG -- Test target for project (TBD)




