include make.i

#Useful Macros

OBJECTS :=	fp/ieee.o		\
		fp/validate.o		\
		parsing/parsing.o	\
		solver/linear.o		\
		solver/quadratic.o

TESTS :=	solver/t1	\
		parsing/t2	\
		fp/t3		\
		fp/t4

#For the actual program

default :: quadsolve

quadsolve : main.o $(OBJECTS)
	$(LINK) $@ $^ -lm

main.o : main.c libraries.h misc.h parsing/parsing.h
	$(COMP) $@ $<

$(OBJECTS) : force
	$(MAKE) -C  $(dir $@) $(notdir $@)

#For the tests

test : $(TESTS) t5
	$(MAKE) -C solver test
	$(MAKE) -C parsing test
	$(MAKE) -C fp test
	./t5

$(TESTS) : force
	$(MAKE) -C  $(dir $@) $(notdir $@)

t5 : fp/validate_feq_test.o cunit.o fp/mock_validate_feq.o fp/validate.o
	$(LINK) $@ $^ -lm

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
	rm -f t5 &>/dev/null
