/* 
 * File:   partition.h
 * Author: 徐子珊
 *
 * Created on 2008年10月17日, 上午11:01
 */

#ifndef _PARTITION_H
#define	_PARTITION_H
#include<stdlib.h>
#include "swap.h"
long randomNumber(long p,long q){
    return p+(long)((double)(q-p)*rand()/(RAND_MAX));
}
long partition(void *a,int size,long p,long r,int(*comp)(void *,void *)){//对数组a的子数组a[p..r]进行划分，返回划分界限位置
    long i,j;
    void *x=(void*)malloc(size);
    memcpy(x,a+r*size,size);//x为主元素a[r]的值
    i=p-1;//[p..i]为不超过x的元素
    for(j=p;j<r;j++)//[i+1..j)为超过x的元素，[j..r-1)为尚未处理的元素
        if(comp(a+j*size,x)<=0){
            i++;
            swap(a+i*size,a+j*size,size);
        }
    free(x);
    swap(a+(i+1)*size,a+r*size,size);
    return i+1;
}
//long partition(void *a,int size,long p,long r,int(*comp)(void *,void *)){//对数组a的子数组a[p..r]进行划分，返回划分界限位置
//    long i=p+1,j=r;
//    void *x=(void*)malloc(size);
//    memcpy(x,a+p*size,size);//x为主元素a[p]的值
//    while(1){
//        while(comp(a+i*size,x)<=0&&i<r)i++;
//        while(comp(a+j*size,x)>0&&j>p)j--;
//        if(i<j){
//            swap(a+i*size,a+j*size,size);
//            i++;j--;
//        }else{
//            swap(a+p*size,a+j*size,size);
//            return j;
//        }
//    }
//}
long randmizedPartition(void *a,int size,long p,long r,int(*comp)(void *,void *)){
    long i=randomNumber(p,r);
    swap(a+p*size,a+i*size,size);
    return partition(a,size,p,r,comp);
}
#endif	/* _PARTITION_H */

