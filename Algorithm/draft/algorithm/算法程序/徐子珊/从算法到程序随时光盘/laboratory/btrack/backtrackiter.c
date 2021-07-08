#include <string.h>
#include <stdio.h>
#include<assert.h>
#include "combineproblem.h"
void clrSet(ValueSet* set, void(*proc)(void*)){/*清理分量取值集合存储空间*/
	set->current=NULL;
	clrList(set->list,proc);
	free(set->list);
}
void clrOMG(ValueSet **OMG, int n, void(*proc)(void*)){/*清理解空间*/
	int i;
	for(i=0;i<n;i++){
		clrSet(OMG[i],proc);
		free(OMG[i]);
	}
}
LinkedList* backtrackiter(ValueSet **OMG, int n){/*组合问题回溯求解*/
	int k=0, size=OMG[0]->list->eleSize;
	void *x=(void*)malloc(n*size);/*解向量*/
	LinkedList *solutions=createList(sizeof(Solution),NULL);/*合法解集合*/
	Solution s;/*合法解暂存空间*/
	assert(x&&solutions);
	while(k>=0){
		while(OMG[k]->current->next!=OMG[k]->list->nil){/*Xk未穷尽*/
			OMG[k]->current=OMG[k]->current->next;
			memcpy((char*)x+k*size,OMG[k]->current->key,size);
			if(isPartial(x, k)){/*部分合法*/
				if(isComplete(x, k)){/*完整合法解*/
					s.x=(void*)malloc((k+1)*size);
					memcpy(s.x,x,(k+1)*size);/*保存解向量*/
					s.k=k+1;/*解向量长度*/
					listPushBack(solutions,&s);/*加入解集*/
					if(OMG[k]->current->next!=OMG[k]->list->nil)
						continue;
				}
				if(k==n-1){/*达到树叶但非完整合法解*/
					if(OMG[k]->current->next==OMG[k]->list->nil)
						break;
				}else k++;
			}
		}
		OMG[k]->current=OMG[k]->list->nil;/*重置Xk*/
		k--;/*回溯*/
	}
	free(x);
	return solutions;/*返回合法解集合*/
}
