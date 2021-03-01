#include "poly.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#define eps 1e-5
Poly newPoly(int n){
	Poly a;
	a.degree=n-1;
	assert(a.coeff=(double*)calloc(n,sizeof(double)));
	return a;
}
Poly newPolyByArry(double *b, int n){
	Poly a=newPoly(n);
	memcpy(a.coeff,b,n*sizeof(double));
	while(a.degree>0&&fabs(a.coeff[a.degree])<eps)
		a.degree--;
	return a;
}
void clrPoly(Poly a){
	free(a.coeff);
}
void printPoly(Poly a){
	int i;
	if(a.degree==0){
		printf("%f\n", a.coeff[0]);
		return;
	}
	for(i=a.degree;i>=0;i--)
		if(fabs(a.coeff[i])>eps){
			if(a.coeff[i]>0.0&&i!=a.degree)
				putchar('+');
			printf("%f",a.coeff[i]);
			if(i>0)
				putchar('x');
			if(i>1)
				printf("^%d", i);
		}
	putchar('\n');
}
Poly polySum(Poly a,Poly b){
	int n=a.degree>b.degree?a.degree+1:b.degree+1,i;
	Poly c=newPoly(n);
	for(i=0;i<n;i++)
		c.coeff[i]=a.coeff[i]+b.coeff[i];
	i--;
	while(i>0&&fabs(c.coeff[i])<eps){
		i--;
		c.degree--;
	}
	return c;
}
Poly polyProd(Poly f, Poly g){
	int i,j,n=f.degree+g.degree+1;
	Poly c=newPoly(n);
	for(i=0;i<=g.degree;i++)
		for(j=0;j<=f.degree;j++)
			c.coeff[i+j]=c.coeff[i+j]+g.coeff[i]*f.coeff[j];
	return c;
}
void polyAssign(Poly* b, Poly a){
	if(b->coeff)
		free(b->coeff);
	assert(b->coeff=(double*)calloc(a.degree+1,sizeof(double)));
	memcpy(b->coeff,a.coeff,(a.degree+1)*sizeof(double));
	b->degree=a.degree;
}
double horner(Poly a, double x){
	double y=0;
	int i;
	for(i=a.degree;i>=0;i--)
		y=a.coeff[i]+y*x;
	return y;
}
Poly derivative(Poly f){
	int n=f.degree,k;
	Poly f1=newPoly(n);
	for(k=1;k<=n;k++)
		f1.coeff[k-1]=f.coeff[k]*k;
	return f1;
}
void nomalPoly(Poly* a){
	int d=a->degree;
	while(d>0&&fabs(a->coeff[d])<1e-8)
		d--;
	a->degree=d;
}