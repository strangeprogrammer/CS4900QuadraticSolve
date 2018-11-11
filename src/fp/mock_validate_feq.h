// mock_validate_feq.h
// mock_validate_feq.c provides a mock object fvor feq() and
// these are the uusual mock support functions .
#ifndef MOCK_VALIDATE_FEQ_H
#define MOCK_VALIDATE_FEQ_H

#include "../misc.h"

// Initialize to expect 1 call to feq()
void mock_setup_validate_feq(float a, float b, bool answer, double eps);
// Check the results
int mock_check_validate_feq(int *lcount,  float *lx, float *ly);
// Reset internal values to the start state
void mock_teardown_validate_feq();

#endif //MOCK_VALIDATE_FEQ_H
