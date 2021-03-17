#ifndef _POINT_H
#define	_POINT_H
#include<math.h>
#define epsilon 1e-10
#define PI 3.1415926
typedef struct{/*平面点*/
    double x,y;/*横坐标与纵坐标*/
}Point;
double dist(Point *a, Point *b);/*两点间距离*/
double crossProduct(Point *a, Point *b);/*叉积*/
Point sub(Point *a, Point *b);/*两点向量差*/
int direction(Point *p0, Point *p1, Point *p2);/*判断向量p2p0是从向量p1p0绕p0的旋转方向*/
int inBox(Point *pi, Point *pj, Point *pk);/*检测pk是否落于以pi,pj为对角线的矩形内*/
int InBox(Point *pi, Point *pj, Point *pk);
double pabs(Point *a);
void normalize(Point *a);
int segmentsIntersect(Point *p1, Point *p2, Point *p3, Point *p4);/*检测线段p1p2和线段p3p4是否相交*/
double psudoPolarAngle(Point *a, Point *b);/*计算伪极角*/
Point jointPoint(Point *a1, Point *b1, Point *a2, Point *b2);/*计算相交线段a1b1、a2b2的交点*/
void pointRotate(Point *p, double theta);
#endif	/* _POINT_H */

