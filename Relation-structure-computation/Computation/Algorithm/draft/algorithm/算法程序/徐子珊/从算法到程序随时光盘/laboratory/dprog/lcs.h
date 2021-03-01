/* 
 * File:   lcs.h
 * Author: 徐子珊
 *
 * Created on 2009年7月1日, 上午10:30
 */

#ifndef _LCS_H
#define	_LCS_H

#ifdef	__cplusplus
extern "C" {
#endif
	int* lcsLength(void *x,void *y,int size, int m,int n,int(*comp)(void *,void *));
	void printLcs(int *c,int n, void *x,void *y,int size,int i,int j,int(*comp)(void *,void *),void(*prt)(void *));
#ifdef	__cplusplus
}
#endif

#endif	/* _LCS_H */

