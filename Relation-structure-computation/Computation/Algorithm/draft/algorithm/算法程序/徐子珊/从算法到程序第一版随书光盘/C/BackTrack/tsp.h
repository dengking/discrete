/* 
 * File:   tsp.h
 * Author: ?����???
 *
 * Created on 2008��11��24��, ����2:30
 */

#ifndef _TSP_H
#define	_TSP_H

#ifdef	__cplusplus
extern "C" {
#endif
#include<float.h>
#include "../DataStructure/problem.h"
#include "../Utility/compare.h"
int start;
int isPartial5(OptimalProblem *p,int k){
    int i,*x=p->x,n=p->n;
    double *currentVal=p->currentVal,*optimalVal=p->optimalVal,*a=p->a;
    for(i=0;i<k;i++)
        if(x[i]==x[k])
            return 0;
    for(*currentVal=0.0,i=0;i<k;i++)
        *currentVal+=a[x[i]*n+x[i+1]];
    if(*currentVal>=*optimalVal)
        return 0;
    return 1;
}
int isOptimal5(OptimalProblem *p,int k){
    double *currentVal=p->currentVal,*optimalVal=p->optimalVal;
    return (*currentVal<*optimalVal);
}
int isComplete5(OptimalProblem *p,int k){
    int *x=p->x,n=p->n,i;
    double *a=p->a;
    if(k>=n)
        return a[x[k-1]*n+x[0]]!=0;
    return 0;
}
List* makeIterms5(OptimalProblem *p, int k){
    List *iterms=NULL;
    int i,*x=p->x,n=p->n;
    double *a=p->a;
    if(k==0){
        int *e=(int*)malloc(sizeof(int));
        *e=start;
        listPushBegin(&iterms,e);
    }else{
        for(i=n-1;i>=0;i--){
            if(a[x[k-1]*n+i]!=0.0){
                int *e=(int*)malloc(sizeof(int));
                *e=i;
                listPushBegin(&iterms,e);
            }
        }
    }
    return iterms;
}
void printSolution5(OptimalProblem *p,int k){
    int i,*x=p->optimalx,n=p->n;
    double *optimalVal=p->optimalVal,*a=p->a;
    printf("%d",x[0]+1);
    for(i=1;i<n;i++)
        printf("->%d",x[i]+1);
    printf("->%d weight: %1.1f\n",x[0]+1,*optimalVal+a[x[n-1]*n+x[0]]);
}
OptimalProblem *createTsp(double *a,int n,int s){
    OptimalProblem *p=(OptimalProblem*)malloc(sizeof(OptimalProblem));
    start=s-1;
    p->a=a;
    p->n=n;
    p->asize=p->vsize=sizeof(double);
    p->xsize=sizeof(int);
    p->flag=0;
    p->x=(int*)malloc(n*sizeof(n));
    p->optimalx=(int*)malloc(n*sizeof(n));
    p->optimalVal=(double*)malloc(sizeof(double));
    *(double*)(p->optimalVal)=DBL_MAX;
    p->currentVal=(double*)malloc(sizeof(double));
    p->vsize=sizeof(double);
    p->isOptimal=isOptimal5;
    p->isComplete=isComplete5;
    p->isPartial=isPartial5;
    p->makeIterms=makeIterms5;
    p->printSolution=printSolution5;
    return p;
}
#ifdef	__cplusplus
}
#endif

#endif	/* _TSP_H */

