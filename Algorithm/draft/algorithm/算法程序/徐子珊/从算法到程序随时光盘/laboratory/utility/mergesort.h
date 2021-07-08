/* 
 * File:   mergesort.h
 * Author: 徐子珊
 *
 * Created on 2009年6月30, 上午10:23
 */

#ifndef _MERGESORT_H
#define	_MERGESORT_H

#ifdef	__cplusplus
extern "C" {
#endif
	void mergeSort(void *a,int size,int p,int r,int(*comp)(void *,void *));
#ifdef	__cplusplus
}
#endif

#endif	/* _MERGESORT_H */
