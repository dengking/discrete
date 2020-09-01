#include "bigint.h"
#include "exponent.h"
unsigned long lg2(unsigned long long n){/*计算n的2进制位数*/
	unsigned long long x=1;
	unsigned long c=0;
	do{
		x=x<<1;
		c++;
	}while(x<n);
	return c;
}
unsigned long long modularExponentiation(unsigned long long a,/*底*/
																 unsigned long long b,/*指数*/
																 unsigned long long m/*模*/){
	unsigned long k=lg2(b);
	unsigned long long d=1,bit=1LL<<k;
	while(bit){
		d=(d*d)%m;
		if(b&bit)/*b的第i位*/
			d=(d*a)%m;
		bit=bit>>1;
	}
	return d;
}
static BigInt modularPow(BigInt a, long b, BigInt m){
	long k=lg2(b),bit=1L<<k;
	BigInt d=newIntByint(1),t={NULL,0},t1={NULL,0};
	if(isOne(a))
		return d;
	while(bit){
		clrBigInt(&t);clrBigInt(&t1);
		t=product(d,d);t1=remainder(t,m);intAssign(&d,t1);
		if(b&bit){
			clrBigInt(&t),clrBigInt(&t1);
			t=product(d,a);
			//printInt(t);putchar('\n');
			//printInt(m);putchar('\n');
			t1=remainder(t,m);
			intAssign(&d,t1);
		}
		bit=bit>>1;
	}
	clrBigInt(&t);clrBigInt(&t1);
	return d;
}
BigInt modularExponent(BigInt a, BigInt b, BigInt m){
	long i,n=b.value->n,x;
	BigInt d=newIntByint(1),t={NULL,0},t1={NULL,0};
	ListNode *p=b.value->nil->prev;
	if(isOne(a))
		return d;
	for(i=1;i<=n;i++){
		clrBigInt(&t);
		t=modularPow(d,Base,m);intAssign(&d,t);
		x=*((long*)(p->key));
		if(x){
			clrBigInt(&t),clrBigInt(&t1);
			t=modularPow(a,x,m);t1=product(d, t);
			clrBigInt(&d);d=remainder(t1,m);
		}
		p=p->prev;
	}
	clrBigInt(&t);clrBigInt(&t1);
	return d;
}