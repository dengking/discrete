/* 
 * File:   knapsack.h
 * Author: ?����???
 *
 * Created on 2008��11��6��, ����8:58
 */

#ifndef _KNAPSACK_H
#define	_KNAPSACK_H
int *knapsack(int *w,int *v,int n,int c){
    int *m=new int[(n+1)*(c+1)],i,j;
    for(i=1;i<n+1;i++)
        m[i*(c+1)]=0;
    for(j=0;j<c+1;j++)
        m[j]=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=c;j++){
            m[i*(c+1)+j]=m[(i-1)*(c+1)+j];
            if(w[i-1]<=j)
                if(v[i-1]+m[(i-1)*(c+1)+j-w[i-1]]>m[(i-1)*(c+1)+j])
                    m[i*(c+1)+j]=v[i-1]+m[(i-1)*(c+1)+j-w[i-1]];
        }
    return m;
}
int *build_solution(int *m,int *w, int c, int n){
    int i,j=c;
    int *x=new int[n];
    for(i=n;i>1;i--)
        if(m[i*(c+1)+j]==m[(i-1)*(c+1)+j])
            x[i-1]=0;
        else{
            x[i-1]=1;
            j-=w[i-1];
        }
    x[0]=m[(c+1)+j]>0?1:0;
    return x;
}
#endif	/* _KNAPSACK_H */

