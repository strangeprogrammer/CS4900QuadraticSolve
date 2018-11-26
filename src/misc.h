#ifndef MISC_H
#define MISC_H

typedef enum bool{
	false=	0,
	true=	1
} bool;

typedef struct intercepts{
	float	low,
		high;
	int numroots;
} intercepts;

typedef enum err_code{
	SUCCESS		= 0,
	NUMARG_ERR	= 1,
	BADARG_ERR	= 2,
	UNDERFLOW_ERR	= 3,
	OVERFLOW_ERR	= 4,
	NANARG_ERR	= 5,
	SCANF_ERR	= 6,
	INTERNAL_ERR	= 7
} err_code;

extern char* err_str[];

#endif //MISC_H
