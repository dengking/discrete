#ifndef _PRIMETEST_H
#define	_PRIMETEST_H
#ifdef	__cplusplus
extern
 "C" {
#endif
#include "bigint.h"
	int isPrime(unsigned long long);/*�����ж�����*/
	unsigned long long RangedRandom( unsigned long long range_min,/*�½�*/
														   unsigned long long range_max/*�Ͻ�*/);
	BigInt random(BigInt a);
	int millerRabin(unsigned long long n, int s);/*����㷨�ж�����*/
	int MillerRabin(BigInt n, int s);
#ifdef	__cplusplus
}
#endif
#endif	/* _PRIMETEST_H */
