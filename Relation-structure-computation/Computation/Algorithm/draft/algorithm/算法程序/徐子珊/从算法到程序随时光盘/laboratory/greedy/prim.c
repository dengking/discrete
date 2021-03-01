#include <stdlib.h>
#include "../DataStructure/pqueue.h"
#include "../DataStructure/pair.h"
#include "../Utility/compare.h"
#include<float.h>
pair mstPrim(double *w,int n,int r){
    int *pi=(int*)malloc(n*sizeof(int)),
       *poped=(int*)malloc(n*sizeof(int)),
         i,u,v;
    double *key=(double*)malloc(n*sizeof(double));
    PQueue *Q=initPQueue(sizeof(double*),n,dblLess);
    for(i=0;i<n;i++){
        key[i]=DBL_MAX;
        pi[i]=-1;
        poped[i]=0;
    }
    key[r]=0.0;
    for(i=0;i<n;i++){
        double *e;
        e=&key[i];
        enQueue(Q,&e);
    }
    while(!empty(Q)){
        u=(*(double**)deQueue(Q))-key;
        poped[u]=1;
        for(v=0;v<n;v++){
            if(w[u*n+v]>0.0)
                if(!poped[v])
                    if(w[u*n+v]<key[v]){
                        pi[v]=u;
                        key[v]=w[u*n+v];
                    }
        }
        fix(Q);
    }
    pQueueClr(Q);
    return make_pair(key, pi);
}
