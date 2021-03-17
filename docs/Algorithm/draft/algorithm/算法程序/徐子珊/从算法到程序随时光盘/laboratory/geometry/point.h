#ifndef _POINT_H
#define	_POINT_H
#include<math.h>
#define epsilon 1e-10
#define PI 3.1415926
typedef struct{/*ƽ���*/
    double x,y;/*��������������*/
}Point;
double dist(Point *a, Point *b);/*��������*/
double crossProduct(Point *a, Point *b);/*���*/
Point sub(Point *a, Point *b);/*����������*/
int direction(Point *p0, Point *p1, Point *p2);/*�ж�����p2p0�Ǵ�����p1p0��p0����ת����*/
int inBox(Point *pi, Point *pj, Point *pk);/*���pk�Ƿ�������pi,pjΪ�Խ��ߵľ�����*/
int InBox(Point *pi, Point *pj, Point *pk);
double pabs(Point *a);
void normalize(Point *a);
int segmentsIntersect(Point *p1, Point *p2, Point *p3, Point *p4);/*����߶�p1p2���߶�p3p4�Ƿ��ཻ*/
double psudoPolarAngle(Point *a, Point *b);/*����α����*/
Point jointPoint(Point *a1, Point *b1, Point *a2, Point *b2);/*�����ཻ�߶�a1b1��a2b2�Ľ���*/
void pointRotate(Point *p, double theta);
#endif	/* _POINT_H */

