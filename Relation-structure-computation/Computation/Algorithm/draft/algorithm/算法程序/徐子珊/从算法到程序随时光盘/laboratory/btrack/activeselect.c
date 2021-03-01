#include "combineproblem.h"
#include <stdio.h>
int s[]={1, 3, 0,	5,	3,	5,	6,	8,	8,	2,	12},
	f[]={4, 5,	6,	7,	8,	9,	10, 11, 12, 13, 14},
	n=11,
	most=-1,
	obj;
int isPartial(int *x, int k){
	int j,i=-1;
	for(obj=0,j=0;j<k;j++)
		if(x[j]){
			obj++;
			i=j;
		}
	if(x[k]){
		obj++;
		if(i>=0&&f[i]>s[k])
				return 0;
	}
	return obj>=most-n+k;
}
int isComplete(int *x, int k){
	if(k<n-1||obj<=most)
		return 0;
	most=obj;
	return 1;
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
	p=ss->nil->prev;
	print(((Solution*)(p->key))->x,((Solution*)(p->key))->k);
	printf("%d\n",most);
	clrList(ss, clrSolution);
	free(ss);
	return 0;
}