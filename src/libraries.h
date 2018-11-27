#ifndef LIBRARIES_H
#define LIBRARIES_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

//Workarounds for some compiler warnings
int fileno(FILE *stream);
FILE *fdopen(int fd, const char *mode);
void setlinebuf(FILE *stream);

#endif //LIBRARIES_H
