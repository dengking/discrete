#ifndef _FACTOR_H
#define	_FACTOR_H
#ifdef	__cplusplus
extern
 "C" {
#endif
#include "bigint.h"
#include "./../datastructure/redblacktree.h"
	void factor(unsigned long n, RBTree* s);
	void Factor(BigInt n, RBTree* s);
#ifdef	__cplusplus
}
#endif
#endif	/* _FACTOR */
