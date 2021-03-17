#include "primetest.h"
#include "exponent.h"
#include <assert.h>
#include <math.h>
#include<stdlib.h>
#include<stdio.h>
#include <time.h>
#include "../utility/randomn.h"
BigInt random(BigInt a){
	BigInt b={createList(sizeof(long),NULL),0};
	ListNode *p=a.value->nil->next;
	long x;
	assert(a.sign==0);
	srand( time(NULL) );
	x=RangedRandom(1,*((long*)(p->key)));
	listPushBack(b.value,&x);
	p=p->next;
	while(p!=a.value->nil){
		x=RangedRandom(0,*((long*)(p->key)));
		listPushBack(b.value,&x);
		p=p->next;
	}
	p=b.value->nil->prev;
	while(p!=b.value->nil->next&&(*((long*)(p->key))==0)){
		listDelete(b.value,p);
		p=b.value->nil->prev;
	}
	return b;
}
int isPrime(unsigned long long n){
	unsigned long long i,m=sqrt((double)n);
	for(i=2;i<=m;i++)
		if(n%i==0)
			return 0;
	return 1;
}
int witness(unsigned long long a, unsigned long long n){
	unsigned long long u=n-1,x0,xi;
	int t=0,i;
	while(!(u&1)){
		u=u>>1;
		t++;
	}
	x0=modularExponentiation(a, u, n);
	xi=x0;/*∂‘xi≥ı ºªØ*/
	for(i=1;i<=t;i++){
		xi=(x0*x0)%n;
		if((xi==1)&&(x0!=1)&&(x0!=n-1))
			return 1;
		x0=xi;
	}
	if(xi!=1)
		return 1;
	return 0;
}
int Witnees(BigInt a, BigInt n){
	BigInt u={NULL,0},x0,xi={NULL,0},tow=newIntByint(2),n1={NULL,0};
	long r,t=0,i;
	intAssign(&u,n),decrease(&u,1);intAssign(&n1,u);
	r=(*((long*)(u.value->nil->next->key)))%2;
	while(!isZero(u)&&!r){
		t++;
		dividedByDigit(u.value,2,&i);
		r=(*((long*)(u.value->nil->next->key)))%2;
	}
	x0=modularExponent(a, u, n);
	intAssign(&xi,x0);
	for(i=1;i<=t;i++){
		clrBigInt(&xi);
		xi=modularExponent(x0,tow,n);
		if(isOne(xi)&&!isOne(x0)&&compareInt(&x0,&n1))
			return 1;
		intAssign(&x0,xi);
	}
	if(!isOne(xi))
		return 1;
	return 0;
}
int millerRabin(unsigned long long n, int s){
	int j;
	unsigned long long a;
	for(j=1;j<=s;j++){
		a=RangedRandom(1, n);
		if(witness(a, n))
			return 0;
	}
	return 1;
}
int MillerRabin(BigInt n, int s){
	BigInt a={NULL,0};
	int j;
	for(j=0;j<s;j++){
		clrBigInt(&a);
		a=random(n);
		if(Witnees(a,n))
			return 0;
	}
	return 1;
}