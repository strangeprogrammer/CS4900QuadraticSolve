include ../src/make.i

#Useful variables to pass to the tests
PROGNAME	= quadsolve
PROGPLACE	= ../src/
PROG		= $(PROGPLACE)$(PROGNAME)

export PROG

#Error codes to pass to the tests

NUMARG_ERR	= 1
BADARG_ERR	= 2
UNDERFLOW_ERR	= 3
OVERFLOW_ERR	= 4
NANARG_ERR	= 5

export NUMARG_ERR BADARG_ERR UNDERFLOW_ERR OVERFLOW_ERR NANARG_ERR

default :: test

test :: numarg badarg overflow underflow nanarg

$(PROG) :
	$(MAKE) -C $(PROGPLACE) $(PROGNAME)

numarg : numarg.bash $(PROG)
	./numarg.bash

badarg : badarg.bash $(PROG)
	./badarg.bash

overflow : overflow.bash $(PROG)
	./overflow.bash

underflow : underflow.bash $(PROG)
	./underflow.bash

nanarg : nanarg.bash $(PROG)
	./nanarg.bash
