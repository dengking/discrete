/* 
 * File:   subsetsum.h
 * Author: ?����???
 *
 * Created on 2008��11��20��, ����9:14
 */

#ifndef _SUBSETSUM_H
#define	_SUBSETSUM_H
#include  "../DataStructure/problem.h"
#include<iostream>
using namespace std;
class SubsetSum:public SpacialProblem<int>{
public:
    int c;
    SubsetSum(int *a,int n,int c){
        this->a=a;
        this->n=n;
        this->c=c;
        this->flag=false;
        this->x= new int[n];
    }
    bool isPartial(int k){
        int i,sum=0;
        for(i=0;i<k;i++)
            sum+=a[i]*x[i];
        return sum<=c;
    }
    bool isComplete(int k){
        int i,sum=0;
        for(i=0;i<k;i++)
            sum+=a[i]*x[i];
        return sum==c;
    }
    void printSolution(int k){
        int i;
        for(i=0;i<k;i++)
            if(x[i]!=0)
                cout<<a[i]<<" ";
        cout<<endl;
    }
};
#endif	/* _SUBSETSUM_H */

