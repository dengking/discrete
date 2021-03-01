#include<limits.h>
#include <stdlib.h>
#include <stdio.h>
#include "bfs.h"
#include "../DataStructure/queue.h"
pair bfs(Graph *g,int s){
    Queue *Q=createQueue(sizeof(int));
    int *pi,*d,i,u,v,n=g->n;
    Color *color;
    pi=(int*)malloc(n*sizeof(int));
    d=(int*)malloc(n*sizeof(int));
    color=(Color*)malloc(n*sizeof(Color));
    for(i=0;i<g->n;i++){
        pi[i]=-1;
        d[i]=INT_MAX;
        color[i]=WHITE;
    }
    d[s]=0;
    color[s]=GRAY;
    enQueue(Q,&s);
    while(!queueEmpty(Q)){
        ListNode *q=deQueue(Q);
		u=*(int*)q->key;
		clrListNode(q,NULL);
		q=g->adj[u]->nil->next;
        while(q!=g->adj[u]->nil){
			v=((vertex *)(q->key))->index;
            if(color[v]==WHITE){
                color[v]=GRAY;
                d[v]=d[u]+1;
                pi[v]=u;
                enQueue(Q,&v);
            }
            q=q->next;
        }
        color[u]=BLACK;
    }
    clrQueue(Q,NULL);
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
