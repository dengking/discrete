/* 
 * File:   threecolor.h
 * Author: 徐子珊
 *
 * Created on 2008年11月15日, 下午6:52
 */

#ifndef _THREECOLOR_H
#define	_THREECOLOR_H
#include  "../DataStructure/problem.h"
#include<iostream>
using namespace std;
class MColor:public CombineProblem<int,int>{
public:
    int m;
    MColor(int *a,int n,int m){
        this->a=a;
        this->m=m;
        this->n=n;
        this->flag=false;
        this->x=new int[n];
    }
    bool isPartial(int k){
        int i;
        for(i=0;i<k;i++)
            if((a[i*n+k]==1)&&(x[i]==x[k]))
                return false;
        return true;
    }
    bool isComplete(int k){
        return k>=n;
    }
    void printSolution(int k){
        int i;
        for(i=0;i<n;i++)
            cout<<x[i]<<" ";
        cout<<endl;
    }
    vector<int> makeIterms(int k){
        vector<int> iterms;
        int i;
        for(i=0;i<m;i++)
            iterms.push_back(i+1);
        return iterms;
    }
};
#endif	/* _THREECOLOR_H */

