/* 
 * File:   prime.h
 * Author: 徐子珊
 *
 * Created on 2008年9月25日, 下午11:05
 */

#ifndef _PRIM_H
#define	_PRIM_H
#include "../DataStructure/queue.h"
#include "../DataStructure/pair.h"
#include "../Utility/compare.h"
#include "../Utility/arrayCpy.h"
#include<float.h>
#define dblInfy DBL_MAX
#define NIL -1
pair mstPrim(double *w,int n,int r){//prim算法实现
    pair result;
    int *pi=(int*)malloc(n*sizeof(int)),//顶点的父节点指针属性初始化为-1
        *poped=(int*)malloc(n*sizeof(int)),//顶点是否出队标志属性初始化为false
         i,u=NIL,v=0;
    double *key=(double*)malloc(n*sizeof(double)),infy=dblInfy;//顶点的key属性初始化为∞
    arrayFill(key,sizeof(double),&infy,n);
    arrayFill(pi,sizeof(int),&u,n);
    arrayFill(poped,sizeof(int),&v,n);
    key[r]=0.0;
    priorityQueue Q=heapAlloc(sizeof(double*),n);
    for(i=0;i<n;i++){
        double **address=(double**)malloc(sizeof(double*));
        *address=&key[i];
        enQueue(&Q,sizeof(double*),address,dblLess);//创建优先队列
    }
    while(!empty(Q)){
        u=(*(double**)deQueue(&Q,sizeof(double*),dblLess))-key;//计算队首顶点的编号
        poped[u]=1;//置顶点u的出队标志为true
        for(v=0;v<n;v++){//对与u相邻的顶点逐一考察
            if(w[u*n+v]>0.0)
                if(!poped[v])
                    if(w[u*n+v]<key[v]){//若v在队列Q中且w(u,v)<key[v]
                        pi[v]=u;
                        key[v]=w[u*n+v];
                    }
        }
        fix(&Q,sizeof(double*),dblLess);
    }
    pqueueClear(&Q);
    result.first=key;
    result.second=pi;
    return result;
}
#endif	/* _PRIM_H */

