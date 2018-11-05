include ../make.i

#Commands "make tests && make runall" -> runs all tests

SRC = makefile cunit.c cunit.h t1.c t2.c t3.c t4.c


#Targets:

all ::
	gcc -Wall -pedantic -std=c99 -c *.c

runall : t1.o t2.o t3.o t4.o
	./t1 && ./t2 && ./t3 && ./t4

tests : t1 t2 t3 t4
	$(t1) $(t2) $(t3) $(t4) $(t5)

t1 : t1.o cunit.o ../solver/quadratic.o ../solver/linear.o ../fp/ieee.o
	$(LINK) t1 t1.o cunit.o ../solver/quadratic.o ../solver/linear.o ../fp/ieee.o -lm

t2 : t2.o cunit.o  ../parsing/parsing.o
	$(LINK) t2 t2.o cunit.o ../parsing/parsing.o -lm

t3 : t3.o cunit.o ../fp/ieee.o
	$(LINK) t3 t3.o cunit.o ../fp/ieee.o -lm

t4 : t4.o cunit.o ../fp/validate.o ../fp/ieee.o
	$(LINK) t4 t4.o cunit.o ../fp/validate.o ../fp/ieee.o -lm


#Dependencies from headers
t1.o : cunit.h ../solver/quadratic.h ../solver/linear.h ../misc.h

t2.o : cunit.h ../parsing/parsing.h 

t3.o : cunit.h ../fp/ieee.h

t4.o : cunit.h ../misc.h ../fp/validate.h ../fp/ieee.h



#Clean

squeaky : clean
	rm -f t1 &>/dev/null
	rm -f t2 &>/dev/null
	rm -f t3 &>/dev/null
	rm -f t4 &>/dev/null
	rm -f t5 &>/dev/null


