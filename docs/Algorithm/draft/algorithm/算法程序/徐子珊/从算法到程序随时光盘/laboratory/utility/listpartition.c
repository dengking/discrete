#include "listpartition.h"
#include "randomn.h"
#include "swap.h"
ListNode* listPartition(LinkedList *A, ListNode *p,ListNode * r){
    ListNode *i, *j;
	void *x=(void*)malloc(A->eleSize);
	memcpy((char*)x,(char*)r->key,A->eleSize);/*x¡ûa[r]*/
	i=p->prev;
	for(j=p;j!=r;j=j->next)
		if(A->comp((char*)j->key,(char*)x)<=0){/*a[j]¡Üx*/
			i=i->next;
			swap((char*)i->key,(char*)j->key,A->eleSize);/*a[i]?a[j]*/
        }
	free(x);
	swap((char*)i->next->key,(char*)r->key,A->eleSize);/* a[i+1]?a[r]*/
	return i->next;
}
ListNode* rndListPartition(LinkedList *A, ListNode *p,ListNode * r){
	int d=distance(p,r),t=randomNumber(0,d);
	ListNode *i=advance(p,t);
	swap(i->key,r->key,A->eleSize);/*a[r]?a[i]*/
	return listPartition(A,p,r);
}
