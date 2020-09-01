#ifndef _POLYNOMIAL_H
#define	_POLYNOMIAL_H
#include "complex.h"
typedef struct{/*����ʽ����*/
	Complex *coeff;/*ϵ����*/
	int degree;/*����*/
}Polynomial;
Polynomial newPoly(int n);/*����0����ʽ*/
Polynomial newPolyByArry(double *, int n);/*�������������ɶ���ʽ*/
void clrPoly(Polynomial);/*�������ʽ�ռ�*/
void printPoly(Polynomial);/*�������ʽ*/
Polynomial polySum(Polynomial,Polynomial);/*����ʽ�ĺ�*/
Polynomial polyProd(Polynomial f, Polynomial g);
double horner(Polynomial, double);/*���ɷ��������ʽ��ֵ*/
#endif	/* _POLYNOMIAL_H */
