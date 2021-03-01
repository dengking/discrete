/* 
 * File:   dijkstra.h
 * Author: 徐子珊
 *
 * Created on 2008年10月1日,下午8:40
 */

#ifndef _DIJKSTRA_H
#define	_DIJKSTRA_H
#include "../Utility/compare.h"
#include "../DataStructure/queue.h"
#include<limits>
#include<iostream>
using namespace std;
pair<double*,int*> dijkstra(double *w, int n, int s){
    pair<double*,int*> result;
    int *pi=new int[n],i,u,v;
    bool *poped=new bool[n];
    double *d=new double[n];
    for(i=0;i<n;i++){
        d[i]=numeric_limits<double>::infinity();
        pi[i]=-1;
        poped[i]=false;
    }
    d[s]=0.0;
    PrioQueue<double*,Greater<double> > Q;
    for(i=0;i<n;i++)
        Q.enQueue(&d[i]);
    while(!Q.empty()){
        u=Q.deQueue()-d;
        poped[u]=true;
        for(v=0;v<n;v++){
            if(!poped[v])
                if(w[u*n+v]>0)
                    if(d[v]>d[u] + w[u*n+v]){
                        d[v]=d[u] + w[u*n+v];
                        pi[v]=u;
                    }
        }
        Q.fix();
    }
    result=make_pair(d,pi);
    return result;
}
void printPath(int *pi,int s,int i){
    if(i==s){
        cout<<i+1<<" ";
        return;
    }
    if(pi[i]==-1)
        cout<<"no path from "<<(s+1)<<" to "<<(i+1)<<endl;
    else{
        printPath(pi,s,pi[i]);
        cout<<i+1<<" ";
    }
}
#endif	/* _DIJKSTRA_H */

