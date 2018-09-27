PROGNAME	= quadsolve
PROGPLACE	= ../src/
PROG		= $(PROGPLACE)$(PROGNAME)

export PROG

all : argtest

.SILENT :

argtest : argtest.bash $(PROG)
	./argtest.bash || echo "Error: $(PROG) does not pass test '$<'."
	echo "'$<' passed successfully."

$(PROG) :
	make -C $(PROGPLACE) $(PROGNAME)
