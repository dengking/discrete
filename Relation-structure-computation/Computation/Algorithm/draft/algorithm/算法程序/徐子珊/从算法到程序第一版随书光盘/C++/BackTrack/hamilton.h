/* 
 * File:   hamilton.h
 * Author: 徐子珊
 *
 * Created on 2008年11月21日, 下午3:43
 */

#ifndef _HAMILTON_H
#define	_HAMILTON_H
#include "../DataStructure/problem.h"
class Hamilton:public CombineProblem<int,int>{
private:
    int start;
public:
    Hamilton(int *a,int n,int start){
        this->a=a;
        this->n=n;
        this->start=start-1;
        x=new int[n];
        flag=false;
    }
    bool isComplete(int k){
        if(k>=n)
            return a[x[k-1]*n+x[0]]!=0;
        return false;
    }
    bool isPartial(int k){
        for(int i=0;i<k;i++)
            if(x[i]==x[k])
                return false;
        return true;
    }
    vector<int> makeIterms(int k){
        vector<int> iterms;
        if(k==0){
            iterms.push_back(start);
        }else{
            for(int i=0;i<n;i++)
                if(a[x[k-1]*n+i]==1)
                    iterms.push_back(i);
        }
        return iterms;
    }
    void printSolution(int k){
        cout<<x[0]+1;
        for(int i=1;i<n;i++)
            cout<<"->"<<x[i]+1;
        cout<<"->"<<x[0]+1<<endl;
    }
};
#endif	/* _HAMILTON_H */

