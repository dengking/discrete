#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include "backtrackiter.h"
int G[]={0,1,1,0,0,
			 1,0,0,1,1,
			 1,0,0,1,1,
			 0,1,1,0,1,
			 0,1,1,1,0},/*图G的邻接矩阵*/
	n=5;/*图G的顶点个数*/
ValueSet *newSet(){/*创建集合X*/
	int i;
	ValueSet *s=(ValueSet*)malloc(sizeof(ValueSet));
	assert(s!=NULL);
	s->list=createList(sizeof(int),NULL);
	for(i=1;i<=3;i++)
		listPushBack(s->list,&i);
	s->current=s->list->nil;
	return s;
}
int isPartial(int *x, int k){
	int i;
	for(i=0;i<k;i++)
		if(G[i*n+k]&&x[i]==x[k])
			return 0;
	return 1;
}
int isComplete(int *x, int k){
	return k==n-1;
}
void print(int *x, int k){
	int i;
	for(i=0;i<=k;i++)
		printf("%d ", x[i]);
	printf("\n");
}
int main(){
	ValueSet **OMG=makeOMG(n);
	backtrackiter(OMG, n);
	clrOMG(OMG,n,NULL);
	free(OMG);
	return 0;
}