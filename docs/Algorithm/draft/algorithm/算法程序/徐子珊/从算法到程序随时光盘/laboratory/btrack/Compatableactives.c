#include "combineproblem.h"
#include <stdio.h>
int s[]={1, 3, 0,	5,	3,	5,	6,	8,	8,	2,	12},
	f[]={4, 5,	6,	7,	8,	9,	10, 11, 12, 13, 14},
	n=11;
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