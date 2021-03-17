//�����������������Լ��Ծ�����д������ռ�����ȵ�ά���ĺ���

#ifndef _MATRIX_H
#define	_MATRIX_H
#include "rational.h"

typedef struct{/*�������Ͷ���*/
	double *tab;/*��ά����*/
	int row,col;/*����������*/
}Matrix;


Matrix newMatrix(int, int);/*����0����*/
Matrix newMatrixByArry(double*, int, int);/*�������������ɾ��󣬵�һ������Ϊָ��Դ�����ָ�룬��������ʼ��Ŀ�����*/
void clrMatrix(Matrix);/*�������ռ�*/
void printMatrix(Matrix);/*�������*/
Matrix matrixAdd(Matrix, Matrix);/*�������*/
Matrix matrixDiff(Matrix, Matrix);/*�������*/
Matrix matrixMultiply(Matrix, Matrix);/*�������*/
Matrix transform(Matrix);/*����ת��*/
void swapRows(Matrix a, int i, int j);/*��������*/


typedef struct{
	Rational *tab;/*��ά����*/
	int row,col;/*����������*/
}rMatrix;
rMatrix rnewMatrix(int, int);/*����0����*/
rMatrix rnewMatrixByArry(Rational*, int, int);/*�������������ɾ���*/
void rclrMatrix(rMatrix);/*�������ռ�*/
void rprintMatrix(rMatrix a);
void rswapRows(rMatrix a, int i, int j);/*��������*/
#endif	/* _MATRIX_H */
