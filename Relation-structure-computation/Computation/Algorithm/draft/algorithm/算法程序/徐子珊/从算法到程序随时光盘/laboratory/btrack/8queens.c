#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include "combineproblem.h"
int n=5;/*棋盘规模*/
ValueSet *newSet(){/*创建集合X*/
	int i;
	ValueSet *s=(ValueSet*)malloc(sizeof(ValueSet));
	assert(s!=NULL);
	s->list=createList(sizeof(int),NULL);
	for(i=1;i<=n;i++)
		listPushBack(s->list,&i);
	s->current=s->list->nil;
	return s;
}
ValueSet** makeOMG(int n){/*创建Ω*/
	int i;
	ValueSet **OMG=(ValueSet**)malloc(n*sizeof(ValueSet*));
	assert(OMG!=NULL);
	for(i=0;i<n;i++)
		OMG[i]=newSet();
	return OMG;
}
int isPartial(int *x, int k){
	int i;
	for(i=0;i<k;i++)
		if(x[i]==x[k]||x[i]-x[k]==k-i||x[k]-x[i]==k-i)
			return 0;
	return 1;
}
int isComplete(int *x, int k){
	return k==n-1;
}
void print(int *x, int k){
	int i,j;
	for(i=0;i<k;i++){
		for(j=1;j<x[i];j++)
			printf("%c",'-');
		printf("%c",'Q');
		for(j++;j<=n;j++)
			printf("%c",'-');
		printf("\n");
	}
	printf("\n");
}
int main(){
	LinkedList *ss;
	ListNode *p;
	ValueSet **OMG=makeOMG(n);
	ss=backtrackiter(OMG, n);
	p=ss->nil->next;
	while(p!=ss->nil){
		print(((Solution*)(p->key))->x,((Solution*)(p->key))->k);
		p=p->next;
	}
	clrList(ss, clrSolution);
	free(ss);
	clrOMG(OMG,n,NULL);
	free(OMG);
	return 0;
}
