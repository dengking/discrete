#include <stdio.h>
#include <assert.h>
#include<stdlib.h>
#include <math.h>
#include <float.h>
#include "../../geometry/point.h"
double psudoAngle(Point *a, Point *b){
	Point p1=sub(a,b);
	assert(pabs(&p1)>=epsilon);
	normalize(&p1);
	return p1.y;
}
double calculate(double *x, double *y, int n, int i, int j, int isup){
	int k;
	Point a, b,left,right,p;/*计算过点a, b的线段left right*/
	a.x=x[i];b.x=x[j];/*还原a, b*/
	a.y=isup?y[i]:y[i]-1;
	b.y=isup?y[j]-1:y[j];
	left.x=x[0];right.x=x[n-1];/*左右端点的横坐标*/
	left.y=(b.y-a.y)/(b.x-a.x)*(left.x-a.x)+a.y;/*左端点的纵坐标*/
	right.y=(b.y-a.y)/(b.x-a.x)*(right.x-a.x)+a.y;/*右端点的纵坐标*/
	a.x=x[j];a.y=isup?y[j]:y[j]-1;/*第j段管子管壁起点*/
	b.x=x[j+1];b.y=isup?y[j+1]:y[j+1]-1;/*第j段管子的终点*/
	if(segmentsIntersect(&a, &b, &left, &right)){/*若a, b和left,right相交*/
		p=jointPoint(&a, &b, &right, &left);/*计算交点*/
		return dist(&left, &p);/*计算光束长度*/
	}
	k=j+1;
	while(k<n-1){/*从第j+1段管子起搜索与left, right相交的管壁*/
		a.x=x[k];a.y=y[k];
		b.x=x[k+1];b.y=y[k+1];
		if(segmentsIntersect(&a, &b, &left, &right)){
			p=jointPoint(&a, &b, &right, &left);
			return dist(&left, &p);
		}
		a.y--;b.y--;
		if(segmentsIntersect(&a, &b, &left, &right)){
			p=jointPoint(&a, &b, &right, &left);
			return dist(&left, &p);
		}
		k++;
	}
}
double pipe(double *x, double *y, int n){
	double angle1, angle2,len=-1,l=-DBL_MAX,u=DBL_MAX,low, up;
	int i=1,j,k;
	Point a,b,c,d;
	do{/*计算通过各个管桶光束最大最小角度跟踪公共角度范围*/
		double m1, m2;
		low=l;up=u;
		k=i;
		a.x=x[i-1],a.y=y[i-1],b.x=x[i], b.y= y[i]-1;
		angle1=psudoAngle(&b,&a);
		a.y=y[i-1]-1;b.y=y[i];
		angle2=psudoAngle(&b,&a);
		m1=(angle1<angle2)?angle1:angle2;
		m2=angle1+angle2-m1;
		if(m1>l)
			l=m1;
		if(m2<u)
			u=m2;
		i++;
	}while(i<n&&l<=u);
	if(l<=u)/*通透*/
		return len;
	for(i=0;i<k-1;i++){/*计算过每对合法点光束的长度，跟踪最大者*/
		a.x=b.x=x[i];a.y=y[i];b.y=y[i]-1;/*左边点*/
		for(j=i+1;j<k;j++){
			double temp,alpha;
			c.x=d.x=x[j];c.y=y[j];d.y=y[j]-1;/*右边点*/
			alpha=psudoAngle(&a, &d);/*线段ad的张角*/
			if(alpha>=low&&alpha<=up){
				temp=calculate(x,y,n,i,j,1);
				if(temp>len)
					len=temp;
			}
			alpha=psudoAngle(&b, &c);/*线段bc的张角*/
			if(alpha>=low&&alpha<=up){
				temp=calculate(x,y,n,i,j,0);
				if(temp>len)
					len=temp;
			}
		}
	}
	return len;
}
int main(){
	double *x=NULL, *y=NULL, *y1=NULL,length;
	int n,i;
	FILE *f1=fopen("chap05/Pipe/inputdata.txt","r"), 
		*f2=fopen("chap05/Pipe/outputdata.txt","w");
	assert(f1&&f2);
	fscanf(f1, "%d",&n);/*读取案例数n*/
	while(n>0){
		if(x)free(x);
		if(y)free(y);
		assert(x=(double*)malloc(n*sizeof(double)));
		assert(y=(double*)malloc(n*sizeof(double)));
		for(i=0;i<n;i++)/*读取案例数据*/
			fscanf(f1,"%lf%lf",x+i,y+i);
		length=pipe(x,y,n);/*计算光束长度*/
		if(length<0)/*通透*/
			fprintf(f2, "Through all the pipe.\n");
		else
			fprintf(f2, "%.2f\n",length);/*最长的光束长度*/
		fscanf(f1, "%d",&n);
	}
	free(x);free(y);free(y1);
	fclose(f1);fclose(f2);
	return 0;
}
