#include <math.h>
#include <float.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "closestpairpoints.h"
double force(Point *x, int n){//计算最邻近点对距离的蛮力算法实现函数
    int i,j;
    double d=DBL_MAX,t;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++){
            t=dist(&x[i],&x[j]);
            if(t<d)
                d=t;
        }
    return d;
}
double combine(Point *y, int n, double lx,double delta){
    int i,j;
	double d=DBL_MAX,t;
    Point* y1=(Point*)malloc(n*sizeof(Point));
    for(i=0,j=0;i<n;i++)//将点集中位于对称于竖线l宽度为2*delta的带状区域内的子集置于y1
        if(fabs(y[i].x-lx)<=delta)
            y1[j++]=y[i];
	n=j;
    for(i=0;i<n;i++){//计算y1中最邻近点对距离
        for( j=1;i+j<n&&j<8;j++){
            t=dist(&y1[i],&y1[i+j]);
            if(t<d)
                d=t;
        }
    }
	free(y1);
    return d;
}
double closestPairPoints(Point *x, Point *y, int n){
	int half,k,i,j;
	double lx,deltal,deltar,delta,d;
	Point *xl,*xr,*yl,*yr;
    if(n<=3)//若点数不超过3蛮力计算所有点对的距离并返回最小者
        return force(x,n);
    half=n/2;
    lx=x[half].x;
    xl=(Point*)malloc(half*sizeof(Point)),
    xr=(Point*)malloc((n-half)*sizeof(Point)),
    yl=(Point*)malloc(half*sizeof(Point)),
	yr=(Point*)malloc((n-half)*sizeof(Point));
	assert(xl&&xr&&yl&&yr);
	memcpy(xl, x, half);memcpy(xr,x+half,n-half);//将x按点的横坐标升序分解成两个集合
    for(k=i=j=0;k<n;k++)//根据x的分解，将y分解成对应的两个按纵坐标升序集合
        if(y[k].x<=lx&&i<=half)
            yl[i++]=y[k];
        else
            yr[j++]=y[k];
    deltal=closestPairPoints(xl,yl,half);//对左半部分递归
    deltar=closestPairPoints(xr,yr,n-half);//对左半部分递归
    delta=deltal<deltar?deltal:deltar;
    d=combine(y,n,lx,delta);
	free(xl);free(yl);free(xr);free(yr);
    return d<delta?d:delta;
}
