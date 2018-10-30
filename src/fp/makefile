include ../make.i

#For the actual program

ieee.o : ieee.c ../libraries.h ../misc.h
	$(COMP) $@ $<

validate.o : validate.c ../misc.h validate.h ieee.h
	$(COMP) $@ $<
