#include <math.h>
#include <assert.h>
#include "point.h"
Point sub(Point *a, Point *b){//两点向量差
	Point c={a->x-b->x, a->y-b->y};
    return c;
}
double crossProduct(Point *a, Point *b){//叉积
    return a->x*b->y-a->y*b->x;
}
int direction(Point *p0, Point *p1, Point *p2){//判断向量p2p0是从向量p1p0绕p0的旋转方向
	Point p=sub(p2,p0),q=sub(p1,p0);
    double d=crossProduct(&p,&q);
    if(d>0.0)//顺时针
        return 1;
    if(d<0.0)//逆时针
        return -1;
    return 0;//共线
}
int inBox(Point *pi, Point *pj, Point *pk){//检测pk是否落于以pi,pj为对角线的矩形内
	double x1=pi->x<pj->x?pi->x:pj->x,
		x2=pi->x>pj->x?pi->x:pj->x,
		y1=pi->y<pj->y?pi->y:pj->y,
		y2=pi->y>pj->y?pi->y:pj->y;
    return x1<=pk->x&&pk->x<=x2&&
           y1<=pk->y&&pk->y<=y2;
}
int InBox(Point *pi, Point *pj, Point *pk){//检测pk是否落于以pi,pj为对角线的矩形内
	double x1=pi->x<pj->x?pi->x:pj->x,
		x2=pi->x+pj->x-x1,
		y1=pi->y<pj->y?pi->y:pj->y,
		y2=pi->y+pj->y-y1;
    return x1<(pk->x)&&(pk->x)<x2&&
           y1<(pk->y)&&(pk->y<y2);
}
int segmentsIntersect(Point *p1, Point *p2, Point *p3, Point *p4){//检测线段p1p2和线段p3p4是否相交
    int d1=direction(p3,p4,p1),
        d2=direction(p3,p4,p2),
        d3=direction(p1,p2,p3),
        d4=direction(p1,p2,p4);
	if((d1*d2<0)&&(d3*d4<0))
        return 1;
    if(d1==0&&inBox(p3,p4,p1))
        return 1;
    if(d2==0&&inBox(p3,p4,p2))
        return 1;
    if(d3==0&&inBox(p1,p2,p3))
        return 1;
    if(d4==0&&inBox(p1,p2,p4))
        return 1;
    return 0;
}
double dist(Point *a, Point *b){//两点间距离
    return sqrt(pow(a->x-b->x,2)+pow(a->y-b->y,2));
}
double pabs(Point *a){//计算向量a的模
	Point o={0.0,0.0};
    return dist(a,&o);
}
void normalize(Point *a){//向量a正规化（模长为1）
	double r=pabs(a);
	if(r>=epsilon){/*a非0向量*/
		a->x/=r;
		a->y/=r;
	}
}
double psudoPolarAngle(Point *a, Point *b){//计算向量a关于向量b的的极角
    Point p1=sub(a,b);
	normalize(&p1);
    if(pabs(&p1)<epsilon)
        return 2*PI;
    if(p1.y>=0.0&&p1.x>=0.0)//p位于第I象限
        return p1.y;
    if(p1.y>=0.0&&p1.x<0.0)//p位于第II象限
        return PI/2-p1.x;
    if(p1.y<0.0&&p1.x<0.0)//p位于第III象限
        return PI-p1.y;
    return 3*PI/2+p1.x;//p位于第IV象限
}
Point jointPoint(Point *p1, Point *p2, Point *p3, Point *p4){
	double a11,a12, a21, a22, b1, b2, d, dx, dy;
	Point p;
	a11=(p2->y-p1->y);a12=(p1->x-p2->x);b1=a11*(p2->x)+a12*(p2->y);
	a21=(p4->y-p3->y);a22=(p3->x-p4->x);b2=a21*(p4->x)+a22*(p4->y);
	d=a11*a22-a21*a12;
	dx=b1*a22-b2*a12;
	dy=a11*b2-a21*b1;
	p.x=dx/d;p.y=dy/d;
	return p;
}
void pointRotate(Point *p, double theta){
	double x=(p->x)*cos(theta)-(p->y)*sin(theta),
		y=(p->x)*sin(theta)+(p->y)*cos(theta);
	p->x=x;
	p->y=y;
}
