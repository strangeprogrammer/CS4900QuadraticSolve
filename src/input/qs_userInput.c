#include "../libraries.h"
#include "../misc.h"

/*
	Function takes users input as a string and returns it to calling function
	MAX_UI_SIZE = Maximum user input size
*/

char *userInput(){
	
	
	char *input = malloc(sizeof(char)*MAX_UI_SIZE);
	fgets(input, sizeof(char)*MAX_UI_SIZE,stdin);

	return input;
}
