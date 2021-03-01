#include "gcd.h"
#include "valuecalc.h"
#include <stdio.h>
ul_int gcd(ul_int a, ul_int b){
	ul_int r;
	while(b){
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
ul_int egcd(ul_int a, ul_int b, l_int *x, l_int *y){
	ul_int q, r;
	l_int x1=0, x2, y1=1, y2;
	*x=1;*y=0;
	while(b){
		q=a/b;r=a%b;x2=*x-q*x1;y2=*y-q*y1;
		a=b;b=r;*x=x1;x1=x2;*y=y1;y1=y2;
	}
	return a;
}
BigInt euclid(BigInt a, BigInt b){
	BigInt r={NULL,0},a1={NULL,0},b1={NULL,0};
	intAssign(&a1,a);intAssign(&b1,b);/*a1←a, b1←b*/
	a1.sign=b1.sign=0;
	while(!isZero(b1)){/*while b≠0*/
		clrBigInt(&r);/*清理r的空间*/
		r=remainder(a1,b1);/*r←a mod b*/
		intAssign(&a1,b1);/*a←b*/
		intAssign(&b1,r);/*b←r*/
	}
	clrBigInt(&b1);clrBigInt(&r);
	return a1;/*return a*/
}
BigInt extendedEuclid(BigInt a, BigInt b, BigInt* x, BigInt* y){
	BigInt r={NULL,0},q={NULL,0},t1={NULL,0},t2={NULL,0},
			  x2={NULL,0}, y2={NULL,0},a1={NULL,0},b1={NULL,0},
			  x1=newIntBystring("0"),/*x1←0*/
			  y1=newIntBystring("1");/*y1←1*/
			  intAssign(&a1,a),intAssign(&b1,b),/*a1←a, b1←b*/
			  intAssign(x,y1),intAssign(y, x1);/*x←1,y←0*/
	a1.sign=b1.sign=0;
	while(!isZero(b1)){/*while b≠0*/
		clrBigInt(&q),clrBigInt(&r),r.value=createList(sizeof(long),NULL);/*清理q，r空间*/
		q.value=valueDivision(a1.value,b1.value, r.value);/*q←a/b, r←a mod b*/
		clrBigInt(&t1),clrBigInt(&t2),t1=product(q, x1),t2=product(q, y1);
		clrBigInt(&x2),clrBigInt(&y2),/*清理x2，y2空间*/
		x2=diff(*x,t1), y2=diff(*y,t2);/*x2←x-qx1, y2←x-qy2*/
		intAssign(&a1,b1);intAssign(&b1,r);/*a←b, b←r*/
		intAssign(x, x1);intAssign(y,y1);/*x←x1, y←y1*/
		intAssign(&x1,x2);intAssign(&y1,y2);/*x1←x2,y1←y2*/
	}
	clrBigInt(&b1);clrBigInt(&q);clrBigInt(&r);clrBigInt(&x1);/*清理各临时变量的空间*/
	clrBigInt(&y1);clrBigInt(&x2);clrBigInt(&y2);clrBigInt(&t1);clrBigInt(&t2);
	return a1;/*return a*/
}
