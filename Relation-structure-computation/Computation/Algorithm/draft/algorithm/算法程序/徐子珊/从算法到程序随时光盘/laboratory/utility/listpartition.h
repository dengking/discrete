#ifndef _LISTPARTITION_H
#define	_LISTPARTITION_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "../datastructure/list.h"
ListNode* listPartition(LinkedList *A, ListNode *p,ListNode * r);
ListNode* rndListPartition(LinkedList *A, ListNode *p,ListNode * r);
#ifdef	__cplusplus
}
#endif

#endif	/* _LISTPARTITION_H */