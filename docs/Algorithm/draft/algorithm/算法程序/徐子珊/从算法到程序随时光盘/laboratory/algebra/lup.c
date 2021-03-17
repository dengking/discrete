#include "lup.h"
#include "./../utility/swap.h"
#include <math.h>
#include<assert.h>
#include<stdlib.h>
Matrix lupDecomposition(Matrix a, int *pi){/*此函数将返回两个对象：1矩阵的LU分解，2表示置换矩阵P的数组pi*/
	int i,j,k,k1,n=a.row;
	double p;
	Matrix lu=newMatrixByArry(a.tab,a.row,a.col);
	for(i=0;i<n;i++)
		pi[i] = i;/*初始化的时候，pi[i] = i相当于为矩阵的每行编一个行号*/
	for(k=0;k<n;k++){
		p=0.0;
		for(i=k;i<n;i++)
		if (fabs(lu.tab[i*n + k])>p){/*此for循环的功能是找出第k列中绝对值最大的元素，并且用kl来记录下这个元素所在的行号*/
				p=fabs(lu.tab[i*n+k]);
				k1=i;
			}
			assert(p>1e-10);/*用p>1e-10这种形式表示p！=0，是因为在计算机中浮点数不保证精度以外的数字是否准确，所以浮点型数据需要按照一定的精度判断是否等于0.0*/
		swap(pi+k, pi+k1,sizeof(int));
		swapRows(lu,k,k1);
		for(i=k+1;i<n;i++){
			lu.tab[i*n + k] = lu.tab[i*n + k] / lu.tab[k*n + k];/*此步实现的是v/a[k,k]*/
			for(j=k+1;j<n;j++)
				lu.tab[i*n + j] = lu.tab[i*n + j] - lu.tab[i*n + k] * lu.tab[k*n + j];/*此步实现的是a[i,j]-a[i,k]*a[k,j]*/
		}
	}
	return lu;
}
double* lupSolve(Matrix lu, int *pi, double *b){/*此函数的功能是lup法解线性方程组
												在类似的问题中得到解的通式是非常重要的*/
	int i,j,n=lu.row;
	double *x = (double*)calloc(n, sizeof(double));/*数组x是用来存放解的*/
	for (i = 0; i<n; i++){/*b是方程组右端数组*/
		x[i] = b[pi[i]];/*这步相当重要，虽然它非常简单，但是这种方法是值得我学习的*/
		for (j = 0; j<i; j++)                    /*这个嵌套的for循环所实现的功能是y3= b[pi[i]]-(l31y1+l32y2)
												 作者的这种实现方法是值得我学习的*/
			x[i]=x[i]-lu.tab[i*n+j]*x[j];
	}
	for (i = n - 1; i >= 0; i--){          /*这个嵌套的for循环实现的功能是xi=(yi-∑［ｊ＝ｉ＋１，ｎ］/u[i,i]
										   这种实现方法是非常值得我借鉴和学习的*/
		for(j=i+1;j<n;j++)
			x[i]=x[i]-lu.tab[i*n+j]*x[j];
		x[i]=x[i]/lu.tab[i*n+i];
	}
	return x;
}
Matrix matrixInverse(Matrix a){                     /*这是运用LUP分解计算矩阵的逆。因为LUP分解与b无关只与A有关，因此，一旦有了A的LUP分解，就可以用⊙（kn∧2)的时间解k个版本的方程Ax=b
													，它们中仅仅b的不同而已。
													方程      AX=In，显然X即为A的逆矩阵。
													设Xi表示X的第i列，单位向量ei是In的第i个列，因此可以分别对每个方程AXi=ei解出Xi进而解出X*/
	double *e=NULL,*s=NULL;
	int n=a.row,*pi=(int*)calloc(n,sizeof(int)), i;
	Matrix b=newMatrix(n,n),lu,c;
	lu=lupDecomposition(a, pi);
	for(i=0;i<n;i++){
		if(e)free(e);
		e=(double*)calloc(n,sizeof(double));
		e[i]=1.0;
		if(s)free(s);
		s=lupSolve(lu,pi,e);
		memcpy(b.tab+i*n, s, n*sizeof(double));
	}
	c=transform(b);
	clrMatrix(lu);clrMatrix(b);
	free(pi);free(e);free(s);
	return c;
}
rMatrix rlupDecomposition(rMatrix a, int *pi){
	int i,j,k,k1,n=a.row;
	Rational p;
	rMatrix lu=rnewMatrixByArry(a.tab,a.row,a.col);
	for(i=0;i<n;i++)              
		pi[i]=i;
	for(k=0;k<n;k++){
		p.numerator=0,p.denominator=1,p.sign=0;
		for(i=k;i<n;i++)
			if(valueCompare(lu.tab[i*n+k],p)>0){
				p=lu.tab[i*n+k];
				k1=i;
			}
		assert(! rationalIsZero(p));
		swap(pi+k, pi+k1,sizeof(int));
		rswapRows(lu,k,k1);
		for(i=k+1;i<n;i++){
			lu.tab[i*n+k]=rationalQuot(lu.tab[i*n+k],lu.tab[k*n+k]);
			for(j=k+1;j<n;j++)
				lu.tab[i*n+j]=rationalDiff(lu.tab[i*n+j],rationalProd(lu.tab[i*n+k],lu.tab[k*n+j]));
		}
	}
	return lu;
}
Rational* rlupSolve(rMatrix lu, int *pi, Rational *b){
	int i,j,n=lu.row;
	Rational *x=(Rational*)calloc(n,sizeof(Rational));
	for(i=0;i<n;i++){
		x[i]=b[pi[i]];
		for(j=0;j<i;j++)
			x[i]=rationalDiff(x[i],rationalProd(lu.tab[i*n+j],x[j]));
	}
	for(i=n-1;i>=0;i--){
		for(j=i+1;j<n;j++)
			x[i]=rationalDiff(x[i],rationalProd(lu.tab[i*n+j],x[j]));
		x[i]=rationalQuot(x[i],lu.tab[i*n+i]);
	}
	return x;
}
