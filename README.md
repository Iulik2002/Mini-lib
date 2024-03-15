API and Implementation Tasks
The API of the C standard library is declared in several header files, each containing function declarations, data type definitions, and macros. Key header files for your minimal implementation are:

<string.h>: Defines string manipulation functions.
Functions to be implemented include: strcpy(), strcat(), strlen(), strncpy(), strncat(), strcmp(), strncmp(), strstr(), strrstr(), memcpy(), memset(), memmove(), memcmp().

<stdio.h>: Defines printing and I/O functions.
You'll need to implement puts().

<unistd.h>, <sys/fcntl.h>, and <sys/stat.h>: Define I/O primitives.
Functions to be implemented include: open(), close(), lseek(), stat(), fstat(), truncate(), ftruncate().
Additionally, you'll need to implement the nanosleep() and sleep() functions.

<stdlib.h> and <sys/mman.h>: Define memory allocation functions.
Functions to be implemented include: malloc(), free(), calloc(), realloc(), realloc_array(), mmap(), mremap(), munmap().
A basic list structure for managing memory areas is provided in include/internal/mm/mem_list.h and mm/mem_list.c.

<errno.h> and errno.c: Declare and define the errno variable, which indicates errors encountered during system calls and some library functions.
