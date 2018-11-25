include ../make.i

#For the actual program

ieee.o : ieee.c ../libraries.h ../misc.h
	$(COMP) $@ $<

quadfunc.o : quadfunc.c quadfunc.h
	$(COMP) $@ $<

validate.o : validate.c validate.h quadfunc.h ieee.h ../misc.h
	$(COMP) $@ $<

#Mock objects

mock_validate_deps.o : mock_validate_deps.c ../cunit/cunit.h ../misc.h quadfunc.h validate.h ieee.h
	$(COMP) $@ $<

#Intermediate testing objects

t3.o : t3.c ../cunit/cunit.h ieee.h
	$(COMP) $@ $<

t4.o : t4.c ../cunit/cunit.h quadfunc.h
	$(COMP) $@ $<

t5.o : t5.c ../cunit/cunit.h validate.h
	$(COMP) $@ $<

#For the tests

t3 : t3.o ../cunit/cunit.o ieee.o
	$(LINK) $@ $^ -lm

t4 : t4.o ../cunit/cunit.o quadfunc.o
	$(LINK) $@ $^ -lm

t5 : t5.o ../cunit/cunit.o mock_validate_deps.o validate.o
	$(LINK) $@ $^ -lm

test : t3 t4 t5
	./t3
	./t4
	./t5

#Miscellaneous

squeaky :: clean
	rm -f t3 &>/dev/null
	rm -f t4 &>/dev/null
	rm -f t5 &>/dev/null
