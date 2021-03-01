/* 
 * File:   hamilton.h
 * Author: ?����???
 *
 * Created on 2008��11��21��, ����9:18
 */

#ifndef _HAMILTON_H
#define	_HAMILTON_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "../DataStructure/problem.h"
#include "../Utility/compare.h"
int start,count=0;
int isPartial4(CombineProblem *p,int k){
    int i,*a=p->a,*x=p->x;
    for(i=0;i<k;i++)
        if(x[i]==x[k])
            return 0;
    return 1;
}
int isComplete4(CombineProblem *p,int k){
    int *a=p->a,*x=p->x,n=p->n;
    if(k>=n)
        return a[x[k-1]*n+x[0]]!=0;
    return 0;
}
List* makeIterms4(CombineProblem *p, int k){
    List *iterms=NULL;
    int i,*a=p->a,*x=p->x,n=p->n;
    if(k==0){
        int *e=(int*)malloc(sizeof(int));
        *e=start;
        listPushBegin(&iterms,e);
    }else{
        for(i=n-1;i>=0;i--){
            if(a[x[k-1]*n+i]!=0){
                int *e=(int*)malloc(sizeof(int));
                *e=i;
                listPushBegin(&iterms,e);
            }
        }
    }
    return iterms;
}
void printSolution4(CombineProblem *p,int k){
    int i,*a=p->a,*x=p->x,n=p->n;
    printf("%d: ",++count);
    printf("%d",x[0]+1);
    for(i=1;i<n;i++)
        printf("->%d",x[i]+1);
    printf("->%d\n",x[0]+1);
}
CombineProblem *createHamilton(int *a,int n,int s){
    CombineProblem *p=(CombineProblem*)malloc(sizeof(CombineProblem));
    start=s-1;
    p->a=a;
    p->n=n;
    p->asize=sizeof(int);
    p->xsize=sizeof(int);
    p->flag=0;
    p->x=(int*)malloc(n*sizeof(n));
    p->isComplete=isComplete4;
    p->isPartial=isPartial4;
    p->makeIterms=makeIterms4;
    p->printSolution=printSolution4;
    return p;
}
#ifdef	__cplusplus
}
#endif

#endif	/* _HAMILTON_H */

