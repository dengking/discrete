#include "../../btrack/combineproblem.h"
#include <stdio.h>
#include <string.h>
#include <float.h>
#include <assert.h>
double *p,/*�ذ����ظ���*/
			max ,/*��ǰ���Ž�Ŀ��ֵ*/
			obj;/*��ǰ���н�Ŀ��ֵ*/
	int  *G,/*ͼG���ڽӾ���*/
			n,/*ͼG�Ķ������*/
			s=1,/*���*/
			*origin;/*�޳���㡢�յ��Ķ����ʼ����*/
int isPartial(int *x, int k){/*���ֿ��н��ж�*/
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
	fscanf(f1,"%d",&cn);/*����������*/
	for(k=0;k<cn;k++){
		int i, j;
		max=-DBL_MAX;
		fscanf(f1, "%d", &n);/*�����ذ���*/
		assert(G=(int*)malloc(n*n*sizeof(int)));
		for(i=0;i<n;i++)/*������ͼ����*/
			for(j=0;j<n;j++)
				fscanf(f1, "%d", G+i*n+j);
		assert(origin=(int*)malloc((n-2)*sizeof(int)));
		for(i=0;i<n-2;i++)/*���ó������ų�����ذ���ʼ����*/
			origin[i]=i+2;
		assert(p=(double*)malloc(n*sizeof(double)));
		p[0]=p[n-1]=1.0;
		for(i=1;i<n-1;i++)/*�������ذ����ظ���*/
			fscanf(f1, "%lf", p+i);
		ss=permutTree(origin, sizeof(int), n-2);/*��������ģ�ͻ�������*/
		if(!listEmpty(ss)&&max>=0.0001)/*���*/
			fprintf(f2, "Case %d: %.4f\n",k+1, max);
		else
			fprintf(f2, "Case %d: Cannot reach!\n", k+1);
		clrList(ss, clrSolution);free(ss);/*����⼯�ռ�*/
		free(G);free(p);free(origin);/*�����ͼ���ذ������ʴ洢�ռ�*/
	}
	fclose(f1);fclose(f2);
	return 0;
}