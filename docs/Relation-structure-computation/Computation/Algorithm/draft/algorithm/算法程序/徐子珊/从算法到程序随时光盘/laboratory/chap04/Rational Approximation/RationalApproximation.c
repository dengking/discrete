#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../../algebra/matrix.h"
#include "../../algebra/lup.h"
#include "../../algebra/poly.h"
#include "../../algebra/rational.h"
rMatrix formMatrix(int m, int n, int *f){
	int i,j,t;
	rMatrix M=rnewMatrix(m+n,m+n);
	for(i=0;i<m+n;i++){
		t=(i<n?i+1:n);
		for(j=0;j<t;j++){
			M.tab[i*(m+n)+j].numerator=(f[i-j]>=0?f[i-j]:-f[i-j]);
			if(f[i-j]<0)
				M.tab[i*(m+n)+j].sign=1;
		}
		if(i<m)
			M.tab[i*(m+n)+n+i].numerator=1,
			M.tab[i*(m+n)+n+i].sign=1;
	}
	return M;
}
int main(){
	int m, n;
	FILE *f1=fopen("chap04/Rational Approximation/inputdata.txt","r"), 
		*f2=fopen("chap04/Rational Approximation/outputdata.txt","w");
	assert(f1&&f2);
	fscanf(f1,"%d%d",&m,&n);
	while(m!=0&&n!=0){
		int i,*f,*pi,pm,qn;
		rMatrix a,lu;
		Rational *b,*x;
		assert(f=(int*)calloc(m+n,sizeof(int)));
		assert(b=(Rational*)calloc(m+n,sizeof(Rational)));
		assert(pi=(int*)calloc(m+n,sizeof(int)));
		for(i=0;i<m+n;i++)
			b[i].denominator=1;
		b[m+n-1].numerator=1;
		for(i=0;i<m+n;i++){
			fscanf(f1,"%d",f+i);
			pi[i]=i;
		}
		a=formMatrix(m,n,f);free(f);
		lu=rlupDecomposition(a,pi);rclrMatrix(a);
		x=rlupSolve(lu,pi,b);rclrMatrix(lu);
		pm=m+n-1;
		while(pm>n&&rationalIsZero(x[pm]))
			pm--;
		qn=n-1;
		while(qn>0&&rationalIsZero(x[qn]))
			qn--;
		if(pm==n||!rationalIsZero(x[n])){
			printf("(");
			printRational(x[n]);
			printf(",%d) ", 0);
		}
		for(i=n+1;i<m+n;i++)
			if(!rationalIsZero(x[i])){
				printf("(");
				printRational(x[i]);
				printf(",%d) ", i-n);
			}
		putchar('\n');
		if(qn==0||!rationalIsZero(x[0])){
			printf("(");
			printRational(x[0]);
			printf(",%d) ", 0);
		}
		for(i=1;i<n;i++){
			if(!rationalIsZero(x[i])){
				printf("(");
				printRational(x[i]);
				printf(",%d) ", i);
			}
		}
		printf("\n\n");
		free(x);free(pi);free(b);
		fscanf(f1,"%d%d",&m,&n);
	}
	fclose(f1);fclose(f2);
	return 0;
}