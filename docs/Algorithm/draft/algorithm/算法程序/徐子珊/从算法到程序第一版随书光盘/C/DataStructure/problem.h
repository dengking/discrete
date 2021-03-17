/* 
 * File:   problem.h
 * Author: 徐子珊
 *
 * Created on 2008年11月18日, 下午6:49
 */

#ifndef _PROBLEM_H
#define	_PROBLEM_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "bilist.h"
struct CombineProblem{
    void *a;
    int n;
    int asize;
    int xsize;
    void *x;
    int flag;
    int (*isPartial)(void *p,int k);
    int (*isComplete)(void *p,int k);
    List* (*makeIterms)(void *p,int k);
    void (*printSolution)(void *p,int k);
};
typedef struct CombineProblem CombineProblem;
void comprobClear(CombineProblem *p){
    if(p->a!=NULL)
        p->a=NULL;
    if(p->x!=NULL){
        free(p->x);
        p->x=NULL;
    }
    p->isComplete=NULL;
    p->isPartial=NULL;
    p->makeIterms=NULL;
    p->printSolution=NULL;
}
struct SpacialProblem{
    void *a;
    int n;
    int asize;
    int *x;
    int flag;
    int (*isPartial)(void *p,int k);
    int (*isComplete)(void *p,int k);
    void (*printSolution)(void *p,int k);
};
typedef struct SpacialProblem SpacialProblem;
void spcprobClear(SpacialProblem *sp){
    if(sp->a!=NULL)
        sp->a=NULL;
    if(sp->x!=NULL){
        free(sp->x);
        sp->x=NULL;
    }
    sp->isComplete=NULL;
    sp->isPartial=NULL;
    sp->printSolution=NULL;
}
struct OptimalProblem{
    void *a;
    int asize;
    void *x;
    void *optimalx;
    int xsize;
    void *optimalVal;
    void *currentVal;
    int vsize;
    int n;
    int flag;
    int (*isPartial)(void *p,int k);
    int (*isComplete)(void *p,int k);
    List* (*makeIterms)(void *p,int k);
    int (*isOptimal)(void *p,int k);
    void (*printSolution)(void *p);
};
typedef struct OptimalProblem OptimalProblem;
void optprobClear(OptimalProblem *op){
    if(op->a!=NULL)
        op->a=NULL;
    if(op->currentVal!=NULL){
        free(op->currentVal);
        op->currentVal=NULL;
    }
    if(op->optimalVal!=NULL){
        free(op->optimalVal);
        op->optimalVal=NULL;
    }
    if(op->optimalx!=NULL){
        free(op->optimalx);
        op->optimalx=NULL;
    }
    if(op->x!=NULL){
        free(op->x);
        op->x=NULL;
    }
    op->isComplete=NULL;
    op->isOptimal=NULL;
    op->isPartial=NULL;
    op->makeIterms=NULL;
    op->printSolution=NULL;
}
#ifdef	__cplusplus
}
#endif
#endif	/* _PROBLEM_H */

