#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include<assert.h>
#include "bigint.h"
int compareInt(BigInt *a, BigInt *b){
	ListNode *p=a->value->nil->prev,*q=a->value->nil->prev;
	if(a->sign==0&&b->sign==0)/*a、b皆为正数*/
		return valueCompare(a->value,b->value);
	if(a->sign==0)/*a为正数，b为负数*/
		return 1;
	if(b->sign==0)/*a为负数，b为正数*/
		return -1;
	return -valueCompare(a->value, b->value);/*a，b均为负数*/
}
void printInt(BigInt *a){
	ListNode *p;
	if(listEmpty(a->value))
		return;
	if(a->sign)
		printf("-");
	p=a->value->nil->prev;
	printf("%lu",*((long*)(p->key)));
	p=p->prev;
	while(p!=a->value->nil){
		printf("%09lu",*((long*)(p->key)));
		p=p->prev;
	}
	putchar(' ');
}
char *toString(BigInt *a){
	ListNode *p;
	char *s,d[10];
	if(listEmpty(a->value))
		return NULL;
	s=(char*)calloc(a->value->n*10,sizeof(char));
	if(a->sign)
		strcpy(s,"-");
	p=a->value->nil->prev;
	sprintf(d,"%lu",*((long*)(p->key)));
	strcat(s,d);
	p=p->prev;
	while(p!=a->value->nil){
		sprintf(d, "%09lu",*((long*)(p->key)));
		strcat(s,d);
		p=p->prev;
	}
	return s;
}
BigInt newIntByint(long long x){
	long a;
	BigInt n;
	n.value=createList(sizeof(long), NULL);
	n.sign=x<0;
	x=x<0?-x:x;
	do{
		a=(long)(x%Base);
		listPushBack(n.value,&a);
		x=x/Base;
	}while(x);
	return n;
}
BigInt newIntBystring(char *s){
	int n,i;
	long x;
	div_t qr;
	BigInt a;
	char digit[10];
	a.value=createList(sizeof(long), NULL);
	if(s[0]=='-'){
		a.sign=1;
		s++;
	}else
		a.sign=0;
	n=strlen(s);
	qr=div(n,9);
	if(qr.rem){
		strncpy(digit,s,qr.rem);
		x=strtoul(digit, NULL, 10);
		listPushFront(a.value,&x);
	}
	for(i=0;i<qr.quot;i++){
		strncpy(digit,s+qr.rem+i*9,9);
		x=strtoul(digit, NULL, 10);
		listPushFront(a.value,&x);
	}
	return a;
}
void clrBigInt(BigInt *a){
	if(a->value){
		clrList(a->value,NULL);
		free(a->value);
	}
}
static BigInt intClone(BigInt a){
	BigInt b={NULL,a.sign};
	b.value=listClone(a.value);
	return b;
}
void intAssign(BigInt *a, BigInt b){
	if(a->value){
		clrList(a->value,NULL);
		free(a->value);
	}
	*a=intClone(b);
}
BigInt negative(BigInt a){
	BigInt b;
	b.value=listClone(a.value);
	b.sign=!a.sign;
	return b;
}
BigInt sum(BigInt a, BigInt b){
	BigInt c;
	int comp=valueCompare(a.value,b.value);
	if(a.sign==b.sign){/*a，b符号相同*/
		c.value=valueAdd(a.value,b.value);
		c.sign=a.sign;
		return c;
	}
	if(comp==0){/*符号相反，绝对值相同*/
		long x=0;
		c.value=createList(sizeof(long),NULL);
		listPushBack(c.value,&x);
		c.sign=0;
		return c;
	}
	if(comp>0){/*符号相反，a的绝对值大于b的绝对值*/
		c.value=valueSub(a.value,b.value);
		c.sign=a.sign;
	}else{/*符号相反，b的绝对值大于a的绝对值*/
		c.value=valueSub(b.value,a.value);
		c.sign=b.sign;
	}
	return c;
}
void increase(BigInt *a, unsigned long n){
	long x, carry;
	ListNode *p=a->value->nil->next;
	if(a->sign==0){
		x=*((long*)(p->key))+n;
		if(carry=x/Base)
			x=x%Base;
		memcpy(p->key,&x,sizeof(long));
		p=p->next;
		while(carry&&p!=a->value->nil){
			x=*((long*)(p->key))+carry;
			if(carry=x/Base)
				x=x%Base;
			memcpy(p->key,&x,sizeof(long));
			p=p->next;
		}
		if(carry)
			listPushBack(a->value,&carry);
	}else{
		x=*((long*)(p->key))-n;
		if(x<0){
			x+=Base;
			if(p->next!=a->value->nil)
				(*((long*)(p->next->key)))--;
			else a->sign=0;
		}
		memcpy(p->key,&x,sizeof(long));
		p=p->next;
		while(p!=a->value->nil&&*((long*)(p->key))<0){
			x=*((long*)(p->key))+Base;
			memcpy(p->key,&x,sizeof(long));
			p=p->next;
			if(p!=a->value->nil)
				(*((long*)(p->key)))--;
			else a->sign=0;
		}
		p=a->value->nil->prev;
		while(p!=a->value->nil->next&&(*((long*)(p->key))==0)){
			listDelete(a->value,p);
			p=a->value->nil->prev;
		}
		if(a->value->n==1&&(*((long*)(a->value->nil->next->key))==0))
			a->sign=0;
	}
}
void decrease(BigInt *a, unsigned n){
	a->sign=!a->sign;
	increase(a,n);
	a->sign=!a->sign;
}
BigInt diff(BigInt a, BigInt b){
	BigInt x=negative(b);
	return sum(a, x);
}
int isZero(BigInt x){
	return (x.value->n==1)&&(*((long*)(x.value->nil->next->key))==0);
}
int isOne(BigInt a){
	return ((a.sign==0)&&(a.value->n==1)&&(*((long*)(a.value->nil->next->key))==1));
}
BigInt product(BigInt a, BigInt b){
	BigInt c;
	long x;
	c.value=createList(sizeof(long),NULL);
	if(isZero(a)||isZero(b)){
		x=0;
		listPushBack(c.value,&x);
		c.sign=0;
		return c;
	}
	c.sign=a.sign!=b.sign;
	c.value=valueMulti(a.value,b.value);
	return c;
}
void valuePrint(LinkedList *a){
	ListNode *p=a->nil->prev;
	printf("%lu ",*((int*)(p->key)));
	p=p->prev;
	while(p!=a->nil){
		printf("%09lu ",*((int*)(p->key)));
		p=p->prev;
	}
	putchar('\n');
}
BigInt quotient(BigInt a, BigInt b){
	BigInt c,r;
	r.value=createList(sizeof(long), NULL);
	assert(!isZero(b));
	c.sign=a.sign!=b.sign;
	c.value=valueDivision(a.value, b.value, r.value);
	if(c.sign&&!isZero(r))
		decrease(&c,1);
	clrBigInt(&r);
	return c;
}
BigInt remainder(BigInt a, BigInt b){
	BigInt c, r;
	assert(!isZero(b));
	assert(b.sign!=1);
	r.value=createList(sizeof(long),NULL);
	r.sign=0;
	c.value=valueDivision(a.value,b.value,r.value);
	if(a.sign){
		b=diff(b, r);
		clrBigInt(&r);
		r.value=listClone(b.value);
		clrBigInt(&b);
	}
	clrList(c.value,NULL);free(c.value);
	return r;
}