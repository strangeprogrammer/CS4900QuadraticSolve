include ../make.i

#For the actual program

ieee.o : ieee.c ../libraries.h ../misc.h
	$(COMP) $@ $<

validate.o : validate.c ../misc.h validate.h ieee.h
	$(COMP) $@ $<

#For the tests

t3.o : t3.c ../cunit.h ieee.h
	$(COMP) $@ $<

t3 : t3.o ../cunit.o ieee.o
	$(LINK) $@ $^ -lm

t4.o : t4.c ../cunit.h ../misc.h validate.h ieee.h
	$(COMP) $@ $<

t4 : t4.o ../cunit.o validate.o ieee.o
	$(LINK) $@ $^ -lm

validate_feq_test.o : ../cunit.h validate.h mock_validate_feq.h
	$(COMP) $@ $^

test : t3 t4
	./t3
	./t4

#Miscellaneous

squeaky :: clean
	rm -f t3 &>/dev/null
	rm -f t4 &>/dev/null
