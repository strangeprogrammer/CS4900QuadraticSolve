#ifndef MISC_H
#define MISC_H
#define MAX_UI_SIZE 100

typedef enum bool{
	true=	1,
	false=	0
} bool;

typedef struct intercepts{
	float	low,
		high;
	int numroots;
} intercepts;

typedef struct values
{
	char num1[MAX_UI_SIZE/3];
	char num2[MAX_UI_SIZE/3];
	char num3[MAX_UI_SIZE/3];
	int count;
	
} Values;

char *userInput();
Values *tokenizer(char *str);

typedef enum err_code{
	SUCCESS=	0,
	NUMARG_ERR=	1,
	BADARG_ERR=	2,
	UNDERFLOW_ERR=	3,
	OVERFLOW_ERR=	4,
	NANARG_ERR=	5
} err_code;




#endif //MISC_H
