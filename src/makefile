CC = gcc
CFLAGS = -Wall -pedantic -std=c99
COMP = $(CC) $(CFLAGS) -c -o
LINK = $(CC) $(CFLAGS) -o

#For the actual program

quadsolve : main.o ieee.o misc.o parsing.o linear.o quadratic.o validate.o
	$(LINK) $@ $^ -lm

main.o : main.c libraries.h misc.h parsing.h
	$(COMP) $@ $<

ieee.o : ieee.c libraries.h misc.h
	$(COMP) $@ $<

misc.o : misc.c libraries.h misc.h
	$(COMP) $@ $<

parsing.o : parsing.c libraries.h parsing.h misc.h
	$(COMP) $@ $<

linear.o : linear.c linear.h ieee.h misc.h
	$(COMP) $@ $<

quadratic.o : quadratic.c quadratic.h libraries.h ieee.h
	$(COMP) $@ $<

validate.o : validate.c misc.h validate.h ieee.h
	$(COMP) $@ $<

#For the tests

quadtest : testmain.o testing.o ieee.o misc.o parsing.o linear.o quadratic.o validate.o
	$(LINK) $@ $^ -lm

testmain.o : testmain.c libraries.h misc.h parsing.h testing.h ieee.h quadratic.h validate.h
	$(COMP) $@ $<

testing.o : testing.c libraries.h misc.h parsing.h
	$(COMP) $@ $<

#Miscellaneous

clean :
	rm -f *.o &>/dev/null

squeaky : clean
	rm -f quadsolve &>/dev/null
	rm -f quadtest &>/dev/null
