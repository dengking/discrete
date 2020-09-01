#ifndef _COMPLEX_H
#define	_COMPLEX_H
typedef struct{
	double real;/*实部*/
	double magic;/*虚部*/
}Complex;/*复数类型*/
void printComplex(Complex);/*复数的输出*/
int isZero(Complex);/*检测是否为0*/
Complex compSum(Complex,Complex);/*复数相加*/
Complex compDiff(Complex,Complex);/*复数想减*/
Complex compProd(Complex,Complex);/*复数相乘*/
Complex compQuot(Complex,Complex);/*复数相除*/
#endif	/* _COMPLEX_H */
