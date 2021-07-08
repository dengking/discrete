#include<stdio.h>
#include<assert.h>
#include<string.h>
#include "list.h"



ListNode* createListNode(void* d, int size) { /*�����ڵ㣬d��ָ�����������ڸ����ݵ������ڱ����ʱ�򲢲�֪���������Ҫ��֪�����ݵ�size���Ա㶯̬�����ڴ�*/
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

void clrListNode(ListNode* x, void(*proc)(void*)) {/*����ڵ�*/
    if (x != NULL) {
        if (proc != NULL)
            proc(x->key);
        free(x->key);
    }
    x->next = x->prev = NULL;
}

LinkedList *createList(unsigned long size,int(*comp)(void*,void*)) {/*����������*/
    LinkedList *L = (LinkedList *) malloc(sizeof (LinkedList));
	assert(L!=NULL);
    L->nil=createListNode(NULL,0);/*�����ڱ��ڵ�*/
	L->nil->prev=L->nil->next=L->nil;
    L->n = 0;
	L->eleSize=size;/*����Ԫ�����ݴ洢���*/
	L->comp=comp;/*����Ԫ�����ݱȽϹ���*/
    return L;
}

void clrList(LinkedList* L, void(*proc)(void*)) {/*��������*/
	ListNode *x = L->nil->next;/*��xָ�������ͷ���*/
	while (x != L->nil) {/*��������β����next��ָ���ڱ����*/
        listDelete(L, x);
        clrListNode(x, proc);
        free(x);
		x=L->nil->next;
    }
	free(L->nil);
	L->comp=NULL;
}

int listEmpty(LinkedList* L) {/*��������Ƿ�Ϊ��*/
	return L->nil->next==L->nil;
}

ListNode* listSearch(LinkedList* L, void* e) {/*�������в���*/
	ListNode* x = L->nil->next;
	int (*comp)(void*, void*)=L->comp;
	while (x != L->nil && comp(x->key, e) != 0) {
        x = x->next;
    }
    return x;
}

void listInsert(LinkedList* L, ListNode* a, void* k) {/*��L��a֮ǰ����Ԫ��k*/
	int size=L->eleSize;
	ListNode* x = createListNode(k, size), *b=a->prev;
    L->n++;
	x->next=a;
	x->prev=b;
	a->prev=b->next=x;
}

void listPushFront(LinkedList* L, void* k){/*�ڱ��ײ���*/
	listInsert(L,L->nil->next,k);
}

void listPushBack(LinkedList* L, void* k){/*�ڱ�β����*/
	listInsert(L,L->nil,k);
}

void listDelete(LinkedList* L, ListNode* x) {/*��������ɾ���ڵ�*/
	ListNode *a=x->next,*b=x->prev;
	if (x == L->nil)
        return;
	b->next=a;
	a->prev=b;
    L->n--;
}

void listTraverse(LinkedList* L, void(*proc)(void*)) {/*�������*/
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