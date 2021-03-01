#ifndef _PRIMETEST_H
#define	_PRIMETEST_H
#ifdef	__cplusplus
extern
 "C" {
#endif
#include "bigint.h"
	int isPrime(unsigned long long);/*常规判断素数*/
	unsigned long long RangedRandom( unsigned long long range_min,/*下界*/
														   unsigned long long range_max/*上界*/);
	BigInt random(BigInt a);
	int millerRabin(unsigned long long n, int s);/*随机算法判断素数*/
	int MillerRabin(BigInt n, int s);
#ifdef	__cplusplus
}
#endif
#endif	/* _PRIMETEST_H */
