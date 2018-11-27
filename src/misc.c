#include "misc.h"

//Idea for this sort of initialization taken from 'https://github.com/qmk/qmk_firmware/blob/master/keyboards/planck/keymaps/default/keymap.c'
char* err_str[]={
	[SUCCESS]=	"",//No error? No problem! No string!
	[NUMARG_ERR]=	"Error: this program needs 3 arguments exactly.\n",
	[BADARG_ERR]=	"Error: could not convert argument to a float.\n",
	[UNDERFLOW_ERR]="Error: argument causes underflow.\n",
	[OVERFLOW_ERR]=	"Error: argument causes overflow.\n",
	[NANARG_ERR]=	"Error: argument is not a number.\n",
	[INTERNAL_ERR]=	"Error: an unexpected error occured.\n",
	[NOARG_ERR]=	"Error: an argument is required.\n"
};
