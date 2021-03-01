/* 
 * File:   tsp.h
 * Author: ?����???
 *
 * Created on 2008��12��2��, ����10:25
 */

#ifndef _TSP_H
#define	_TSP_H
#include<iostream>
#include<limits>
using namespace std;
#include "../DataStructure/problem.h"
class tsp:public OptSpecialProblem<double>{
public:
    tsp(double *a,int n){
        this->a=a;
        this->n=n;
        this->flag=false;
        this->most=numeric_limits<double>::infinity();
        this->x=new int[n];
        this->current=new int[n];
        for(int i=0;i<n;i++)
            current[i]=i;
        this->currentValue=0.0;
    }
    ~tsp(){
        if(this->a!=NULL)
            this->a=NULL;
        if(this->x!=NULL){
            delete [] this->x;
            this->x=NULL;
        }
        if(this->current!=NULL){
            delete [] this->current;
            this->current=NULL;
        }
    }
    double objValue(double v,int k){
        return v+a[current[k-1]*n+current[k]];
    }
    bool isComplete(int k){
        return a[current[n-1]*n+current[0]]!=0.0;
    }
    bool isPartial(int k){
        for(int i=0;i<k;i++)
            if(current[i]==current[k])
                return false;
        if(currentValue>=most+a[x[n-1]*n+x[0]])
            return false;
        return true;
    }
    void printSolution(int k){
        cout<<"circle: "<<x[0]+1;
        for(int i=1;i<n;i++)
            cout<<"->"<<x[i]+1;
        cout<<"->"<<x[0]+1<<endl;
        cout<<"weight: "<<most+a[x[n-1]*n+x[0]]<<endl;
    }
    bool isOptimal(int k){
        return currentValue+a[current[n-1]*n+current[0]]<most+a[x[n-1]*n+x[0]];
    }
};
#endif/* _TSP_H */
