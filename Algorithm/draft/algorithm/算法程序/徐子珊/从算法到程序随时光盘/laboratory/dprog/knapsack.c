#include<stdlib.h>
int *knapsack(int *w,int *v,int n,int c){
    int *m=(int*)malloc((n+1)*(c+1)*sizeof(int)),i,j;
    for(j=0;j<c+1;j++)
        m[j]=0;/*m[0,j]¡û0*/
	for(i=1;i<=n;i++){
        m[i*(c+1)]=0;/*m[i,0]¡û0*/
        for(j=1;j<=c;j++){
            m[i*(c+1)+j]=m[(i-1)*(c+1)+j];/*m[i,j] ¡ûm[i-1,j]*/
            if(w[i-1]<=j)
                if(v[i-1]+m[(i-1)*(c+1)+j-w[i-1]]>m[(i-1)*(c+1)+j])
                    m[i*(c+1)+j]=v[i-1]+m[(i-1)*(c+1)+j-w[i-1]];
        }
	}
    return m;
}
int *buildSolution(int *m, int n,int *w, int c){
    int i,j=c;
    int *x=(int*)malloc(n*sizeof(int));
    for(i=n;i>=1;i--)
        if(m[i*(c+1)+j]==m[(i-1)*(c+1)+j])
            x[i-1]=0;
        else{
            x[i-1]=1;
            j-=w[i-1];
        }
    return x;
}