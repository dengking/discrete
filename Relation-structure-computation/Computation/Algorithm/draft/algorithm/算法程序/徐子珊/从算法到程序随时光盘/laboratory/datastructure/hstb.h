/* 
 * File:   hashtable.h
 * Author: 徐子珊
 *
 * Created on 2010年12月25日, 下午10:03
 */
#ifndef _HSTA_H
#define	_HSTA_H
#ifdef	__cplusplus
extern
 "C" {
#endif
#include "list.h"
    typedef struct {/*hash表结构*/
        LinkedList **table; /*槽位数组*/
        size_t m; /*槽位数*/
        size_t n; /*元素个数*/
    } Hash_Table;
    Hash_Table* createTable(int c); /*创建具有c个槽位的hash表*/
    void clrTable(Hash_Table* t);
    int tbIsEmpty(Hash_Table* t); /*检测表空*/
    int hashInsert(Hash_Table* t, unsigned long long key); /*向表t中插入元素ele*/
    int inHashTable(Hash_Table* t, unsigned long long key); /*在表t中查找关键值key*/
    int hashDelete(Hash_Table* t, int unsigned long long); /*在表t中删除元素ele*/
#ifdef	__cplusplus
}
#endif
#endif	/* _HSTA_H */
