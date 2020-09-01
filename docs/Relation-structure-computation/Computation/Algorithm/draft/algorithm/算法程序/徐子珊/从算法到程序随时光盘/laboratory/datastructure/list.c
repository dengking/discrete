#include<stdio.h>
#include<assert.h>
#include<string.h>
#include "list.h"



ListNode* createListNode(void* d, int size) { /*创建节点，d是指向数据域，由于该数据的类型在编译的时候并不知道，因此需要告知此数据的size，以便动态分配内存*/
    ListNode* x = (ListNode*) malloc(sizeof (ListNode));
	assert(x!=NULL);
	if(d&&size){
		x->key = (void*) malloc(size);
		assert(x->key!=NULL);
		memcpy(x->key, d, size);
		x->prev = x->next = NULL;
	}
    return x;
}

void clrListNode(ListNode* x, void(*proc)(void*)) {/*清理节点*/
    if (x != NULL) {
        if (proc != NULL)
            proc(x->key);
        free(x->key);
    }
    x->next = x->prev = NULL;
}

LinkedList *createList(unsigned long size,int(*comp)(void*,void*)) {/*创建新链表*/
    LinkedList *L = (LinkedList *) malloc(sizeof (LinkedList));
	assert(L!=NULL);
    L->nil=createListNode(NULL,0);/*创建哨兵节点*/
	L->nil->prev=L->nil->next=L->nil;
    L->n = 0;
	L->eleSize=size;/*设置元素数据存储宽度*/
	L->comp=comp;/*设置元素数据比较规则*/
    return L;
}

void clrList(LinkedList* L, void(*proc)(void*)) {/*清理链表*/
	ListNode *x = L->nil->next;/*让x指向链表的头结点*/
	while (x != L->nil) {/*环形链表尾结点的next即指向哨兵结点*/
        listDelete(L, x);
        clrListNode(x, proc);
        free(x);
		x=L->nil->next;
    }
	free(L->nil);
	L->comp=NULL;
}

int listEmpty(LinkedList* L) {/*检测链表是否为空*/
	return L->nil->next==L->nil;
}

ListNode* listSearch(LinkedList* L, void* e) {/*在链表中查找*/
	ListNode* x = L->nil->next;
	int (*comp)(void*, void*)=L->comp;
	while (x != L->nil && comp(x->key, e) != 0) {
        x = x->next;
    }
    return x;
}

void listInsert(LinkedList* L, ListNode* a, void* k) {/*在L的a之前插入元素k*/
	int size=L->eleSize;
	ListNode* x = createListNode(k, size), *b=a->prev;
    L->n++;
	x->next=a;
	x->prev=b;
	a->prev=b->next=x;
}

void listPushFront(LinkedList* L, void* k){/*在表首插入*/
	listInsert(L,L->nil->next,k);
}

void listPushBack(LinkedList* L, void* k){/*在表尾插入*/
	listInsert(L,L->nil,k);
}

void listDelete(LinkedList* L, ListNode* x) {/*在链表中删除节点*/
	ListNode *a=x->next,*b=x->prev;
	if (x == L->nil)
        return;
	b->next=a;
	a->prev=b;
    L->n--;
}

void listTraverse(LinkedList* L, void(*proc)(void*)) {/*输出链表*/
	ListNode* x = L->nil->next;
	while (x != L->nil) {
        proc(x->key);
        x = x->next;
    }
}
ListNode *advance(ListNode *i,int d){
	int distance=d>=0?d:-d, k=1;
	while(k<distance){
		if(d>=0)
			i=i->next;
		else
			i=i->prev;
		k++;
	}
	return i;
}
int distance(ListNode *p, ListNode *r){
	int dist=1;
	while(p!=r){
		dist++;
		p=p->next;
	}
	return dist;
}
LinkedList *listClone(LinkedList*x){
	LinkedList *y=createList(x->eleSize,x->comp);
	ListNode *p=x->nil->next;
	while(p!=x->nil){
		listPushBack(y, p->key);
		p=p->next;
	}
	return y;
}