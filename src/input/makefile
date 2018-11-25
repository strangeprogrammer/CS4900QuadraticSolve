include ../make.i

#For the program

input.o : qs_userInput.c ../libraries.h ../misc.h
	$(COMP) $@ $<

token.o : qs_tokenizer.c ../libraries.h ../misc.h
	$(COMP) $@ $<

#For testing

test ::

#Miscellaneous

squeaky ::
	rm -f t2 &>/dev/null
