#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include "mcolor.h"
ValueSet *newSet(){/*创建集合X*/
	int i;
	ValueSet *s=(ValueSet*)malloc(sizeof(ValueSet));
	assert(s!=NULL);
	s->list=createList(sizeof(int),NULL);
	for(i=1;i<=m;i++)
		listPushBack(s->list,&i);
	s->current=s->list->nil;
	return s;
}
ValueSet** makeOMG(){/*创建Ω*/
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
		if(G[i*n+k]&&x[i]==x[k])
			return 0;
	return 1;
}
int isComplete(int *x, int k){
	int i;
	if(k==n-1){
	for(i=0;i<n;i++)
		printf("%d ",x[i]);
	printf("\n");
	return 1;
	}
	return 0;
	//return k==n-1;
}
