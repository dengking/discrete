#include<assert.h>
#include "stack.h"
Stack* createStack(unsigned long size){/*������ջ*/
    Stack *S=(Stack*)malloc(sizeof(Stack));/*����ռ�*/
	assert(S!=NULL);
    S->L=createList(size,NULL);/*������������*/
	S->top=S->L->nil->next;/*��ʼ��ջ��*/
    return S;
}
void clrStack(Stack *S, void(*proc)(void*)){
	S->top=NULL;/*ջ��ָ���ÿ�*/
	clrList(S->L,proc);/*��������ռ�*/
	free(S->L);
}
int stackEmpty(Stack* S){/*���ջ��*/
	return S->top==S->L->nil;
}
void push(Stack *S,void *k){/*ѹջ����*/
    listPushFront(S->L,k);/*������β����*/
	S->top=S->L->nil->next;
}
ListNode *pop(Stack *S){/*��������*/
    ListNode *x;
    assert(!stackEmpty(S));/*�������*/
	x=S->top;/*x����Ϊջ��*/
	S->top=x->next;/*�����µ�ջ��*/
    listDelete(S->L,x);/*��ջ��������β��ժ��*/
    return x;
}
