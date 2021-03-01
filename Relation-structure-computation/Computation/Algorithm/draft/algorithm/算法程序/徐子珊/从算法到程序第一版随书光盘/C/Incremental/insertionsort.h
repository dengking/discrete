/* 
 * File:   insertionsort.h
 * Author: 徐子珊
 *
 * Created on 2008年10月9日, 下午3:10
 */

#ifndef _INSERTIONSORT_H
#define	_INSERTIONSORT_H
#include<stdlib.h>
#include "../DataStructure/bilist.h"
#include "../Utility/arrayCpy.h"
void insertionSort(void *a, int n,int size,int(*comp)(void *,void *)){
    int i,j;
    void *key=(void *)malloc(size);
    for(j=1;j<n;j++){
        assign(key,0,a,j,size);
        i=j-1;
        while((i>=0)&&(comp(a+i*size,key)>0)){
            assign(a,i+1,a,i,size);
            i--;
        }
        assign(a,i+1,key,0,size);
    }
}
void listInsertionSort(struct Node *List,int size,int(*comp)(void *,void *)){
    struct Node *p,*q,*t;
    void* key=(void *)malloc(size);
    for(p=List->next;p!=NULL;p=p->next){
        memcpy(key,p->data,size);
        q=p->pre;
        t=p;
        while((q!=NULL)&&(comp(q->data,key)>0)){
            memcpy((q->next)->data,q->data,size);
            t=q;
            q=q->pre;
        }
        memcpy(t->data,key,size);
    }
}
#endif	/* _INSERTIONSORT_H */

