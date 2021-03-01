/* 
 * File:   matrixchain.h
 * Author: ?����???
 *
 * Created on 2008��11��4��, ����4:21
 */

#ifndef _MATRIXCHAIN_H
#define	_MATRIXCHAIN_H
#include<iostream>
using namespace std;
pair<int*,int*> matrixChainOrder(int *p,int n){
    long i,l,j,k,q;
    int *m=new int[(n+1)*(n+1)];
    int *s=new int[(n+1)*(n+1)];
    pair<int*,int*> result;
    for(i=0;i<=n;i++)
        m[i*(n+1)+i]=0;
    for(l=2;l<=n;l++)//l为子矩阵链的长度
        for(i=1;i<=n-l+1;i++){
            j=i+l-1;
            m[i*(n+1)+j]=numeric_limits<int>::max();//m[i,j]←∞
            for(k=i;k<=j-1;k++){
                q=m[i*(n+1)+k]+m[(k+1)*(n+1)+j]+p[i-1]*p[k]*p[j];
                if(q<m[i*(n+1)+j]){
                    m[i*(n+1)+j]=q;
                    s[i*(n+1)+j]=k;
                }
            }
        }
    result.first=m;
    result.second=s;
    return result;
}
void printOptimalParens(int *s,int i,int j,int n){
    if(i==j)
        cout<<'A'<<i;
    else{
        cout<<'(';
        printOptimalParens(s,i,s[i*(n+1)+j],n);
        printOptimalParens(s,s[i*(n+1)+j]+1,j,n);
        cout<<')';
    }
}
#endif	/* _MATRIXCHAIN_H */

