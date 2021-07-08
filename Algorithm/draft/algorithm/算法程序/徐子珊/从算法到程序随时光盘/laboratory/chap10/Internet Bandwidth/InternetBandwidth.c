#include "../../graph/edmondskarp.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int main(){
	int n, count=0;
	FILE *f1,*f2;
	assert(f1=fopen("chap10/Internet Bandwidth/inputdata.txt","r"));
	assert(f2=fopen("chap10/Internet Bandwidth/outputdata.txt","w"));
	fscanf(f1,"%d", &n);/*读取案例个数n*/
	while(n){
		int s, t, m, i, u, v;
		double *c=(double*)calloc(n*n, sizeof(double)), w, *f;
		fscanf(f1, "%d%d%d",&s, &t, &m);
		for(i=0;i<m;i++){
			fscanf(f1, "%d%d%lf", &u, &v, &w);
			c[(u-1)*n+(v-1)]=c[(v-1)*n+(u-1)]=w;
		}
		f=edmondsKarp(c,n,s-1,t-1);
		for(w=i=0;i<n;i++)
			w+=f[i];
		fprintf(f2,"Network %d\n", ++count);
		fprintf(f2,"The bandwidth is %.0f\n", w);
		free(c);free(f);
		fscanf(f1, "%d", &n);
	}
	fclose(f1);fclose(f2);
	return 0;
}