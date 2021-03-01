#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../datastructure/stack.h"
#include "../utility/swap.h"
#include "combineproblem.h"
LinkedList* permutTree(void *origin, int size, int n){
	Stack *S=createStack(sizeof(int));
	void *x=(void*)malloc(n*size);
	int k=0,i=-1;
	LinkedList *solutions=createList(n*sizeof(Solution),NULL);/*合法解集合*/
	Solution s;/*合法解暂存空间*/
	assert(x&&solutions);
	memcpy(x,origin,n*size);
	k=0;push(S,&i);
	while(k>=0){
		i++;
		while(i<n){
			swap((char*)x+k*size,(char*)x+i*size,size);
			if(isPartial(x, k))
				if(isComplete(x,k)){
					s.x=(void*)malloc((k+1)*size);
					memcpy(s.x,x,(k+1)*size);/*保存解向量*/
					s.k=k+1;/*解向量长度*/
					listPushBack(solutions,&s);/*加入解集*/
					break;
				}
			k++;
			push(S,&i);
			i=k;
		}
		k--;
		i=*((int*)(pop(S)->key));
		swap((char*)x+k*size,(char*)x+i*size,size);
	}
	free(x);
	clrStack(S,NULL);
	free(S);
	return solutions;/*返回合法解集合*/
}
