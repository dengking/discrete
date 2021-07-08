#include "lup.h"
#include "./../utility/swap.h"
#include <math.h>
#include<assert.h>
#include<stdlib.h>
Matrix lupDecomposition(Matrix a, int *pi){/*�˺�����������������1�����LU�ֽ⣬2��ʾ�û�����P������pi*/
	int i,j,k,k1,n=a.row;
	double p;
	Matrix lu=newMatrixByArry(a.tab,a.row,a.col);
	for(i=0;i<n;i++)
		pi[i] = i;/*��ʼ����ʱ��pi[i] = i�൱��Ϊ�����ÿ�б�һ���к�*/
	for(k=0;k<n;k++){
		p=0.0;
		for(i=k;i<n;i++)
		if (fabs(lu.tab[i*n + k])>p){/*��forѭ���Ĺ������ҳ���k���о���ֵ����Ԫ�أ�������kl����¼�����Ԫ�����ڵ��к�*/
				p=fabs(lu.tab[i*n+k]);
				k1=i;
			}
			assert(p>1e-10);/*��p>1e-10������ʽ��ʾp��=0������Ϊ�ڼ�����и���������֤��������������Ƿ�׼ȷ�����Ը�����������Ҫ����һ���ľ����ж��Ƿ����0.0*/
		swap(pi+k, pi+k1,sizeof(int));
		swapRows(lu,k,k1);
		for(i=k+1;i<n;i++){
			lu.tab[i*n + k] = lu.tab[i*n + k] / lu.tab[k*n + k];/*�˲�ʵ�ֵ���v/a[k,k]*/
			for(j=k+1;j<n;j++)
				lu.tab[i*n + j] = lu.tab[i*n + j] - lu.tab[i*n + k] * lu.tab[k*n + j];/*�˲�ʵ�ֵ���a[i,j]-a[i,k]*a[k,j]*/
		}
	}
	return lu;
}
double* lupSolve(Matrix lu, int *pi, double *b){/*�˺����Ĺ�����lup�������Է�����
												�����Ƶ������еõ����ͨʽ�Ƿǳ���Ҫ��*/
	int i,j,n=lu.row;
	double *x = (double*)calloc(n, sizeof(double));/*����x��������Ž��*/
	for (i = 0; i<n; i++){/*b�Ƿ������Ҷ�����*/
		x[i] = b[pi[i]];/*�ⲽ�൱��Ҫ����Ȼ���ǳ��򵥣��������ַ�����ֵ����ѧϰ��*/
		for (j = 0; j<i; j++)                    /*���Ƕ�׵�forѭ����ʵ�ֵĹ�����y3= b[pi[i]]-(l31y1+l32y2)
												 ���ߵ�����ʵ�ַ�����ֵ����ѧϰ��*/
			x[i]=x[i]-lu.tab[i*n+j]*x[j];
	}
	for (i = n - 1; i >= 0; i--){          /*���Ƕ�׵�forѭ��ʵ�ֵĹ�����xi=(yi-�ƣۣꣽ�飫�������/u[i,i]
										   ����ʵ�ַ����Ƿǳ�ֵ���ҽ����ѧϰ��*/
		for(j=i+1;j<n;j++)
			x[i]=x[i]-lu.tab[i*n+j]*x[j];
		x[i]=x[i]/lu.tab[i*n+i];
	}
	return x;
}
Matrix matrixInverse(Matrix a){                     /*��������LUP�ֽ���������档��ΪLUP�ֽ���b�޹�ֻ��A�йأ���ˣ�һ������A��LUP�ֽ⣬�Ϳ����áѣ�kn��2)��ʱ���k���汾�ķ���Ax=b
													�������н���b�Ĳ�ͬ���ѡ�
													����      AX=In����ȻX��ΪA�������
													��Xi��ʾX�ĵ�i�У���λ����ei��In�ĵ�i���У���˿��Էֱ��ÿ������AXi=ei���Xi�������X*/
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
