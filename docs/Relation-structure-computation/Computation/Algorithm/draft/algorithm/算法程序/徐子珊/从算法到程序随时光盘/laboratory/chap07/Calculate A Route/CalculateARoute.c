#include "../../btrack/combineproblem.h"
#include <stdio.h>
#include <string.h>
#include <float.h>
#include <assert.h>
double *p,/*关隘过关概率*/
			max ,/*当前最优解目标值*/
			obj;/*当前可行解目标值*/
	int  *G,/*图G的邻接矩阵*/
			n,/*图G的顶点个数*/
			s=1,/*起点*/
			*origin;/*剔除起点、终点后的顶点初始排列*/
int isPartial(int *x, int k){/*部分可行解判断*/
	int i;
	if(G[(s-1)*n+x[0]-1]==0)
		return 0;
	obj=p[x[0]-1];
	for(i=0;i<k;i++){
		if( G[(x[i]-1)*n+x[i+1]-1]==0)
			return 0;
		obj*=p[x[i+1]-1];
		if(obj<=max)
			return 0;
	}
	return 1;
}
int isComplete(int *x, int k){
	if (G[(x[k]-1)*n+n-1]==0)
		return 0;
	if(obj<=max)
		return 0;
	max=obj;
	return 1;
}
int main(){
	FILE *f1=fopen("chap07/Calculate A Route/inputdata.txt","r"),
		*f2=fopen("chap07/Calculate A Route/outputdata.txt","w");
	LinkedList *ss;
	int k,cn;
	assert(f1&&f2);
	fscanf(f1,"%d",&cn);/*读出案例数*/
	for(k=0;k<cn;k++){
		int i, j;
		max=-DBL_MAX;
		fscanf(f1, "%d", &n);/*读出关隘数*/
		assert(G=(int*)malloc(n*n*sizeof(int)));
		for(i=0;i<n;i++)/*读出地图数据*/
			for(j=0;j<n;j++)
				fscanf(f1, "%d", G+i*n+j);
		assert(origin=(int*)malloc((n-2)*sizeof(int)));
		for(i=0;i<n-2;i++)/*设置除许都、古城外各关隘初始序列*/
			origin[i]=i+2;
		assert(p=(double*)malloc(n*sizeof(double)));
		p[0]=p[n-1]=1.0;
		for(i=1;i<n-1;i++)/*读出各关隘过关概率*/
			fscanf(f1, "%lf", p+i);
		ss=permutTree(origin, sizeof(int), n-2);/*按排列树模型回溯搜索*/
		if(!listEmpty(ss)&&max>=0.0001)/*输出*/
			fprintf(f2, "Case %d: %.4f\n",k+1, max);
		else
			fprintf(f2, "Case %d: Cannot reach!\n", k+1);
		clrList(ss, clrSolution);free(ss);/*清理解集空间*/
		free(G);free(p);free(origin);/*清理地图、关隘、概率存储空间*/
	}
	fclose(f1);fclose(f2);
	return 0;
}