/* 
 * File:   mergesort.h
 * Author: ����ɺ
 *
 * Created on 2009��6��30, ����10:23
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
