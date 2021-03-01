/* 
 * File:   dfs.h
 * Author: 徐子珊
 *
 * Created on 2009年7月13日, 下午4:18
 */

#ifndef _SCC_H
#define	_SCC_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "graph.h"
LinkedList *strongConnectedComponents(Graph *g);
#ifdef	__cplusplus
}
#endif

#endif	/* _SCC_H */

