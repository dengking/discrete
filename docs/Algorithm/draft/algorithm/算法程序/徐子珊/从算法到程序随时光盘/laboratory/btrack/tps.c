#include "combineproblem.h"
#include <stdio.h>
#include <string.h>
#include <float.h>
double G[]={0,3,1,5,8,
			 3,0,6,7,9,
			 1,6,0,4,2,
			 5,7,4,0,3,
			 8,9,2,3,0},/*ͼG���ڽӾ���*/
	most=DBL_MAX ,/*��ǰ���Ž�Ŀ��ֵ*/
	obj;/*��ǰ���н�Ŀ��ֵ*/
	int n=5,/*ͼG�Ķ������*/
	s=1,/*���*/
	origin[]={2, 3, 4,5};/*�޳�����Ķ����ʼ����*/
int isPartial(int *x, int k){/*���ֿ��н��ж�*/
	int i;
	if(G[(s-1)*n+x[0]-1]==0)
		return 0;
	obj=G[(s-1)*n+x[0]-1];
	for(i=0;i<k;i++){
		if( G[(x[i]-1)*n+x[i+1]-1]==0)
			return 0;
		obj+=G[(x[i]-1)*n+x[i+1]-1];
		if(obj>=most)
			return 0;
	}
	return 1;
}
int isComplete(int *x, int k){
	if (k<n-2||G[(x[n-2]-1)*n+s-1]==0)
		return 0;
	obj+=G[(x[n-2]-1)*n+s-1];
	if(obj>=most)
		return 0;
	most=obj;
	return 1;
}
void print(int *x, int k){
	int i;
	printf("%d->",s);
	for(i=0;i<k;i++)
		printf("%d->", x[i]);
	printf("%d\n",s);
}
int main(){
	LinkedList *ss=permutTree(origin, sizeof(int), n-1);
	ListNode *p=ss->nil->prev;
	int i;
	print(((Solution*)(p->key))->x,((Solution*)(p->key))->k);
	printf("%.1f\n",most);
	clrList(ss, clrSolution);
	free(ss);
	return 0;
}