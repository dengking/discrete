/* 
 * File:   partition.h
 * Author: ?����???
 *
 * Created on 2008��10��17��, ����2:37
 */

#ifndef _PARTITION_H
#define	_PARTITION_H
#include<stdlib.h>
#include<iterator>
using namespace std;
template<typename Iterator>
Iterator partition(Iterator p,Iterator r){
    typedef typename iterator_traits<Iterator>::value_type T;
    Iterator i,j;
    T x;
    x=*--r;//x←a[r]
    for(i=j=p,i--;j!=r;j++)
        if(*j<=x){//a[j] ≤x
            i++;
            iter_swap(i,j);//a[i]↔a[j]
        }
	i++;//i+1
	iter_swap(i,r);//a[i+1]↔a[r]
    return i;
}
long randomNumber(long p,long q){
    return p+(long)((double)(q-p)*rand()/(RAND_MAX));
}
template <typename Iterator,typename Comparator>
Iterator randomizedPartition(Iterator p, Iterator r,Comparator comp){
    long n=distance(p,r),i;
    Iterator q=p;//q--;
    i=randomNumber(1,n-1);
    advance(q,i);
    iter_swap(q,p);
    return partition(p,r,bind2nd(comp, *p));
};
#endif	/* _PARTITION_H */

