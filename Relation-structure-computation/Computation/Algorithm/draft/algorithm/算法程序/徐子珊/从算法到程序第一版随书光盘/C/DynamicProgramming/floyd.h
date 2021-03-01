/* 
 * File:   floyd.h
 * Author: ?����???
 *
 * Created on 2008��11��6��, ����10:25
 */

#ifndef _FLOYD_H
#define	_FLOYD_H
#include<string.h>
#include<float.h>
#include "../DataStructure/pair.h"
#include "../Utility/arrayCpy.h"
#define dblInfy DBL_MAX
pair floydWarshall(double* w,int n){
    double *d=(double*)malloc(n*n*sizeof(double));
    int i,j,k,*pi=(int*)malloc(n*n*sizeof(int));
    pair result;
    arrayCopy(d,w,sizeof(double),n*n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(j==i||w[i*n+j]>=dblInfy)
                pi[i*n+j]=-1;
            else
                pi[i*n+j]=i;
    for(k=1;k<=n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(d[i*n+j]>d[i*n+k-1]+d[(k-1)*n+j]){
                    d[i*n+j]=d[i*n+k-1]+d[(k-1)*n+j];
                    pi[i*n+j]=pi[(k-1)*n+j];
                }
    result.first=d;
    result.second=pi;
    return result;
}
void printAllPairsShotestPath(int *pi,int n,int i,int j){
    if(i==j){
        printf("%d ",i+1);
        return;
    }
    if(pi[i*n+j]==-1)
        printf("no path from %d to %d exists.\n",i+1,j+1);
    else{
        printAllPairsShotestPath(pi,n,i,pi[i*n+j]);
        printf("%d ",j+1);
    }
}
#endif	/* _FLOYD_H */

