include ../make.i

#For the actual program

linear.o : linear.c linear.h ../fp/ieee.h ../misc.h
	$(COMP) $@ $<

quadratic.o : quadratic.c quadratic.h ../libraries.h ../fp/ieee.h
	$(COMP) $@ $<

#For the tests

t_quad_line.o : t_quad_line.c ../cunit/cunit.h quadratic.h linear.h ../misc.h
	$(COMP) $@ $<

t_quad_line : t_quad_line.o ../cunit/cunit.o quadratic.o linear.o ../fp/ieee.o
	$(LINK) $@ $^ -lm

test :: t_quad_line
	./t_quad_line

#Miscellaneous

squeaky ::
	rm -f t_quad_line &>/dev/null
