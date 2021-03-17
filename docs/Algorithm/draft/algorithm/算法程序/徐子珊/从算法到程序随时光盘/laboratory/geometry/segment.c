#include "segment.h"
#include "./../datastructure/redblacktree.h"
#include "./../utility/quicksort.h"
#include <assert.h>
Segment newSeg(Point *a, Point *b){/*生成线段*/
	Segment c;
	c.left.point=*a;
	c.left.e=0;
	c.right.point=*b;
	c.right.e=1;
	c.length=dist(&c.left.point, &c.right.point);
	c.tan=((c.left.point).y-(c.right.point).y)/((c.left.point).x-(c.right.point).x);
	c.yOffset=c.tan*(c.left.point).x-c.left.point.y;
	return c;
}
int pointLess(EndPoint *a, EndPoint *b){/*端点比较*/
	if(a->point.x<b->point.x)
        return 1;
	if(a->point.x==b->point.x)
        if(a->e==b->e)
			return a->point.y<b->point.y;
        else
            return a->e<b->e;
    return 0;
}
double getY(Segment *a, double x){/*计算线段在x处的纵坐标*/
	assert(x>=a->left.point.x&&x<=a->right.point.x);
    return a->tan*x-a->yOffset;
}
EndPoint getLeft(Segment *a){/*取得左端点*/
    return a->left;
}
EndPoint getRight(Segment *a){/*取得右端点*/
    return a->right;
}
typedef struct{/*事件点表元素类型*/
    EndPoint point;//端点
    size_t index;//端点所在线段在数组中的下标
}p_i;
p_i newp_i(EndPoint p,size_t i){/*生成事件点表中元素*/
	p_i x;
	x.point=p;
	x.index=i;
	return x;
}
int p_iComp(p_i *a, p_i *b){/*按端点的比较规则比较*/
	return pointLess(&(a->point), &(b->point));
}
int segComp(Segment *a, Segment *b){/*线段比较*/
	double x0=a->left.point.x>b->left.point.x?a->left.point.x:b->left.point.x,
		x1=a->right.point.x<b->right.point.x?a->right.point.x:b->right.point.x,
			x;
    assert(x0<=x1);
    x=(x0+x1)/2.0;
    return getY(a,x)>getY(b,x);
}
int anySegmentIntersect(Segment* S, int n){
	int i;
    RBTree *T=creatRBTree(sizeof(Segment),segComp);/*基于红黑树的集合*/
    p_i  *p=(p_i*)malloc(2*n*sizeof(p_i));/*跟踪端点所属线段的数组*/
    for(i=0;i<n;i++){/*析出所有端点*/
		p[2*i]=newp_i(getLeft(&S[i]),i);
		p[2*i+1]=newp_i(getRight(&S[i]),i);
    }
    quickSort(p,sizeof(p_i),0,n-1,pointLess);/*对所有端点排序*/
    for(i=0;i<2*n;i++){/*以端点为事件点扫描*/
        Segment *s=&S[p[i].index],*above,*below;
        RBNode* pt;
		Point p1,p2,p3,p4;
        if(p[i].point.e==0){/*如果该端点为某线段的左端点*/
			p1=getLeft(s).point;p2=getRight(s).point;
			pt=rbInsert(T, s);/*将该线段插入T*/
			above=(Segment*)(treePredecessor(pt))->key;
			below=(Segment*)(treeSuccessor(pt))->key;
			if(above!=NULL){/*above是指向紧挨着s指向的且处于上方的线段*/
				p3=getLeft(above).point;p4=getRight(above).point;
				if(segmentsIntersect(&p1,&p2,&p3,&p4))/*above，s相交*/
                    break;
            }
            if(below!=NULL){/*below是指向紧挨着s指向的且处于下方的线段*/
 			   p3=getLeft(below).point;p4=getRight(below).point;
               if(segmentsIntersect(&p1,&p2, &p3,&p4))/*s，below相交*/
                    break;
            }
        }else{/*若该端点是某线段的右端点*/
            pt=rbSearch(T,s);/*pt指向该线段*/
			above=(Segment*)(treePredecessor(pt))->key;
			below=(Segment*)(treeSuccessor(pt))->key;
            if(above!=NULL&&below!=NULL){/*above,below分别指向紧挨着该线段上下方的线段*/
 			   p1=getLeft(above).point;p2=getRight(above).point;
 			   p3=getLeft(below).point;p4=getRight(below).point;
               if(segmentsIntersect(&p1,&p2,&p3,&p4))/*above，below相交*/
                    break;
            }
            rbDelete(T, pt);/*从T中删除该线段*/
        }
    }
	free(p);
	clrRBTree(T,NULL);free(T);
	if(i<2*n)/*有线段相交*/
		return 1;
    return 0;//没有相交线段
}
