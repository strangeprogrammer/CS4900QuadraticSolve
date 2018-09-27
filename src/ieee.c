#include "headers.h"

bool dbleq(double a,double b){
	if(fabs(a-b)<0.005){
		return true;
	}
	return false;
}
