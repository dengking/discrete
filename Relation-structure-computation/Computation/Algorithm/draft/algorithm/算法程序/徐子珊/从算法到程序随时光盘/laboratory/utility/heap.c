#include "heap.h"
#include "swap.h"
int left(int i){
    return 2*i+1;
}
int right(int i){
    return 2*i+2;
}
int parent(int i){
	return (i-1)/2;
}
//void heapify(void *a,int size,int i,int heapSize,int(*comp)(void const *,void const *)){
//    int l=left(i),r=right(i),most;
//    if(l<heapSize&&comp((char*)a+l*size,(char*)a+i*size)>0)
//        most=l;
//    else
//        most=i;
//    if(r<heapSize&&comp((char*)a+r*size,(char*)a+most*size)>0)
//        most=r;
//    if(most!=i){
//        swap((char*)a+i*size,(char*)a+most*size,size);
//        heapify(a,size,most,heapSize,comp);
//    }
//}
void heapify(void *a,int size,int i,int heapSize,int(*comp)(void const *,void const *)){
    int l=left(i),r=right(i),most;
    if(l<heapSize&&comp((char*)a+l*size,(char*)a+i*size)>0)
        most=l;
    else
        most=i;
    if(r<heapSize&&comp((char*)a+r*size,(char*)a+most*size)>0)
        most=r;
    while(most!=i){
        swap((char*)a+i*size,(char*)a+most*size,size);
		i=most;
		l=left(i),r=right(i);
		if(l<heapSize&&comp((char*)a+l*size,(char*)a+i*size)>0)
			most=l;
		else
			most=i;
		if(r<heapSize&&comp((char*)a+r*size,(char*)a+most*size)>0)
			most=r;
    }
}
void buildHeap(void *a,int size, int length, int(*comp)(void const *,void const *)){
    int i;
    for(i=(length/2)-1;i>=0;i--)
        heapify(a,size,i,length,comp);
}
