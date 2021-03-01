#include <stdlib.h>
#include "convexhull.h"
#include "..\utility\swap.h"
#include "..\utility\quicksort.h"
#include "..\utility\most.h"
static Point *O;
static int angleComp(Point *a, Point *b){
	double anglea=psudoPolarAngle(a,O), angleb=psudoPolarAngle(b,O);
	if(anglea==angleb)
		return 0;
	if(anglea<angleb)
		return -1;
	return 1;
}
static int pyxcomp(Point *a, Point *b){
	if(a->y<b->y)
		return 1;
	if(a->y==b->y&&a->x<b->x)
		return 1;
	if(a->y==b->y&&a->x==b->x)
		return 0;
	return -1;
}
Point *grahamScan(Point* p, int n,int *m){
    Stack *S=createStack(sizeof(Point));
 	int i=most(p,n,sizeof(Point),pyxcomp);
	Point *q;
	swap(p,p+i,sizeof(Point));
	O=p;
	quickSort(p+1,sizeof(Point),0,n-1,angleComp);
    push(S,p);push(S,p+1);push(S,p+2);
    for(i=3;i<n;i++){
		ListNode *b=S->top, *a=b->next;
		while(direction(a->key, b->key, p+i)>0){
            pop(S);
			b=S->top;
			a=b->next;
        }
        push(S, p+i);
    }
	*m=S->L->n;q=(Point*)calloc(*m, sizeof(Point));
	for(i=*m-1;i>=0;i--){
		ListNode *x=pop(S);
		q[i]=*((Point*)(x->key));
		clrListNode(x,NULL);
		free(x);
	}
	clrStack(S,NULL);
	free(S);
    return q;
}
