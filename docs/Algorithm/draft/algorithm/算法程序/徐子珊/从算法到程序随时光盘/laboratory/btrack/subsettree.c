#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "../datastructure/list.h"
#include "combineproblem.h"
LinkedList* subSetTree(int n){
	LinkedList *solutions=createList(n*sizeof(Solution),NULL);/*�Ϸ��⼯��*/
	Solution s;/*�Ϸ����ݴ�ռ�*/
	int *x=(int*)malloc(n*sizeof(int)),k=0;
	memset(x,-1,n*sizeof(int));
	assert(x&&solutions);
	while(k>=0){
		while(x[k]<1){
			x[k]++;
			if(isPartial(x, k)){/*���ֺϷ�*/
				if(isComplete(x, k)){/*�����Ϸ���*/
					s.x=(int*)malloc((k+1)*sizeof(int));
					memcpy(s.x,x,(k+1)*sizeof(int));/*���������*/
					s.k=k+1;/*����������*/
					listPushBack(solutions,&s);/*����⼯*/
					if(x[k]<1)
						continue;
				}
				if(k>=n-1){/*�ﵽ��Ҷ���ǺϷ���*/
					if(x[k]==1)
						break;
				}else k++;
			}
		}
		x[k]=-1;
		k--;
	}
	free(x);
	return solutions;/*���غϷ��⼯��*/
}
