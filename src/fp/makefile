include ../make.i

#For the actual program

ieee.o : ieee.c ../libraries.h ../misc.h
	$(COMP) $@ $<

validate.o : validate.c ../misc.h validate.h ieee.h
	$(COMP) $@ $<

#Mock objects

validate_feq_test.o : validate_feq_test.c ../cunit.h validate.h mock_validate_feq.h
	$(COMP) $@ $<

mock_validate_feq.o : mock_validate_feq.c mock_validate_feq.h ../libraries.h  ieee.h ../misc.h
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

t5 : validate_feq_test.o ../cunit.o mock_validate_feq.o validate.o
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
