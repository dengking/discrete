#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "../datastructure/list.h"
#include "combineproblem.h"
LinkedList* subSetTree(int n){
	LinkedList *solutions=createList(n*sizeof(Solution),NULL);/*合法解集合*/
	Solution s;/*合法解暂存空间*/
	int *x=(int*)malloc(n*sizeof(int)),k=0;
	memset(x,-1,n*sizeof(int));
	assert(x&&solutions);
	while(k>=0){
		while(x[k]<1){
			x[k]++;
			if(isPartial(x, k)){/*部分合法*/
				if(isComplete(x, k)){/*完整合法解*/
					s.x=(int*)malloc((k+1)*sizeof(int));
					memcpy(s.x,x,(k+1)*sizeof(int));/*保存解向量*/
					s.k=k+1;/*解向量长度*/
					listPushBack(solutions,&s);/*加入解集*/
					if(x[k]<1)
						continue;
				}
				if(k>=n-1){/*达到树叶但非合法解*/
					if(x[k]==1)
						break;
				}else k++;
			}
		}
		x[k]=-1;
		k--;
	}
	free(x);
	return solutions;/*返回合法解集合*/
}
