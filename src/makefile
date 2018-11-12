include make.i

#Useful Macros

OBJECTS :=	fp/ieee.o		\
		fp/quadfunc.o		\
		fp/validate.o		\
		parsing/parsing.o	\
		solver/linear.o		\
		solver/quadratic.o

TESTS :=	solver/t1	\
		parsing/t2	\
		fp/t3		\
		fp/t4		\
		fp/t5

#For the actual program

default :: quadsolve

quadsolve : main.o $(OBJECTS)
	$(LINK) $@ $^ -lm

main.o : main.c libraries.h misc.h parsing/parsing.h
	$(COMP) $@ $<

$(OBJECTS) : force
	$(MAKE) -C  $(dir $@) $(notdir $@)

#For the tests

test : $(TESTS)
	$(MAKE) -C solver test
	$(MAKE) -C parsing test
	$(MAKE) -C fp test

$(TESTS) : force
	$(MAKE) -C  $(dir $@) $(notdir $@)

#Miscellaneous

clean ::
	$(MAKE) -C fp clean
	$(MAKE) -C parsing clean
	$(MAKE) -C solver clean

squeaky :: clean
	$(MAKE) -C fp squeaky
	$(MAKE) -C parsing squeaky
	$(MAKE) -C solver squeaky
	rm -f quadsolve &>/dev/null
