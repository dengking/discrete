/* 
 * File:   queue.h
 * Author: 徐子珊
 *
 * Created on 2010年8月30日, 下午8:43
 */

#ifndef _QUEUE_H
#define	_QUEUE_H
#include "list.h"
typedef struct{/*队列类型*/
    LinkedList *L;/*链表属性*/
    ListNode *head,*tail;/*队首、队尾属性*/
}Queue;
Queue* createQueue(unsigned long size);/*创建空队列*/
void clrQueue(Queue *Q, void(*proc)(void*));/*清理队列空间*/
int queueEmpty(Queue *Q);/*检测队列空*/
void enQueue(Queue *Q,void *k);/*入队操作*/
ListNode *deQueue(Queue *Q);/*出队操作*/
#endif	/* _QUEUE_H */

