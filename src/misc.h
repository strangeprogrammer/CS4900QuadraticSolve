#ifndef MISC_H
#define MISC_H

typedef enum bool{
	true=1,
	false=0
} bool;

bool isquad(float a,float b,float c);

typedef struct intercepts{
	float low,high;
	int numroots;
} intercepts;

#endif //MISC_H
