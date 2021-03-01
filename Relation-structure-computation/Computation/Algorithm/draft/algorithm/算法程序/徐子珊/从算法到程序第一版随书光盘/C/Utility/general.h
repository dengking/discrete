/* 
 * File:   general.h
 * Author: 徐子珊
 *
 * Created on 2008年11月16日, 下午3:34
 */

#ifndef _GENERAL_H
#define	_GENERAL_H
#include<string.h>
#include "../DataStructure/problem.h"
#include "swap.h"
void backtrack(CombineProblem *p,void(*explore)(void *,int)){
    explore(p,0);
    if(!p->flag)
        printf("no sulution!\n");    
}
void generalExplore(CombineProblem *p,int k){
    int i;
    if(k>=p->n){
        if(p->isComplete(p,k)){
            p->flag=1;
            p->printSolution(p,k);
            return;
        }
        return;
    }
    List *iterms=p->makeIterms(p,k),*q=iterms;
    while(q!=NULL){
        memcpy(p->x+k*p->xsize,q->data,p->xsize);/*x[k]←iterms[i]*/
        if(p->isPartial(p,k))
            generalExplore(p,k+1);
        q=q->next;
    }
    listClear(iterms);
    free(iterms);
    iterms=NULL;
}
void subsetTreeExplore(SpacialProblem *p,int k){
    int i,one=1,zero=0;
    if(k>=p->n){
        if(p->isComplete(p,k)){
            p->flag=1;
            p->printSolution(p,k);
        }
        return;
    }
    for(i=0;i<2;i++){
        p->x[k]=i;
        if(p->isPartial(p,k))
            subsetTreeExplore(p,k+1);
    }
}
void subsetTreeBacktrack(SpacialProblem *p){
    subsetTreeExplore(p,0);
    if(!p->flag)
        printf("no sulution!\n");
}
void permuteTreeExplore(SpacialProblem *p,int k){
    int i;
    if(k>=p->n){
        if(p->isComplete(p,k)){
            p->flag=1;
            p->printSolution(p,k);
        }
        return;
    }
    for(i=k;i<p->n;i++){
        swap(p->x+i,p->x+k,sizeof(int));
        if(p->isPartial(p,k))
            permuteTreeExplore(p,k+1);
        swap(p->x+i,p->x+k,sizeof(int));
    }
}
void permuteTreeBacktrack(SpacialProblem *p){
    permuteTreeExplore(p,0);
    if(!p->flag)
        printf("no sulution!\n");
}
void optimopalBacktrack(OptimalProblem *p,void(*optimalExplore)(OptimalProblem *,int)){
    optimalExplore(p,0);
    if(p->flag)
        p->printSolution(p);
    else
        printf("no sulution!\n");    
}
void generalOptimalExplore(OptimalProblem *p,int k){
    int i;
    if(k>=p->n){
        if(p->isComplete(p,k)){
            p->flag=1;
            if(p->isOptimal(p,k)){
                memcpy(p->optimalVal,p->currentVal,p->vsize);
                memcpy(p->optimalx,p->x,p->n*p->xsize);
            }
        }
        return;
    }
    List *iterms=p->makeIterms(p,k),*q=iterms;
    while(q!=NULL){
        memcpy(p->x+k*p->xsize,q->data,p->xsize);/*x[k]←iterms[i]*/
        if(p->isPartial(p,k))
            generalOptimalExplore(p,k+1);
        q=q->next;
    }
    listClear(iterms);
    free(iterms);
    iterms=NULL;
}
#endif	/* _GENERAL_H */

