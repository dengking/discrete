#include<iostream>
#include<assert.h>
#include<string>
#include "matrix.h"

Matrix::Matrix(int m, int n)
{
	assert(m >= 0 && n >= 0);
	row = m;
	col = n;
	tab = (double*)calloc(m*n, sizeof(double));
    
}

void Matrix::clrMatrix()
{
	free(tab);
}

Matrix::Matrix(Matrix &x)
{
	col = x.col;
	row = x.row;
	memcpy(tab,x.tab, col*row*sizeof(double));
}

Matrix Matrix::transform()
{
	int i, j;
	Matrix trans(col, row);
	for (i = 0; i < row;i++)
	for (j = 0; j < col; j++)
		trans.tab[j*row + i] = tab[i*col + j];
	return trans;
}
/*注意在此程序中将一个矩阵存入一维数组是按行存入的。*/

Matrix Matrix::operator+(Matrix &x)
{
	assert(row == x.row&&col == x.col);
	Matrix sum(row,col);
	for (int i = 0; i < row;i++)
	for (int j = 0; j < col; j++)
		sum.tab[i*col + j] = tab[i*col + j] + x.tab[i*col + j];/*(i,j)与矩阵中元素的下标恰好对应*/
	return sum;
}