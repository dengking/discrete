#include<assert.h>
#include "stack.h"
Stack* createStack(unsigned long size){/*创建空栈*/
    Stack *S=(Stack*)malloc(sizeof(Stack));/*分配空间*/
	assert(S!=NULL);
    S->L=createList(size,NULL);/*创建链表属性*/
	S->top=S->L->nil->next;/*初始化栈顶*/
    return S;
}
void clrStack(Stack *S, void(*proc)(void*)){
	S->top=NULL;/*栈顶指针置空*/
	clrList(S->L,proc);/*清理链表空间*/
	free(S->L);
}
int stackEmpty(Stack* S){/*检测栈空*/
	return S->top==S->L->nil;
}
void push(Stack *S,void *k){/*压栈操作*/
    listPushFront(S->L,k);/*在链表尾插入*/
	S->top=S->L->nil->next;
}
ListNode *pop(Stack *S){/*弹出操作*/
    ListNode *x;
    assert(!stackEmpty(S));/*检测下溢*/
	x=S->top;/*x设置为栈顶*/
	S->top=x->next;/*设置新的栈顶*/
    listDelete(S->L,x);/*将栈顶从链表尾部摘除*/
    return x;
}
