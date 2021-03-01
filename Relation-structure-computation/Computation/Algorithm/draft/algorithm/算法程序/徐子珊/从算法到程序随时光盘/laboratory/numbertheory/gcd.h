#ifndef _GCD_H
#define	_GCD_H
#ifdef	__cplusplus
extern
 "C" {
#endif
#include "bigint.h"
	 typedef unsigned long long ul_int;
	 typedef long long l_int;
	 ul_int gcd(ul_int, ul_int);
	 ul_int egcd(ul_int a, ul_int b, l_int *x, l_int *y);
	 BigInt euclid(BigInt, BigInt);
	 BigInt extendedEuclid(BigInt, BigInt, BigInt*, BigInt*);
#ifdef	__cplusplus
}
#endif
#endif	/* _GCD_H */
