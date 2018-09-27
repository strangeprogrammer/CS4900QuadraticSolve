COMP = gcc -c -o
LINK = gcc -o

quadsolve : main.o ieee.o misc.o
	$(LINK) $@ $^

main.o : main.c
	$(COMP) $@ $^

ieee.o : ieee.c
	$(COMP) $@ $^

misc.o : misc.c
	$(COMP) $@ $^
