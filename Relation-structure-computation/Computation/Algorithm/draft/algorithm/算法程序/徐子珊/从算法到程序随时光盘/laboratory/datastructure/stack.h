/* 
 * File:   stack.h
 * Author: ����ɺ
 *
 * Created on 2010��8��30��, ����5:01
 */
#ifndef _STACK_H
#define	_STACK_H
#include "list.h"
typedef struct{/*ջ����*/
    LinkedList *L;/*��������*/
    ListNode *top;/*ջ������*/
}Stack;
Stack* createStack(unsigned long size);/*������ջ*/
void clrStack(Stack *S, void(*proc)(void*));
int stackEmpty(Stack* S);/*���ջ��*/
void push(Stack *S,void *k);/*ѹջ����*/
ListNode *pop(Stack *S);/*��������*/
#endif	/* _STACK_H */
