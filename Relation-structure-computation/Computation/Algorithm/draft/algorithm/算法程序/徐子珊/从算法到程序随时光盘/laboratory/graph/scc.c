#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
#include "../DataStructure/stack.h"
#include "../DataStructure/pair.h"
int isRoot(int *pi,int s,int v){
    if(s==v)//树根本身
        return 1;
    if(pi[v]==-1)//另一棵树的根
        return 0;
    return isRoot(pi,s,pi[v]);//递归检测父节点
}
LinkedList *makeForest(int *pi,int n){
    LinkedList *forest=createList(sizeof(LinkedList*),NULL);
	int s,v;
    for(s=0;s<n;s++){
        if(pi[s]==-1){//是一棵树的根
			LinkedList *tree=createList(sizeof(int),NULL);
            for(v=0;v<n;v++)//存储树中节点
                if(isRoot(pi,s,v))
					listPushBack(tree, &v);
			listPushBack(forest,&tree);
        }
    }
	return forest;
}
pair dfsByOrder(Graph *g,int *order){
    Stack *S=createStack(sizeof(int));//ջ
    int u,s,n=g->n,v,m=n,
        *pi=(int*)malloc(n*sizeof(int)),
        *topLogic=(int*)malloc(n*sizeof(int));
    Color *color=(Color*)malloc(n*sizeof(Color));
    ListNode **pos=(ListNode**)malloc(n*sizeof(ListNode*));
    for(u=0;u<n;u++){
        pi[u]=-1;
        color[u]=WHITE;
		pos[u]=g->adj[u]->nil->next;
    }
    for(s=0;s<n;s++){
        if(color[order[s]]==WHITE){
            color[order[s]]=GRAY;
            push(S,&order[s]);
            while(!stackEmpty(S)){
				ListNode *p;
				u=*(int*)(S->top->key);
                p=pos[u];
				v=(p!=g->adj[u]->nil)?((vertex*)(p->key))->index:-1;
                while(p!=g->adj[u]->nil&&color[v]!=WHITE){
                    p=p->next;
					v=(p!=g->adj[u]->nil)?((vertex*)(p->key))->index:-1;
                }
                pos[u]=p;
                if(pos[u]!=g->adj[u]->nil){
                    color[v]=GRAY;
                    pi[v]=u;
                    push(S,&v);
                }else{
                    color[u]=BLACK;
                    topLogic[--m]=u;
                    pop(S);
                }
            }
        }
    }
	free(pos);free(color);
    return make_pair(pi, topLogic);
}
LinkedList* strongConnectedComponents(Graph *g){
    int n=g->n,u;
    pair r;
    int *pi,*order=(int*)malloc(n*sizeof(int));
	LinkedList *forest;
	Graph *gt;
    for(u=0;u<n;u++)
        order[u]=u;
    gt=transpose(g);
    r=dfsByOrder(g,order);
	free(r.first);free(order);
    order=(int*)(r.second);
    r=dfsByOrder(gt,order);
	graphClear(gt);free(gt);
	pi=(int*)(r.first);free(r.second);free(order);
	forest=makeForest(pi, n);
	free(pi);
	return forest;
}
