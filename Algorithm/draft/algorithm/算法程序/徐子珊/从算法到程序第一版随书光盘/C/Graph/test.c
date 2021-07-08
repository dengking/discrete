/* 
 * File:   test.c
 * Author: 徐子珊
 *
 * Created on 2008年12月5日, 下午6:31
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
#include "../Utility/bfs.h"

#include "../DataStructure/stack.h"
#include "../DataStructure/queue.h"

/*
#include "../Utility/dfs.h"
*/

int main(int argc, char** argv) {
    int i,s=4,n=8,*pi,*d;
    pair r;
    float a[]={0,1,0,0,1,0,0,0,
               1,0,0,0,0,1,0,0,
               0,0,0,1,0,1,1,0,
               0,0,1,0,0,0,1,1,
               1,0,0,0,0,0,0,0,
               0,1,1,0,0,0,1,0,
               0,0,1,1,0,1,0,1,
               0,0,0,1,0,0,1,0};
    Graph *g=createGraph(a,8);
    r=bfs(g,s);
    pi=r.first;
    d=r.second;
    for(i=0;i<n;i++)
        if(i!=s){
            printPath(pi,s,i);
            printf(" length: %d\n",d[i]);
        }
    graphClear(g);
    free(g);
/*
    int i,*e;
    stack *S=createStack();
    Queue *Q=createQueue();
    for(i=0;i<10;i++){
        e=(int*)malloc(sizeof(int));
        *e=i;
        push(&S,e);
        EnQueue(&Q,e);
    }
    while(!isEmpty(&S))
        printf("%d ",*(int*)(pop(&S)));
    printf("\n");
    while(!Empty(&Q))
        printf("%d ",*(int*)(DeQueue(&Q)));
    printf("\n");
*/
/*
    float b[]={0,1,0,0,0,0,1,0,0,0,
               1,0,1,0,0,1,0,0,0,0,
               0,1,0,1,1,0,0,0,0,0,
               0,0,1,0,1,0,0,0,0,0,
               0,0,1,1,0,0,0,0,0,0,
               0,1,0,0,0,0,1,0,0,0,
               1,0,0,0,0,1,0,1,0,0,
               0,0,0,0,0,0,1,0,1,1,
               0,0,0,0,0,0,0,1,0,1,
               0,0,0,0,0,0,0,1,1,0};
    List *r;
    int s,u,v;
    Graph *g=createGraph(b,10),*gt;
    for(u=0;u<g->n;u++){
        r=g->adj[u*sizeof(List*)];
        while(r!=NULL){
            printf("%d ",((vertex*)(r->data))->index);
            r=r->next;
        }
        printf("\n");
    }
    gt=transpose(g);
    for(u=0;u<gt->n;u++){
        r=gt->adj[u*sizeof(List*)];
        while(r!=NULL){
            printf("%d ",((vertex*)(r->data))->index);
            r=r->next;
        }
        printf("\n");
    }
*/
/*
    for(s=0;s<10;s++){
        r=articpoint(g,s);
        while(r!=NULL){
            printf("%c ",*(int*)(r->data)+97);
            r=r->next;
        }
        printf("\n");
    }
*/
/*
    float a[]={0,1,0,0,0,0,0,0,
               0,0,1,0,1,1,0,0,
               0,0,0,1,0,0,1,0,
               0,0,1,0,0,0,0,1,
               1,0,0,0,0,1,0,0,
               0,0,0,0,0,0,1,0,
               0,0,0,0,0,1,0,1,
               0,0,0,0,0,0,0,1};
    int s,u,n=8;
    int *pi;
    Graph *g=createGraph(a,n),*gt;
    List *r;
    strongConnectedComponents(g);
    graphClear(g);
    free(g);
*/
/*
    printComponents(pi);
*/
    return (EXIT_SUCCESS);
}

