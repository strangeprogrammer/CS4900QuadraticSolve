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

#Miscellaneous

#squeaky ::
#	rm -f t2 &>/dev/null
