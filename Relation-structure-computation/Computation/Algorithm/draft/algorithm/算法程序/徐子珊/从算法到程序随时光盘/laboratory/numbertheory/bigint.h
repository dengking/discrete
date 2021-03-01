#ifndef _BIGINT_H
#define	_BIGINT_H
#ifdef	__cplusplus
extern
 "C" {
#endif
#include "valuecalc.h"
#include "./../datastructure/list.h"
	typedef struct{
		LinkedList *value;
		int sign;
	}BigInt;
	BigInt newIntByint(long long);
	BigInt newIntBystring(char *);
	void clrBigInt(BigInt*);
	void intAssign(BigInt *a, BigInt b);
	void printInt(BigInt*);
	char *toString(BigInt *a);
	int compareInt(BigInt*, BigInt*);
	int isZero(BigInt x);
	int isOne(BigInt a);
	BigInt negative(BigInt a);
	BigInt sum(BigInt, BigInt);
	void increase(BigInt*, unsigned);
	BigInt diff(BigInt, BigInt);
	void decrease(BigInt*, unsigned);
	BigInt product(BigInt, BigInt);
	BigInt quotient(BigInt, BigInt);
	BigInt remainder(BigInt, BigInt);
#ifdef	__cplusplus
}
#endif
#endif	/* _BIGINT */
