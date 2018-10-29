

CFLAGS= -Wall -pedantic -std=c99
CC= gcc
LIBS=-lm
SRC=makefile cunit.c cunit.h ../solver/mock_quadratic.c ../solver/mock_quadratic.h 

test: t1

t1: t1.o ../solver/quadratic.o cunit.o 
	${CC} -o t1 t1.o ../solver/quadratic.o cunit.o ${LIBS}

mock_quadratic.o: ../solver/quadratic.o ../solver/quadratic.h
cunit.o: cunit.h
t1.o: cunit.h ../solver/quadratic.h


# exanple of preprocessor macro useage
#test_macros: test_macros.c
#
#unit_tests.tar: ${SRC}
#	tar cvf unit_tests.tar ${SRC}


clean:
	-rm -f ${EXES} core *.log *.o *.exe qsolve t1 *.tar