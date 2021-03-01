#include "listselect.h"
#include "listpartition.h"
ListNode* listSelect(LinkedList *a, ListNode *p, ListNode *r,int i){
	ListNode *q;
	int k;
	if(p==r)
		return p;
	q=rndListPartition(a,p,r);
	k=distance(p,q)-1;
	if(k==i)
		return q;
	if(i<k)
		return listSelect(a,p,q!=p?q->prev:p,i);
	return listSelect(a, q!=r?q->next:r, r,i-k-1);
}