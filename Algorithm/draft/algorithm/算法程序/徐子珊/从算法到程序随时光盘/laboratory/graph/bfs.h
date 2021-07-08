/* 
 * File:   bfs.h
 * Author: 徐子珊
 *
 * Created on 2009年7月13日, 下午3:19
 */

#ifndef _BFS_H
#define	_BFS_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "graph.h"
#include "../DataStructure/pair.h"
pair bfs(Graph *g,int s);
void printPath(int *pi,int s, int v);
#ifdef	__cplusplus
}
#endif

#endif	/* _BFS_H */

