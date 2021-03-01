/* 
 * File:   knapsack.h
 * Author: 徐子珊
 *
 * Created on 2009年7月2日, 下午3:32
 */

#ifndef _KNAPSACK_H
#define	_KNAPSACK_H

#ifdef	__cplusplus
extern "C" {
#endif
	int *knapsack(int *w,int *v,int n,int c);
	int *buildSolution(int *m, int n,int *w, int c);
#ifdef	__cplusplus
}
#endif

#endif	/* _KNAPSACK_H */

