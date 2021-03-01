#include <assert.h>
#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include "matrix.h"

///////////////////////////////////普通矩阵////////////////////////////////////////
Matrix newMatrix(int m, int n){/*生成0矩阵*/
	Matrix a;
	assert(m>=0&&n>=0);
	a.row=m;a.col=n;
	a.tab=(double*)calloc(m*n, sizeof(double));
	return a;
}
Matrix newMatrixByArry(double* a, int m,int n){/*用数组数据生成矩阵*/
	Matrix b=newMatrix(m,n);
	memcpy(b.tab,a,n*m*sizeof(double));
	return b;
}
void clrMatrix(Matrix a){/*清理矩阵空间*/
	free(a.tab);
}
void printMatrix(Matrix a){/*输出矩阵*/
	int i, j;
	for(i=0;i<a.row;i++){
		for(j=0;j<a.col;j++)
			printf("%f ", a.tab[i*a.col + j]);/*此处需要特别注意，因为是用数组来存储矩阵，数组在内存中是连续排列的，
											   而矩阵逻辑是有行和列，为此我们需要建立数组下标和矩阵元素下标的对应关系：数组下标k=i*a.col + j*/
		putchar('\n');
	}
}
Matrix transform(Matrix a){/*计算矩阵的转置*/
	int i, j,m=a.col,n=a.row;
	Matrix b=newMatrix(m, n);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			b.tab[i*n + j] = a.tab[j*m + i];/*A[j,i]对应B[j,i]，且B的列数等于A的行数*/
	return b;
}
Matrix matixAdd(Matrix a, Matrix b){/*矩阵相加*/
	Matrix c;
	int i,j,m=a.col,n=a.row;
	assert(m==b.row&&n==b.col);
	c=newMatrix(m,n);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			c.tab[i*n+j]=a.tab[i*n+j]+b.tab[i*n+j];
	return c;
}
Matrix matrixDiff(Matrix a, Matrix b){/*矩阵相减*/
	Matrix c;
	int i,j,m=a.col,n=a.row;
	assert(m==b.row&&n==b.col);
	c=newMatrix(m,n);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			c.tab[i*n+j]=a.tab[i*n+j]-b.tab[i*n+j];
	return c;
}
Matrix matrixProd(Matrix a, Matrix b){/*矩阵相乘*/
	Matrix c;
	int i,j,k;
	assert(a.col==b.row);
	c=newMatrix(a.row,b.col);
	for(i=0;i<a.row;i++)
		for(j=0;j<b.col;j++)
			for(k=0;k<a.col;k++)
				c.tab[i*c.col+j]+=a.tab[i*a.col+k]*b.tab[k*b.col+j];
	return c;
}
void swapRows(Matrix a, int i, int j){/*交换i、j两行*/
	double *tmp=(double*)calloc(a.col,sizeof(double));
	memcpy(tmp,a.tab+i*a.col, a.col*sizeof(double));
	memcpy(a.tab+i*a.col,a.tab+j*a.col,a.col*sizeof(double));
	memcpy(a.tab+j*a.col,tmp,a.col*sizeof(double));
	free(tmp);
}




///////////////////////////////////////////////有理数矩阵/////////////////////////////////////////
rMatrix rnewMatrix(int m, int n){/*生成0矩阵*/
	int i,j;
	rMatrix a;
	assert(m>=0&&n>=0);
	a.row=m;a.col=n;
	a.tab=(Rational*)calloc(m*n, sizeof(Rational));
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			a.tab[i*n+j].denominator=1;
	return a;
}
rMatrix rnewMatrixByArry(Rational *a, int m, int n){/*用数组数据生成矩阵*/
	rMatrix b=rnewMatrix(m,n);
	memcpy(b.tab,a,n*m*sizeof(Rational));
	return b;
}
void rprintMatrix(rMatrix a){/*输出矩阵*/
	int i, j;
	for(i=0;i<a.row;i++){
		for(j=0;j<a.col;j++){
			printRational(a.tab[i*a.col+j]);
			putchar(' ');
		}
		putchar('\n');
	}
}
void rclrMatrix(rMatrix a){/*清理矩阵空间*/
	free(a.tab);
}
void rswapRows(rMatrix a, int i, int j){/*交换两行*/
	Rational *tmp=(Rational*)calloc(a.col,sizeof(Rational));
	memcpy(tmp,a.tab+i*a.col, a.col*sizeof(Rational));
	memcpy(a.tab+i*a.col,a.tab+j*a.col,a.col*sizeof(Rational));
	memcpy(a.tab+j*a.col,tmp,a.col*sizeof(Rational));
	free(tmp);
}
