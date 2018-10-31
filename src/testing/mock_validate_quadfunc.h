
//Prototypes for mock object

#ifndef MOCK_VALIDATE_QUADFUNC_H
#define MOCK_VALIDATE_QUADFUNC_H

#include "../misc.h"
void mock_setup_quadfunc(float ta, float tb, float tc, float tx, float tepsilon, float tquadfuncAns);
int mock_check_quadfunc(int *tcount, float *ta, float *tb, float *tc, float *tx);
void mock_teardown_quadfunc();

#endif  //MOCK_VALIDATE_QUADFUNC_H
