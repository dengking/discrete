/* 
 * File:   dfs.h
 * Author: 徐子珊
 *
 * Created on 2008年12月19日, 下午4:45
 */

#ifndef _DFS_H
#define	_DFS_H
#include "../DataStructure/graph.h"
#include "../DataStructure/stack.h"
#include "../DataStructure/pair.h"
enum vertex_color {WHITE,GRAY,BLACK};
typedef enum vertex_color Color;
List *articpoint(Graph *g,int s){/*计算无向连通图的关节点*/
    int n=g->n,/*图的顶点数*/
        time=0,/*时间计数器*/
        rootDegree=0,/*根节点度数*/
        *start=(int*)malloc(sizeof(int)),/*指向根节点的指针*/
        u,v;/*临时顶点*/
    Color *color=(Color*)malloc(n*sizeof(Color));/*顶点颜色*/
    int *pi=(int*)malloc(n*sizeof(int)),/*父节点指针数组*/
        *d=(int*)malloc(n*sizeof(int)),/*发现时间数组*/
        *f=(int*)malloc(n*sizeof(int)),/*完成时间数组*/
        *low=(int*)malloc(n*sizeof(int));/*low属性数组*/
    List **pos=(List**)malloc(n*sizeof(List));/*顶点的邻接表指针数组*/
    for(u=0;u<n;u++){/*数组pi，color和pos的初始化*/
        pi[u]=-1;
        color[u]=WHITE;
        pos[u*sizeof(List*)]=g->adj[u*sizeof(List*)];
    }
    stack *S=createStack();//栈
    List* result=NULL;/*存储将返回的关节点集合的链表*/
    {color[s]=GRAY;
    low[s]=d[s]=++time;
    *start=s;}/*初始化源顶点属性*/
    push(S,&s);
    while(!isEmpty(S)){
        u=*(int*)(top(S));/*处于栈顶的顶点*/
        List *p=pos[u*sizeof(List*)];
        v=(p==NULL)?0:((vertex *)(p->data))->index;
        while(p!=NULL&&color[v]!=WHITE){/*与顶点u邻接的灰色顶点*/
           if(pi[u]!=v)//回边
                if(low[u]>d[v])
                    low[u]=d[v];
            p=p->next;
            v=(p==NULL)?0:((vertex *)(p->data))->index;
        }
        pos[u*sizeof(List*)]=p;
        if(pos[u*sizeof(List*)]!=NULL){//找到白色顶点将其压入栈S
            if(u==s)/*u是树根*/
                rootDegree++;
            color[v]=GRAY;
            low[v]=d[v]=++time;
            pi[v]=u;
            int *v1=(int*)malloc(sizeof(int));/*指向顶点v的指针*/
            *v1=v;
            push(S,v1);
        }else{//否则（没有与u邻接的顶点）则完成对u的访问
            color[u]=BLACK;
            f[u]=++time;
            pop(S);
        }
    }
    for(u=0;u<n;u++)
        if(pi[u]!=-1)
            if(low[pi[u]]>low[u])
                low[pi[u]]=low[u];
    if(rootDegree>1)
        listPushBegin(&result,start);
    for(u=0;u<n;u++)
        if(pi[u]!=s){
            if(low[u]>=d[pi[u]])
                listPushBegin(&result,pi+u);
        }
    return result;
}
pair dfsByOrder(Graph *g,int *order){
    int u,s,n=g->n,v,m=n,
        *pi=(int*)malloc(n*sizeof(int)),
        *topLogic=(int*)malloc(n*sizeof(int));
    Color *color=(Color*)malloc(n*sizeof(Color));
    List **pos=(List**)malloc(n*sizeof(List*));
    for(u=0;u<n;u++){
        pi[u]=-1;
        color[u]=WHITE;
        pos[u*sizeof(List*)]=g->adj[u*sizeof(List*)];
    }
    stack *S=createStack();//栈
    for(s=0;s<n;s++){
        if(color[order[s]]==WHITE){
            color[order[s]]=GRAY;
            push(S,&order[s]);
            while(!isEmpty(S)){
                u=*(int*)(top(S));
                List *p=pos[u*sizeof(List*)];
                v=(p!=NULL)?((vertex*)(p->data))->index:-1;
                while(p!=NULL&&color[v]!=WHITE){
                    p=p->next;
                    v=(p!=NULL)?((vertex*)(p->data))->index:-1;
                }
                pos[u*sizeof(List*)]=p;
                if(pos[u*sizeof(List*)]!=NULL){
                    color[v]=GRAY;
                    pi[v]=u;
                    int *v1=(int*)malloc(sizeof(int));/*指向顶点v的指针*/
                    *v1=v;
                    push(S,v1);
                }else{
                    color[u]=BLACK;
                    topLogic[--m]=u;
                    pop(S);
                }
            }
        }
    }
    return make_pair(pi, topLogic);
}
int isRoot(int *pi,int r,int v){
    if(v==r)//树根本身
        return 1;
    if(pi[v]==-1)//另一棵树的根
        return 0;
    return isRoot(pi,r,pi[v]);//递归检测父节点
}
void printComponents(int *pi,int n){
    int s,v;
    for(s=0;s<n;s++){
        if(pi[s]==-1){//是一棵树的根
            for(v=0;v<n;v++)//输出该树
                if(isRoot(pi,s,v))
                    printf("%d ",v);
            printf("\n");
        }
    }
}
void strongConnectedComponents(Graph *g){
    int s,n=g->n,u;
    List *t;
    pair r;
    int *pi,*order=(int*)malloc(n*sizeof(int));
    for(s=0;s<n;s++)
        order[s]=s;
    Graph *gt=transpose(g);
    r=dfsByOrder(g,order);
    order=(int*)(r.second);
    r=dfsByOrder(gt,order);
    pi=(int*)(r.first);
    printComponents(pi,gt->n);
}
#endif	/* _DFS_H */

