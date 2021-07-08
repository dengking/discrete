/* 
 * File:   list.h
 * Author: ����ɺ
 *
 * Created on 2010��8��21��, ����2:34
 */

#ifndef _LIST_H
#define	_LIST_H
#include <stdlib.h>

typedef struct ListNode{/*�ڵ����ͽṹ��*/
    void* key; /*�ؼ�ֵָ��*/
    struct ListNode* prev; /*ǰ���ڵ�ָ��*/
    struct ListNode* next; /*��̽ڵ�ָ��*/
} ListNode;
ListNode* createListNode(void* d, int size); /*�����ڵ�*/
void clrListNode(ListNode* x, void(*proc)(void*)); /*����ڵ�*/

typedef struct {/*�������ͽṹ��*/
	size_t eleSize;/*Ԫ�����ݴ洢���*/
	int (*comp)(void*, void*);/*Ԫ�����ݱȽϹ���*/
    ListNode* nil; /*ͷָ�룬nil���ڱ���㣬next[nil]Ϊ����ı��׽�㣬pre[nil]Ϊ����ı�β��㣬��������ʵ�ʳ�Ϊ��һ����������*/
    int n; /*Ԫ�ظ���*/
}LinkedList;
LinkedList *createList(unsigned long size,int(*comp)(void*,void*)); /*����������*/
void clrList(LinkedList* L, void(*proc)(void*));/*��������*/
int listEmpty(LinkedList*);/*��������Ƿ�Ϊ��*/
ListNode* listSearch(LinkedList* L, void* e);/*�������в���*/
void listInsert(LinkedList* L, ListNode* a, void* k);/*��L�Ľڵ�aǰ����keyΪk�Ľڵ�*/
void listPushFront(LinkedList* L, void* k);/*�ڱ��ײ���*/
void listPushBack(LinkedList* L, void* k);/*�ڱ�β����*/
void listDelete(LinkedList* L, ListNode* e);/*��������ɾ���ڵ�*/
void listTraverse(LinkedList* L, void(*proc)(void*));/*��������*/
ListNode *advance(ListNode *i,int d);
int distance(ListNode *p, ListNode *r);
LinkedList *listClone(LinkedList*);

#endif	/* _LIST_H */

