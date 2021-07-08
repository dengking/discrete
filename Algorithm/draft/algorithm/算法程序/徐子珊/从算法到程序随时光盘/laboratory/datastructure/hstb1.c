#include "hstb1.h"
#include <assert.h>
#include <stdio.h>
HashTable* CreateTable(long c){
    int i;
    HashTable *tab = (HashTable *) malloc(sizeof (HashTable));/*����ռ�*/
    assert(tab);
    tab->m =newIntByint(c);/*���ò�λ��*/
    tab->table = (LinkedList**) malloc(c * sizeof (LinkedList*));/*�����λ*/
    assert(tab->table);
    tab->n = 0;/*Ԫ�ظ�����ʼ��Ϊ0*/
    for (i = 0; i < c; i++)
        tab->table[i] = createList(sizeof(BigInt),compareInt);/*������λ����*/
    return tab;
}
void ClrTable(HashTable* t){
	size_t i,m=*((long*)(t->m.value->nil->next->key));
    for (i = 0; i < m; i++)
        clrList(t->table[i], clrBigInt); /*�����λ����*/
    free(t->table);/*�ͷŲ�λ*/
}
int TbIsEmpty(HashTable* t) {
    return t->n == 0;
}
int InHashTable(HashTable* t, BigInt key) {/*���key�Ƿ��ڱ���*/
    int index;
	BigInt Index=remainder(key,t->m);
    ListNode *node;
    if (TbIsEmpty(t))
        return 0;
	index= *((long*)(Index.value->nil->next->key));/*����key��hash����ֵ*/
	clrBigInt(&Index);
    node = listSearch(t->table[index], &key);/*��ָ����λ��ȥ����*/
    if (node!=t->table[index]->nil)/*���ҵ�*/
        return 1;
    return 0;
}
int HashInsert(HashTable* t, BigInt key) {
    if (!InHashTable(t,key)) {/*��������key*/
		BigInt Index=remainder(key, t->m);
		long index=*((long*)(Index.value->nil->next->key));/*����key��hash����ֵ*/
		clrBigInt(&Index);
        listPushFront(t->table[index], &key);/*��ָ����λ�����в���*/
        t->n++;
		return 1;
    }
    return 0;/*��������key*/
}
int HashDelete(HashTable* t, BigInt key) {
    long index;
    ListNode *node;
	BigInt Index=remainder(key,t->m);
    if (TbIsEmpty(t))
        return 0;
	index = *((long*)(Index.value->nil->next->key));/*����key��hash����ֵ*/
    node = listSearch(t->table[index], &key);/*��ָ����λ�����в���*/
    if (node!=t->table[index]->nil) {/*�ҵ�*/
        listDelete(t->table[index], node);
        t->n--;
		free(node);
		return 1;
    }
    return 0;/*������key*/
}
