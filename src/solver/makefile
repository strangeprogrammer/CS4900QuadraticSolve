include ../make.i

#For the actual program

linear.o : linear.c linear.h ../fp/ieee.h ../misc.h
	$(COMP) $@ $<

quadratic.o : quadratic.c quadratic.h ../libraries.h ../fp/ieee.h
	$(COMP) $@ $<

#For the tests

t1.o : t1.c ../cunit/cunit.h quadratic.h linear.h ../misc.h
	$(COMP) $@ $<

t1 : t1.o ../cunit/cunit.o quadratic.o linear.o ../fp/ieee.o
	$(LINK) $@ $^ -lm

test :: t1
	./t1

#Miscellaneous

squeaky ::
	rm -f t1 &>/dev/null
