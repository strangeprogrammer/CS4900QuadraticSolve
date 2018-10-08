COMP = gcc -c -o
LINK = gcc -o

#For the actual program

quadsolve : main.o ieee.o misc.o parsing.o quadratic.o validate.o
	$(LINK) $@ $^ -lm

main.o : main.c libraries.h err_codes.h misc.h parsing.h
	$(COMP) $@ $<

ieee.o : ieee.c libraries.h misc.h
	$(COMP) $@ $<

misc.o : misc.c libraries.h misc.h
	$(COMP) $@ $<

parsing.o : parsing.c libraries.h err_codes.h parsing.h
	$(COMP) $@ $<

quadratic.o : quadratic.c quadratic.h libraries.h ieee.h
	$(COMP) $@ $<

validate.o : validate.c misc.h validate.h ieee.h
	$(COMP) $@ $<

#For the tests

quadtest : testmain.o testing.o ieee.o misc.o parsing.o quadratic.o validate.o
	$(LINK) $@ $^ -lm

testmain.o : testmain.c libraries.h err_codes.h misc.h parsing.h testing.h ieee.h quadratic.h validate.h
	$(COMP) $@ $<

testing.o : testing.c libraries.h err_codes.h misc.h parsing.h
	$(COMP) $@ $<

#Miscellaneous

clean :
	rm -f *.o &>/dev/null
	rm -f quadsolve &>/dev/null
	rm -f quadtest &>/dev/null
