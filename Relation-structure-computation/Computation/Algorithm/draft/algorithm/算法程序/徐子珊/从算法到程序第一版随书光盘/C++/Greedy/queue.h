/* 
 * File:   queue.h
 * Author: 徐子珊
 *
 * Created on 2008年9月23日, 下午8:13
 */

#ifndef _QUEUE_H
#define	_QUEUE_H
#include<assert.h>
#include<iostream>
#include<iterator>
#include<algorithm>
#include<vector>
using namespace std;
//template<typename T=int, typename C=less<T> >
//class DynamicPriorityQueue{
//private:
//    vector<T> heap;
//    int size;
//public:
//    DynamicPriorityQueue():size(0){}
//    void enQueue(T e){
//        size++;
//        heap.push_back(e);
//        push_heap(heap.begin(),heap.end(),C());
//    }
//    T deQueue(){
//        assert(size>=1);
//        pop_heap(heap.begin(),heap.end(),C());
//        size--;
//        T r=heap[size];
//        heap.erase(heap.end()-1);
//        return r;
//    }
//    void fix(){
//        make_heap(heap.begin(),heap.end(),C());
//    }
//    bool empty(){
//        if(size>0)
//            return false;
//        return true;
//    }
//};
#include<assert.h>
#include<stdlib.h>
struct DynamicPriorityQueue{
    int heap_cpacity;
    int heap_size;
    void **heap;
};
struct DynamicPriorityQueue heapAlloc(int n){
    struct DynamicPriorityQueue q;
    q.heap_cpacity=n;
    q.heap_size=0;
    q.heap=(void **)malloc(5*sizeof(void *));
    return q;
}
static int left(int i){
    return 2*i+1;
}
static int right(int i){
    return 2*i+2;
}
static int parent(int i){
    if(i%2)
        return (i-1)/2;
    return (i-2)/2;
}
static void heapify(struct DynamicPriorityQueue *q,int i,int(*compare)(void *,void *)){
    int l=left(i),r=right(i),most;
    if(l<q->heap_size&&compare(q->heap[l],q->heap[i])>0)
        most=l;
    else
        most=i;
    if(r<q->heap_size&&compare(q->heap[r],q->heap[most])>0)
        most=r;
    if(most!=i){
        {void *temp=q->heap[i];
        q->heap[i]=q->heap[most];
        q->heap[most]=temp;}//交换a[i]，a[largest]
        heapify(q,most,compare);
    }
}
void enQueue(struct DynamicPriorityQueue *q,void *e,int(*compare)(void *,void *)){
    if(q->heap_size==q->heap_cpacity)
        return;
    int i=q->heap_size++;
    q->heap[i]=e;
    while (i>0&&compare(q->heap[parent(i)],q->heap[i])<0){
        void *temp=q->heap[parent(i)];
        q->heap[parent(i)]=q->heap[i];
        q->heap[i]=temp;
        i=parent(i);
    }
}
void * deQueue(struct DynamicPriorityQueue *q,int(*compare)(void *,void *)){
    assert(q->heap_size>=1);
    void *top=q->heap[0];
    q->heap[0]=q->heap[--q->heap_size];
    heapify(q,0,compare);
    return top;
}
void fix(struct DynamicPriorityQueue *q,int(*compare)(void *,void *)){
    for(int i=q->heap_size/2;i>=0;i--)
        heapify(q,i,compare);
}
int empty(struct DynamicPriorityQueue q){
    if(q.heap_size<1)
        return 1;
    return 0;
}

#endif	/* _QUEUE_H */

