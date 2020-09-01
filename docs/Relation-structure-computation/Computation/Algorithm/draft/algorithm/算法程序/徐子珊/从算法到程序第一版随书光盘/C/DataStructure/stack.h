/* 
 * File:   stack.h
 * Author: 徐子珊
 *
 * Created on 2008年12月18日, 上午10:30
 */
#ifndef _STACK_H
#define	_STACK_H
#include "bilist.h"
struct stack{
    List *head;
};
typedef struct stack stack;
stack *createStack(){
    stack *s=(stack*)malloc(sizeof(stack));
    s->head=NULL;
    return s;
}
int isEmpty(stack *S){
    return S->head==NULL;
}
void push(stack *S, void *e){
    listPushBegin(&(S->head),e);
}
void *top(stack *S){
    if(!isEmpty(S))
        return S->head->data;
    return NULL;
}
void *pop(stack *S){
    void *r=NULL;
    if(!isEmpty(S))
        r=listDeleteBeging(&(S->head));
    return r;
}
#endif	/* _STACK_H */
