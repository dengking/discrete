/* 
 * File:   graph.h
 * Author: 徐子珊
 *
 * Created on 2008年12月5日, 下午�5:57
 */

#ifndef _GRAPH_H
#define	_GRAPH_H
#include "bilist.h"
#include "Vertex.h"
struct Graph{
    List **adj;
    int n;
};
typedef struct Graph Graph;
Graph *createGraph(float *a, int n){
    Graph *g=(Graph*)malloc(sizeof(Graph));
    int i,j;
    g->adj=(List**)malloc(n*sizeof(List*));
    g->n=n;
    for(i=0;i<n;i++){/*对每一个顶点i*/
        List *l=NULL;/*建立该顶点的邻接表*/
        for(j=n-1;j>=0;j--)
            if(a[i*n+j]!=0.0){/*j与i邻接*/
                vertex *v=(vertex*)malloc(sizeof(vertex));
                v->index=j;
                v->weight=a[i*n+j];
                listPushBegin(&l,v);/*将j加入到i的邻接表中*/
            }
        g->adj[i*sizeof(List*)]=l;
    }
    return g;
}
void graphClear(Graph *g){
    int i;
    for(i=g->n;i>-1;i--)/*清理每个顶点的邻接表*/
        if((g->adj[i*sizeof(List*)])!=NULL){
            listClear(g->adj[i*sizeof(List*)]);
            free(g->adj[i*sizeof(List*)]);
        }
    free(g->adj);/*释放邻接表数组*/
    g->n=0;
}
Graph *transpose(Graph *g){
    Graph *gt=(Graph*)malloc(sizeof(Graph));
    int n=gt->n=g->n;
    gt->adj=(List**)malloc(n*sizeof(List*));
    List *i;
    int u,v;
    for(u=0;u<n;u++)
        gt->adj[u*sizeof(List*)]=NULL;
    for(u=0;u<n;u++){
        i=g->adj[u*sizeof(List*)];
        while(i!=NULL){
            vertex *u1=(vertex*)malloc(sizeof(vertex));
            v=((vertex *)(i->data))->index;
            u1->index=u;
            u1->weight=((vertex *)(i->data))->weight;
            listPushBegin(&(gt->adj[v*sizeof(List*)]),u1);
            i=i->next;
        }
    }
    return gt;
}
#endif	/* _GRAPH_H */

