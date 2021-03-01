/* 
 * File:   lcs.h
 * Author: ?����???
 *
 * Created on 2008��11��4��, ����8:34
 */

#ifndef _LCS_H
#define	_LCS_H
int* lcsLength(void *x,void *y,int size, int m,int n,int(*comp)(void *,void *)){
    int i,j;
    int *c=(int *)malloc((m+1)*(n+1)*sizeof(int));
    for(i=1;i<=m;i++)
        c[i*(n+1)]=0;
    for(j=0;j<=n;j++)
        c[j]=0;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(comp(x+(i-1)*size,y+(j-1)*size)==0)
                c[i*(n+1)+j]=c[(i-1)*(n+1)+j-1]+1;
            else if(c[(i-1)*(n+1)+j]>=c[i*(n+1)+j-1])
                c[i*(n+1)+j]=c[(i-1)*(n+1)+j];
            else
                c[i*(n+1)+j]=c[i*(n+1)+j-1];
    return c;
}
void printLcs(int *c,int n, void *x,void *y,int size,int i,int j,int(*comp)(void *,void *),void(*prt)(void *)){
/*c是记录匹配信息的矩阵，x,y是两个字符串，i，j分别是x，y前缀的串长，n是y的串长*/
    if(i==0||j==0)
        return;
    if(comp(x+(i-1)*size,y+(j-1)*size)==0){
        printLcs(c,n,x,y,size,i-1,j-1,comp,prt);
        prt(x+(i-1)*size);
    }else if(c[(i-1)*(n+1)+j]>=c[i*(n+1)+j-1])
        printLcs(c,n,x,y,size,i-1,j,comp,prt);
    else
        printLcs(c,n,x,y,size,i,j-1,comp,prt);
}
#endif	/* _LCS_H */

