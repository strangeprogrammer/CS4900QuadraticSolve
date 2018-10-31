//Prototypes for mock object

#ifndef MOCK_PARSING_GETARG_H
#define MOCK_PARSING_GETARG_H

#include "../parsing/parsing.h"
void mock_setup_getarg(char targ[], float tepsilon, fpstatus tgetargAns);
int mock_check_getarg(int *tcount, char *targ);
void mock_teardown_getarg();

#endif	//MOCK_PARSING_GETARG_H
