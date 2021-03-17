#include "hashtable.h"
#include "../utility/compare.h"
#include <assert.h>

HashTable* createTable(int c) {
    int i;
    HashTable *tab = (HashTable *) malloc(sizeof (HashTable));/*����ռ�*/
	assert(tab);
    tab->m = c;/*���ò�λ��*/
    tab->table = (LinkedList**) malloc(c * sizeof (LinkedList*));/*�����λ*/
	assert(tab->table);
    tab->n = 0;/*Ԫ�ظ�����ʼ��Ϊ0*/
    for (i = 0; i < c; i++)
        tab->table[i] = createList(sizeof(int),intGreater);/*������λ����*/
    return tab;
}

void clrTable(HashTable* t) {
    int i;
    for (i = 0; i < t->m; i++)
        clrList(t->table[i], NULL); /*�����λ����*/
    free(t->table);/*�ͷŲ�λ*/
}

int tbIsEmpty(HashTable* t) {
    return t->n == 0;
}

int inHashTable(HashTable* t, int key) {/*���key�Ƿ��ڱ���*/
    int index;
	ListNode *node;
	if (tbIsEmpty(t))
        return 0;
    index= key % (t->m);/*����key��hash����ֵ*/
    node = listSearch(t->table[index], &key);/*��ָ����λ��ȥ����*/
	if (node!=t->table[index]->nil)/*���ҵ�*/
        return 1;
    return 0;
}
int hashInsert(HashTable* t, int key) {
	if (!inHashTable(t,key)) {/*��������key*/
		int index=key%t->m;/*����key��hash����ֵ*/
        listPushFront(t->table[index], &key);/*��ָ����λ�����в���*/
        t->n++;
		return 1;
    }
	return 0;/*��������key*/
}

int hashDelete(HashTable* t, int key) {
	int index;
	ListNode *node;
    if (tbIsEmpty(t))
        return 0;
    index = key % t->m;/*����key��hash����ֵ*/
    node = listSearch(t->table[index], &key);/*��ָ����λ�����в���*/
	if (node!=t->table[index]->nil) {/*�ҵ�*/
        listDelete(t->table[index], node);
        t->n--;
		free(node);
		return 1;
    }
    return 0;/*������key*/
}

