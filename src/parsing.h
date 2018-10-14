#ifndef PARSING_H
#define PARSING_H

#include "misc.h"

typedef struct fpstatus{
	float f;
	err_code e;
} fpstatus;

bool checkargs(int argc);
fpstatus getarg(char* arg);

#endif //PARSING_H
