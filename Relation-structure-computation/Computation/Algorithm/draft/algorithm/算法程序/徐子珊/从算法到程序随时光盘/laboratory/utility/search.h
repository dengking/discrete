/* 
 * File:   search.h
 * Author: 徐子珊
 *
 * Created on 2010年10月10日, 下午4:00
 */

#ifndef _SEARCH_H
#define	_SEARCH_H

#ifdef	__cplusplus
extern "C" {
#endif
//    int linearSearch(int* a,int n, int x);
    int linearSearch(void* a,int size, int n, void* x,int(*comp)(void*,void*));
#ifdef	__cplusplus
}
#endif

#endif	/* _SEARCH_H */

