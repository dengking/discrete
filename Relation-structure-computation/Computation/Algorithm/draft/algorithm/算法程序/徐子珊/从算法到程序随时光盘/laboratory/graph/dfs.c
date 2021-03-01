#include "dfs.h"
#include "../DataStructure/stack.h"
pair dfs(Graph *g){
	pair *df=(pair*)malloc(sizeof(pair));
    Stack *S=createStack(sizeof(int));
    int u,s,n=g->n,v,m=n,time=0,
        *pi=(int*)malloc(n*sizeof(int)),
		*d=(int*)malloc(n*sizeof(int)),
		*f=(int*)malloc(n*sizeof(int));
    Color *color=(Color*)malloc(n*sizeof(Color));
    ListNode **pos=(ListNode**)malloc(n*sizeof(ListNode*));
    for(u=0;u<n;u++){
        pi[u]=-1;
        color[u]=WHITE;
		pos[u]=g->adj[u]->nil->next;
    }
    for(s=0;s<n;s++){
        if(color[s]==WHITE){
            color[s]=GRAY;
			d[s]=++time;
            push(S,&s);
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
					d[v]=++time;
                    pi[v]=u;
                    push(S,&v);
                }else{
                    color[u]=BLACK;
                    f[u]=++time;
                    pop(S);
                }
            }
        }
    }
	*df=make_pair(d, f);
	free(pos);free(color);
    return make_pair(pi, df);
}
