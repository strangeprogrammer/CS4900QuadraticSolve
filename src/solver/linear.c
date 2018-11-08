#include "linear.h"
#include "../fp/ieee.h"
#include "../misc.h"

intercepts linear(float b,float c){
	intercepts retval;
	if(feq(b,0)){//If the slope is 0
		if(feq(c,0)){//If the line is the x-axis
			retval.low=0;
			retval.numroots=1;//This should be more like infinity, but it'll work
		}else{//The line can't possibly hit the x-axis
			retval.numroots=0;
		}
	}else{//Use standard algebra to find intercept
		retval.low=-c/b;
		retval.numroots=1;
	}
	return retval;
}
