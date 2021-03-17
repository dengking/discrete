/* 
 * File:   queue.h
 * Author: ����ɺ
 *
 * Created on 2010��8��30��, ����8:43
 */

#ifndef _QUEUE_H
#define	_QUEUE_H
#include "list.h"
typedef struct{/*��������*/
    LinkedList *L;/*��������*/
    ListNode *head,*tail;/*���ס���β����*/
}Queue;
Queue* createQueue(unsigned long size);/*�����ն���*/
void clrQueue(Queue *Q, void(*proc)(void*));/*������пռ�*/
int queueEmpty(Queue *Q);/*�����п�*/
void enQueue(Queue *Q,void *k);/*��Ӳ���*/
ListNode *deQueue(Queue *Q);/*���Ӳ���*/
#endif	/* _QUEUE_H */

