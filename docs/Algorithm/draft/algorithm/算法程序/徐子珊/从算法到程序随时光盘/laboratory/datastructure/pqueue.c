#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include "../utility/heap.h"
#include "../utility/swap.h"
#include "./pqueue.h"
PQueue *initPQueue(int size,int n,int(*comp)(void const *,void const *)){
    PQueue *q=(PQueue*)malloc(sizeof(PQueue));
	assert(q);
    q->length=n;/*设置堆的最大长度*/
    q->heapSize=0;/*目前队空*/
	q->eleSize=size;/*设置元素存储宽度*/
    q->heap=(void *)malloc(n*size);/*分配堆空间*/
	q->compare=comp;/*设置元素比较规则*/
    return q;
}
void pQueueClr(PQueue *q){/**/
    free(q->heap);
	q->heap=q->compare=NULL;
	q->heapSize=q->length=q->eleSize=0;
}
int empty(PQueue *q){
    return q->heapSize<1;
}
void enQueue(PQueue *q,void *e){
	int i,heapSize=q->heapSize,length=q->length,eleSize=q->eleSize;
	int(*comp)(void*,void*)=q->compare;
	void* heap=q->heap;
    if(heapSize==length)/*队列满*/
        return;
    i=heapSize++;/*i为扩大后的堆的最后元素的下标*/
	q->heapSize++;
	memcpy((char*)heap+i*eleSize,(char*)e,eleSize);/*heap[i]←e*/
	while (i>0&&comp((char*)heap+parent(i)*eleSize,(char*)heap+i*eleSize)<0){
		swap((char*)heap+i*eleSize,(char*)heap+parent(i)*eleSize,eleSize);
        i=parent(i);
    }
}
void *top(PQueue *q){
	void *x;
	assert(!empty(q));
	assert(x=malloc(q->eleSize));
	memcpy(x, q->heap,q->eleSize);
	return x;
}
void * deQueue(PQueue *q){
	int heapSize=q->heapSize,length=q->length,eleSize=q->eleSize;
	int(*comp)(void const *,void const *)=q->compare;
	void* heap=q->heap, *top;
	assert(!empty(q));
	assert(top=(void*)malloc(eleSize));
	memcpy(top,heap,eleSize);/*top←heap[0]*/
 	heapSize--;q->heapSize--;
	memcpy((char*)heap,(char*)heap+heapSize*eleSize,eleSize);
	heapify(heap,eleSize, 0, heapSize, comp);
    return top;
}
void fix(PQueue *q){
	buildHeap(q->heap,q->eleSize,q->heapSize,q->compare);
}