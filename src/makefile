include make.i

#Useful Macros

OBJECTS :=	fp/ieee.o		\
		fp/validate.o		\
		parsing/parsing.o	\
		solver/linear.o		\
		solver/quadratic.o

#For the actual program

default :: quadsolve

quadsolve : main.o $(OBJECTS)
	$(LINK) $@ $^ -lm

main.o : main.c libraries.h misc.h parsing/parsing.h
	$(COMP) $@ $<

$(OBJECTS) : force
	$(MAKE) -C  $(dir $@) $(notdir $@)

#For the tests

quadtest : testmain.o testing.o $(OBJECTS)
	$(LINK) $@ $^ -lm

testmain.o : testmain.c libraries.h misc.h parsing/parsing.h testing.h fp/ieee.h solver/quadratic.h fp/validate.h
	$(COMP) $@ $<

testing.o : testing.c libraries.h misc.h parsing/parsing.h
	$(COMP) $@ $<

#Miscellaneous

.PHONY : squeaky

clean ::
	$(MAKE) -C fp clean
	$(MAKE) -C parsing clean
	$(MAKE) -C solver clean

squeaky : clean
	rm -f quadsolve &>/dev/null
	rm -f quadtest &>/dev/null
