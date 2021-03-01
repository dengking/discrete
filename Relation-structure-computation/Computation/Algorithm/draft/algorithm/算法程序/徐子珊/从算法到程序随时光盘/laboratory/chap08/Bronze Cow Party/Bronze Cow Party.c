#include "../../dprog/floyd.h"
#include<assert.h>
#include<stdio.h>
#include<float.h>
#include<stdlib.h>
#include "../../utility/select.h"
#include "../../utility/compare.h"
double bronzeCowParty(double *w,int n, int x){
	double *time, *d,result;
	int i;
	pair p;
	assert(time=(double*)malloc(n*sizeof(double)));
	p=floydWarshall(w,n);
	d=p.first;
	for(i=0;i<n;i++)
		time[i]=d[i*n+(x-1)]+d[(x-1)*n+i];
	free(d);
	result=*(double*)(select(time,sizeof(double),0,n-1,n-1,doubleGreater));
	free(time);
	return result;
}
int main(){
	FILE *f1=fopen("chap04/Bronze Cow Party/inputdata.txt","r"),
		*f2=fopen("chap04/Bronze Cow Party/outputdata.txt","w");
	int n, m, x, t, a, b, i,j;
	double *w;
	assert(f1&&f2);
	fscanf(f1,"%d %d %d", &n, &m, &x);/*读取顶点数n，边数m，和顶点号x*/
	assert(w=(double*)malloc(n*n*sizeof(double)));
	for(i=0;i<n;i++)/*初始化权矩阵*/
		for(j=0;j<n;j++)
			if(i==j)
				w[i*n+j]=0.0;
			else
				w[i*n+j]= DBL_MAX;
	for(i=0;i<m;i++){
		fscanf(f1,"%d %d %d", &a, &b, &t);/*读取顶点a，b及a,b间的权t*/
		if(w[(a-1)*n+b-1]>t)
			w[(a-1)*n+b-1]=w[(b-1)*n+(a-1)]=t;
	}
	fprintf(f2,"%.0f\n",  bronzeCowParty(w,n,x));
	free(w);
	fclose(f1),fclose(f2);
	return 0;
}