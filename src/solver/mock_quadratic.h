
//Prototypes for mock object

#ifndef MOCK_QUADRATIC_H
#define MOCK_QUADRATIC_H

#include "../misc.h"
void mock_setup_quadratic(float ta, float tb, float tc, float tepsilon, intercepts tquadAns);
intercepts quadratic(float ta, float tb, float tc);
int mock_check_quadratic();
void mock_teardown_quadratic();

#endif	//MOCK_QUADRATIC_H
