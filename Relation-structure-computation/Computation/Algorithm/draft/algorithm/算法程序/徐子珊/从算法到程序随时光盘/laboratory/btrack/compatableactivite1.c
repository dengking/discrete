#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include "combineproblem.h"
int s[]={1, 3, 0,	5,	3,	5,	6,	8,	8,	2,	12},
	f[]={4, 5,	6,	7,	8,	9,	10, 11, 12, 13, 14},
	n=11;
ValueSet *newSet(){/*创建集合X*/
	int i;
	ValueSet *s=(ValueSet*)malloc(sizeof(ValueSet));
	assert(s!=NULL);
	s->list=createList(sizeof(int),NULL);
	for(i=0;i<=1;i++)
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
	int i=k-1;
	if(x[k]==0)
		return 1;
	while(i>=0&&x[i]==0)
		i--;
	if(i<0)
		return 1;
	return f[i]<=s[k];
}
int isComplete(int *x, int k){
	return k==n-1;
}
void print(int *x, int k){
	int i;
	printf("{");
	for(i=0;i<k;i++)
		if(x[i])
			printf("a%d ", i+1);
	printf("}\n");
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