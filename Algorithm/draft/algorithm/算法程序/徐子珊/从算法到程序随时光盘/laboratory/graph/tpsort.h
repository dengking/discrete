#ifndef _TPSORT_H
#define	_TPSORT_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "graph.h"
#include "../DataStructure/pair.h"
pair toplogicalSort(Graph *g);
#ifdef	__cplusplus
}
#endif

#endif	/* _TPSORT_H */
