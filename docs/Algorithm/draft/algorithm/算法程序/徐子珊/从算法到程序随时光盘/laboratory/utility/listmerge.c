#include "listmerge.h"
#include <assert.h>
#include <string.h>
void listMerge(LinkedList *A, ListNode *p, ListNode *q, ListNode *r){
	LinkedList *L=createList(A->eleSize,A->comp), 
		               *R=createList(A->eleSize,A->comp);
	ListNode *i, *j, *k;
	assert(L&&R);
	i=p;
	do{/*��A[p..q]������L*/
		listPushBack(L,i->key);
		i=i->next;
	}while(i!=q->next);
	j=q->next;
	do{/*��A[q+1..r]������R*/
		listPushBack(R,j->key);
		j=j->next;
	}while(j!=r->next);
	i=L->nil->next,j=R->nil->next,k=p;
	while(i!=L->nil&&j!=R->nil){
		if(A->comp((char*)i->key,(char*)j->key)<0){/*L[i]<R[j]*/
			memcpy((char*)k->key,(char*)i->key,A->eleSize);/*A[k]��L[i]*/
			i=i->next;/*i��i+1*/
		}else{
			memcpy((char*)k->key,(char*)j->key,A->eleSize);/*A[k] ��R[j]*/
			j=j->next;/*j��j+1*/
		}
		k=k->next;/*k��k+1*/
	}
	if(i!=L->nil)
		while(i!=L->nil){/*��L[i..n1]������A[k..r]*/
			memcpy((char*)k->key,(char*)i->key,A->eleSize);/*A[k]��L[i]*/
			i=i->next,k=k->next;
		}
	if(j!=R->nil)
		while(j!=R->nil){/*��R[j..n2]������A[k..r]*/
			memcpy((char*)k->key,(char*)j->key,A->eleSize);
			j=j->next,k=k->next;
		}
	clrList(L,NULL),free(L);
	clrList(R,NULL),free(R);
}
