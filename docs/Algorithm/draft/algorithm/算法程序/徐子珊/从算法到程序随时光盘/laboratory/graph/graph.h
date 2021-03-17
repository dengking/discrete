/* 
 * File:   graph.h
 * Author: 徐子珊
 *
 * Created on 2009年7月13日, 下午3:15
 */

#ifndef _GRAPH_H
#define	_GRAPH_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "../datastructure/list.h"
typedef struct{
    double weight;
    int index;
} vertex;
typedef struct Graph{
    LinkedList **adj;
    int n;
} Graph;
typedef enum {WHITE,GRAY,BLACK} Color;
Graph *createGraph(double *a, int n);
Graph *zeroGraph(int n);
void graphClear(Graph *g);
Graph *transpose(Graph *g);
Graph *cloneGraph(Graph *const g);
void printGraph(Graph *g);
void addVertex(Graph *g);
void deleteVertex(Graph *g, int u);
void addEdge(Graph *g, int u, int v, double w);
void deleteEdge(Graph *g, int u, int v);
#ifdef	__cplusplus
}
#endif

#endif	/* _GRAPH_H */

