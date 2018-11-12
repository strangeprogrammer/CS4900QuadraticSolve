#include "../cunit.h"
#include "validate.h"

int main(){
	cunit_init();//Initialize testing framework
	
	//TEST NUMROOTS==0
	//Test 1
	//Real-ish data
	float	a1=0,
		b1=0,
		c1=50;
	intercepts x1={	.low=0,
			.high=0,
			.numroots=0};
	assert_eq("validate didn't return correct value",validate(a1,b1,c1,x1),false);
	
	//Test 2
	//Garbage data
	float	a2=1,
		b2=2,
		c2=3;
	intercepts x2={	.low=4,
			.high=5,
			.numroots=0};
	assert_eq("validate didn't return correct value",validate(a2,b2,c2,x2),false);
	
	//TEST NUMROOTS=1
	//Test 3
	//Real data (line)
	float	a3=0,
		b3=2,
		c3=4;
	intercepts x3={	.low=-2,
			.high=0,
			.numroots=1};
	assert_eq("validate didn't return correct value",validate(a3,b3,c3,x3),true);
	
	//Test 4
	//Garbage data (line)
	float	a4=0,
		b4=10,
		c4=200;
	intercepts x4={	.low=8,
			.high=0,
			.numroots=1};
	assert_eq("validate didn't return correct value",validate(a4,b4,c4,x4),false);
	
	//Test 5
	//Real data (quadratic)
	float	a5=4,
		b5=8,
		c5=4;
	intercepts x5={	.low=-1,
			.high=0,
			.numroots=1};
	assert_eq("validate didn't return correct value",validate(a5,b5,c5,x5),true);
	
	//Test 6
	//Real data (quadratic)
	float	a6=1,
		b6=0,
		c6=0;
	intercepts x6={	.low=0,
			.high=0,
			.numroots=1};
	assert_eq("validate didn't return correct value",validate(a6,b6,c6,x6),true);
	
	//Test 7
	//Garbage data (quadratic)
	float	a7=9,
		b7=18,
		c7=9;
	intercepts x7={	.low=-5800,
			.high=0,
			.numroots=1};
	assert_eq("validate didn't return correct value",validate(a7,b7,c7,x7),false);
	
	//TEST NUMROOTS=2
	//Test 8
	//Real data (quadratic)
	//(3*x+5)*(-4*x-2)=0
	//-12*x^2-26*x-10=0
	//x in {-5/3,-1/2}
	float	a8=-12,
		b8=-26,
		c8=-10;
	intercepts x8={	.low=-0.6666666666666666666666,
			.high=-0.5,
			.numroots=2};
	assert_eq("validate didn't return correct value",validate(a8,b8,c8,x8),true);
	
	//Test 9
	//Real data (quadratic)
	//(20*x-2)*(4*x-8)=0
	//80*x^2-168*x+16=0
	//x in {1/10,2}
	float	a9=80,
		b9=-168,
		c9=16;
	intercepts x9={.low=0.1,
			.high=2,
			.numroots=2};
	assert_eq("validate didn't return correct value",validate(a9,b9,c9,x9),true);
	
	//Test 10
	//Garbage data (quadratic)
	//(3*x+6)*(x/2-9)=0
	//3/2*x^2-24*x-54=0
	//x in {-2,18}
	float	a10=1.5,
		b10=-24,
		c10=-54;
	intercepts x10={.low=-3,
			.high=19,
			.numroots=2};
	assert_eq("validate didn't return correct value",validate(a10,b10,c10,x10),false);
	
	return 0;
}
