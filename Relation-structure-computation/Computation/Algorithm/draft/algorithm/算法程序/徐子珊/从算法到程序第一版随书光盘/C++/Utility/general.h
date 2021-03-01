/* 
 * File:   general.h
 * Author: 徐子珊
 *
 * Created on 2008年11月17日, 下午9:04
 */

#ifndef _GENERAL_H
#define	_GENERAL_H
#include<iostream>
using namespace std;
#include  "../DataStructure/problem.h"
template<typename T1,typename T2>
void explore(CombineProblem<T1,T2> *p,int k){
    int i,m;
    vector<T2> iterms;
    if(p->isComplete(k)){//完整合法解
        p->flag=true;
        p->printSolution(k);
        return ;//回溯
    }
    if(k>=p->n)//x[1..n]作为部分解合法，但不是完整合法解
        return;//回溯
    iterms=p->makeIterms(k);//生成第k个分量的取值集合
    m=iterms.size();//集合iterms的长度
    for(i=0;i<m;i++){
        p->x[k]=iterms[i];/*x[k]←iterms[i]*/
        if(p->isPartial(k))
            explore(p,k+1);//探索下一层
    }
}
template<typename T1,typename T2>
void backtrack(CombineProblem<T1,T2> *p){
    explore(p,0);
    if(!p->flag)
        cout<<"no sulution!"<<endl;
}
template<typename T>
void explore(SpacialProblem<T> *p,int k){
    int i;
    if(k>=p->n){
        if(p->isComplete(k)){
            p->flag=true;
            p->printSolution(k);
        }
        return ;//回溯
    }
    for(i=0;i<2;i++){
        p->x[k]=i;
        if(p->isPartial(k))
            explore<T>(p,k+1);//探索下一层
    }
}
template<typename T>
void backtrack(SpacialProblem<T> *p){
    explore<T>(p,0);
    if(!p->flag)
        cout<<"no sulution!"<<endl;
}
template<typename T>
void optExplore(OptSpecialProblem<T> *p,int k){
    int i;
    if(k>=p->n){
        if(p->isComplete(k)){
            p->flag=true;
            if(p->isOptimal(k)){
                p->most=p->currentValue;
                copy(p->current,p->current+p->n,p->x);
            }
        }
        return ;//回溯
    }
    double v=p->currentValue;
    for(i=k;i<p->n;i++){
        swap(p->current[i],p->current[k]);
        p->currentValue=p->objValue(v,k);
        if(p->isPartial(k))
            optExplore(p,k+1);
        swap(p->current[i],p->current[k]);
    }
    p->currentValue=v;
}
template<typename T>
void optBacktrack(OptSpecialProblem<T> *p){
    optExplore<T>(p,0);
    if(p->flag)
        p->printSolution(p->n);
    else
        cout<<"no sulution!"<<endl;
}
#endif	/* _GENERAL_H */
