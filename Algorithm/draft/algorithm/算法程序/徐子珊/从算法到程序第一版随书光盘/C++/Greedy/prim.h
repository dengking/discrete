/* 
 * File:   prime.h
 * Author: 徐子珊
 *
 * Created on 2008年9月25日, 下午11:05
 */

#ifndef _PRIM_H
#define	_PRIM_H
#include "../DataStructure/queue.h"
#include "../Utility/compare.h"
#include<limits>
#include<algorithm>
#include<iostream>
using namespace std;
pair<double*,int*> mstPrime(double *w,int n,int r){//prim算法实现
    int i;
    pair<double*,int*> result;
    double *key=new double[n];
    int *pi=new int[n];
    bool *poped=new bool[n];
    fill(key,key+n,numeric_limits<float>::infinity());
    fill(pi,pi+n,-1);
    fill(poped,poped+n,false);
    key[r]=0.0;
    PrioQueue<double*,Greater<double> > Q;//最小优先队列
    for(i=0;i<n;i++)
        Q.enQueue(&key[i]);//初始化优先队列
    while(!Q.empty()){
        int u=Q.deQueue()-key;//计算队首顶点的编号
        poped[u]=true;//置顶点u的出队标志为true
        for(int v=0;v<n;v++){//对与u相邻的顶点逐一考察
            if(!poped[v])//若v在队列Q
                if(w[u*n+v]!=0.0)
                    if(w[u*n+v]<key[v]){//w(u,v)<key[v]
                        pi[v]=u;
                        key[v]=w[u*n+v];
                    }
        }
        Q.fix();
    }
    result=make_pair(key,pi);
    return result;
}
#endif	/* _PRIM_H */

