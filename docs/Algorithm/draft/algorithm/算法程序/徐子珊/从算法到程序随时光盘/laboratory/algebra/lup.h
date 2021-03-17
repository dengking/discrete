#ifndef _LUP_H
#define	_LUP_H
#include "matrix.h"
Matrix lupDecomposition(Matrix a, int *pi);
double* lupSolve(Matrix lu, int *pi, double *b);
Matrix matrixInverse(Matrix a);
rMatrix rlupDecomposition(rMatrix a, int *pi);
Rational* rlupSolve(rMatrix lu, int *pi, Rational *b);
#endif	/* _LUP_H */
