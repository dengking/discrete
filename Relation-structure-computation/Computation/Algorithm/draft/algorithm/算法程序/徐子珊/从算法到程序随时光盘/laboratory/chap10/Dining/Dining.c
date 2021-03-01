#include "../../graph/edmondskarp.h"
#include "../../graph/graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int main(){
	int n, f, d, i;
	FILE *f1,*f2;
	double *fl, *c, max=0.0;
	assert(f1=fopen("chap10/Dining/inputdata.txt","r"));
	assert(f2=fopen("chap10/Dining/outputdata.txt","w"));
	fscanf(f1,"%d%d%d", &n, &f, &d);/*读取牛牛数n，食物数f，饮料数d*/
	assert(c=(double*)calloc((f+d+2)*(f+d+2),sizeof(double)));
	for(i=1;i<=f;i++)/*添加一个源点*/
		c[i]=1.0;
	for(i=1;i<=d;i++)/*添加一个目标点*/
		c[(f+i)*(f+d+2)+f+d+1]=1.0;
	for(i=0;i<n;i++){/*根据二部图创建流网络*/
		int fi,di,*u, *v, p, q;
		fscanf(f1, "%d%d", &fi,&di);
		assert(u=(int*)malloc(fi*sizeof(int)));
		assert(v=(int*)malloc(fi*sizeof(int)));
		for(p=0;p<fi;p++)
			fscanf(f1, "%d", u+p);
		for(q=0;q<di;q++)
			fscanf(f1, "%d", v+q);
		for(p=0;p<fi;p++)
			for(q=0;q<di;q++)
				c[u[p]*(f+d+2)+f+v[q]]=1.0;
		free(u);free(v);
	}
	fl=edmondsKarp(c,f+d+2,0,f+d+1);/*计算最大流*/
	for(i=0;i<f+d+2;i++)/*计算最大匹配*/
		max+=fl[i];
	fprintf(f2,"%.0f\n", max);
	free(c);free(fl);
	fclose(f1);fclose(f2);
	return 0;
}