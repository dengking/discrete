/* 
 * File:   mergesort.h
 * Author: ?����???
 *
 * Created on 2008��10��20��, ����9:49
 */

#ifndef _MERGESORT_H
#define	_MERGESORT_H
#include "../Utility/merge.h"
void mergeSort(void *a,int size,int p,int r,int(*comp)(void *,void *)){
    int q,i;
    if(p<r){
        q=(p+r)/2;
        mergeSort(a,size,p,q,comp);
        mergeSort(a,size,q+1,r,comp);
        merge(a,size,p,q,r,comp);
    }
}
#endif	/* _MERGESORT_H */

