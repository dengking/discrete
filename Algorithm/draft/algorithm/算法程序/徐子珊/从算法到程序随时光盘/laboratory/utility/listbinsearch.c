#include "listbinsearch.h"
ListNode *listBinSearch(LinkedList *L, void *x){
	int p=0,r=L->n-1,q,c;
	ListNode *P=L->nil->next, *R=L->nil->prev, *Q;
	while(p<=r){
		q=(p+r)/2;
		Q=advance(P,q);
		c=L->comp(x,Q->key);
		if(c==0)
			return Q;
		if(c>0){
			P=Q->next;
			p=q+1;
		}else{
			R=Q->prev;
			r=q-1;
		}
	}
	return NULL;
}