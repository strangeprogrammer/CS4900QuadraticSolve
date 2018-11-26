#Useful Macros

CC	:= gcc
CFLAGS 	:= -Wall -pedantic -std=c99
COMP	:= $(CC) $(CFLAGS) -c -o
LINK	:= $(CC) $(CFLAGS) -o

#Miscellaneous

.PHONY : default clean force squeaky test

#Thanks to 'https://stackoverflow.com/a/24005420'
export VERBOSE
ifndef VERBOSE
.SILENT:
endif

default ::

clean ::
	rm -f *.o &>/dev/null

squeaky :: clean
