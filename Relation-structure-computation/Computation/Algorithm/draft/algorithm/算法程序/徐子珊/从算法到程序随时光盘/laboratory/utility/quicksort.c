#include "quicksort.h"
void quickSort(void* a,int size,int p,int r,int(*comp)(void *,void *)){
    if(p<r){
        int q=randmizedPartition(a,size,p,r,comp);
        quickSort(a,size,p,q-1,comp);
        quickSort(a,size,q+1,r,comp);
    }
}
