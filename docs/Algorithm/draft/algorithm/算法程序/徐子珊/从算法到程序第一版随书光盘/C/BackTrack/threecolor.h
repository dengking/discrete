/* 
 * File:   threecolor.h
 * Author: 徐子珊
 *
 * Created on 2008年11月14日, 上午11:01
 */

#ifndef _THREECOLOR_H
#define	_THREECOLOR_H
#include "../DataStructure/problem.h"
int m;
int isPartial(int *a,int *c,int n,int k){
    int i;
    for(i=0;i<k;i++)
        if((a[i*n+k]==1)&&(c[i]==c[k]))
            return 0;
    return 1;
}
void printSolution(int *c,int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d ",c[i]);
    printf("\n");
}
int graphColor(int *a,int *c,int n,int k){
    static int flag=0;
    int color;
    if(k>=n){
        flag=1;
        printSolution(c,n);
        return flag;
    }
    for(color=1;color<=3;color++){
        c[k]=color;
        if(isPartial(a,c,n,k))
            graphColor(a,c,n,k+1);
    }
    return flag;
}
int threeColor(int *a, int n){
    int i;
    int *c=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        c[i]=0;
    if(!graphColor(a,c,n,0))
        printf("no sulution!\n");
}
int isPartial2(CombineProblem *p,int k){
    int i,*a=p->a,*x=p->x,n=p->n;
    for(i=0;i<k;i++)
        if((a[i*n+k]==1)&&(x[i]==x[k]))
            return 0;
    return 1;
}
int isComplete2(CombineProblem *p,int k){
    return k>=p->n;
}
void printSolution2(CombineProblem *p,int k){
    int i,*x=p->x,n=p->n;
    for(i=0;i<n;i++)
        printf("%d ",x[i]);
    printf("\n");
}
List *makeIterms2(CombineProblem *p,int k){
    List *iterms=NULL;
    int i;
    for(i=0;i<m;i++){
        int *e=(int*)malloc(sizeof(int));
        *e=m-i;
        listPushBegin(&iterms,e);
    }
    return iterms;
}
CombineProblem *createMColor(int *a,int n,int m1){
    CombineProblem *p=(CombineProblem*)malloc(sizeof(CombineProblem));
    p->a=a;
    p->n=n;
    p->flag=0;
    p->x=(int*)malloc(n*sizeof(int));
    m=m1;
    p->asize=sizeof(int);
    p->xsize=sizeof(int);
    p->isComplete=isComplete2;
    p->isPartial=isPartial2;
    p->makeIterms=makeIterms2;
    p->printSolution=printSolution2;
    return p;
}
#endif	/* _THREECOLOR_H */

