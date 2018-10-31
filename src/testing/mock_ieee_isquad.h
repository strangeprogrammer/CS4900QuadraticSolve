
//Prototypes for mock object
#ifndef MOCK_IEEE_ISQUAD_H
#define MOCK_IEEE_ISQUAD_H

#include "../misc.h"
void mock_setup_isquad(float ta, float tb, float tc, float tepsilon, bool tisquadAns);
//bool isquad(float ta, float tb, float tc);
int mock_check_isquad(int *tcount, float *ta, float *tb, float *tc);
void mock_teardown_isquad();

#endif  //MOCK_IEEE_ISQUAD_H
