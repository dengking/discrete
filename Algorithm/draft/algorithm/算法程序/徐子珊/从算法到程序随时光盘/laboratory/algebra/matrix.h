//定义矩阵的数据类型以及对矩阵进行创建，空间清理等等维护的函数

#ifndef _MATRIX_H
#define	_MATRIX_H
#include "rational.h"

typedef struct{/*矩阵类型定义*/
	double *tab;/*二维数表*/
	int row,col;/*行数、列数*/
}Matrix;


Matrix newMatrix(int, int);/*生成0矩阵*/
Matrix newMatrixByArry(double*, int, int);/*用数组数据生成矩阵，第一个参数为指向源数组的指针，用它来初始化目标矩阵*/
void clrMatrix(Matrix);/*清理矩阵空间*/
void printMatrix(Matrix);/*输出矩阵*/
Matrix matrixAdd(Matrix, Matrix);/*矩阵相加*/
Matrix matrixDiff(Matrix, Matrix);/*矩阵相减*/
Matrix matrixMultiply(Matrix, Matrix);/*矩阵相乘*/
Matrix transform(Matrix);/*矩阵转置*/
void swapRows(Matrix a, int i, int j);/*交换两行*/


typedef struct{
	Rational *tab;/*二维数表*/
	int row,col;/*行数、列数*/
}rMatrix;
rMatrix rnewMatrix(int, int);/*生成0矩阵*/
rMatrix rnewMatrixByArry(Rational*, int, int);/*用数组数据生成矩阵*/
void rclrMatrix(rMatrix);/*清理矩阵空间*/
void rprintMatrix(rMatrix a);
void rswapRows(rMatrix a, int i, int j);/*交换两行*/
#endif	/* _MATRIX_H */
