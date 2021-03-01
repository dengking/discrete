#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include "../../datastructure/pair.h"
#include "../../dprog/knapsack.h"
pair extend(int *p, int *k, int *m, int C){
	int *newp,*newk, *m1,x,i,newm,j,t;
	assert(m1=(int*)malloc((*m)*sizeof(int)));
	for(i=0;i<*m;i++){
		x=1;
		while(x*(x+1)*p[i]/2<C)x++;
		m1[i]=x;
	}
	for(i=0,newm=0;i<*m;i++)
		newm+=m1[i];
	assert(newp=(int*)malloc(newm*sizeof(int)));
	assert(newk=(int*)malloc(newm*sizeof(int)));
	for(i=0,t=0;i<*m;i++)
		for(j=0;j<m1[i];j++,t++){
			newp[t]=(j+1)*p[i];
			newk[t]=(j+1)*k[i];
		}
	free(m1);
	*m=newm;
	return make_pair(newp,newk);
}
int theCiceronesAbacus(int *p, int *k, int m, int *C, int n){
	int max=0,i,*p1,*k1,m1,*matrix;
	pair r;
	for(i=0;i<n;i++){
		m1=m;
		r=extend(p,k,&m1,C[i]);
		p1=r.first;
		k1=r.second;
		matrix=knapsack(p1,k1,m1,C[i]);
		max+=matrix[m1*(C[i]+1)+C[i]];
		free(p1),free(k1),free(matrix);
	}
	return max;
}
int main(){
	FILE *f1=fopen("chap04/The cicerone's abacus/inputdata.txt","r"),
		*f2=fopen("chap04/The cicerone's abacus/outputdata.txt","w");
	int *p,*k,*C,m,n,i;
	assert(f1&&f2);
	while(!feof(f1)){
		fscanf(f1,"%d",&n);
		assert(C=(int*)malloc(n*sizeof(int)));
		for(i=0;i<n;i++)
			fscanf(f1,"%d",C+i);
		fscanf(f1,"%d",&m);
		assert(p=(int*)malloc(m*sizeof(int)));
		assert(k=(int*)malloc(m*sizeof(int)));
		for(i=0;i<m;i++)
			fscanf(f1,"%d %d",p+i,k+i);
		fprintf(f2,"%d\n",theCiceronesAbacus(p,k,m,C,n));
		free(p),free(k),free(C);		
	}
	fclose(f1),fclose(f2);
	return 0;
}