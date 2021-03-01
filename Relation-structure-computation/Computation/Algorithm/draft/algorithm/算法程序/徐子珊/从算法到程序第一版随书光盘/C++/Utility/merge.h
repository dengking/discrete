/* 
 * File:   merge.h
 * Author: ?����???
 *
 * Created on 2008��10��15��, ����7:24
 */

#ifndef _MERGE_H
#define	_MERGE_H
int count1;
#include<algorithm>
#include<iterator>
using namespace std;
template<typename Iterator >
void merge(Iterator p, Iterator q, Iterator r){
    typedef typename iterator_traits<Iterator>::value_type T;
    long i,j,
        n1=distance(p,q),//[p..q)的长度
        n2=distance(q,r);//[q..r)的长度
    T *L=new T[n1],*R=new T[n2];//分配左、右临时数组L，R的空间
    copy(p,q,L);
    copy(q,r,R);
    Iterator k=p;
    i=j=0;
    while(i<n1&&j<n2){
        if(L[i]<R[j])
            *k=L[i++];
        else{
            if(L[i]>R[j])
                count1=count1+n1-i;
            *k=R[j++];
        }
        k++;
    }
    if(i<n1)
        copy(L+i,L+n1,k);
    if(j<n2)
        copy(R+j,R+n2,k);
}
template<typename Iterator,typename Comparator>
void merge(Iterator p, Iterator q, Iterator r){
    typedef typename iterator_traits<Iterator>::value_type T;
    long i,j,
        n1=distance(p,q),//[p..q)的长度
        n2=distance(q,r);//[q..r)的长度
     T *L=new T[n1],
       *R=new T[n2];//分配左、右临时数组L，R的空间
    copy(p,q,L);
    copy(q,r,R);
    Iterator k=p;
    i=j=0;
    while(i<n1&&j<n2){
        if(Comparator()(L[i],R[j]))
            *k=L[i++];
        else
            *k=R[j++];
        k++;
    }
    if(i<n1)
        copy(L+i,L+n1,k);
    if(j<n2)
        copy(R+j,R+n2,k);
    delete []L;
    delete []R;
}
#endif	/* _MERGE_H */

