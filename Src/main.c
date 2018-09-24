#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum bool{
	true=1,
	false=0
} bool;

bool dbleq(double a,double b){
	if(fabs(a-b)<0.005){
		return true;
	}
	return false;
}

int main(int argc,char* argv[]){
	if(argc!=4){
		printf("Error: this program needs 3 arguments exactly.");
		return 1;
	}
	return 0;
}
