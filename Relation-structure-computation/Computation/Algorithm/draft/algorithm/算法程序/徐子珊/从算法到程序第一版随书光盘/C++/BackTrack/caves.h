/* 
 * File:   caves.h
 * Author: ?����???
 *
 * Created on 2009��1��17��, ����9:52
 */

#ifndef _CAVES_H
#define	_CAVES_H
#include <vector>
using namespace std;
//#include "../DataStructure/problem.h"
class tribe{
public:
    float *a;
    float *d;
    int n;
    float x;
    int count;
    int max;
    int current;
    int *pi;
    tribe(float *a, int n,float x){
        this->a=a;
        this->n=n;
        this->x=x;
        this->count=1;
        this->max=-1;
        this->current=0;
        this->pi=new int[n];
        this->d=new float[n];
        fill(pi,pi+n,-1);
        fill(d,d+n,0.0);
    }
    vector<int> makeIterms(){
        vector<int> iterms=vector<int>();
        int i;
        for(i=0;i<n;i++)
            if(a[n*current+i]!=0.0){
                pi[i]=current;
                iterms.push_back(i);
            }
        return iterms;
    }
    bool isComplete(){
        if(x-a[pi[current]*n+current]<=0)
            return true;
        return false;
    }
    bool isPartial(){
        if(x-a[pi[current]*n+current]>=0)
            return true;
        return false;
    }
    bool isMax(){
        return count>max;
    }
};
void caves(tribe *t,int k){
    int i,m;
    vector<int> iterms;
    if(t->isComplete()){
        if(t->isMax())
            t->max=t->count;
        t->count--;
        t->x=t->x+t->a[(t->pi[t->current])*(t->n)+t->current];
        return ;//回溯
    }
    if(t->current<0)
        return;
    iterms=t->makeIterms();//生成第k个分量的取值集合
    m=iterms.size();//集合iterms的长度
    for(i=0;i<m;i++){
        t->current=iterms[i];/*x[k]←iterms[i]*/
        t->d[t->current]=(t->d[t->pi[t->current]])+t->a[(t->pi[t->current])*(t->n)+t->current];
        if(t->isPartial()){
            t->count++;
            t->x=t->x-t->a[(t->pi[t->current])*(t->n)+(t->current)];
            caves(t,k+1);//探索下一层
        }else{
            if(t->isMax())
                t->max=t->count;
            t->count=k;
            t->x=t->d[t->pi[t->current]];
            return;
        }
    }
    t->x=t->x-t->a[(t->pi[t->current])*(t->n)+t->current];
}
#endif	/* _CAVES_H */

