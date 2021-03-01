#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include "combineproblem.h"
int G[]={0,1,1,1,0,
		 1,0,1,0,1,
		 1,1,0,1,0,
		 1,0,1,0,1,
		 0,1,0,1,0},/*图G的邻接矩阵*/
	n=5,/*图G的顶点个数*/
	s=1,
	origin[]={2, 3, 4, 5};
int isPartial(int *x, int k){
	int i;
	if(G[(s-1)*n+x[0]-1]==0)
		return 0;
	for(i=0;i<k;i++)
		if( G[(x[i]-1)*n+x[i+1]-1]==0)
			return 0;
	return 1;
}
int isComplete(int *x, int k){
	return k==n-2&&G[(x[n-2]-1)*n+s-1];
}
void print(int *x, int k){
	int i;
	printf("%d->",s);
	for(i=0;i<k;i++)
		printf("%d->", x[i]);
	printf("%d\n",s);
}
int main(){
	LinkedList *ss;
	ListNode *p;
	ss=permutTree(origin, sizeof(int), n-1);
	p=ss->nil->next;
	while(p!=ss->nil){
		print(((Solution*)(p->key))->x,((Solution*)(p->key))->k);
		p=p->next;
	}
	clrList(ss, clrSolution);
	free(ss);
	return 0;
}