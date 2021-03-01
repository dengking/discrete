#include <assert.h>
#include "list.h"
#include "queue.h"
Queue* createQueue(unsigned long size){
    Queue *Q=(Queue*)malloc(sizeof(Queue));
	assert(Q);
    Q->L=createList(size,NULL);/*创建链表属性*/
	Q->head=Q->L->nil->next;/*初始化队首*/
	Q->tail=Q->L->nil->prev;/*初始化队尾*/
    return Q;
}
void clrQueue(Queue *Q, void(*proc)(void*)){/*清理队列空间*/
	Q->head=Q->tail=NULL;/*栈顶指针置空*/
	clrList(Q->L,proc);/*清理链表空间*/
	free(Q->L);
}
int queueEmpty(Queue *Q){/*检测队列空*/
    return listEmpty(Q->L);
}
void enQueue(Queue *Q,void *k){/*入队操作*/
    listPushBack(Q->L,k);/*在链表为插入*/
	if(Q->head==Q->L->nil)/*插入新节点前队列为空*/
		Q->head=Q->L->nil->next;
	Q->tail=Q->L->nil->prev;
}
ListNode *deQueue(Queue *Q){/*出队操作*/
    ListNode *x=Q->head;/*x置为队首*/
    assert(!queueEmpty(Q));/*防止下溢*/
	Q->head=x->next;/*设置新的队首*/
    listDelete(Q->L,x);/*将原队首从队列中摘下*/
    return x;
}
