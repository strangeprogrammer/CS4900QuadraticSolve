include ../make.i

SRC = makefile mock_ieee_feq.c mock_ieee_feq.h  mock_ieee_isquad.c \
  mock_ieee_isquad.h mock_linear.c mock_linear.h mock_parsing_getarg.c \
  mock_parsing_getarg.h mock_quadratic.c mock_quadratic.h mock_validate_quadfunc.c \
  mock_validate_quadfunc.h mock_validate_validate.c mock_validate_validate.h \
  cunit.c cunit.h t1.c


#Targets:

all ::
	gcc -Wall -pedantic -std=c99 -c *.c

t1 : t1.o cunit.o ../solver/quadratic.o ../fp/ieee.o
	$(LINK) t1 t1.o cunit.o ../solver/quadratic.o ../fp/ieee.o -lm



#Dependencies from headers

t1.o : t1.c cunit.h ../solver/quadratic.h ../misc.h

mock_ieee_feq.o : mock_ieee_feq.c ../libraries.h ../misc.h mock_ieee_feq.h

mock_ieee_isquad.o : mock_ieee_isquad.c mock_ieee_isquad.h ../libraries.h 

mock_linear.o : mock_linear.c mock_linear.h ../libraries.h 

mock_parsing_getarg.o : mock_parsing_getarg.c mock_parsing_getarg.h ../libraries.h

mock_quadratic.o : mock_quadratic.c mock_quadratic.h ../libraries.h

mock_validate_quadfunc.o : mock_validate_quadfunc.c mock_validate_quadfunc.h ../libraries.h

mock_validate_validate.o : mock_validate_validate.c mock_validate_validate.h ../libraries.h

#	$(COMP) $@ $<	


