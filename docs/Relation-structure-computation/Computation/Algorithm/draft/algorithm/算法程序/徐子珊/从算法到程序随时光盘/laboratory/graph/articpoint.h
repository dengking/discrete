#ifndef _ARTICPOINT_H
#define	_ARTICPOINT_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "graph.h"
#include "../DataStructure/list.h"
LinkedList* articPoint(Graph *g, int s);
#ifdef	__cplusplus
}
#endif

#endif	/* _ARTICPOINT_H */
