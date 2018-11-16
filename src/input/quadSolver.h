#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UI_SIZE 100

typedef struct values
{
	char num1[MAX_UI_SIZE/3];
	char num2[MAX_UI_SIZE/3];
	char num3[MAX_UI_SIZE/3];
	int count;
	
} Values;

char *userInput();
Values *tokenizer(char *str);
