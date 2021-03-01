/* 
 * File:   nqueens.h
 * Author: 徐子珊
 *
 * Created on 2008年11月16日, 下午4:48
 */

#ifndef _NQUEENS_H
#define	_NQUEENS_H
#include "../DataStructure/problem.h"
int isPartial3(SpacialProblem *p,int k){
    int i,*a=p->a,*x=p->x,difference;
    for(i=0;i<k;i++){
        difference=x[i]-x[k];
        if((difference==0)||difference==i-k||difference==k-i)
            return 0;
    }
    return 1;
}
int isComplete3(SpacialProblem *p,int k){
    return k>=p->n;
}
//List* makeIterms3(SpacialProblem *p, int k){
//    List *iterms=NULL;
//    int i;
//    for(i=0;i<p->n;i++){
//        int *e=(int*)malloc(sizeof(int));
//        *e=p->n-i;
//        listPushBegin(&iterms,e);
//    }
//    return iterms;
//}
void printSolution3(SpacialProblem *p,int k){
    int i,j,*x=p->x,n=p->n;
    for(i=0;i<n;i++){
        printf("%d: ",x[i]);
        for(j=0;j<x[i]-1;j++)
            printf("-");
        printf("Q");
        for(j++;j<n;j++)
            printf("-");
    printf("\n");
    }
    printf("\n");
}
SpacialProblem *createNQueens(int n){
    int i;
    SpacialProblem *p=(SpacialProblem*)malloc(sizeof(SpacialProblem));
    p->a=NULL;
    p->n=n;
    p->asize=0;
    p->flag=0;
    p->x=(int*)malloc(n*sizeof(n));
    p->isComplete=isComplete3;
    p->isPartial=isPartial3;
    p->printSolution=printSolution3;
    for(i=0;i<n;i++)
        p->x[i]=i+1;
    return p;
}
#endif	/* _NQUEENS_H */

