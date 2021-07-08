/* 
 * File:   dfs.h
 * Author: 徐子珊
 *
 * Created on 2008年12月8日, 下午8:55
 */

#ifndef _DFS_H
#define	_DFS_H
#include<stack.h>
#include "../DataStructure/graph.h"
enum vertex_color {WHITE,GRAY,BLACK};
typedef enum vertex_color Color;
//pair<int*,pair<int*,int*> > dfs(Graph& g){//DFS的迭代版本
//    int n=g.n,u,v,s;
//    Color *color=new Color[n];
//    int *pi=new int[n],*d=new int[n],*f=new int[n],time=0;
//    fill(pi,pi+n,-1);
//    fill(color,color+n,WHITE);
//    list<vertex>::iterator *pos=new list<vertex>::iterator[n];
//    for(u=0;u<n;u++)
//	pos[u]=g.adj[u].begin();
//    stack<int> S;//栈
//    for(s=0;s<n;s++){
//        if(color[s]==WHITE){//以顶点i为根创建一棵深度优先树
//            color[s]=GRAY;
//            d[s]=++time;
//            S.push(s);
//            while(!S.empty()){
//                u=S.top();
//                while(pos[u]!=g.adj[u].end()&&color[(*(pos[u])).index]!=WHITE)
//                    pos[u]++;//u的邻接点中找尚存的未发现顶点
//                if(pos[u]!=g.adj[u].end()){//找到将其压入栈s
//                    v=(*pos[u]).index;
//                    color[v]=GRAY;
//                    d[v]=++time;
//                    pi[v]=u;
//                    S.push(v);
//                }else{//否则（没有与u邻接的顶点）则完成对u的访问
//                    color[u]=BLACK;
//                    f[u]=++time;
//                    S.pop();
//                    pos[u]=g.adj[u].begin();//完成访问的顶点，其邻接链表指针应还原
//                }
//            }
//        }
//    }
//    return make_pair(pi,make_pair(d,f));
//}
//vector<int> articpoint(Graph& g, int s){//计算无向连通图的关节点
//    vector<int> result;
//    int n=g.n,u,v,time=0,rootDegree=0;
//    Color *color=new Color[n];
//    int *pi=new int[n],*d=new int[n],*low=new int[n];
//    fill(pi,pi+n,-1);
//    fill(color,color+n,WHITE);
//    list<vertex>::iterator *pos=new list<vertex>::iterator[n];
//    for(u=0;u<n;u++)
//	pos[u]=g.adj[u].begin();
//    stack<int> S;//栈
//    color[s]=GRAY;
//    low[s]=d[s]=++time;
//    S.push(s);
//    while(!S.empty()){
//        u=S.top();
//        list<vertex>::iterator p=pos[u];
//        v=(p!=g.adj[u].end())?((*p).index):-1;
//        while(p!=g.adj[u].end()&&color[v]!=WHITE){
//           if(pi[u]!=v){//回边
//                if(low[u]>d[v])
//                    low[u]=d[v];
//            }
//            p++;
//            v=(p!=g.adj[u].end())?((*p).index):-1;
//        }
//        pos[u]=p;
//        if(pos[u]!=g.adj[u].end()){//找到白色顶点将其压入栈S
//            if(u==s)
//                rootDegree++;
//            color[v]=GRAY;
//            low[v]=d[v]=++time;
//            pi[v]=u;
//            S.push(v);
//        }else{//否则（没有与u邻接的顶点）则完成对u的访问
//            color[u]=BLACK;
//            S.pop();
//        }
//    }
//    for(u=0;u<n;u++){
//        if(pi[u]!=-1)
//            if(low[pi[u]]>low[u])
//                low[pi[u]]=low[u];
//    }
//    if(rootDegree>1)
//        result.push_back(s);
//    for(u=0;u<n;u++){
//        if(pi[u]!=s){
//            if(low[u]>=d[pi[u]])
//                result.push_back(pi[u]);
//        }
//    }
//    return result;
//}
pair<int*,pair<int*,int*> > dfs(Graph& g){//DFS的迭代版本
    int n=g.n,u,v,s,count;
    Color *color=new Color[n];
    int *pi=new int[n],*d=new int[n],*f=new int[n],time=0;
    fill(pi,pi+n,-1);
    fill(color,color+n,WHITE);
    list<vertex>::iterator pos;
    stack<int> S;//栈
    for(s=0;s<n;s++){
        if(color[s]==WHITE){//以顶点s为根创建一棵深度优先树
            color[s]=GRAY;
            d[s]=++time;
            S.push(s);
            while(!S.empty()){
                u=S.top();
                count=0;
                for(pos=g.adj[u].begin();pos!=g.adj[u].end();pos++){
                    v=(*pos).index;
                    if(color[v]==WHITE){//找到与u邻接的白色顶点将其压入栈s
                        color[v]=GRAY;
                        d[v]=++time;
                        pi[v]=u;
                        S.push(v);
                        count++;
                   }
                }
                if(count==0){//否则（没有与u邻接的顶点）则完成对u的访问
                    color[u]=BLACK;
                    f[u]=++time;
                    S.pop();
                }
            }
        }
    }
    return make_pair(pi,make_pair(d,f));
}
vector<int> articpoint(Graph& g, int s){//计算无向连通图的关节点
    vector<int> result;
    int n=g.n,u,v,time=0,rootDegree=0;
    Color *color=new Color[n];
    int *pi=new int[n],*d=new int[n],*low=new int[n];
    fill(pi,pi+n,-1);
    fill(color,color+n,WHITE);
    list<vertex>::iterator pos;
    stack<int> S;//栈
    color[s]=GRAY;
    low[s]=d[s]=++time;
    S.push(s);
    while(!S.empty()){
        u=S.top();
        list<vertex>::iterator p=pos[u];
        v=(p!=g.adj[u].end())?((*p).index):-1;
        while(p!=g.adj[u].end()&&color[v]!=WHITE){
           if(pi[u]!=v){//回边
                if(low[u]>d[v])
                    low[u]=d[v];
            }
            p++;
            v=(p!=g.adj[u].end())?((*p).index):-1;
        }
        pos[u]=p;
        if(pos[u]!=g.adj[u].end()){//找到白色顶点将其压入栈S
            if(u==s)
                rootDegree++;
            color[v]=GRAY;
            low[v]=d[v]=++time;
            pi[v]=u;
            S.push(v);
        }else{//否则（没有与u邻接的顶点）则完成对u的访问
            color[u]=BLACK;
            S.pop();
        }
    }
    for(u=0;u<n;u++){
        if(pi[u]!=-1)
            if(low[pi[u]]>low[u])
                low[pi[u]]=low[u];
    }
    if(rootDegree>1)
        result.push_back(s);
    for(u=0;u<n;u++){
        if(pi[u]!=s){
            if(low[u]>=d[pi[u]])
                result.push_back(pi[u]);
        }
    }
    return result;
}
#endif	/* _DFS_H */

