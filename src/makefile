COMP = gcc -c -o
LINK = gcc -o

quadsolve : main.o ieee.o misc.o parsing.o testing.o
	$(LINK) $@ $^

main.o : main.c libraries.h err_codes.h misc.h parsing.h
	$(COMP) $@ $<

ieee.o : ieee.c libraries.h misc.h
	$(COMP) $@ $<

misc.o : misc.c libraries.h misc.h
	$(COMP) $@ $<

parsing.o : parsing.c libraries.h err_codes.h parsing.h
	$(COMP) $@ $<

testing.o : testing.c libraries.h err_codes.h misc.h parsing.h
	$(COMP) $@ $<