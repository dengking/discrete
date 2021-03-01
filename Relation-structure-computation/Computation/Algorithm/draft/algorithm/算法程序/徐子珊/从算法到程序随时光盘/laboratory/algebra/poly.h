#ifndef _POLY_H
#define	_POLY_H
typedef struct{
	double *coeff;
	int degree;
}Poly;
Poly newPoly(int n);
Poly newPolyByArry(double *, int n);
void clrPoly(Poly);
void printPoly(Poly);
void polyAssign(Poly*,Poly);
Poly polySum(Poly,Poly);
Poly polyProd(Poly f, Poly g);
double horner(Poly, double);
Poly derivative(Poly);
void nomalPoly(Poly*);
#endif	/* _POLY_H */
