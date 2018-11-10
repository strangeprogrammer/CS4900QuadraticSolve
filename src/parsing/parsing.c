#include "../libraries.h"
#include "../misc.h"
#include "parsing.h"

bool checkargs(int argc){
    if(argc!=4){
        fprintf(stderr,"Error: this program needs 3 arguments exactly.\n");
        return false;
    }
    return true;
}

fpstatus getarg(char arg[]){
    char* end;
    errno=0;
    float parsed=strtof(arg,&end);
    fpstatus retval={.f=0,.e=SUCCESS};
    if(parsed==0||fpclassify(parsed)==FP_ZERO){
        if(end==arg){
            fprintf(stderr,"Error: could not convert argument '%s' to a float.\n",arg);
            retval.e=BADARG_ERR;
        }else if(errno==ERANGE){
            fprintf(stderr,"Error: argument '%s' causes underflow.\n",arg);
            retval.e=UNDERFLOW_ERR;
        }
    }else if(isinf(parsed)){
        fprintf(stderr,"Error: argument '%s' causes overflow.\n",arg);
        retval.e=OVERFLOW_ERR;
    }else if(isnan(parsed)){
        fprintf(stderr,"Error: argument '%s' is not a number.\n",arg);
        retval.e=NANARG_ERR;
    }
    retval.f=parsed;
    return retval;
}

//fpstatus.f is individual arguments
