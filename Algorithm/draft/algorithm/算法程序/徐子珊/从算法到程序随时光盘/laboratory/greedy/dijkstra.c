#include<float.h>
#include <stdio.h>
#include <stdlib.h>
#include "../DataStructure/pqueue.h"
#include "../DataStructure/pair.h"
#include "../Utility/compare.h"
pair dijkstra(double *w, int n, int s){
    int *pi=(int*)malloc(n*sizeof(int)),
       *poped=(int*)malloc(n*sizeof(int)),i,u,v;
    double *d=(double*)malloc(n*sizeof(double));
    PQueue *Q=initPQueue(sizeof(double*),n,dblLess);
    for(i=0;i<n;i++){
        pi[i]=-1;
        poped[i]=0;
        d[i]=DBL_MAX;
    }
    d[s]=0.0;
    for(i=0;i<n;i++){
        double *e;
        e=&d[i];
        enQueue(Q,&e);
    }
    while(!empty(Q)){
        u=(*(double**)deQueue(Q))-d;
        poped[u]=1;
        for(v=0;v<n;v++){
            if(!poped[v])
                if(w[u*n+v]>0.0)
                    if(d[v]>d[u] + w[u*n+v]){
                        d[v]=d[u] + w[u*n+v];
                        pi[v]=u;
                    }
        }
        fix(Q);
    }
    pQueueClr(Q);
    return make_pair(d, pi);
}
void printPath(int *pi,int s, int i){
    if(i==s){
        printf("%d ",i+1);
        return;
    }
    if(pi[i]==-1)
 	printf("no path from %d to %d\n", s+1,i+1);
    else{
    	printPath(pi,s,pi[i]);
        printf("%d ",i+1);
    }
}
