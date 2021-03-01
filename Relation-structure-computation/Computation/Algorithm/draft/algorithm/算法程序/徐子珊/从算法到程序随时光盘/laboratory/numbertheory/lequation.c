#include "lequation.h"
#include "gcd.h"
#include "bigint.h"
#include<stdio.h>
long long mod(long long a, long long m){
	long long x=a%m;
	if(x<0)
		x=x+m;
	return x;
}
LinkedList *modularLinearEquationSolver(unsigned long long a, unsigned long long b, unsigned long long n){
	LinkedList *S=createList(sizeof(unsigned long long),NULL);
	long long x, y,x0,i;
	unsigned long long d=egcd(a,n,&x,&y);
	if(b%d==0){
		x0=mod(x*(b/d), n);/*x*(b/d)可能是负数*/
		for(i=0;i<d;i++){
			x=(x0+i*n/d)%n;
			listPushBack(S,&x);
		}
	}
	return S;
}
LinkedList* modularEquationSolver(BigInt a, BigInt b, BigInt n){
	LinkedList *S=createList(sizeof(BigInt),NULL);
	BigInt x0, x={NULL,0}, y={NULL,0}, i,
			  d=extendedEuclid(a, n,&x, &y),
			  t=remainder(b,d),t1,t2;
	ListNode *p;
	if(isZero(t)){
		t1=quotient(b,d);t2=product(x,t1);
		x0=remainder(t2,n);
		for(clrBigInt(&x),i=newIntByint(0);compareInt(&i,&d)<0;increase(&i,1)){
			clrBigInt(&t1),clrBigInt(&t2);clrBigInt(&t);
			t1=quotient(n,d),t2=product(i,t1),t=sum(x0, t2);
			x= remainder(t,n);
			listPushBack(S,&x);
		}
	}
	clrBigInt(&y);clrBigInt(&x0);clrBigInt(&d);clrBigInt(&t);clrBigInt(&t1);clrBigInt(&t2);
	return S;
}