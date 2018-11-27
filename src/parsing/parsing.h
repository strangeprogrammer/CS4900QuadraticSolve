#ifndef PARSING_H
#define PARSING_H

#include "../misc.h"

bool prompt(int argunm);
err_code convert(char* arg,int arglen,float* dropbox);
err_code getarg(float* dropbox);
err_code getargs(float* a,float* b,float* c);

#endif //PARSING_H
