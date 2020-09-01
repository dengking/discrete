/* 
 * File:   dijkstra.h
 * Author: 徐子珊
 *
 * Created on 2009年7月9日, 下午4:10
 */

#ifndef _DIJKSTRA_H
#define	_DIJKSTRA_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "../DataStructure/pair.h"
#define dblinfy DBL_MAX
pair dijkstra(double *w, int n, int s);
void printPath(int *pi,int s, int i);
#ifdef	__cplusplus
}
#endif

#endif	/* _DIJKSTRA_H */

