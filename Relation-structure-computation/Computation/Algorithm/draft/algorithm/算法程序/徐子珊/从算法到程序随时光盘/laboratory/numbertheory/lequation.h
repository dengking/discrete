#ifndef _LEQUATION_H
#define	_LEQUATION_H
#ifdef	__cplusplus
extern
 "C" {
#endif
#include "../datastructure/list.h"
	 long long mod(long long a, long long m);
	LinkedList *modularLinearEquationSolver(unsigned long long,/*ϵ��*/
																	unsigned long long,/*����*/
																	unsigned long long/*ģ*/);
	LinkedList* modularEquationSolver(BigInt, BigInt, BigInt);
#ifdef	__cplusplus
}
#endif
#endif	/* _LEQUATION_H */
