/* 
 * File:   pair.h
 * Author: 徐子珊
 *
 * Created on 2009年7月1日, 下午9:45
 */

#ifndef _PAIR_H
#define	_PAIR_H

#ifdef	__cplusplus
extern "C" {
#endif
	typedef struct {/*用来存储两个指针的结构体*/
		void *first;
		void *second;
	} pair;
	pair make_pair(void *f, void *d);
#ifdef	__cplusplus
}
#endif

#endif	/* _PAIR_H */

