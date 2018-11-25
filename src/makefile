include make.i
ts := $(shell /bin/date "+%Y-%m-%d_%H:%M:%S")

#Useful Macros

CUNIT :=	cunit/cunit.o

OBJECTS :=	fp/ieee.o		\
		fp/quadfunc.o		\
		fp/validate.o		\
		parsing/parsing.o	\
		solver/linear.o		\
		solver/quadratic.o 	\
		input/input.o 		\
		input/token.o

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

$(OBJECTS) $(CUNIT) : force
	$(MAKE) -C  $(dir $@) $(notdir $@)

run :
	@./quadsolve < fileIn.txt > input/logs/fileOut.txt | mv input/logs/fileOut.txt input/logs/$(ts)_log.txt

#For the tests

test : $(TESTS) $(CUNIT)
	$(MAKE) -C solver test
	$(MAKE) -C parsing test
	$(MAKE) -C input test
	$(MAKE) -C fp test

$(TESTS) : force
	$(MAKE) -C  $(dir $@) $(notdir $@)

#Miscellaneous

clean ::
	$(MAKE) -C fp clean
	$(MAKE) -C input clean
	$(MAKE) -C parsing clean
	$(MAKE) -C solver clean

squeaky :: clean
	$(MAKE) -C fp squeaky
	$(MAKE) -C input squeaky
	$(MAKE) -C parsing squeaky
	$(MAKE) -C solver squeaky
	rm -f quadsolve &>/dev/null
