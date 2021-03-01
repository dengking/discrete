/* 
 * File:   mergesort.h
 * Author: ?����???
 *
 * Created on 2008��10��21��, ����4:51
 */

#ifndef _MERGESORT_H
#define	_MERGESORT_H
#include "../Utility/merge.h"
template<typename Iterator>
void mergeSort(Iterator p,Iterator r){
    Iterator q;
    int n=distance(p,r);
    if(n>1){
        q=p;
        advance(q,n/2);
        mergeSort(p,q);
        mergeSort(q,r);
        merge(p,q,r);
    }
}
//template<typename Iterator,typename Comparator>
//void mergeSort(Iterator p,Iterator r){
//    Iterator q;
//    int n=distance(p,r);
//    if(n>1){
//        q=p;
//        advance(q,n/2);
//        mergeSort<Iterator,Comparator>(p,q);
//        mergeSort<Iterator,Comparator>(q,r);
//        inplace_merge(p,q,r,Comparator());
//    }
//}
#endif	/* _MERGESORT_H */

