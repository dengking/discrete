#include<string.h>
#include <stdlib.h>
#include<assert.h>
#include "valuecalc.h"
int valueCompare(LinkedList *a, LinkedList *b){
	ListNode *p=a->nil->prev, *q=b->nil->prev;
	if(a->n>b->n)
		return 1;
	if(a->n<b->n)
		return -1;
	while(p!=a->nil){
		if(*((long*)(p->key))>*((long*)(q->key)))
			return 1;
		if(*((long*)(p->key))<*((long*)(q->key)))
			return -1;
		p=p->prev;q=q->prev;
	}
	return 0;
}
LinkedList *valueAdd(LinkedList *a, LinkedList *b){
	LinkedList *x,*y,*z=createList(sizeof(long), NULL);
	ListNode *p,*q;
	long r,carry=0;
	if(a->n>=b->n){
		x=a;y=b;
	}else{
		x=b;y=a;
	}
	p=x->nil->next;q=y->nil->next;
	while(q!=y->nil){
		r=*((long*)(p->key))+*((long*)(q->key))+carry;
		carry=r/Base;
		r=r%Base;
		listPushBack(z,&r);
		p=p->next;q=q->next;
	}
	while(p!=x->nil){
		r=*((long*)(p->key))+carry;
		carry=r/Base;
		r=r%Base;
		listPushBack(z,&r);
		p=p->next;
	}
	if(carry)
		listPushBack(z,&carry);
	return z;
}
LinkedList* valueSub(LinkedList *a, LinkedList *b){
	LinkedList *x=listClone(a), *y=b, *z=createList(sizeof(long), NULL);
	ListNode *p=x->nil->next,*q=y->nil->next;
	long r;
	while(q!=b->nil){
		r=*((long*)(p->key))-*((long*)(q->key));
		p=p->next;q=q->next;
		if(r<0){
			r+=Base;
			(*((long*)(p->key)))--;
		}
		listPushBack(z,&r);
	}
	while(p!=x->nil){
		r=*((long*)(p->key));
		p=p->next;
		if(r<0){
			r+=Base;
			*((long*)(p->key))--;
		}
		listPushBack(z,&r);
	}
	p=z->nil->prev;
	while(p!=z->nil->next&&*((long*)(p->key))==0){
		listDelete(z,p);
		p=z->nil->prev;
	}
	clrList(x,NULL);
	free(x);
	return z;
}
void valueDecreas(LinkedList *a, LinkedList *b){
	ListNode *p=a->nil->next, *q=b->nil->next;
	long x;
	while(q!=b->nil){
		x=*((long*)(p->key))-*((long*)(q->key));
		if(x<0){
			x+=Base;
			(*((long*)(p->next->key)))--;
		}
		memcpy(p->key,&x,sizeof(long));
		p=p->next;q=q->next;
	}
	while(p!=a->nil){
		x=*((long*)(p->key));
		if(x<0){
			x+=Base;
			memcpy(p->key,&x,sizeof(long));
			(*((long*)(p->next->key)))--;
		}
		p=p->next;
	}
	p=a->nil->prev;
	while(p!=a->nil->next&&*((long*)(p->key))==0){
		listDelete(a,p);
		p=a->nil->prev;
	}
}
void valueReduplicate(LinkedList *a, long b){
	long long x;
	long carry=0;
	ListNode *p=a->nil->next;
	while(p!=a->nil){
		x=(long long)(*((long*)(p->key)))*b+carry;
		carry=x/Base;
		x=x%Base;
		memcpy(p->key,&x,sizeof(long));
		p=p->next;
	}
	if(carry)
		listPushBack(a, &carry);
}
LinkedList* multedByDigit(LinkedList* a, long x){
	ListNode *p=a->nil->next;
	LinkedList *b=createList(sizeof(long),NULL);
	long long y;
	long carry=0,z;
	while(p!=a->nil){
		y=(long long)(*((long*)(p->key)))*x+carry;
		carry=y/Base;
		z=y%Base;
		listPushBack(b,&z);
		p=p->next;
	}
	if(carry)
		listPushBack(b,&carry);
	return b;
}
LinkedList* valueMulti(LinkedList *a, LinkedList *b){
	ListNode *r=a->nil->next, *q=b->nil->next, *p, *t;
	long long x;
	long y,carry=0,i,j,n=a->n,m=b->n;
	LinkedList *c=createList(sizeof(long),NULL);
	for(i=0;i<m+n;i++)
		listPushBack(c,&carry);
	for(t=c->nil->next,q=b->nil->next,i=0;i<m;q=q->next,t=t->next,i++){
		carry=0;
		for(p=a->nil->next,r=t,j=0;j<n;p=p->next,r=r->next,j++){
			x=(long long)(*((long*)(p->key)))*(*((long*)(q->key)))+(*((long*)(r->key)))+carry;
			carry=x/Base;
			y=x%Base;
			memcpy(r->key,&y,sizeof(long));
		}
		if(carry)
			memcpy(r->key,&carry,sizeof(long));
	}
	if((*((long*)(r->key)))==0)
		listDelete(c,r);
	return c;
}
void dividedByDigit(LinkedList *a, long x, long *r){
	long z;
	long long y;
	ListNode *p=a->nil->prev;
	assert(x!=0);
	*r=0;
	while(p!=a->nil){
		y=*((long*)(p->key))+(long long)(*r)*Base;
		z=y/x;
		memcpy(p->key,&z,sizeof(long));
		*r=y%x;
		p=p->prev;
	}
	p=a->nil->prev;
	while(p!=a->nil->next&&*((long*)(p->key))==0){
		listDelete(a,p);
		p=a->nil->prev;
	}
}
LinkedList *valueDivision(LinkedList *a, LinkedList *b, LinkedList *r){
	LinkedList *q=createList(sizeof(long), NULL),/*q为商*/
		*u, *v,/*u，v分别是a，b的规格化*/
		*u1=createList(sizeof(long), NULL),*v1=NULL;/*u1为中间余数，v1为1位商与v的积*/
	ListNode *p, *t;/*临时节点指针*/
	long i, n, m,/*n,m分别是u和v的位数*/
		vm, d, qj/*vm为v的最高位数字，d为规格化因子，qj是商的1位数字*/;
	int comp=valueCompare(a,b);
	if(comp<0){/*被除数a小于除数b*/
		qj=0;
		listPushFront(q,&qj);/*商q为0*/
		for(p=a->nil->next;p!=a->nil;p=p->next)/*余数r为a*/
			listPushBack(r,p->key);
		return q;
	}
	if(comp==0){/*被除数a与除数b相等*/
		qj=1;
		listPushFront(q,&qj);/*商q为1*/
		qj=0;
		listPushFront(r, &qj);/*余数r为0*/
		return q;
	}
	t=b->nil->prev;/*t指向b的最高位*/
	d=*((long*)(t->key))<Base/2?Base/(*((long*)(t->key))+1):1;/*计算规格化因子*/
	u=multedByDigit(a, d);/*规格化a*/
	v=multedByDigit(b, d);/*规格化b*/
	n=u->n;m=v->n;
	t=v->nil->prev;vm=*((long*)(t->key));/*t指向v的最高位*/
	for(p=u->nil->prev,i=0;i<m;i++,p=p->prev)/*初始化中间余数u1为u的高m-1位*/
		listPushFront(u1, p->key);
	for(i=n-m;i>=0;i--){/*逐位试商*/
		if(valueCompare(u1,v)<0){/*中间余数小于除数*/
			qj=0;
			listPushFront(q,&qj);/*商0*/
			if(p!=u->nil){/*中间余数添加1位*/
				listPushFront(u1,p->key);
				p=p->prev;
			}
			continue;
		}
		t=u1->nil->prev;/*t指向u1的最高位*/
		if(u1->n==m)/*u1和v位数相等时试商*/
			qj=*((long*)(t->key))/vm;
		else{/*u1的位数大于v的位数时试商*/
			qj=((long long)(*((long*)(t->key)))*Base+*((long*)(t->prev->key)))/vm;
			if(qj>Base-1)
				qj=Base-1;
			qj-=2;
		}
		if(v1){
			clrList(v1,NULL);
			free(v1);
		}
		v1=multedByDigit(v, qj);/*计算qj与v的积v1*/
		valueDecreas(u1, v1);/*从u1中减去v1*/
		while(valueCompare(u1, v)>=0){/*确定本位商*/
			qj++;
			valueDecreas(u1, v);
		}
		listPushFront(q, &qj);/*加入商*/
		t=u1->nil->prev;
		while(t!=u1->nil->next&&*((long*)(t->key))==0){/*去除u1的高位0*/
			listDelete(u1,t);
			t=u1->nil->prev;
		}
		if(p!=u->nil){
			listPushFront(u1,p->key);/*中间余数添加1位*/
			p=p->prev;
		}
	}
	p=q->nil->prev;
	while(p!=q->nil->next&&*((long*)(p->key))==0){/*去除q的高位0*/
		listDelete(q,p);
		p=q->nil->prev;
	}
	if(r){
		p=u1->nil->next;
		while(p!=u1->nil){/*确定余数r*/
			listPushBack(r,p->key);
			p=p->next;
		}
		dividedByDigit(r, d, &vm);/*去规格化*/
	}
	clrList(u,NULL);free(u);clrList(v,NULL);free(v);
	clrList(u1,NULL);free(u1);clrList(v1,NULL);free(v1);
	return q;
}
