#Useful Macros

CC	:= gcc
CFLAGS 	:= -Wall -pedantic -std=c99
COMP	:= $(CC) $(CFLAGS) -c -o
LINK	:= $(CC) $(CFLAGS) -o

#Miscellaneous

.PHONY : default clean force

default ::

clean ::
	rm -f *.o &>/dev/null
