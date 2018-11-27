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

t6 : t6.o prompt.o ../cunit/cunit.o ../misc.o
	$(LINK) $@ $^ -lm

t7.o : t7.c convert.h ../libraries.h ../misc.h ../cunit/cunit.h
	$(COMP) $@ $<

t7 : t7.o convert.o ../cunit/cunit.o ../misc.o
	$(LINK) $@ $^ -lm

mock_convert.o : mock_convert.c 
	$(COMP) $@ $<

t8.o : t8.c getarg.h ../libraries.h ../misc.h ../cunit/cunit.h
	$(COMP) $@ $<

t8 : t8.o mock_convert.o getarg.o ../cunit/cunit.o ../misc.o
	$(LINK) $@ $^ -lm

mock_getarg.o : mock_getarg.c getarg.h ../libraries.h ../misc.h ../cunit/cunit.h
	$(COMP) $@ $<

mock_prompt.o : mock_prompt.c prompt.h ../misc.h
	$(COMP) $@ $<

t9.o : t9.c getargs.h ../libraries.h ../misc.h ../cunit/cunit.h
	$(COMP) $@ $<

t9 : t9.o mock_getarg.o mock_prompt.o getargs.o ../cunit/cunit.o ../misc.o
	$(LINK) $@ $^ -lm

test :: t6 t6.py
	./t6 | ./t6.py

test :: t7
	./t7

test :: t8 t8.bash
	./t8.bash | ./t8

test :: t9
	./t9

#Miscellaneous

squeaky ::
#	rm -f t2 &>/dev/null
	rm -f t6 &>/dev/null
	rm -f t7 &>/dev/null
	rm -f t8 &>/dev/null
	rm -f t9 &>/dev/null
