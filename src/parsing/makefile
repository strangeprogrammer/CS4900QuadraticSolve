include ../make.i

#For the actual program

parsing.o : parsing.c ../libraries.h parsing.h ../misc.h
	$(COMP) $@ $<

#For the tests

t2.o : t2.c ../cunit/cunit.h parsing.h ../libraries.h ../misc.h
	$(COMP) $@ $<

t2 : t2.o ../cunit/cunit.o parsing.o ../misc.o
	$(LINK) $@ $^ -lm

test :: t2
	./t2

#Miscellaneous

squeaky ::
	rm -f t2 &>/dev/null
