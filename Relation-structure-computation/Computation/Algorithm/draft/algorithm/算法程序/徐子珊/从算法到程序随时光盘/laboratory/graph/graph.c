#include "graph.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int vComp(vertex *a, vertex *b){
	return a->index-b->index;
}
Graph *createGraph(double *a, int n){
    Graph *g=(Graph*)malloc(sizeof(Graph));
    int i,j;
	vertex *v;
    g->adj=(LinkedList**)malloc(n*sizeof(LinkedList*));
    g->n=n;
    for(i=0;i<n;i++){/*对每一个顶点i*/
        LinkedList *l=createList(sizeof(vertex),vComp);/*建立该顶点的邻接表*/
        for(j=n-1;j>=0;j--)
            if(a[i*n+j]!=0.0){/*j与i邻接*/
                v=(vertex*)malloc(sizeof(vertex));
                v->index=j;
                v->weight=a[i*n+j];
                listPushFront(l,v);/*将j加入到i的邻接表中*/
            }
			(g->adj)[i]=l;
    }
    return g;
}
void printGraph(Graph *g){
	int i;
	vertex *v;
	ListNode* p;
	for(i=0;i<g->n;i++){
		p=g->adj[i]->nil->next;
		while(p!=g->adj[i]->nil){
			v=(vertex*)(p->key);
			printf("%d, %f ", v->index, v->weight);
			p=p->next;
		}
		putchar('\n');
	}
}
void graphClear(Graph *g){
    int i;
	LinkedList *l;
	for(i=g->n-1;i>=0;i--){/*清理每个顶点的邻接表*/
		l=g->adj[i];
		clrList(l,NULL);
		free(l);
	}
    free(g->adj);/*释放邻接表数组*/
    g->n=0;
}
Graph *transpose(Graph *g){
    Graph *gt=(Graph*)malloc(sizeof(Graph));
    int u,v,n=gt->n=g->n;
    gt->adj=(LinkedList**)malloc(n*sizeof(LinkedList));
    for(u=0;u<n;u++)
        gt->adj[u]=createList(sizeof(vertex),NULL);
    for(u=0;u<n;u++){
		ListNode *i =g->adj[u]->nil->next;/*g的顶点u的邻接表指针*/
        while(i!=g->adj[u]->nil){/*在u的邻接表扫描*/
            vertex *u1=(vertex*)malloc(sizeof(vertex));
			v=((vertex *)(i->key))->index;/*u, v邻接*/
            u1->index=u;
			u1->weight=((vertex *)(i->key))->weight;
            listPushFront(gt->adj[v], u1);
            i=i->next;
        }
    }
    return gt;
}
void addVertex(Graph *g){
	int n=g->n+1;
	LinkedList **adj=(LinkedList**)malloc(n*sizeof(LinkedList*));
	if(g->adj){
		memcpy(adj, g->adj, n-1);
		free(g->adj);
		g->adj=adj;
	}
	g->adj[n-1]=createList(sizeof(vertex),vComp);
	g->n=n;
}
void deleteVertex(Graph *g, int u){
	int v, n=g->n-1;
	LinkedList **adj=(LinkedList**)malloc(n*sizeof(LinkedList*));
	memcpy(adj, g->adj,u*sizeof(LinkedList*));
	memcpy(adj+u,g->adj+u+1, (n-u)*sizeof(LinkedList*));
	for(v=0;v<n;v++){
		ListNode *p=adj[v]->nil->next;
		while(p!=adj[v]->nil){
			if(((vertex*)p->key)->index==u){
				ListNode *q=p->next;
				listDelete(adj[v],p);
				clrListNode(p,NULL);
				free(p);p=q;
				continue;
			}
			if(((vertex*)p->key)->index>u)
				((vertex*)p->key)->index--;
			p=p->next;
		}
	}
	free(g->adj);g->adj=adj;
	g->n=n;
}
void addEdge(Graph *g, int u, int v, double w){
	vertex x={w, v};
	listPushBack(g->adj[u],&x);
}
void deleteEdge(Graph *g, int u, int v){
	vertex x={0.0, v};
	ListNode *p=listSearch(g->adj[u],&x);
	if(p!=g->adj[u]->nil)
		listDelete(g->adj[u],p);
}
Graph *zeroGraph(int n){
	int i;
    Graph *g=(Graph*)malloc(sizeof(Graph));
	g->n=n;
    g->adj=(LinkedList**)malloc(n*sizeof(LinkedList*));
	for(i=0;i<n;i++)
		g->adj[i]=createList(sizeof(vertex),vComp);/*建立该顶点的邻接表*/
	return g;
}
Graph *cloneGraph(Graph *const g){
	Graph *g1=zeroGraph(g->n);
	int i;
	for(i=0;i<g1->n;i++)
		g1->adj[i]=listClone(g->adj[i]);
	return g1;
}