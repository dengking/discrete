#include "listmerge.h"
#include "listmergesort.h"
void listMergeSort(LinkedList *A, ListNode *p, ListNode *r){
	if(p!=r->next&&p->prev!=r&&p!=r){
		 int n=distance(p,r);
         ListNode *q=p;
		 q=advance(q,n/2);
         listMergeSort(A, p,q);
		 listMergeSort(A, q->next,r);
         listMerge(A, p,q,r);
     }
}