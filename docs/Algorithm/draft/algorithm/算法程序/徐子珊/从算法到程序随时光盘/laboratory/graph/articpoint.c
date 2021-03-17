#include "articpoint.h"
#include "../DataStructure/stack.h"
LinkedList *articPoint(Graph *g, int s){
    Stack *S=createStack(sizeof(int));
    int n=g->n,u,v,time=0,rootDegree=0;
    Color *color=(Color*)malloc(sizeof(Color));
    int *pi=(int*)malloc(n*sizeof(int)),
		*d=(int*)malloc(n*sizeof(int)),
		*low=(int*)malloc(n*sizeof(int));
	LinkedList *a=createList(sizeof(int),NULL);
    ListNode **pos=(ListNode**)malloc(n*sizeof(ListNode*));
	for(u=0;u<n;u++){
		pi[u]=-1;
		color[u]=WHITE;
		pos[u]=g->adj[u]->nil->next;
	}
    color[s]=GRAY;
    low[s]=d[s]=++time;
    push(S,&s);
    while(!stackEmpty(S)){
		ListNode *p;
		u=*(int*)(S->top->key);
        p=pos[u];
        v=(p!=g->adj[u]->nil)?((vertex*)(p->key))->index:-1;
        while(p!=g->adj[u]->nil&&color[v]!=WHITE){
            if(pi[u]!=v){//�ر�
                if(low[u]>d[v])
                    low[u]=d[v];
            }
            p=p->next;
            v=(p!=g->adj[u]->nil)?((vertex*)(p->key))->index:-1;
        }
        pos[u]=p;
        if(pos[u]!=g->adj[u]->nil){//�ҵ���ɫ���㽫��ѹ��ջS
            if(u==s)
                rootDegree++;
            color[v]=GRAY;
            low[v]=d[v]=++time;
            pi[v]=u;
            push(S,&v);
        }else{//����û����u�ڽӵĶ��㣩����ɶ�u�ķ���
            color[u]=BLACK;
            pop(S);
        }
    }
    for(u=0;u<n;u++){
        if(pi[u]!=-1)
            if(low[pi[u]]>low[u])
                low[pi[u]]=low[u];
    }
    if(rootDegree>1)
        listPushBack(a,&s);
    for(u=0;u<n;u++){
        if(pi[u]!=s&&pi[u]!=-1){
            if(low[u]>=d[pi[u]])
                listPushBack(a, pi+u);
        }
    }
    return a;
}