#include "combineproblem.h"
#include <stdio.h>
#include <string.h>
int w[]={2, 3, 4, 5},
	v[]={3, 4, 5, 7},
	C=9,
	n=4,
	most=-1,
	total=19;
int isPartial(int *x, int k){
	int obj=0,weight=0,i,d=total;
	for(i=0;i<=k;i++){
		weight+=x[i]*w[i];
		if(weight>C)
			return 0;
		obj+=x[i]*v[i];
		d-=v[i];
	}
	if(obj+d<most)
		return 0;
	return 1;
}
int isComplete(int *x, int k){
	int obj=0,i;
	if(k<n-1)
		return 0;
	for(i=0;i<=k;i++)
		obj+=x[i]*v[i];
	if(obj<=most)
			return 0;
	most=obj;
	return 1;
}
int main(){
	LinkedList *ss=subSetTree(n);
	ListNode *p=ss->nil->prev;
	int i;
	for(i=0;i<n;i++)
		printf("%d ", *((int*)(((Solution*)(p->key))->x)+i));
	printf("\n");
	printf("%d\n",most);
	clrList(ss, clrSolution);
	free(ss);
	return 0;
}