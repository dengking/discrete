#ifndef _COMPLEX_H
#define	_COMPLEX_H
typedef struct{
	double real;/*ʵ��*/
	double magic;/*�鲿*/
}Complex;/*��������*/
void printComplex(Complex);/*���������*/
int isZero(Complex);/*����Ƿ�Ϊ0*/
Complex compSum(Complex,Complex);/*�������*/
Complex compDiff(Complex,Complex);/*�������*/
Complex compProd(Complex,Complex);/*�������*/
Complex compQuot(Complex,Complex);/*�������*/
#endif	/* _COMPLEX_H */
