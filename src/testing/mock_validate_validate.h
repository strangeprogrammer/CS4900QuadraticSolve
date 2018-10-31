
//Prototypes for mock object
#ifndef MOCK_VALIDATE_VALIDATE_H
#define MOCK_VALIDATE_VALIDATE_H

#include "../misc.h"
void mock_setup_validate(float ta, float tb, float tc, intercepts tx, float tepsilon, bool tvalidateAns);
int mock_check_validate(int *tcount, float *ta, float *tb, float *tc, intercepts *tx);
void mock_teardown_validate();

#endif  //MOCK_VALIDATE_VALIDATE_H
