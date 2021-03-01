#include <float.h>
#include "../geometry/convexhull.h"
#include "../utility/most.h"
#include "overlaprectangle.h"
static void chRotate(Point *x, int n, double theta){/*点集x旋转theta角*/
	int i;
	for(i=0;i<n;i++)
		pointRotate(x+i,theta);/*点x[i]旋转theta角*/
}
static int pxgreater(Point *a, Point *b){/*平面点按横坐标比较大小*/
	if(a->x>b->x)
		return 1;
	if(a->x<b->x)
		return -1;
	return 0;
}
static int pxless(Point *a, Point *b){
	return -pxgreater(a, b);
}
static int pygreater(Point *a, Point *b){/*平面点按纵坐标比较大小*/
	if(a->y>b->y)
		return 1;
	if(a->y<b->y)
		return -1;
	return 0;
}
static int pyless(Point *a, Point *b){
	return -pygreater(a, b);
}
Rectangle smallestBoundingRectangle(Point *q, int n){/*计算点集q的最小覆盖矩形*/
	Rectangle result;
	int i,j,m;
	double minimx,maxmx,minimy,maxmy,area=DBL_MAX,temp; 
	Point *p=grahamScan(q,n,&m),/*计算点集q的凸包p*/
		a;
	for(i=0,j=0;i<m;i++,j++){/*对凸包的每一条边计算外接矩形面积*/
		double tg,theta;
		a=sub(p+((j+1)%m),p+j);/*一条边a*/
		tg=a.y/a.x;/*边a的斜率*/
		theta=PI/2-atan(tg);/*旋转后边a垂直的旋转角*/
		chRotate(p,m,theta);/*旋转*/
		minimx=p[most(p,m,sizeof(Point),pxless)].x;/*凸包最左边点横坐标*/
		maxmx=p[most(p,m,sizeof(Point),pxgreater)].x;/*最右边点横坐标*/
		minimy=p[most(p,m,sizeof(Point),pyless)].y;/*最下边点纵坐标*/
		maxmy=p[most(p,m,sizeof(Point),pygreater)].y;/*最上边点纵坐标*/
		temp=(maxmx-minimx)*(maxmy-minimy);/*覆盖凸包矩形面积*/
		if(temp<area){/*跟踪最小者*/
			area=temp;
			result.height=(maxmy-minimy);
			result.width=(maxmx-minimx);
		}
	}
	free(p);
	return result;
}