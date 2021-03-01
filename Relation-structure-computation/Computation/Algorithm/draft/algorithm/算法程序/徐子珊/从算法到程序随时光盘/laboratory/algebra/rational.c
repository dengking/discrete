#include "rational.h"
#include <stdio.h>
#include <assert.h>
static long long gcd(long long a, long long b){
	long long r;
	while(b){
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
void printRational(Rational a){
	if(a.sign)
		putchar('-');
	if(a.denominator>1)
		printf("%d/%d",a.numerator,a.denominator);
	else
		printf("%d",a.numerator);
}
void normaliz(Rational *a){
	unsigned g=(unsigned)gcd(a->numerator,a->denominator);
	a->numerator/=g;
	a->denominator/=g;
	if(a->numerator==0)
		a->sign=0;
}
int valueCompare(Rational a, Rational b){
	if(a.numerator*b.denominator>a.denominator*b.numerator)
		return 1;
	if(a.numerator*b.denominator==a.denominator*b.numerator)
		return 0;
	return -1;
}
int rationalIsZero(Rational a){
	return a.numerator==0;
}
Rational rationalSum(Rational a,Rational b){
	long long n,d=a.denominator*b.denominator,g;
	Rational c;
	if(a.sign==b.sign){
		c.sign=a.sign;
		n=a.numerator*b.denominator+b.numerator*a.denominator;
	}else	if(a.numerator*b.denominator>a.denominator*b.numerator){
		n=a.numerator*b.denominator-a.denominator*b.numerator;
		c.sign=a.sign;
	}else{
		n=a.denominator*b.numerator-a.numerator*b.denominator;
		c.sign=b.sign;
	}
	g=gcd(n,d);
	c.numerator=(unsigned)(n/g);
	c.denominator=(unsigned)(d/g);
	if(c.numerator==0)
		c.sign=0;
	return c;
}
Rational rationalDiff(Rational a, Rational b){
	Rational b1=b;
	b1.sign=!b1.sign;
	return rationalSum(a,b1);
}
Rational rationalProd(Rational a,Rational b){
	long long n=a.numerator*b.numerator,
		d=a.denominator*b.denominator,
		g=gcd(n,d);
	Rational c;
	c.numerator=(unsigned)(n/g);
	c.denominator=(unsigned)(d/g);
	c.sign=(a.sign==b.sign?0:1);
	if(c.numerator==0)
		c.sign=0;
	return c;
}
Rational rationalQuot(Rational a,Rational b){
	Rational b1={b.denominator,b.numerator,b.sign};
	assert(b1.denominator);
	return rationalProd(a,b1);
}