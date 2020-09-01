#include "hstb.h"
#include <assert.h>
int ulongGreater(unsigned long long *a, unsigned long long *b){
    if(*a==*b)
        return 0;
    if(*a>*b)
        return 1;
    return -1;
}
Hash_Table* createTable(int c){
    int i;
    Hash_Table *tab = (Hash_Table *) malloc(sizeof (Hash_Table));/*����ռ�*/
    assert(tab);
    tab->m = c;/*���ò�λ��*/
    tab->table = (LinkedList**) malloc(c * sizeof (LinkedList*));/*�����λ*/
    assert(tab->table);
    tab->n = 0;/*Ԫ�ظ�����ʼ��Ϊ0*/
    for (i = 0; i < c; i++)
        tab->table[i] = createList(sizeof(unsigned long long),ulongGreater);/*������λ����*/
    return tab;
}
void clrTable(Hash_Table* t){
    size_t i;
    for (i = 0; i < t->m; i++)
        clrList(t->table[i], NULL); /*�����λ����*/
    free(t->table);/*�ͷŲ�λ*/
}
int tbIsEmpty(Hash_Table* t) {
    return t->n == 0;
}
int inHashTable(Hash_Table* t, unsigned long long key) {/*���key�Ƿ��ڱ���*/
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
int hashInsert(Hash_Table* t, unsigned long long key) {
    if (!inHashTable(t,key)) {/*��������key*/
		int index=key%t->m;/*����key��hash����ֵ*/
        listPushFront(t->table[index], &key);/*��ָ����λ�����в���*/
        t->n++;
		return 1;
    }
    return 0;/*��������key*/
}
int hashDelete(Hash_Table* t, unsigned long long key) {
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
