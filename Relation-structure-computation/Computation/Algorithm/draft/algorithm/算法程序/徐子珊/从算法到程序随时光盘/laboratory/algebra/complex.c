#include "complex.h"
#include <assert.h>
#include <stdio.h>
#include <math.h>
#define eps 1e-3
int isZero(Complex a){
	return ((fabs(a.real)<eps)&&(fabs(a.magic)<eps));
}
void printComplex(Complex a){
	if(fabs(a.magic)<eps){
		printf("%.1f",a.real);
		return;
	}
	printf("%.1f",a.real);
	if(a.magic>0&&fabs(a.real)>=eps)
		putchar('+');
	printf("%.1fi",a.magic);
}
Complex compSum(Complex a,Complex b){
	Complex c;
	c.real=a.real+b.real;
	c.magic=a.magic+b.magic;
	return c;
}
Complex compDiff(Complex a,Complex b){
	Complex c;
	c.real=a.real-b.real;
	c.magic=a.magic-b.magic;
	return c;
}
Complex compProd(Complex a,Complex b){
	Complex c;
	c.real=a.real*b.real-a.magic*b.magic;
	c.magic=a.real*b.magic+a.magic*b.real;
	return c;
}
Complex compQuot(Complex a,Complex b){
	Complex c;
	double r=b.real*b.real+b.magic*b.magic;
	assert(r);
	c.real=(a.real*b.real+a.magic*b.magic)/r;
	c.magic=(a.magic*b.real-a.real*b.magic)/r;
	return c;
}