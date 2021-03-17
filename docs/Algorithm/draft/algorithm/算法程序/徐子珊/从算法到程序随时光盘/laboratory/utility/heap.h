/* 
 * File:   heap.h
 * Author: ����ɺ
 *
 * Created on 2009�� 7�� 1��, ���� 4:17
 */

#ifndef _HEAP_H
#define	_HEAP_H

#ifdef	__cplusplus
extern "C" {
#endif
	int left(int i);
	int right(int i);
	int parent(int i);
	void heapify(void *a,int size,int i,int heapSize,int(*comp)(void const *,void const *));
	void buildHeap(void *a,int size, int length, int(*comp)(void const *,void const *));
#ifdef	__cplusplus
}
#endif

#endif	/* _HEAP_H */

