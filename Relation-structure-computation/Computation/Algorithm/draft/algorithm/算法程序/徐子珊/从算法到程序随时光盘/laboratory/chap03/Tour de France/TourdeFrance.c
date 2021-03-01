#include<stdio.h>
#include<assert.h>
#include "../../utility/compare.h"
#include "../../utility/quicksort.h"
#include "../../utility/select.h"
double tuorDeFrance(int *m, int *n, int f, int r){
	double *d=(double*)malloc(f*r*sizeof(double)),
		*spread=(double*)malloc((f*r-1)*sizeof(double)),
		result;
	int i,j,k=0;
	assert(d&&spread);
	for(j=0;j<r;j++)
		for(i=0;i<f;i++)
			d[k++]=(double)n[j]/m[i];
	quickSort(d,sizeof(double),0,f*r-1,doubleGreater);
	for(k=0;k<f*r-1;k++)
		spread[k]=d[k+1]/d[k];
	free(d);
	result=*((double*)select(spread,sizeof(double),0,f*r-2,f*r-2,doubleGreater));
	free(spread);
	return result;
}
int main(){
	FILE *f1=fopen("chap03/Tour de France/inputdata.txt","r"), 
		*f2=fopen("chap03/Tour de France/outputdata.txt","w");
	assert(f1&&f2);
	while(1){
		int f,r,*m,*n,i;
		fscanf(f1,"%d",&f);
		if(!f) break;
		fscanf(f1,"%d",&r);
		m=(int*)malloc(f*sizeof(int));
		n=(int*)malloc(r*sizeof(int));
		assert(m&&n);
		for(i=0;i<f;i++)
			fscanf(f1,"%d",m+i);
		for(i=0;i<r;i++)
			fscanf(f1,"%d",n+i);
		fprintf(f2,"%.2f\n",tuorDeFrance(m,n,f,r));
		free(m);free(n);
	}
	fclose(f1);fclose(f2);
	return 0;
}