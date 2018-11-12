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

test : numarg badarg overflow underflow nanarg

.SILENT :

$(PROG) :
	make -C $(PROGPLACE) $(PROGNAME) || { echo "Error: $(PROG) does not compile properly."; exit 1; }
	echo "$(PROG) compiled properly."

numarg : numarg.bash $(PROG)
	./numarg.bash && echo "'$<' passed successfully." || echo "Error: $(PROG) does not pass test '$<'."

badarg : badarg.bash $(PROG)
	./badarg.bash && echo "'$<' passed successfully." || echo "Error: $(PROG) does not pass test '$<'."

overflow : overflow.bash $(PROG)
	./overflow.bash && echo "'$<' passed successfully." || echo "Error: $(PROG) does not pass test '$<'."

underflow : underflow.bash $(PROG)
	./underflow.bash && echo "'$<' passed successfully." || echo "Error: $(PROG) does not pass test '$<'."

nanarg : nanarg.bash $(PROG)
	./nanarg.bash && echo "'$<' passed successfully." || echo "Error: $(PROG) does not pass test '$<'."
