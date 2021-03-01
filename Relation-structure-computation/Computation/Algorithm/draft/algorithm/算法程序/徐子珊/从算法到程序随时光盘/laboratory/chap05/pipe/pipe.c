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
	Point a, b,left,right,p;/*�������a, b���߶�left right*/
	a.x=x[i];b.x=x[j];/*��ԭa, b*/
	a.y=isup?y[i]:y[i]-1;
	b.y=isup?y[j]-1:y[j];
	left.x=x[0];right.x=x[n-1];/*���Ҷ˵�ĺ�����*/
	left.y=(b.y-a.y)/(b.x-a.x)*(left.x-a.x)+a.y;/*��˵��������*/
	right.y=(b.y-a.y)/(b.x-a.x)*(right.x-a.x)+a.y;/*�Ҷ˵��������*/
	a.x=x[j];a.y=isup?y[j]:y[j]-1;/*��j�ι��ӹܱ����*/
	b.x=x[j+1];b.y=isup?y[j+1]:y[j+1]-1;/*��j�ι��ӵ��յ�*/
	if(segmentsIntersect(&a, &b, &left, &right)){/*��a, b��left,right�ཻ*/
		p=jointPoint(&a, &b, &right, &left);/*���㽻��*/
		return dist(&left, &p);/*�����������*/
	}
	k=j+1;
	while(k<n-1){/*�ӵ�j+1�ι�����������left, right�ཻ�Ĺܱ�*/
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
	do{/*����ͨ��������Ͱ���������С�Ƕȸ��ٹ����Ƕȷ�Χ*/
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
	if(l<=u)/*ͨ͸*/
		return len;
	for(i=0;i<k-1;i++){/*�����ÿ�ԺϷ�������ĳ��ȣ����������*/
		a.x=b.x=x[i];a.y=y[i];b.y=y[i]-1;/*��ߵ�*/
		for(j=i+1;j<k;j++){
			double temp,alpha;
			c.x=d.x=x[j];c.y=y[j];d.y=y[j]-1;/*�ұߵ�*/
			alpha=psudoAngle(&a, &d);/*�߶�ad���Ž�*/
			if(alpha>=low&&alpha<=up){
				temp=calculate(x,y,n,i,j,1);
				if(temp>len)
					len=temp;
			}
			alpha=psudoAngle(&b, &c);/*�߶�bc���Ž�*/
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
	fscanf(f1, "%d",&n);/*��ȡ������n*/
	while(n>0){
		if(x)free(x);
		if(y)free(y);
		assert(x=(double*)malloc(n*sizeof(double)));
		assert(y=(double*)malloc(n*sizeof(double)));
		for(i=0;i<n;i++)/*��ȡ��������*/
			fscanf(f1,"%lf%lf",x+i,y+i);
		length=pipe(x,y,n);/*�����������*/
		if(length<0)/*ͨ͸*/
			fprintf(f2, "Through all the pipe.\n");
		else
			fprintf(f2, "%.2f\n",length);/*��Ĺ�������*/
		fscanf(f1, "%d",&n);
	}
	free(x);free(y);free(y1);
	fclose(f1);fclose(f2);
	return 0;
}
