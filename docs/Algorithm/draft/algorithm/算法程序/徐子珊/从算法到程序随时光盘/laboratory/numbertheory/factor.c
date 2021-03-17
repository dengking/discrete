#include "factor.h"
#include "gcd.h"
#include "./../datastructure/hstb1.h"
#include "./../datastructure/hstb.h"
#include "primetest.h"
#include <stdio.h>
unsigned long pollarRho(unsigned long n){
	unsigned long i=1, k=2;
	unsigned long long x=RangedRandom(0,n),y=x,d;
	Hash_Table *S=createTable(100);
	do{
		hashInsert(S,x);
		d=gcd(x>y?x-y:y-x, n);
		if(d!=1&&d!=n)
			return d;
		i++;
		if(i==k){
			y=x;
			k<<=1;
		}
		x=(x*x-1)%n;
	}while(!inHashTable(S,x));
	return n;
}
void factor(unsigned long n, RBTree* s){
	unsigned long d, x;
	if(isPrime(n)){
		rbInsert(s,&n);
		return;
	}
	do{
		d=pollarRho(n);
	}while(d==n||d==1);
	factor(d,s);
	factor(n/d,s);
}
BigInt PollardRho(BigInt n){
    size_t i=1,k=2;
    HashTable *S=CreateTable(100);
	BigInt x=random(n),y={NULL,0},d={NULL,0},t={NULL,0},tow=newIntByint(2);
	intAssign(&y,x);
    do{
        HashInsert(S,x);clrBigInt(&t);
		t=compareInt(&y,&x)>0?diff(y,x):diff(x,y);
		clrBigInt(&d);
        d=euclid(t,n);
        if(!isOne(d)&&compareInt(&d,&n))
            break;
        i++;
        if(i==k){
			intAssign(&y,x);
            k<<=1;
        }
		clrBigInt(&t);t=product(x,x);decrease(&t,1);
        x=remainder(t,n);
   }while(!InHashTable(S,x));
	clrBigInt(&t);
	clrBigInt(&tow);
	ClrTable(S);free(S);
    return d;
}
void Factor(BigInt n, RBTree* s){
	BigInt d={NULL,0},t={NULL,0},x={NULL,0};
    if(MillerRabin(n,50)){
		intAssign(&x, n);
		rbInsert(s, &x);
        return;
    }
    do{
		clrBigInt(&d);
        d=PollardRho(n);
	}while(!compareInt(&d,&n)||isOne(d));
	clrBigInt(&t);t=quotient(n,d);
    Factor(d,s);
    Factor(t,s);
	clrBigInt(&d);clrBigInt(&t);
}
