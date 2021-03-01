/* 
 * File:   hashtable.h
 * Author: ����ɺ
 *
 * Created on 2010��12��25��, ����10:03
 */
#ifndef _HSTA_H
#define	_HSTA_H
#ifdef	__cplusplus
extern
 "C" {
#endif
#include "list.h"
    typedef struct {/*hash��ṹ*/
        LinkedList **table; /*��λ����*/
        size_t m; /*��λ��*/
        size_t n; /*Ԫ�ظ���*/
    } Hash_Table;
    Hash_Table* createTable(int c); /*��������c����λ��hash��*/
    void clrTable(Hash_Table* t);
    int tbIsEmpty(Hash_Table* t); /*�����*/
    int hashInsert(Hash_Table* t, unsigned long long key); /*���t�в���Ԫ��ele*/
    int inHashTable(Hash_Table* t, unsigned long long key); /*�ڱ�t�в��ҹؼ�ֵkey*/
    int hashDelete(Hash_Table* t, int unsigned long long); /*�ڱ�t��ɾ��Ԫ��ele*/
#ifdef	__cplusplus
}
#endif
#endif	/* _HSTA_H */
