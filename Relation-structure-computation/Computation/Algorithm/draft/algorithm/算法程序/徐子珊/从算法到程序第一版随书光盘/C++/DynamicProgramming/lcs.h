/* 
 * File:   lcs.h
 * Author: ?����???
 *
 * Created on 2008��11��5��, ����10:14
 */

#ifndef _LCS_H
#define	_LCS_H
#include<iostream>
using namespace std;
template<typename Iterator>
int* lcsLength(Iterator x,Iterator y, int m, int n){
    int *c=new int[(m+1)*(n+1)],i,j;
    for(i=1;i<=m;i++)
        c[i*(n+1)]=0;
    for(j=0;j<=n;j++)
        c[j]=0;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(*(x+i-1)==*(y+j-1))
                c[i*(n+1)+j]=c[(i-1)*(n+1)+j-1]+1;
            else if(c[(i-1)*(n+1)+j]>=c[i*(n+1)+j-1])
                    c[i*(n+1)+j]=c[(i-1)*(n+1)+j];
            else
                    c[i*(n+1)+j]=c[i*(n+1)+j-1];
    return c;
}
template<typename Iterator>
void printLcs(int *c,int n,Iterator x,Iterator y,int i,int j){
    if(i==0||j==0)
            return;
    if(*(x+i-1)==*(y+j-1)){
        printLcs(c,n,x,y,i-1,j-1);
        cout<<*(x+i-1)<<" ";
    }else if(c[(i-1)*(n+1)+j]>=c[i*(n+1)+j-1])
              printLcs(c,n,x,y,i-1,j);
     else
              printLcs(c,n,x,y,i,j-1);
}
#endif	/* _LCS_H */

