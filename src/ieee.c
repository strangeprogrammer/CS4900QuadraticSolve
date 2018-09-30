#include "libraries.h"
#include "misc.h"

bool feq(double a,double b){
	if(fabs(a-b)<0.0001){//Might have to change this constant
		return true;
	}
	return false;
}
