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

#Mock objects

mock_convert.o : mock_convert.c 
	$(COMP) $@ $<

mock_getarg.o : mock_getarg.c getarg.h ../libraries.h ../misc.h ../cunit/cunit.h
	$(COMP) $@ $<

mock_prompt.o : mock_prompt.c prompt.h ../misc.h
	$(COMP) $@ $<

#Intermediate testing objects

t_prompt.o : t_prompt.c prompt.h ../cunit/cunit.h ../libraries.h ../misc.h
	$(COMP) $@ $<

t_conv.o : t_conv.c convert.h ../libraries.h ../misc.h ../cunit/cunit.h
	$(COMP) $@ $<

t_getarg.o : t_getarg.c getarg.h ../libraries.h ../misc.h ../cunit/cunit.h
	$(COMP) $@ $<

t_getargs.o : t_getargs.c getargs.h ../libraries.h ../misc.h ../cunit/cunit.h
	$(COMP) $@ $<

#Tests

t_prompt : t_prompt.o prompt.o ../cunit/cunit.o ../misc.o
	$(LINK) $@ $^ -lm

t_conv : t_conv.o convert.o ../cunit/cunit.o ../misc.o
	$(LINK) $@ $^ -lm

t_getarg : t_getarg.o mock_convert.o getarg.o ../cunit/cunit.o ../misc.o
	$(LINK) $@ $^ -lm

t_getargs : t_getargs.o mock_getarg.o mock_prompt.o getargs.o ../cunit/cunit.o ../misc.o
	$(LINK) $@ $^ -lm

test :: t_prompt t_prompt.py
	./t_prompt | ./t_prompt.py

test :: t_conv
	./t_conv

test :: t_getarg t_getarg.bash
	./t_getarg.bash | ./t_getarg

test :: t_getargs
	./t_getargs

#Miscellaneous

squeaky ::
	rm -f t_prompt &>/dev/null

squeaky ::
	rm -f t_conv &>/dev/null

squeaky ::
	rm -f t_getarg &>/dev/null

squeaky ::
	rm -f t_getargs &>/dev/null
