#include "listquicksort.h"
void listQuickSort(LinkedList *A, ListNode *p, ListNode *r){
	if(p!=r->next&&p->prev!=r&&p!=r){
		ListNode *q=rndListPartition(A, p, r);
		listQuickSort(A, p, q->prev);
		listQuickSort(A, q->next, r);
	}
}