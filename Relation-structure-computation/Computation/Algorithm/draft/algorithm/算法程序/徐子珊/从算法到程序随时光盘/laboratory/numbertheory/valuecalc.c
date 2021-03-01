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
	LinkedList *q=createList(sizeof(long), NULL),/*qΪ��*/
		*u, *v,/*u��v�ֱ���a��b�Ĺ��*/
		*u1=createList(sizeof(long), NULL),*v1=NULL;/*u1Ϊ�м�������v1Ϊ1λ����v�Ļ�*/
	ListNode *p, *t;/*��ʱ�ڵ�ָ��*/
	long i, n, m,/*n,m�ֱ���u��v��λ��*/
		vm, d, qj/*vmΪv�����λ���֣�dΪ������ӣ�qj���̵�1λ����*/;
	int comp=valueCompare(a,b);
	if(comp<0){/*������aС�ڳ���b*/
		qj=0;
		listPushFront(q,&qj);/*��qΪ0*/
		for(p=a->nil->next;p!=a->nil;p=p->next)/*����rΪa*/
			listPushBack(r,p->key);
		return q;
	}
	if(comp==0){/*������a�����b���*/
		qj=1;
		listPushFront(q,&qj);/*��qΪ1*/
		qj=0;
		listPushFront(r, &qj);/*����rΪ0*/
		return q;
	}
	t=b->nil->prev;/*tָ��b�����λ*/
	d=*((long*)(t->key))<Base/2?Base/(*((long*)(t->key))+1):1;/*����������*/
	u=multedByDigit(a, d);/*���a*/
	v=multedByDigit(b, d);/*���b*/
	n=u->n;m=v->n;
	t=v->nil->prev;vm=*((long*)(t->key));/*tָ��v�����λ*/
	for(p=u->nil->prev,i=0;i<m;i++,p=p->prev)/*��ʼ���м�����u1Ϊu�ĸ�m-1λ*/
		listPushFront(u1, p->key);
	for(i=n-m;i>=0;i--){/*��λ����*/
		if(valueCompare(u1,v)<0){/*�м�����С�ڳ���*/
			qj=0;
			listPushFront(q,&qj);/*��0*/
			if(p!=u->nil){/*�м��������1λ*/
				listPushFront(u1,p->key);
				p=p->prev;
			}
			continue;
		}
		t=u1->nil->prev;/*tָ��u1�����λ*/
		if(u1->n==m)/*u1��vλ�����ʱ����*/
			qj=*((long*)(t->key))/vm;
		else{/*u1��λ������v��λ��ʱ����*/
			qj=((long long)(*((long*)(t->key)))*Base+*((long*)(t->prev->key)))/vm;
			if(qj>Base-1)
				qj=Base-1;
			qj-=2;
		}
		if(v1){
			clrList(v1,NULL);
			free(v1);
		}
		v1=multedByDigit(v, qj);/*����qj��v�Ļ�v1*/
		valueDecreas(u1, v1);/*��u1�м�ȥv1*/
		while(valueCompare(u1, v)>=0){/*ȷ����λ��*/
			qj++;
			valueDecreas(u1, v);
		}
		listPushFront(q, &qj);/*������*/
		t=u1->nil->prev;
		while(t!=u1->nil->next&&*((long*)(t->key))==0){/*ȥ��u1�ĸ�λ0*/
			listDelete(u1,t);
			t=u1->nil->prev;
		}
		if(p!=u->nil){
			listPushFront(u1,p->key);/*�м��������1λ*/
			p=p->prev;
		}
	}
	p=q->nil->prev;
	while(p!=q->nil->next&&*((long*)(p->key))==0){/*ȥ��q�ĸ�λ0*/
		listDelete(q,p);
		p=q->nil->prev;
	}
	if(r){
		p=u1->nil->next;
		while(p!=u1->nil){/*ȷ������r*/
			listPushBack(r,p->key);
			p=p->next;
		}
		dividedByDigit(r, d, &vm);/*ȥ���*/
	}
	clrList(u,NULL);free(u);clrList(v,NULL);free(v);
	clrList(u1,NULL);free(u1);clrList(v1,NULL);free(v1);
	return q;
}
