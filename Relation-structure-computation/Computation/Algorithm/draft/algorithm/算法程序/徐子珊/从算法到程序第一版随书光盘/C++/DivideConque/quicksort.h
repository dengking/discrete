/* 
 * File:   partitionsort.h
 * Author: ?����???
 *
 * Created on 2008��10��22��, ����2:43
 */
#include "../Utility/partition.h"
#ifndef _QUICKSORT_H
#define	_QUICKSORT_H
#include "../Utility/partition.h"
template<typename Iterator,typename Comparator>
void quickSort(Iterator p, Iterator r,Comparator comp){
    long n=distance(p,r);
    if(n>1){
        Iterator q=randomizedPartition(p,r,comp);
//        Iterator q=partition(p,r,bind2nd(comp, *t));
        copy(p,r, ostream_iterator<int>(cout, " "));
        cout<<endl;
        quickSort(p,q,comp);
        quickSort(q,r,comp);
    }
}
#endif	/* _QUICKSORT_H */

