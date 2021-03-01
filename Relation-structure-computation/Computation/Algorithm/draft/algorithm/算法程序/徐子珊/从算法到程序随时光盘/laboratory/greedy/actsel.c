#include "actsel.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
int activeComp(Active *a, Active *b){
	if(a->f>b->f)
		return 1;
	if(a->f<b->f)
		return -1;
	return 0;
}
int *greedyActivitySelector(Active *a, int n){
	int i,m,*x=(int*)calloc(n,sizeof(int));
	assert(x);
	qsort(a,n,sizeof(Active),activeComp);
	for(x[0]=1,i=0,m=1;m<n;m++)
		if(a[m].s>=a[i].f){
			x[m]=1;
			i=m;
		}
	return x;
}