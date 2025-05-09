#include "partition.h"
#include "swap.h"
#include "randomn.h"
long partition(void *a,int size,int p,int r,int(*comp)(void *,void *)){
    int i,j;
    void *x=(void*)malloc(size);
    memcpy((char*)x,(char*)a+r*size,size);/*x←a[r]*/
    i=p-1;
    for(j=p;j<r;j++)
        if(comp((char*)a+j*size,(char*)x)<=0){/*a[j]≤x*/
            i++;
            swap((char*)a+i*size,(char*)a+j*size,size);/*a[i]↔a[j]*/
        }
	 free(x);
     swap((char*)a+(i+1)*size,(char*)a+r*size,size);/* a[i+1]↔a[r]*/
     return i+1;
}
long randmizedPartition(void *a,int size,long p,long r,int(*comp)(void *,void *)){
    int i=randomNumber(p,r);
    swap((char*)a+r*size,(char*)a+i*size,size);/*a[r]↔a[i]*/
    return partition(a,size,p,r,comp);
}
