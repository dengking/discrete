#include "polynomial.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fft.h"
Polynomial newPoly(int n){/*生成0多项式*/
	Polynomial a;
	a.degree=n-1;
	a.coeff=(Complex*)calloc(n, sizeof(Complex));
	return a;
}
Polynomial newPolyByArry(double *c, int n){/*用数组数据生成多项式*/
	Polynomial a;
	int i;
	a.coeff=(Complex*)calloc(n, sizeof(Complex));
	a.degree=n-1;
	for(i=0;i<n;i++)
		a.coeff[i].real=c[i];
	return a;
}
void clrPoly(Polynomial a){/*清理多项式存储空间*/
	free(a.coeff);
}
void printPoly(Polynomial a){/*输出多项式*/
	int n=a.degree,i;
	if(n==0){/*0次多项式*/
		printComplex(a.coeff[0]);
		putchar('\n');
		return;
	}
	for(i=n;i>=0;i--){
		if(!isZero(a.coeff[i])){
			if(i<n)
				putchar('+');
			printf("(");
			printComplex(a.coeff[i]);
			printf(")");
			if(i){
				putchar('x');
				if(i>1)printf("^%d",i);
			}
		}
	}
	printf("\n");
}
Polynomial polySum(Polynomial a,Polynomial b){/*多项式的和*/
	int m=a.degree,n=b.degree,i=0,j=0,k=0;
	Polynomial c=newPoly((m>n?m:n)+1);
	while(i<=m&&j<=n)
		c.coeff[k++]=compSum(a.coeff[i++],b.coeff[j++]);
	while(i<=m)
		c.coeff[k++]=a.coeff[i++];
	while(j<=n)
		c.coeff[k++]=b.coeff[j++];
	k--;
	while(k>0&&isZero(c.coeff[k--]))
	    c.degree--;
	return c;
}
double horner(Polynomial a, double x){/*霍纳法计算多项式的值*/
	Complex y={0.0,0.0}, x1={x, 0.0};
	int i,n=a.degree;
	for(i=n;i>=0;i--)
		y=compSum(a.coeff[i],compProd(x1,y));
	return y.real;
}
static Complex* componentwiseMultiplay(Complex* f, Complex* g, int n){//按分量积
	Complex* p=(Complex*)calloc(n, sizeof(Complex));
	int i;
	for(i=0;i<n;i++)
		p[i]=compProd(f[i],g[i]);
	return p;
}
Polynomial polyProd(Polynomial f, Polynomial g){//多项式相乘
	int l,n,max,min;
	Polynomial p;
	Complex *a,*b, *x, *y, *z;
	max=f.degree>=g.degree?f.degree:g.degree;
	min=f.degree<=g.degree?f.degree:g.degree;
	l=max+min+1;
	n=1;
	while(n<l)n*=2;
	a=(Complex*)calloc(n, sizeof(Complex));memcpy(a,f.coeff,(f.degree+1)*sizeof(Complex));
	b=(Complex*)calloc(n, sizeof(Complex));memcpy(b,g.coeff,(g.degree+1)*sizeof(Complex));
	x=fft(a, n, 1);y=fft(b, n, 1);
	z=componentwiseMultiplay(x,y,n);
	p.coeff=fftInverse(z,n);
	p.degree=min+max;
	free(x);free(y);free(z);
	return p;
}
