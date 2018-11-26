#include "misc.h"

char* err_str[]={
	"",//No error, no string
	"Error: this program needs 3 arguments exactly.\n",
	"Error: could not convert argument '%s' to a float.\n",
	"Error: argument '%s' causes underflow.\n",
	"Error: argument '%s' causes overflow.\n",
	"Error: argument '%s' is not a number.\n"
};
