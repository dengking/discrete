#include <math.h>
#include <float.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "closestpairpoints.h"
double force(Point *x, int n){//�������ڽ���Ծ���������㷨ʵ�ֺ���
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
    for(i=0,j=0;i<n;i++)//���㼯��λ�ڶԳ�������l���Ϊ2*delta�Ĵ�״�����ڵ��Ӽ�����y1
        if(fabs(y[i].x-lx)<=delta)
            y1[j++]=y[i];
	n=j;
    for(i=0;i<n;i++){//����y1�����ڽ���Ծ���
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
    if(n<=3)//������������3�����������е�Եľ��벢������С��
        return force(x,n);
    half=n/2;
    lx=x[half].x;
    xl=(Point*)malloc(half*sizeof(Point)),
    xr=(Point*)malloc((n-half)*sizeof(Point)),
    yl=(Point*)malloc(half*sizeof(Point)),
	yr=(Point*)malloc((n-half)*sizeof(Point));
	assert(xl&&xr&&yl&&yr);
	memcpy(xl, x, half);memcpy(xr,x+half,n-half);//��x����ĺ���������ֽ����������
    for(k=i=j=0;k<n;k++)//����x�ķֽ⣬��y�ֽ�ɶ�Ӧ�����������������򼯺�
        if(y[k].x<=lx&&i<=half)
            yl[i++]=y[k];
        else
            yr[j++]=y[k];
    deltal=closestPairPoints(xl,yl,half);//����벿�ֵݹ�
    deltar=closestPairPoints(xr,yr,n-half);//����벿�ֵݹ�
    delta=deltal<deltar?deltal:deltar;
    d=combine(y,n,lx,delta);
	free(xl);free(yl);free(xr);free(yr);
    return d<delta?d:delta;
}
