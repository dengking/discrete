/* 
 * File:   floyd.h
 * Author:徐子珊
 *
 * Created on 2009年7月2日, 下午3:50
 */

#ifndef _FLOYD_H
#define	_FLOYD_H

#ifdef	__cplusplus
extern "C" {
#endif
	#include "../DataStructure/pair.h"
	pair floydWarshall(double* w,int n);
	void printAllPairsShotestPath(int *pi,int n,int i,int j);
#ifdef	__cplusplus
}
#endif

#endif	/* _FLOYD_H */

