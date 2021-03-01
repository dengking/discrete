#ifndef _RATIONAL_H
#define	_RATIONAL_H
typedef struct{
	unsigned numerator;
	unsigned denominator;
	int sign;
}Rational;
void printRational(Rational);
int rationalIsZero(Rational);
int valueCompare(Rational a, Rational b);
void normaliz(Rational*);
Rational rationalSum(Rational,Rational);
Rational rationalDiff(Rational,Rational);
Rational rationalProd(Rational,Rational);
Rational rationalQuot(Rational,Rational);
#endif	/* _RATIONAL_H */
