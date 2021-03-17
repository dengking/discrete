/* 
 * File:   subsetsum.h
 * Author: 徐子珊
 *
 * Created on 2008年11约19日, 上午10:49
 */

#ifndef _SUBSETSUM_H
#define	_SUBSETSUM_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "../DataStructure/problem.h"
int c;
int isPartial1(SpacialProblem *p,int k){
    int i,*a=p->a,*x=p->x,sum=0;
    for(i=0;i<k;i++)
        sum+=a[i]*x[i];
    return sum<=c;
}
int isComplete1(SpacialProblem *p,int k){
    int i,*a=p->a,*x=p->x,sum=0;
    for(i=0;i<k;i++)
        sum+=a[i]*x[i];
    return sum==c;
}
void printSolution1(SpacialProblem *p,int k){
    int i,*a=p->a,*x=p->x;
    for(i=0;i<k;i++)
        if(x[i]==1)
        printf("%d ",a[i]);
    printf("\n");
}
//List *makeIterms1(CombineProblem *p,int k){
//    List *iterms=NULL;
//    int i;
//    for(i=0;i<2;i++){
//        int *e=(int*)malloc(sizeof(int));
//        *e=1-i;
//        listPushBegin(&iterms,e);
//    }
//    return iterms;
//}
SpacialProblem *createSubsetSum(void *a,int n, int c1){
    SpacialProblem *p=(SpacialProblem*)malloc(sizeof(SpacialProblem));
    c=c1;
    p->a=a;
    p->n=n;
    p->flag=0;
    p->x=(int*)malloc(n*sizeof(n));
    p->asize=sizeof(int);
    p->isComplete=isComplete1;
    p->isPartial=isPartial1;
    p->printSolution=printSolution1;
    return p;
}
#ifdef	__cplusplus
}
#endif
#endif	/* _SUBSETSUM_H */

