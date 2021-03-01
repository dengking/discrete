#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <assert.h>
#include "../../geometry/point.h"
#include "../../greedy/dijkstra.h"
double *makeGraph(Point *A, double *p, int n){
	int i,j,k=0;
	double *w=(double*)calloc(n*n, sizeof(double)),d;
	assert(w);
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++){
			d=sqrt((A[i].x-A[j].x)*(A[i].x-A[j].x)+(A[i].y-A[j].y)*(A[i].y-A[j].y));
			w[i*n+j]=w[j*n+i]=d*p[k++];
		}
	return w;
}
int pLess(Point **a, Point **b){
	if((*a)->x>(*b)->x)
		return 1;
	if((*a)->x<(*b)->x)
		return -1;
	if((*a)->y>(*b)->y)
		return 1;
	if((*a)->y<(*b)->y)
		return -1;
	return 0;
}
void fixGraph(double *w,Point *A, Point *B, int n, int m){
	Point **a;
	int *bounds=(int *)malloc(m*sizeof(int));
	int i, j, index;
	assert(a=(Point**)malloc(n*sizeof(Point*)));
	for(i=0;i<n;i++)
		a[i]=A+i;
	qsort(a,n,sizeof(Point*),pLess);
	for(i=0;i<m;i++){
		index=0;
		while((a[index])->x<B[i].x)
			index++;
		bounds[i]=index;
	}
	for(i=0;i<m;i++){
		int u,v;
		for(u=0;u<bounds[i];u++)
			for(v=bounds[i];v<n;v++)
				if(!direction(a[u],&B[i],a[v])){
					int p=a[u]-A,q=a[v]-A;
					w[p*n+q]=w[q*n+p]=DBL_MAX;
				}
	}
	free(a);free(bounds);
}
int round(double x){
	int a=x;
	if(x-a>=0.5)
		a++;
	return a;
}
int pipeLying(Point *A, int n, Point *B, int m, double *p, int s, int t){
	pair r;
	int x;
	double *w=makeGraph(A,p,n), *d;
	fixGraph(w,A,B,n,m);
	r=dijkstra(w,n,s-1);
	d=(double*)r.first;
	x=round(d[t-1]);
	free(w);free(r.second);free(d);
	return x;
}
int main(){
	int i,t;
	FILE *f1, *f2;
	assert(f1=fopen("chap09/Pipe Laying Problem/inputdata.txt","r"));
	assert(f2=fopen("chap09/Pipe Laying Problem/outputdata.txt","w"));
	fscanf(f1,"%d",&t);/*读取案例数*/
	for(i=0;i<t;i++){/*处理每个案例*/
		int j,n,m,s,t;
		Point *A,*B;
		double *p;
		fscanf(f1,"%d",&n);/*读取本案例中气站个数*/
		assert(A=(Point*)malloc(n*sizeof(Point)));
		for(j=0;j<n;j++)/*读取各气站坐标*/
			fscanf(f1,"%lf%lf",&A[j].x,&A[j].y);
		fscanf(f1, "%d", &m);/*读取本案例障碍物数*/
		assert(B=(Point*)malloc(m*sizeof(Point)));
		for(j=0;j<m;j++)/*读取各障碍物坐标*/
			fscanf(f1, "%lf%lf",&B[j].x,&B[j].y);
		p=(double *)malloc(n*(n-1)/2*sizeof(double));
		for(j=0;j<n*(n-1)/2;j++)/*读取两气站间直接耗费*/
			fscanf(f1,"%lf", p+j);
		fscanf(f1, "%d%d",&s, &t);/*读取本案例起止点*/
		fprintf(f2, "%d\n",pipeLying(A,n,B,m,p,s,t));/*输出计算结果*/
		free(A);free(B);free(p);
	}
	fclose(f1);fclose(f2);
	return 0;
}