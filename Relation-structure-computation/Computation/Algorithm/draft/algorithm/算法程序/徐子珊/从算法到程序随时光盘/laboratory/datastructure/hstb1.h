#ifndef _HSTB1_H
#define	_HSTB1_H
#ifdef	__cplusplus
extern
 "C" {
#endif
#include "list.h"
#include "./../numbertheory/bigint.h"
    typedef struct {/*hash表结构*/
        LinkedList **table; /*槽位数组*/
        BigInt m; /*槽位数*/
        size_t n; /*元素个数*/
    } HashTable;
    HashTable* CreateTable(long c); /*创建具有c个槽位的hash表*/
    void ClrTable(HashTable* t);
    int TbIsEmpty(HashTable* t); /*检测表空*/
    int HashInsert(HashTable* t, BigInt key); /*向表t中插入元素key*/
    int InHashTable(HashTable* t, BigInt key); /*在表t中查找关键值key*/
    int HashDelete(HashTable* t, BigInt key); /*在表t中删除元素key*/
#ifdef	__cplusplus
}
#endif
#endif	/* _HSTB1_H */
