#ifndef MOCK_VALIDATE_FEQ_H
#define MOCK_VALIDATE_FEQ_H

#include "../misc.h"

// mock_validate_feq.c provides a mock object for feq() and these are the usual mock support functions.

// Initialize to expect 1 call to feq()
void mock_setup_validate_feq(float a, float b, bool answer, double eps);

// Check the results
int mock_check_validate_feq(int *lcount, float *lx, float *ly);

// Reset internal values to the start state
void mock_validate_feq_init();

#endif //MOCK_VALIDATE_FEQ_H
