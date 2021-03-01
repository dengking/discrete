#ifndef _HSTB1_H
#define	_HSTB1_H
#ifdef	__cplusplus
extern
 "C" {
#endif
#include "list.h"
#include "./../numbertheory/bigint.h"
    typedef struct {/*hash��ṹ*/
        LinkedList **table; /*��λ����*/
        BigInt m; /*��λ��*/
        size_t n; /*Ԫ�ظ���*/
    } HashTable;
    HashTable* CreateTable(long c); /*��������c����λ��hash��*/
    void ClrTable(HashTable* t);
    int TbIsEmpty(HashTable* t); /*�����*/
    int HashInsert(HashTable* t, BigInt key); /*���t�в���Ԫ��key*/
    int InHashTable(HashTable* t, BigInt key); /*�ڱ�t�в��ҹؼ�ֵkey*/
    int HashDelete(HashTable* t, BigInt key); /*�ڱ�t��ɾ��Ԫ��key*/
#ifdef	__cplusplus
}
#endif
#endif	/* _HSTB1_H */
