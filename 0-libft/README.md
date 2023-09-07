# Libft
The libft library is a collection of general purpose functions designed to be used in the 42 school curriculum. It provides various utility functions to handle strings, memory, standard input/output character types, and more.

## Usage
To compile the library using its Makefile:  
`make -C /path/to/libft`

Include the header file libft.h in your C source code.  
`#include "libft.h"`

To compile your programs with the library:  
`cc file.c -I/path/to/libft -L/path/to/libft -lft`

## Install
Alternatively, libft can be installed in */usr/local/* :  
`sudo cp libft.a /usr/local/lib`  
`sudo cp libft.h /usr/local/include`