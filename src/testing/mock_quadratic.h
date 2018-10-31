
//Prototypes for mock object

#ifndef MOCK_QUADRATIC_H
#define MOCK_QUADRATIC_H

#include "../misc.h"
void mock_setup_quadratic(float ta, float tb, float tc, float tepsilon, intercepts tquadAns);
int mock_check_quadratic(int *tcount, float *ta, float *tb, float *tc);
void mock_teardown_quadratic();

#endif  //MOCK_QUADRATIC_H
