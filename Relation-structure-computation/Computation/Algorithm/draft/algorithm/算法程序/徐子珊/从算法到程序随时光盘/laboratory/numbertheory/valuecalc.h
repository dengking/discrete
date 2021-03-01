#ifndef _VALUECALC_H
#define	_VALUECALC_H
#ifdef	__cplusplus
extern
 "C" {
#endif
#include "./../datastructure/list.h"
#define Base 1000000000
	 int valueCompare(LinkedList *a, LinkedList *b);
	 LinkedList *valueAdd(LinkedList *a, LinkedList *b);
	 LinkedList* valueSub(LinkedList *a, LinkedList *b);
	 void valueDecreas(LinkedList *a, LinkedList *b);
	 void valueReduplicate(LinkedList *a, long b);
	 LinkedList* multedByDigit(LinkedList* a, long x);
	 LinkedList* valueMulti(LinkedList *a, LinkedList *b);
	 void dividedByDigit(LinkedList *a, long x, long *r);
	 LinkedList *valueDivision(LinkedList *a, LinkedList *b, LinkedList *r);
#ifdef	__cplusplus
}
#endif
#endif	/* _VALUECALC */
