#ifndef _SEGMENT_H
#define	_SEGMENT_H
#include "point.h"
typedef struct{
    Point point;/*端点坐标*/
    int e;/*端点标志（左0右1）*/
}EndPoint;/*线段端点类型*/
int pointLess(EndPoint *a, EndPoint *b);//端点比较
typedef struct{
    EndPoint left;/*左端点*/
    EndPoint right;/*右端点*/
    double length;/*长度*/
    double tan;/*斜率*/
    double yOffset;/*所在直线在y轴的截距*/
}Segment;/*线段类*/
Segment newSeg(Point *a, Point *b);//构造函数
EndPoint getLeft(Segment *a);//访问左端点
EndPoint getRight(Segment *a);//访问右端点
double getY(Segment *a, double x);//计算线段在x处的纵坐标
EndPoint getLeft(Segment *a);
EndPoint getRight(Segment *a);
int segComp(Segment *a, Segment *b);//线段比较
int anySegmentIntersect(Segment* S, int n);
#endif	/* _SEGMENT_H */
