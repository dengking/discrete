#ifndef _COMBINEPROBLEM_H
#define	_COMBINEPROBLEM_H
#include "../datastructure/list.h"
typedef struct{/*����������ȡֵ��������*/
	LinkedList *list;/*����*/
	ListNode *current;/*list��ǰ���ָ��*/
}ValueSet;
void clrSet(ValueSet* set, void(*proc)(void*));/*����ȡֵ���ϴ洢�ռ�*/
void clrOMG(ValueSet **OMG, int n, void(*proc)(void*));/*�����ռ�*/
typedef struct{/*�Ϸ�������*/
	void *x;/*������*/
	int k;/*����������*/
}Solution;
void clrSolution(Solution*);/*����Ϸ���洢�ռ�*/
int isPartial(void*, int);/*���ֺϷ��ж�*/
int isComplete(void*, int);/*�����Ϸ����ж�*/
LinkedList* backtrackiter(ValueSet **OMG, int n);/*�������������*/
LinkedList* subSetTree(int n);/*�Ӽ�������������*/
LinkedList* permutTree(void *origin, int size, int n);/*����������������*/
#endif	/* _COMBINEPROBLEM_H */
