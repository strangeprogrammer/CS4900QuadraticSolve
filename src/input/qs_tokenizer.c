#include "quadSolver.h"

/*

	Function takes a string and stores three values from 
	that string into a struct which is passed back to the 
	calling function

*/
Values *tokenizer(char *str){

	char* token;
	char* theRest = str;
	int set = -1;

	Values *vals = (Values *) malloc(sizeof(Values));



	while((token = strtok_r(theRest," ,`~\\*+=!@#$%^&()/-_<>?:;[]{}|\'\"\n", &theRest))){
		

		//Store the three values that will be used for the quad solver
		if (strcmp(vals->num1,"") == 0)
		{
			if(strcmp(token,"") == 0){
			}
			else{
				strcpy(vals->num1,token);
				++vals->count;
			}
		}
		else if (strcmp(vals->num2,"") == 0)
		{			
			if(strcmp(token,"") == 0){
			}
			else{
				strcpy(vals->num2,token);
				++vals->count;
			}
		}
		else if (strcmp(vals->num3,"") == 0)
		{
			if(strcmp(token,"") == 0){
			}
			else{
				strcpy(vals->num3,token);
				++vals->count;
				set = 0;
			}
		}
		else{

			//If user enters more values than needed, inform them.
			if(set == 0)
			{
				printf("\n\tTo many numbers entered");
				printf("\n\tThe following values will not be included:\n");
				printf("\t%s ", token);
				set = 1;
			}
			else if(set == 1){
				printf("%s ", token);
			}
			else{
				printf("ERROR\n");
			}
		}

	}//End of while()


	//Format printing
	printf("\n\n");

	return vals;
}//End of tokenizer()
