/* 
 * File:   insertionsort.h
 * Author: 徐子珊
 *
 * Created on 2008年10月9日, 下午3:10
 */

#ifndef _INSERTIONSORT_H
#define	_INSERTIONSORT_H
#include<algorithm>
using namespace std;
template<typename Iterator>
void insertionSort(const Iterator &a, const Iterator &b){
    int i,j,n=distance(a,b);
    Iterator p,q,t;
    for(j=1,q=p=a,p++,t=p;j<n;j++,q=p,p++){//p跟踪a[j]
        i=j-1;
        while((i>=0)&&(*q>*p))
            q--,i--;
        q++;//q跟踪a[i+1]
        t++;//t跟踪a[j+1]
        rotate(q,p,t);
    }
}
//template<typename Iterator>
//void insertionSort(const Iterator &a, const Iterator &b){
//    typedef typename iterator_traits<Iterator>::value_type T;
//    int i,j,n=distance(a,b);
//    T key;
//    Iterator p,q,t;
//    for(j=1,q=p=a,p++,t=p;j<n;j++,q=p,p++,t=p){//p跟踪a[j]
//        key=*p;//key←a[j]
//        i=j-1;
//        while((i>=0)&&(*q>key)){
//            *t=*q;//a[i+1]←a[i]
//            i--,t--,q--;
//        }
//        *t=key;//a[i+1]←key
//    }
//}
template<typename Iterator,typename Comparator>
void insertionSort(const Iterator &a, const Iterator &b){
    int i,j,n=distance(a,b);
    Iterator p,q,t;
    for(j=1,q=p=a,p++,t=p;j<n;j++,q=p,p++){//p跟踪a[j]
        i=j-1;
        while((i>=0)&&Comparator()(*q,*p))
            q--,i--;
        q++;//q跟踪a[i+1]
        t++;//t跟踪a[j+1]
        rotate(q,p,t);
    }
}
#endif	/* _INSERTIONSORT_H */

