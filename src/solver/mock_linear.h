
//Prototypes for mock object

#ifndef MOCK_LINEAR_H
#define MOCK_LINEAR_H

#include "../misc.h"
void mock_setup_linear(float tb, float tc, float tepsilon, intercepts tquadAns);
intercepts linear(float tb, float tc);
int mock_check_linear();
void mock_teardown_linear();

#endif	//MOCK_LINEAR_H
