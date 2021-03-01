#include <float.h>
#include "../geometry/convexhull.h"
#include "../utility/most.h"
#include "overlaprectangle.h"
static void chRotate(Point *x, int n, double theta){/*�㼯x��תtheta��*/
	int i;
	for(i=0;i<n;i++)
		pointRotate(x+i,theta);/*��x[i]��תtheta��*/
}
static int pxgreater(Point *a, Point *b){/*ƽ��㰴������Ƚϴ�С*/
	if(a->x>b->x)
		return 1;
	if(a->x<b->x)
		return -1;
	return 0;
}
static int pxless(Point *a, Point *b){
	return -pxgreater(a, b);
}
static int pygreater(Point *a, Point *b){/*ƽ��㰴������Ƚϴ�С*/
	if(a->y>b->y)
		return 1;
	if(a->y<b->y)
		return -1;
	return 0;
}
static int pyless(Point *a, Point *b){
	return -pygreater(a, b);
}
Rectangle smallestBoundingRectangle(Point *q, int n){/*����㼯q����С���Ǿ���*/
	Rectangle result;
	int i,j,m;
	double minimx,maxmx,minimy,maxmy,area=DBL_MAX,temp; 
	Point *p=grahamScan(q,n,&m),/*����㼯q��͹��p*/
		a;
	for(i=0,j=0;i<m;i++,j++){/*��͹����ÿһ���߼�����Ӿ������*/
		double tg,theta;
		a=sub(p+((j+1)%m),p+j);/*һ����a*/
		tg=a.y/a.x;/*��a��б��*/
		theta=PI/2-atan(tg);/*��ת���a��ֱ����ת��*/
		chRotate(p,m,theta);/*��ת*/
		minimx=p[most(p,m,sizeof(Point),pxless)].x;/*͹������ߵ������*/
		maxmx=p[most(p,m,sizeof(Point),pxgreater)].x;/*���ұߵ������*/
		minimy=p[most(p,m,sizeof(Point),pyless)].y;/*���±ߵ�������*/
		maxmy=p[most(p,m,sizeof(Point),pygreater)].y;/*���ϱߵ�������*/
		temp=(maxmx-minimx)*(maxmy-minimy);/*����͹���������*/
		if(temp<area){/*������С��*/
			area=temp;
			result.height=(maxmy-minimy);
			result.width=(maxmx-minimx);
		}
	}
	free(p);
	return result;
}