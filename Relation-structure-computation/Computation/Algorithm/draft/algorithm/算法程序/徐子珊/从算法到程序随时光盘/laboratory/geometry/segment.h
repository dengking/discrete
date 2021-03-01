#ifndef _SEGMENT_H
#define	_SEGMENT_H
#include "point.h"
typedef struct{
    Point point;/*�˵�����*/
    int e;/*�˵��־����0��1��*/
}EndPoint;/*�߶ζ˵�����*/
int pointLess(EndPoint *a, EndPoint *b);//�˵�Ƚ�
typedef struct{
    EndPoint left;/*��˵�*/
    EndPoint right;/*�Ҷ˵�*/
    double length;/*����*/
    double tan;/*б��*/
    double yOffset;/*����ֱ����y��Ľؾ�*/
}Segment;/*�߶���*/
Segment newSeg(Point *a, Point *b);//���캯��
EndPoint getLeft(Segment *a);//������˵�
EndPoint getRight(Segment *a);//�����Ҷ˵�
double getY(Segment *a, double x);//�����߶���x����������
EndPoint getLeft(Segment *a);
EndPoint getRight(Segment *a);
int segComp(Segment *a, Segment *b);//�߶αȽ�
int anySegmentIntersect(Segment* S, int n);
#endif	/* _SEGMENT_H */
