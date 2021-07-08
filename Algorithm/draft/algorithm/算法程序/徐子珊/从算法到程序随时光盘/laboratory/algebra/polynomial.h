#ifndef _POLYNOMIAL_H
#define	_POLYNOMIAL_H
#include "complex.h"
typedef struct{/*多项式类型*/
	Complex *coeff;/*系数表*/
	int degree;/*次数*/
}Polynomial;
Polynomial newPoly(int n);/*生成0多项式*/
Polynomial newPolyByArry(double *, int n);/*用数组数据生成多项式*/
void clrPoly(Polynomial);/*清理多项式空间*/
void printPoly(Polynomial);/*输出多项式*/
Polynomial polySum(Polynomial,Polynomial);/*多项式的和*/
Polynomial polyProd(Polynomial f, Polynomial g);
double horner(Polynomial, double);/*霍纳法计算多项式的值*/
#endif	/* _POLYNOMIAL_H */
