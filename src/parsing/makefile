include ../make.i

#For the actual program

parsing.o : parsing.c ../libraries.h parsing.h ../misc.h
	$(COMP) $@ $<

#For the tests

t2.o : t2.c ../cunit.h parsing.h
	$(COMP) $@ $<

t2 : t2.o ../cunit.o parsing.o
	$(LINK) $@ $^ -lm

test : t2
	./t2

#Miscellaneous

squeaky :: clean
	rm -f t2 &>/dev/null
