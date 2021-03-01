/* 
 * File:   heapsort.h
 * Author: ?����???
 *
 * Created on 2008��10��23��, ����10:16
 */

#ifndef _HEAPSORT_H
#define	_HEAPSORT_H
#include "../Utility/heap.h"
void heapSort(void* a, int size, int n,int(*comp)(void *,void *)){
    int i,heapSize=n,j;
    buildHeap(a,size,n,comp);
    for(i=n-1;i>0;i--){
        swap(a+i*size,a,size);
        heapSize--;
        heapify(a,size,0,heapSize,comp);
//        for(j=0;j<10;j++)
//            printf("%d ",*(int *)(a+j*size));
//        printf("\n");
    }
}
#endif	/* _HEAPSORT_H */

