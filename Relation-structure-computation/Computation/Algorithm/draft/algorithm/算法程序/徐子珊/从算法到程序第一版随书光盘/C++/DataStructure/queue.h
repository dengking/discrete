/* 
 * File:   queue.h
 * Author: 徐子珊
 * Created on 2008年10月3日 下午8:13
 */

#ifndef _QUEUE_H
#define	_QUEUE_H
#include<assert.h>
#include<vector>
using namespace std;
template<typename T, typename C >
class DynamicPriorityQueue{
private:
    vector<T> heap;
    int size;
public:
    DynamicPriorityQueue():size(0){}
    void enQueue(T e){
        size++;
        heap.push_back(e);
        push_heap(heap.begin(),heap.end(),C());
    }
    T deQueue(){
        assert(size>=1);
        pop_heap(heap.begin(),heap.end(),C());
        size--;
        T r=heap[size];
        heap.erase(heap.end()-1);
        return r;
    }
    void fix(){
        make_heap(heap.begin(),heap.end(),C());
    }
    bool empty(){
        if(size>0)
            return false;
        return true;
    }
};
template<typename T, typename C >
class PrioQueue{
private:
    vector<T> heap;
    int heapSize;
public:
    PrioQueue():heapSize(0){}
    void enQueue(T e){
        heapSize++;
        heap.push_back(e);
        push_heap(heap.begin(),heap.end(),C());
    }
    T deQueue(){
        assert(heapSize>=1);
        pop_heap(heap.begin(),heap.end(),C());
        heapSize--;
        T r=heap[heapSize];
        heap.erase(heap.end()-1);
        return r;
    }
    void fix(){
        make_heap(heap.begin(),heap.end(),C());
    }
    bool empty(){
        if(heapSize>0)
            return false;
        return true;
    }
};
#endif	/* _QUEUE_H */

