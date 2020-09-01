/* 
 * File:   bfs.h
 * Author: 徐子珊
 *
 * Created on 2008年12月5日, 下午8:15
 */

#ifndef _BFS_H
#define	_BFS_H
#include "../DataStructure/graph.h"
#include "../DataStructure/queue.h"
#include "../DataStructure/pair.h"
#include<limits.h>
enum vertex_color {WHITE,GRAY,BLACK};
typedef enum vertex_color Color;
pair bfs(Graph *g,int s){
    Queue *Q=createQueue();
    int *pi,*d,i,*u,*v;
    Color *color;
    pi=(int*)malloc(g->n*sizeof(int));
    d=(int*)malloc(g->n*sizeof(int));
    color=(Color*)malloc(g->n*sizeof(Color));
    for(i=0;i<g->n;i++){
        pi[i]=-1;
        d[i]=INT_MAX;
        color[i]=WHITE;
    }
    d[s]=0;
    color[s]=GRAY;
    EnQueue(Q,&s);
    while(!Empty(Q)){
        u=DeQueue(Q);
        List *q=*(List**)(g->adj+*u*sizeof(List*));
        while(q!=NULL){
            v=(int*)malloc(sizeof(int));
            *v=((vertex *)(q->data))->index;
            if(color[*v]==WHITE){
                color[*v]=GRAY;
                d[*v]=d[*u]+1;
                pi[*v]=*u;
                EnQueue(Q,v);
            }
            q=q->next;
        }
        color[*u]=BLACK;
    }
    queueClear(Q);
    free(Q);
    return make_pair(pi,d);
}
void printPath(int *pi,int s, int v){
    if(v==s){
        printf("%d ",s);
        return;
    }
    if(pi[v]==-1)
        printf("no path from %d to %d!\n",s,v);
    else{
        printPath(pi,s,pi[v]);
        printf("%d ",v);
    }
}
#endif	/* _BFS_H */

