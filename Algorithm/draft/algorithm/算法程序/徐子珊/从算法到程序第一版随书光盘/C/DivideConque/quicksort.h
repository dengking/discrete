/* 
 * File:   quiksort.h
 * Author: 徐子珊
 *
 * Created on 2008年10月22日, 上午9:14
 */

#ifndef _QUIKSORT_H
#define	_QUIKSORT_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "../Utility/partition.h"
void quickSort(void* a,int size,long p,long r,int(*comp)(void *,void *)){
    if(p<r){
        long q=randmizedPartition(a,size,p,r,comp);
        quickSort(a,size,p,q,comp);
        quickSort(a,size,q+1,r,comp);
    }
}
#ifdef	__cplusplus
}
#endif
#endif	/* _QUIKSORT_H */

