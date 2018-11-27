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

t_isq_feq.o : t_isq_feq.c ../cunit/cunit.h ieee.h
	$(COMP) $@ $<

t_qfunc.o : t_qfunc.c ../cunit/cunit.h quadfunc.h
	$(COMP) $@ $<

t_valid.o : t_valid.c ../cunit/cunit.h validate.h
	$(COMP) $@ $<

#Tests

t_isq_feq : t_isq_feq.o ../cunit/cunit.o ieee.o
	$(LINK) $@ $^ -lm

t_qfunc : t_qfunc.o ../cunit/cunit.o quadfunc.o
	$(LINK) $@ $^ -lm

t_valid : t_valid.o ../cunit/cunit.o mock_validate_deps.o validate.o
	$(LINK) $@ $^ -lm

test :: t_isq_feq
	./t_isq_feq

test :: t_qfunc
	./t_qfunc

test :: t_valid
	./t_valid

#Miscellaneous

squeaky ::
	rm -f t_isq_feq &>/dev/null

squeaky ::
	rm -f t_qfunc &>/dev/null

squeaky ::
	rm -f t_valid &>/dev/null
