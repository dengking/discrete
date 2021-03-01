/* 
 * File:   graph.h
 * Author: ?����???
 *
 * Created on 2008��12��6��, ����11:23
 */

#ifndef _GRAPH_H
#define	_GRAPH_H
#include<list>
using namespace std;
struct vertex{
    float weight;
    int index;
};
typedef struct vertex vertex;
class Graph{
public:
    list<vertex> *adj;
    int n;
    Graph(float *a, int n):n(n){
        int i,j;
        adj=new list<vertex>[n];
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(a[i*n+j]!=0.0){
                    vertex v={a[i*n+j],j};
                    adj[i].push_back(v);
                }
    }
    ~Graph(){
        delete []adj;
        adj=NULL;
    }
};
#endif	/* _GRAPH_H */

