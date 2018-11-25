#include "../libraries.h"
#include "../misc.h"



Values *userInput(){
	char *input = malloc(sizeof(char)*MAX_UI_SIZE);
	Values *vals = (Values *) malloc(sizeof(Values));

	int d = 1,e = 1,f = 1;

	while(d > 0){
	    printf("Enter the first value:");
	    d = scanf("%s", input);
		
		vals->num1 = malloc(sizeof(char)*MAX_UI_SIZE);
		strcpy(vals->num1, input);
		// printf("%s", vals->num1);
		d = checker(vals->num1);
		if(d > 0){
			printf("Please enter a numerical value, ex: \"420\" or \"18.1\"\n");
		}
		// printf("%d\n", d);
	    cleanBuff();
	}
	while(e > 0){
	    printf("Enter the second value:");
	    e = scanf("%s", input);

		vals->num2 = malloc(sizeof(char)*MAX_UI_SIZE);
		strcpy(vals->num2, input);
		// printf("%s", vals->num2);
		e = checker(vals->num2);
		if(e > 0){
			printf("Please enter a numerical value, ex: \"420\" or \"18.1\"\n");
		}
	    cleanBuff();
	}
	while(f > 0){
	    printf("Enter the third value:");
	    f = scanf("%s", input);

		vals->num3 = malloc(sizeof(char)*MAX_UI_SIZE);
		strcpy(vals->num3, input);
		// printf("%s", vals->num3);

		f = checker(vals->num3);
	    if(f > 0){
			printf("Please enter a numerical value, ex: \"420\" or \"18.1\"\n");
		}
	    cleanBuff();
	}
   // vals->num1 = a;
   // vals->num2 = b;
   // vals->num3 = c;


	return vals;
}


void cleanBuff(){
    int n;
    while((n = getchar()) != EOF && n != '\n' );
}
int checker(char* str){
	int ret = 0;
	int dec = 0;

	for(int i = 0; i < strlen(str); i++){
		if((isdigit(str[i])) || str[i] == '.'){
			if (str[i] == '.')
			{
				dec++;
			}
		}
		else{
			ret++;
		}

		if(dec > 1){
			ret++;
		}
		
	}

	return ret;
}