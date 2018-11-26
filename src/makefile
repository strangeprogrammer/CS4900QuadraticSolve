include make.i

ts := $(shell /bin/date "+%Y-%m-%d_%H:%M:%S")

#Useful Macros

CUNIT :=	cunit/cunit.o

OBJECTS :=	fp/ieee.o		\
		fp/quadfunc.o		\
		fp/validate.o		\
		parsing/parsing.o	\
		solver/linear.o		\
		solver/quadratic.o

TESTS :=	fp/t3		\
		fp/t4		\
		fp/t5		\
		parsing/t2	\
		solver/t1

#For the actual program

default :: quadsolve

quadsolve : main.o $(OBJECTS) misc.o
	$(LINK) $@ $^ -lm

main.o : main.c libraries.h misc.h parsing/parsing.h
	$(COMP) $@ $<

misc.o : misc.c misc.h
	$(COMP) $@ $<

#For the tests

test :: $(TESTS) $(CUNIT)
	$(MAKE) -C fp test

test :: $(TESTS) $(CUNIT)
	$(MAKE) -C parsing test

test :: $(TESTS) $(CUNIT)
	$(MAKE) -C solver test

#Miscellaneous

$(CUNIT) $(OBJECTS) $(TESTS) : force
	$(MAKE) -C  $(dir $@) $(notdir $@)

clean ::
	$(MAKE) -C cunit clean

clean ::
	$(MAKE) -C fp clean

clean ::
	$(MAKE) -C parsing clean

clean ::
	$(MAKE) -C solver clean

squeaky ::
	$(MAKE) -C cunit squeaky

squeaky ::
	$(MAKE) -C fp squeaky

squeaky ::
	$(MAKE) -C parsing squeaky

squeaky ::
	$(MAKE) -C solver squeaky

squeaky ::
	rm -f quadsolve &>/dev/null
