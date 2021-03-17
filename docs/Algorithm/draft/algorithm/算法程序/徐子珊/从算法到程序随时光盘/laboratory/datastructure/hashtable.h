/* 
 * File:   hashtable.h
 * Author: 徐子珊
 *
 * Created on 2010年12月25日, 下午10:03
 */

#ifndef _HASHTABLE_H
#define	_HASHTABLE_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "list.h"
#include <string.h>
    typedef struct {/*hash表结构*/
        LinkedList **table; /*槽位数组*/
        int m; /*槽位数*/
        int n; /*元素个数*/
    } HashTable;
    HashTable* createTable(int c); /*创建具有c个槽位的hash表*/
    void clrTable(HashTable* t);
    int tbIsEmpty(HashTable* t); /*检测表空*/
    int hashInsert(HashTable* t, int key); /*向表t中插入元素ele*/
    int inHashTable(HashTable* t, int key); /*在表t中查找关键值key*/
    int hashDelete(HashTable* t, int key); /*在表t中删除元素ele*/
#ifdef	__cplusplus
}
#endif

#endif	/* _HASHTABLE_H */
