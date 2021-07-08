#include "tpsort.h"
#include "../DataStructure/stack.h"
pair toplogicalSort(Graph *g){
    Stack *S=createStack(sizeof(int));
    int u,s,n=g->n,v,m=n,*acyclicity=(int*)malloc(sizeof(int)),
        *topLogic=(int*)malloc(n*sizeof(int));
    Color *color=(Color*)malloc(n*sizeof(Color));
    ListNode **pos=(ListNode**)malloc(n*sizeof(ListNode*));
    for(u=0;u<n;u++){
        color[u]=WHITE;
		pos[u]=g->adj[u]->nil->next;
    }
	*acyclicity=1;
    for(s=0;s<n;s++){
        if(color[s]==WHITE){
            color[s]=GRAY;
            push(S,&s);
            while(!stackEmpty(S)){
				ListNode *p;
				u=*(int*)(S->top->key);
                p=pos[u];
				v=(p!=g->adj[u]->nil)?((vertex*)(p->key))->index:-1;
                while(p!=g->adj[u]->nil&&color[v]!=WHITE){
					if(color[v]==GRAY)
						*acyclicity=0;
                    p=p->next;
					v=(p!=g->adj[u]->nil)?((vertex*)(p->key))->index:-1;
                }
                pos[u]=p;
                if(pos[u]!=g->adj[u]->nil){
                    color[v]=GRAY;
                    push(S,&v);
                }else{
                    color[u]=BLACK;
                    topLogic[--m]=u;
                    pop(S);
                }
            }
        }
    }
	free(pos);
    return make_pair(acyclicity, topLogic);
}
