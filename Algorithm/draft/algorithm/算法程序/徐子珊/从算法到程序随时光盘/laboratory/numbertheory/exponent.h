#ifndef _EXPONENT_H
#define	_EXPONENT_H
#ifdef	__cplusplus
extern
 "C" {
#endif
#include "bigint.h"
	 unsigned long lg2(unsigned long long n);
	 unsigned long long modularExponentiation(unsigned long long a,
																	  unsigned long long b,
																	  unsigned long long modular);
	 BigInt modularExponent(BigInt a, BigInt b, BigInt m);
#ifdef	__cplusplus
}
#endif
#endif	/* _EXPONENT */
