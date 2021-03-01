#ifndef _SELECT_H
#define	_SELECT_H

#ifdef	__cplusplus
extern "C" {
#endif#include "partition.h"
void* select(void* a, int size, int p, int r,int i,int(*comp)(void *,void *));
#ifdef	__cplusplus
}
#endif

#endif	/* _SELECT_H */
