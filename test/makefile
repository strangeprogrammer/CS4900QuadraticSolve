include ../src/make.i

#Useful variables to pass to the tests
PROGNAME	= quadsolve
PROGPLACE	= ../src/
PROG		= $(PROGPLACE)$(PROGNAME)

export PROG

#Error codes to pass to the tests

SUCCESS		= 0
NOARG_ERR	= 1
BADARG_ERR	= 2
UNDERFLOW_ERR	= 3
OVERFLOW_ERR	= 4
NANARG_ERR	= 5
INTERNAL_ERR	= 6

export SUCCESS NOARG_ERR BADARG_ERR UNDERFLOW_ERR OVERFLOW_ERR NANARG_ERR INTERNAL_ERR

default :: test

test :: noarg badarg overflow underflow nanarg

$(PROG) :
	$(MAKE) -C $(PROGPLACE) $(PROGNAME)

noarg : noarg.bash $(PROG)
	./noarg.bash

badarg : badarg.bash $(PROG)
	./badarg.bash

overflow : overflow.bash $(PROG)
	./overflow.bash

underflow : underflow.bash $(PROG)
	./underflow.bash

nanarg : nanarg.bash $(PROG)
	./nanarg.bash

#It's not exactly possible per se to implement tests for internal errors (that and it would become a headache very quickly).
