/* 
 * File:   quicksort.h
 * Author: 徐子珊
 *
 * Created on 2009年7月1日, 下午3:06
 */

#ifndef _QUICKSORT_H
#define	_QUICKSORT_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "partition.h"
	void quickSort(void* a,int size,int p,int r,int(*comp)(void *,void *));
#ifdef	__cplusplus
}
#endif

#endif	/* _QUICKSORT_H */

