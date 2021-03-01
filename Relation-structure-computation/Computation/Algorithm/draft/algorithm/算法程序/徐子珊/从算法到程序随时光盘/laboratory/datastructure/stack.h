/* 
 * File:   stack.h
 * Author: 徐子珊
 *
 * Created on 2010年8月30日, 下午5:01
 */
#ifndef _STACK_H
#define	_STACK_H
#include "list.h"
typedef struct{/*栈类型*/
    LinkedList *L;/*链表属性*/
    ListNode *top;/*栈顶属性*/
}Stack;
Stack* createStack(unsigned long size);/*创建空栈*/
void clrStack(Stack *S, void(*proc)(void*));
int stackEmpty(Stack* S);/*检测栈空*/
void push(Stack *S,void *k);/*压栈操作*/
ListNode *pop(Stack *S);/*弹出操作*/
#endif	/* _STACK_H */
