#include "../../algebra/matrix.h"
#include  "../../algebra/poly.h"
#include  "../../algebra/lup.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
Matrix vanderMonde(int n){
	Matrix a=newMatrix(n,n);
	int i, j;
	double t;
	for(i=1;i<=n;i++){
		a.tab[(i-1)*n]=t=1.0;
		for(j=2;j<=n;j++)
			a.tab[(i-1)*n+j-1]=t=t*i;
	}
	return a;
}
int main(){
	double *b=NULL;
	int t,s,c,*pi=NULL,i,k;
	Poly f={NULL,-1};
	Matrix a={NULL,0,0}, lu={NULL,0,0};
	FILE *f1=fopen("chap04/Complete the sequence/inputdata.txt","r"), 
		*f2=fopen("chap04/Complete the sequence/outputdata.txt","w");
	assert(f1&&f2);
	fscanf(f1,"%d",&t);
	for(k=0;k<t;k++){
		fscanf(f1,"%d%d",&s,&c);
		if(b)free(b);
		if(pi)free(pi);
		assert(b=(double*)calloc(s,sizeof(double)));
		assert(pi=(int*)calloc(s,sizeof(int)));
		for(i=0;i<s;i++)
			fscanf(f1,"%lf",b+i);
		if(a.tab)clrMatrix(a);
		a=vanderMonde(s);
		if(lu.tab)clrMatrix(lu);
		lu=lupDecomposition(a,pi);
		if(f.coeff)free(f.coeff);
		f.degree=s-1;
		f.coeff=lupSolve(lu,pi,b);
		nomalPoly(&f);
		for(i=0;i<c;i++)
			fprintf(f2,"%.0f ", horner(f,i+s+1.0));
		fputc('\n',f2);
	}
	free(b);free(pi);
	clrMatrix(a);clrMatrix(lu);
	clrPoly(f);
	fclose(f1);fclose(f2);
	return 0;
}