//  testing.c
//  Created by Daniel Darcy on 10/6/18.
//
//  Each function can be tested by simply inserting a test<desiredfunction>()
//    at the bottom of main

#include "libraries.h"
#include "misc.h"
#include "parsing/parsing.h"
#include "fp/ieee.h"


//Test getarg function x
void testGetArg(){    //getarg returns float

  float x = 5;
  printf("\ngetarg: (should be 4 errors below)\n");   //4 fails
  x = x + getarg("0");    //Zero case
  x = x + getarg("1");    //Int case
  x = x + getarg("-1");   //Negative int case
  x = x + getarg("2.00");   //Decimal case
  x = x + getarg("-2.00");    //Negative decimal case
  getarg(".00000000000000000000000000000000000000000000043");   //Underflow x
  getarg("100000000000000000000000000000000000000000000043");   //Overflow x
  x = x + getarg("5.85845839309");
  x = x + getarg("-5.85845839309");
  getarg("hello");    //Word x
  getarg("nan");          //nan x

  if(x == 5){
    printf("*** getArg function is stable - parsing.c ***\n");
  }
  else{
    printf("*** getArg function is NOT stable - parsing.c ***\n");
  }
}


//Test checkargs function x
void testCheckArgs(){   //Will only ever get an int (return is void)

  printf("\ncheckargs: (should be 5 errors below)\n");
  checkargs(1);
  checkargs(0);
  checkargs(5);
  checkargs(4);   //Correct
  checkargs(0);
  checkargs(9);

  printf("*** checkArgs function is stable - parsing.c ***\n\n");
}


//Test feq function x
void testFeq(){ //feq returns boolean

  printf("feq:\n");
  int testInt = 0;

  bool test1 = feq(10, 9);    //a,b,c    return false
  bool test2 = feq(8.00001, 8.00001);    //return true
  bool test3 = feq(0, 1);      //return false
  bool test4 = feq(10.00001, 10);   //return true
  bool test5 = feq(10, 10.00001);   //return true

  if((test4 == true) && (test5 == true) && (test1 == false) &&
    (test2 == true) && (test3 == false))   //return true
    printf("*** feq function is stable - ieee.c ***\n\n");
  else{
    printf("*** feq function is NOT stable - ieee.c ***\n\n");
  }
}


//Test isQuad function x
void testIsQuad(){    //isquad returns boolean

  printf("isquad: \n");   //4 fails
  bool broken = false;
  bool booleanArray[7];
  //isquad("hey", "howya", "dern");   //False
  //booleanArray[3] = isquad(0, 0, 0);
  booleanArray[0] = isquad(-1, 32, 19284735);   //True vvv
  booleanArray[1] = isquad(19284735, -1, 32);
  booleanArray[2] = isquad(32, 19284735, -1);

  booleanArray[3] = isquad(1, -.0032, -19284735);   //True vvv
  booleanArray[4] = isquad(-19284735, 1, -.0032);
  booleanArray[5] = isquad(-.0032, -19284735, 1);
  booleanArray[6] = isquad(-.858511, -900, -403975);

  for(int i=0; i<7; i++){
    if(booleanArray[i] != true){
      printf("%u", booleanArray[i]);
      printf("%d", i);
      broken = true;
      printf("*** isquad function is NOT stable - ieee.c ***\n\n");
    }
    else if((broken == false) && (i == 6)){
      printf("*** isquad function is stable - ieee.c ***\n\n");
    }
  }
}   //Only not quadratic if invalid strings are given
