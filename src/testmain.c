#include "libraries.h"
#include "misc.h"
#include "parsing.h"
#include "testing.h"
#include "ieee.h"
#include "quadratic.h"
#include "validate.h"

int main(int argc,char* argv[]){
	testGetArg();
	testCheckArgs();
	testFeq();
	testIsQuad();
	exit(SUCCESS);
}
