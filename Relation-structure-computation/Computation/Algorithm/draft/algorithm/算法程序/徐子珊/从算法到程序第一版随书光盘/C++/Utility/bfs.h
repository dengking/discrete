/* 
 * File:   bfs.h
 * Author: ?����???
 *
 * Created on 2008��12��8��, ����9:00
 */

#ifndef _BFS_H
#define	_BFS_H
#include<limits>
#include<stack.h>
#include "../DataStructure/graph.h"
enum vertex_color {WHITE,GRAY,BLACK};
typedef enum vertex_color Color;
pair<int*,int*> bfs(Graph *g,int s){
    pair<int*,int*> result;
    queue<int> Q;
    int *pi,*d,i,u,v;
    Color *color;
    pi=new int[g->n];
    d=new int[g->n];
    color=new Color[g->n];
    fill(pi,pi+g->n,-1);
    fill(d,d+g->n,numeric_limits<int>::max());
    fill(color,color+g->n,WHITE);
    d[s]=0;
    color[s]=GRAY;
    Q.push(s);
    while(!Q.empty()){
        u=Q.front();
        Q.pop();
        list<vertex>::iterator q=g->adj[u].begin();
        while(q!=g->adj[u].end()){
            v=(*q).index;
            if(color[v]==WHITE){
                color[v]=GRAY;
                d[v]=d[u]+1;
                pi[v]=u;
                Q.push(v);
            }
            q++;
        }
        color[u]=BLACK;
    }
    result=make_pair(pi,d);
    return result;
}
void printPath(int *pi,int s, int v){
    if(v==s){
        cout<<s<<" ";
        return;
    }
    if(pi[v]==-1)
        cout<<"no path from "<<s<<" to  "<<v<<endl;
    else{
        printPath(pi,s,pi[v]);
        cout<<v<<" ";
    }
}
#endif	/* _BFS_H */

