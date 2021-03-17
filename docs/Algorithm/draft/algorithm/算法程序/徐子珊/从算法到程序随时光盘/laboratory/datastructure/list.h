/* 
 * File:   list.h
 * Author: 徐子珊
 *
 * Created on 2010年8月21日, 下午2:34
 */

#ifndef _LIST_H
#define	_LIST_H
#include <stdlib.h>

typedef struct ListNode{/*节点类型结构体*/
    void* key; /*关键值指针*/
    struct ListNode* prev; /*前驱节点指针*/
    struct ListNode* next; /*后继节点指针*/
} ListNode;
ListNode* createListNode(void* d, int size); /*创建节点*/
void clrListNode(ListNode* x, void(*proc)(void*)); /*清理节点*/

typedef struct {/*链表类型结构体*/
	size_t eleSize;/*元素数据存储宽度*/
	int (*comp)(void*, void*);/*元素数据比较规则*/
    ListNode* nil; /*头指针，nil是哨兵结点，next[nil]为链表的表首结点，pre[nil]为链表的表尾结点，这样链表实际成为了一个环形链表*/
    int n; /*元素个数*/
}LinkedList;
LinkedList *createList(unsigned long size,int(*comp)(void*,void*)); /*创建新链表*/
void clrList(LinkedList* L, void(*proc)(void*));/*清理链表*/
int listEmpty(LinkedList*);/*检测链表是否为空*/
ListNode* listSearch(LinkedList* L, void* e);/*在链表中查找*/
void listInsert(LinkedList* L, ListNode* a, void* k);/*在L的节点a前插入key为k的节点*/
void listPushFront(LinkedList* L, void* k);/*在表首插入*/
void listPushBack(LinkedList* L, void* k);/*在表尾插入*/
void listDelete(LinkedList* L, ListNode* e);/*在链表中删除节点*/
void listTraverse(LinkedList* L, void(*proc)(void*));/*遍历链表*/
ListNode *advance(ListNode *i,int d);
int distance(ListNode *p, ListNode *r);
LinkedList *listClone(LinkedList*);

#endif	/* _LIST_H */

