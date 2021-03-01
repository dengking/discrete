#include <assert.h>
#include "list.h"
#include "queue.h"
Queue* createQueue(unsigned long size){
    Queue *Q=(Queue*)malloc(sizeof(Queue));
	assert(Q);
    Q->L=createList(size,NULL);/*������������*/
	Q->head=Q->L->nil->next;/*��ʼ������*/
	Q->tail=Q->L->nil->prev;/*��ʼ����β*/
    return Q;
}
void clrQueue(Queue *Q, void(*proc)(void*)){/*������пռ�*/
	Q->head=Q->tail=NULL;/*ջ��ָ���ÿ�*/
	clrList(Q->L,proc);/*��������ռ�*/
	free(Q->L);
}
int queueEmpty(Queue *Q){/*�����п�*/
    return listEmpty(Q->L);
}
void enQueue(Queue *Q,void *k){/*��Ӳ���*/
    listPushBack(Q->L,k);/*������Ϊ����*/
	if(Q->head==Q->L->nil)/*�����½ڵ�ǰ����Ϊ��*/
		Q->head=Q->L->nil->next;
	Q->tail=Q->L->nil->prev;
}
ListNode *deQueue(Queue *Q){/*���Ӳ���*/
    ListNode *x=Q->head;/*x��Ϊ����*/
    assert(!queueEmpty(Q));/*��ֹ����*/
	Q->head=x->next;/*�����µĶ���*/
    listDelete(Q->L,x);/*��ԭ���״Ӷ�����ժ��*/
    return x;
}
