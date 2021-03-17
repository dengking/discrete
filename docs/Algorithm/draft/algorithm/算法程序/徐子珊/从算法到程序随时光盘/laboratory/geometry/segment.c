#include "segment.h"
#include "./../datastructure/redblacktree.h"
#include "./../utility/quicksort.h"
#include <assert.h>
Segment newSeg(Point *a, Point *b){/*�����߶�*/
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
int pointLess(EndPoint *a, EndPoint *b){/*�˵�Ƚ�*/
	if(a->point.x<b->point.x)
        return 1;
	if(a->point.x==b->point.x)
        if(a->e==b->e)
			return a->point.y<b->point.y;
        else
            return a->e<b->e;
    return 0;
}
double getY(Segment *a, double x){/*�����߶���x����������*/
	assert(x>=a->left.point.x&&x<=a->right.point.x);
    return a->tan*x-a->yOffset;
}
EndPoint getLeft(Segment *a){/*ȡ����˵�*/
    return a->left;
}
EndPoint getRight(Segment *a){/*ȡ���Ҷ˵�*/
    return a->right;
}
typedef struct{/*�¼����Ԫ������*/
    EndPoint point;//�˵�
    size_t index;//�˵������߶��������е��±�
}p_i;
p_i newp_i(EndPoint p,size_t i){/*�����¼������Ԫ��*/
	p_i x;
	x.point=p;
	x.index=i;
	return x;
}
int p_iComp(p_i *a, p_i *b){/*���˵�ıȽϹ���Ƚ�*/
	return pointLess(&(a->point), &(b->point));
}
int segComp(Segment *a, Segment *b){/*�߶αȽ�*/
	double x0=a->left.point.x>b->left.point.x?a->left.point.x:b->left.point.x,
		x1=a->right.point.x<b->right.point.x?a->right.point.x:b->right.point.x,
			x;
    assert(x0<=x1);
    x=(x0+x1)/2.0;
    return getY(a,x)>getY(b,x);
}
int anySegmentIntersect(Segment* S, int n){
	int i;
    RBTree *T=creatRBTree(sizeof(Segment),segComp);/*���ں�����ļ���*/
    p_i  *p=(p_i*)malloc(2*n*sizeof(p_i));/*���ٶ˵������߶ε�����*/
    for(i=0;i<n;i++){/*�������ж˵�*/
		p[2*i]=newp_i(getLeft(&S[i]),i);
		p[2*i+1]=newp_i(getRight(&S[i]),i);
    }
    quickSort(p,sizeof(p_i),0,n-1,pointLess);/*�����ж˵�����*/
    for(i=0;i<2*n;i++){/*�Զ˵�Ϊ�¼���ɨ��*/
        Segment *s=&S[p[i].index],*above,*below;
        RBNode* pt;
		Point p1,p2,p3,p4;
        if(p[i].point.e==0){/*����ö˵�Ϊĳ�߶ε���˵�*/
			p1=getLeft(s).point;p2=getRight(s).point;
			pt=rbInsert(T, s);/*�����߶β���T*/
			above=(Segment*)(treePredecessor(pt))->key;
			below=(Segment*)(treeSuccessor(pt))->key;
			if(above!=NULL){/*above��ָ�������sָ����Ҵ����Ϸ����߶�*/
				p3=getLeft(above).point;p4=getRight(above).point;
				if(segmentsIntersect(&p1,&p2,&p3,&p4))/*above��s�ཻ*/
                    break;
            }
            if(below!=NULL){/*below��ָ�������sָ����Ҵ����·����߶�*/
 			   p3=getLeft(below).point;p4=getRight(below).point;
               if(segmentsIntersect(&p1,&p2, &p3,&p4))/*s��below�ཻ*/
                    break;
            }
        }else{/*���ö˵���ĳ�߶ε��Ҷ˵�*/
            pt=rbSearch(T,s);/*ptָ����߶�*/
			above=(Segment*)(treePredecessor(pt))->key;
			below=(Segment*)(treeSuccessor(pt))->key;
            if(above!=NULL&&below!=NULL){/*above,below�ֱ�ָ������Ÿ��߶����·����߶�*/
 			   p1=getLeft(above).point;p2=getRight(above).point;
 			   p3=getLeft(below).point;p4=getRight(below).point;
               if(segmentsIntersect(&p1,&p2,&p3,&p4))/*above��below�ཻ*/
                    break;
            }
            rbDelete(T, pt);/*��T��ɾ�����߶�*/
        }
    }
	free(p);
	clrRBTree(T,NULL);free(T);
	if(i<2*n)/*���߶��ཻ*/
		return 1;
    return 0;//û���ཻ�߶�
}
