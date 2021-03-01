#include <assert.h>
#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include "matrix.h"

///////////////////////////////////��ͨ����////////////////////////////////////////
Matrix newMatrix(int m, int n){/*����0����*/
	Matrix a;
	assert(m>=0&&n>=0);
	a.row=m;a.col=n;
	a.tab=(double*)calloc(m*n, sizeof(double));
	return a;
}
Matrix newMatrixByArry(double* a, int m,int n){/*�������������ɾ���*/
	Matrix b=newMatrix(m,n);
	memcpy(b.tab,a,n*m*sizeof(double));
	return b;
}
void clrMatrix(Matrix a){/*�������ռ�*/
	free(a.tab);
}
void printMatrix(Matrix a){/*�������*/
	int i, j;
	for(i=0;i<a.row;i++){
		for(j=0;j<a.col;j++)
			printf("%f ", a.tab[i*a.col + j]);/*�˴���Ҫ�ر�ע�⣬��Ϊ�����������洢�����������ڴ������������еģ�
											   �������߼������к��У�Ϊ��������Ҫ���������±�;���Ԫ���±�Ķ�Ӧ��ϵ�������±�k=i*a.col + j*/
		putchar('\n');
	}
}
Matrix transform(Matrix a){/*��������ת��*/
	int i, j,m=a.col,n=a.row;
	Matrix b=newMatrix(m, n);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			b.tab[i*n + j] = a.tab[j*m + i];/*A[j,i]��ӦB[j,i]����B����������A������*/
	return b;
}
Matrix matixAdd(Matrix a, Matrix b){/*�������*/
	Matrix c;
	int i,j,m=a.col,n=a.row;
	assert(m==b.row&&n==b.col);
	c=newMatrix(m,n);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			c.tab[i*n+j]=a.tab[i*n+j]+b.tab[i*n+j];
	return c;
}
Matrix matrixDiff(Matrix a, Matrix b){/*�������*/
	Matrix c;
	int i,j,m=a.col,n=a.row;
	assert(m==b.row&&n==b.col);
	c=newMatrix(m,n);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			c.tab[i*n+j]=a.tab[i*n+j]-b.tab[i*n+j];
	return c;
}
Matrix matrixProd(Matrix a, Matrix b){/*�������*/
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
void swapRows(Matrix a, int i, int j){/*����i��j����*/
	double *tmp=(double*)calloc(a.col,sizeof(double));
	memcpy(tmp,a.tab+i*a.col, a.col*sizeof(double));
	memcpy(a.tab+i*a.col,a.tab+j*a.col,a.col*sizeof(double));
	memcpy(a.tab+j*a.col,tmp,a.col*sizeof(double));
	free(tmp);
}




///////////////////////////////////////////////����������/////////////////////////////////////////
rMatrix rnewMatrix(int m, int n){/*����0����*/
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
rMatrix rnewMatrixByArry(Rational *a, int m, int n){/*�������������ɾ���*/
	rMatrix b=rnewMatrix(m,n);
	memcpy(b.tab,a,n*m*sizeof(Rational));
	return b;
}
void rprintMatrix(rMatrix a){/*�������*/
	int i, j;
	for(i=0;i<a.row;i++){
		for(j=0;j<a.col;j++){
			printRational(a.tab[i*a.col+j]);
			putchar(' ');
		}
		putchar('\n');
	}
}
void rclrMatrix(rMatrix a){/*�������ռ�*/
	free(a.tab);
}
void rswapRows(rMatrix a, int i, int j){/*��������*/
	Rational *tmp=(Rational*)calloc(a.col,sizeof(Rational));
	memcpy(tmp,a.tab+i*a.col, a.col*sizeof(Rational));
	memcpy(a.tab+i*a.col,a.tab+j*a.col,a.col*sizeof(Rational));
	memcpy(a.tab+j*a.col,tmp,a.col*sizeof(Rational));
	free(tmp);
}
