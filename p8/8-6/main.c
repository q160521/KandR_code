#include <stdio.h>
#include <string.h>
#include "syscalls.h"
#include <sys/file.h>   // == <fcntl.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include "dirents.h"

void fsize(char *);

int main(int argc, char *argv[])
{
    if (argc == 1)
        fsize(".");
    else
        while (--argc > 0)
            fsize(*++argv);
        
    return 0;
}
