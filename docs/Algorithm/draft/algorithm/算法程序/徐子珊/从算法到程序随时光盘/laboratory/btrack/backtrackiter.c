#include <string.h>
#include <stdio.h>
#include<assert.h>
#include "combineproblem.h"
void clrSet(ValueSet* set, void(*proc)(void*)){/*�������ȡֵ���ϴ洢�ռ�*/
	set->current=NULL;
	clrList(set->list,proc);
	free(set->list);
}
void clrOMG(ValueSet **OMG, int n, void(*proc)(void*)){/*�����ռ�*/
	int i;
	for(i=0;i<n;i++){
		clrSet(OMG[i],proc);
		free(OMG[i]);
	}
}
LinkedList* backtrackiter(ValueSet **OMG, int n){/*�������������*/
	int k=0, size=OMG[0]->list->eleSize;
	void *x=(void*)malloc(n*size);/*������*/
	LinkedList *solutions=createList(sizeof(Solution),NULL);/*�Ϸ��⼯��*/
	Solution s;/*�Ϸ����ݴ�ռ�*/
	assert(x&&solutions);
	while(k>=0){
		while(OMG[k]->current->next!=OMG[k]->list->nil){/*Xkδ�*/
			OMG[k]->current=OMG[k]->current->next;
			memcpy((char*)x+k*size,OMG[k]->current->key,size);
			if(isPartial(x, k)){/*���ֺϷ�*/
				if(isComplete(x, k)){/*�����Ϸ���*/
					s.x=(void*)malloc((k+1)*size);
					memcpy(s.x,x,(k+1)*size);/*���������*/
					s.k=k+1;/*����������*/
					listPushBack(solutions,&s);/*����⼯*/
					if(OMG[k]->current->next!=OMG[k]->list->nil)
						continue;
				}
				if(k==n-1){/*�ﵽ��Ҷ���������Ϸ���*/
					if(OMG[k]->current->next==OMG[k]->list->nil)
						break;
				}else k++;
			}
		}
		OMG[k]->current=OMG[k]->list->nil;/*����Xk*/
		k--;/*����*/
	}
	free(x);
	return solutions;/*���غϷ��⼯��*/
}
