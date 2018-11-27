include ../make.i

#For the actual program

convert.o : convert.c convert.h ../libraries.h ../misc.h
	$(COMP) $@ $<

getarg.o : getarg.c getarg.h convert.h ../libraries.h ../misc.h
	$(COMP) $@ $<

getargs.o : getargs.c getargs.h getarg.h prompt.h ../misc.h
	$(COMP) $@ $<

prompt.o : prompt.c prompt.h ../libraries.h ../misc.h
	$(COMP) $@ $<

#For the tests

#t2.o : t2.c ../cunit/cunit.h parsing.h ../libraries.h ../misc.h
#	$(COMP) $@ $<
#
#t2 : t2.o ../cunit/cunit.o parsing.o ../misc.o
#	$(LINK) $@ $^ -lm
#
#test :: t2
#	./t2

t6.o : t6.c prompt.h ../cunit/cunit.h ../libraries.h ../misc.h
	$(COMP) $@ $<

t6 : t6.o ../cunit/cunit.o prompt.o ../misc.o
	$(LINK) $@ $^ -lm

t7.o : t7.c convert.h ../libraries.h ../misc.h ../cunit/cunit.h
	$(COMP) $@ $<

t7 : t7.o ../cunit/cunit.o convert.o ../misc.o
	$(LINK) $@ $^ -lm

test :: t6 t6.py
	./t6 | ./t6.py

test :: t7
	./t7

#Miscellaneous

squeaky ::
#	rm -f t2 &>/dev/null
	rm -f t6 &>/dev/null
	rm -f t7 &>/dev/null
