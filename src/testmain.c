#include "libraries.h"
#include "misc.h"
#include "parsing/parsing.h"
#include "testing.h"
#include "fp/ieee.h"
#include "solver/quadratic.h"
#include "fp/validate.h"

int main(int argc,char* argv[]){
	testGetArg();
	testCheckArgs();
	testFeq();
	testIsQuad();
	exit(SUCCESS);
}
