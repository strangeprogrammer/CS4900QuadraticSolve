include make.i

#Useful Macros

OBJECTS :=	fp/ieee.o		\
		fp/validate.o		\
		parsing/parsing.o	\
		solver/linear.o		\
		solver/quadratic.o

#For the actual program

default :: quadsolve

quadsolve : main.o $(OBJECTS)
	$(LINK) $@ $^ -lm

main.o : main.c libraries.h misc.h parsing/parsing.h
	$(COMP) $@ $<

$(OBJECTS) : force
	$(MAKE) -C  $(dir $@) $(notdir $@)

#For the tests

runall : solver/t1.o parsing/t2.o fp/t3.o fp/t4.o
	./t1 && ./t2 && ./t3 && ./t4 && ./t5

tests : t1 t2 t3 t4 t5
	$(t1) $(t2) $(t3) $(t4) $(t5)

t1 : solver/t1.o cunit.o solver/quadratic.o solver/linear.o fp/ieee.o
	$(LINK) t1 solver/t1.o cunit.o solver/quadratic.o solver/linear.o fp/ieee.o -lm

t2 : parsing/t2.o cunit.o  parsing/parsing.o
	$(LINK) t2 parsing/t2.o cunit.o parsing/parsing.o -lm

t3 : fp/t3.o cunit.o fp/ieee.o
	$(LINK) t3 fp/t3.o cunit.o fp/ieee.o -lm

t4 : fp/t4.o cunit.o fp/validate.o fp/ieee.o
	$(LINK) t4 fp/t4.o cunit.o fp/validate.o fp/ieee.o -lm

t5 : fp/validate_feq_test.o cunit.o fp/mock_validate_feq.o fp/validate.o
	$(LINK) t5 fp/validate_feq_test.o cunit.o fp/mock_validate_feq.o fp/validate.o -lm


#Dependencies from headers
solver/t1.o : cunit.h solver/quadratic.h solver/linear.h misc.h

parsing/t2.o : cunit.h parsing/parsing.h 

fp/t3.o : cunit.h fp/ieee.h

fp/t4.o : cunit.h misc.h fp/validate.h fp/ieee.h

fp/validate_feq_test.o : cunit.h fp/validate.h fp/mock_validate_feq.h


#Miscellaneous

.PHONY : squeaky

clean ::
	$(MAKE) -C fp clean
	$(MAKE) -C parsing clean
	$(MAKE) -C solver clean

squeaky : clean
	rm -f quadsolve &>/dev/null
	rm -f t1 &>/dev/null
	rm -f t2 &>/dev/null
	rm -f t3 &>/dev/null
	rm -f t4 &>/dev/null
	rm -f t5 &>/dev/null
