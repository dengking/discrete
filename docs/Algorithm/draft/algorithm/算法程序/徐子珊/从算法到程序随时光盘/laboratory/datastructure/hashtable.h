/* 
 * File:   hashtable.h
 * Author: ����ɺ
 *
 * Created on 2010��12��25��, ����10:03
 */

#ifndef _HASHTABLE_H
#define	_HASHTABLE_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "list.h"
#include <string.h>
    typedef struct {/*hash��ṹ*/
        LinkedList **table; /*��λ����*/
        int m; /*��λ��*/
        int n; /*Ԫ�ظ���*/
    } HashTable;
    HashTable* createTable(int c); /*��������c����λ��hash��*/
    void clrTable(HashTable* t);
    int tbIsEmpty(HashTable* t); /*�����*/
    int hashInsert(HashTable* t, int key); /*���t�в���Ԫ��ele*/
    int inHashTable(HashTable* t, int key); /*�ڱ�t�в��ҹؼ�ֵkey*/
    int hashDelete(HashTable* t, int key); /*�ڱ�t��ɾ��Ԫ��ele*/
#ifdef	__cplusplus
}
#endif

#endif	/* _HASHTABLE_H */
