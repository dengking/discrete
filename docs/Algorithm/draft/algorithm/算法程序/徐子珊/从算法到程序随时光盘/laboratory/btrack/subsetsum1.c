#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include "../datastructure/list.h"
#include "combineproblem.h"
int A[]={1,2,3,4,5,6,7,8,9},/*整数集合*/
	n=9,/*A中元素个数*/
	C=9;
int isPartial(int *x, int k){
	int i,s=0;
	for(i=0;i<=k;i++){
		s+=x[i]*A[i];
		if(s>C)
			return 0;
	}
	return 1;
}
int isComplete(int *x, int k){
	int s=0,i;
	if(k<n-1)
		return 0;
	for(i=0;i<=k;i++)
		s+=x[i]*A[i];
	return (s==C);
}
void print(int *x,int k){
	int i;
	printf("{");
	for(i=0;i<k;i++)
		if(x[i])
			printf("%d ", A[i]);
	printf("}\n");
}
int main(){
	LinkedList *ss;
	ListNode *p;
	ss=subSetTree(n);
	p=ss->nil->next;
	while(p!=ss->nil){
		print(((Solution*)(p->key))->x,((Solution*)(p->key))->k);
		p=p->next;
	}
	clrList(ss, clrSolution);
	free(ss);
	return 0;
}