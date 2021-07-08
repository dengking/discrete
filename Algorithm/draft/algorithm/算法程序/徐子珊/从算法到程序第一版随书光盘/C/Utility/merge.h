/* 
 * File:   merge.h
 * Author: ?����???
 *
 * Created on 2008��10��15��, ����3:26
 */

#ifndef _MERGE_H
#define	_MERGE_H
#include "arrayCpy.h"
void merge(void *a, int size, int p, int q, int r,int(*comp)(void *,void *)){
    int i,j,k,
    n1=q-p+1, //[p..q]的长度
    n2=r-q; //[q+1..r]的长度
    void *L=(void*)malloc(n1*size); //分配左临时数组L的空间
    void *R=(void*)malloc(n2*size); //分配右临时数组R的空间
    arrayCopy(L,a+p*size,size,n1);
    arrayCopy(R,a+(q+1)*size,size,n2);
    i=j=0;
    k=p;
    while(i<n1&&j<n2)
        if(comp(L+i*size,R+j*size)<0)
            assign(a,k++,L,i++,size);
//            memcpy(a+(k++)*size,L+(i++)*size,size);
        else
            assign(a,k++,R,j++,size);
//            memcpy(a+(k++)*size,R+(j++)*size,size);
    if(i<n1)
        arrayCopy(a+k*size,L+i*size,size,(n1-i));
    if(j<n2)
        arrayCopy(a+k*size,R+j*size,size,(n2-j));
    free(L);L=NULL;
    free(R);R=NULL;
}
#endif	/* _MERGE_H */

