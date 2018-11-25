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

	char* num1;
	char* num2;
	char* num3;
	// float num1;
	// float num2;
	// float num3;
	int count;
	
} Values;


Values *userInput();
int checker(char* s);
void cleanBuff();

typedef enum err_code{
	SUCCESS=	0,
	NUMARG_ERR=	1,
	BADARG_ERR=	2,
	UNDERFLOW_ERR=	3,
	OVERFLOW_ERR=	4,
	NANARG_ERR=	5
} err_code;




#endif //MISC_H
