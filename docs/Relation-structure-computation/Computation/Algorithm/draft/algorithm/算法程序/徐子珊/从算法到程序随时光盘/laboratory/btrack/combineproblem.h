#ifndef _COMBINEPROBLEM_H
#define	_COMBINEPROBLEM_H
#include "../datastructure/list.h"
typedef struct{/*解向量分量取值集合类型*/
	LinkedList *list;/*链表*/
	ListNode *current;/*list当前结点指针*/
}ValueSet;
void clrSet(ValueSet* set, void(*proc)(void*));/*清理取值集合存储空间*/
void clrOMG(ValueSet **OMG, int n, void(*proc)(void*));/*清理解空间*/
typedef struct{/*合法解类型*/
	void *x;/*解向量*/
	int k;/*解向量长度*/
}Solution;
void clrSolution(Solution*);/*清理合法解存储空间*/
int isPartial(void*, int);/*部分合法判断*/
int isComplete(void*, int);/*完整合法解判断*/
LinkedList* backtrackiter(ValueSet **OMG, int n);/*组合问题回溯求解*/
LinkedList* subSetTree(int n);/*子集树问题回溯求解*/
LinkedList* permutTree(void *origin, int size, int n);/*排列树问题回溯求解*/
#endif	/* _COMBINEPROBLEM_H */
