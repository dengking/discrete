#include <string.h>
#include <stdlib.h>
#include "huffman.h"
#include "../DataStructure/pqueue.h"
int Compare(Node** a, Node** b){
	if((*a)->f==(*b)->f)
		return (int)((*b)->ch)-(int)((*a)->ch);
	return (*b)->f-(*a)->f;
}
int calck(int r, int n){
	int k=1;
	while(k*(r-1)+r<n)k++;
	return k;
}
HTree Huffman(char *C, int *f, int n, int r){
	HTree cTree;
	int i,j,k,t,z;
	PQueue *Q; 
	Node *e;
	cTree.R=r;cTree.N=n;
	k=calck(r,n);
	t=k*(r-1)+r;
	cTree.Nodes=(Node*)malloc((t+k+1)*sizeof(Node));
	for(i=0;i<n;i++){/*初始化n片字符叶子*/
		cTree.Nodes[i].ch=C[i];
		cTree.Nodes[i].f=f[i];
		cTree.Nodes[i].child=NULL;
		memset(cTree.Nodes[i].code,0,16);
	}
	for(i=n;i<t;i++){/*初始化虚拟叶子结点*/
		cTree.Nodes[i].ch=n-i+1;
		cTree.Nodes[i].f=0;
		cTree.Nodes[i].child=NULL;
	}
	Q=initPQueue(sizeof(Node*),t,Compare);/*创建优先队列*/
	for(i=0;i<t;i++){/*将所有叶子加入队列*/
		e=&(cTree.Nodes[i]);
		enQueue(Q,&e);
	}
	for(i=0,z=t;i<=k;i++,z++){/*贪婪策略创建huffman树*/
		cTree.Nodes[z].child=(int*)malloc(r*(sizeof(int)));
		cTree.Nodes[z].f=0;
		cTree.Nodes[z].ch='z'+z;
		for(j=0;j<r;j++){
			Node** x=(Node**)deQueue(Q);
			int self=*x-cTree.Nodes;
			cTree.Nodes[z].f+=(*x)->f;
			cTree.Nodes[z].child[j]=self;
			cTree.Nodes[self].parent=z;
		}
		e=&(cTree.Nodes[z]);
		enQueue(Q,&e);
	}
	pQueueClr(Q);
	cTree.Nodes[--z].parent=-1;
	return cTree;
}
void clrHTree(HTree *t){
	int i,n,k=1;
	if(t->N<=0)
		return;
	k=calck(t->R, t->N);
	n=k*(t->R-1)+(t->R);
	for(i=0;i<n;i++)
		if(t->Nodes[i].child)
			free(t->Nodes[i].child);
	free(t->Nodes);
}