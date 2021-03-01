#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "../../datastructure/pqueue.h"
#include "../../greedy/prim.h"
double *w;
int *pi;
int p;
int s;
int compare(const int **a, const int **b){
	int u=**a,v=*a-pi,
		x=**b,y=*b-pi;
	if(w[u*p+v]>w[x*p+y])
		return 1;
	if(w[u*p+v]<w[x*p+y])
		return -1;
	return 0;
}
double *makeGraph(int *x, int *y){
	int i,j;
	double *w=(double*)malloc(p*p*sizeof(double));
	for(i=0;i<p;i++)
		for(j=0;j<=i;j++)
			w[i*p+j]=w[j*p+i]=sqrt((double)(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
	return w;
}
double ArcticNetwork(double *w, int p, int s){
	int *e,i,n=s,*visited=(int*)calloc(p,sizeof(int)),u,v;
	double d;
	PQueue *Q=initPQueue(sizeof(int**),p-1,compare);
	pair t=mstPrim(w,p,0);
	pi=(int*)(t.second);
	for(i=0;i<p;i++){
		if(pi[i]!=-1){
			e=pi+i;
			enQueue(Q,&e);
		}
	}
	while(n>=1){
		v=*((int**)deQueue(Q))-pi;
		u=pi[v];
		if(!visited[u]){
			visited[u]=1;
			n--;
		}
		if(!visited[v]){
			visited[v]=1;
			n--;
		}
	}
	if(!n){
		v=*((int**)deQueue(Q))-pi;
		u=pi[v];
	}
	d=w[u*p+v];
	pQueueClr(Q);free(w);free(pi);free(visited);
	return d;
}
int main(){
	int i,n;
	FILE *f1,*f2;
	assert(f1=fopen("chap09/Arctic Network/inputdata.txt","r"));
	assert(f2=fopen("chap09/Arctic Network/outputdata.txt","w"));
	fscanf(f1,"%d",&n);
	for(i=0;i<n;i++){
		int j,*x,*y;
		fscanf(f1,"%d%d",&s, &p);
		assert(x=(int*)malloc(p*sizeof(int)));
		assert(y=(int*)malloc(p*sizeof(int)));
		for(j=0;j<p;j++)
			fscanf(f1,"%d%d",x+j,y+j);
		w=makeGraph(x,y);
		fprintf(f2,"%.2f\n",ArcticNetwork(w,p,s));
		free(x);free(y);
	}
	fclose(f1);fclose(f2);
	return 0;
}