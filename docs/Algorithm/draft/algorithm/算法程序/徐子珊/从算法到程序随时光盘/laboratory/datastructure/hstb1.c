#include "hstb1.h"
#include <assert.h>
#include <stdio.h>
HashTable* CreateTable(long c){
    int i;
    HashTable *tab = (HashTable *) malloc(sizeof (HashTable));/*分配空间*/
    assert(tab);
    tab->m =newIntByint(c);/*设置槽位数*/
    tab->table = (LinkedList**) malloc(c * sizeof (LinkedList*));/*分配槽位*/
    assert(tab->table);
    tab->n = 0;/*元素个数初始化为0*/
    for (i = 0; i < c; i++)
        tab->table[i] = createList(sizeof(BigInt),compareInt);/*创建槽位链表*/
    return tab;
}
void ClrTable(HashTable* t){
	size_t i,m=*((long*)(t->m.value->nil->next->key));
    for (i = 0; i < m; i++)
        clrList(t->table[i], clrBigInt); /*清理槽位链表*/
    free(t->table);/*释放槽位*/
}
int TbIsEmpty(HashTable* t) {
    return t->n == 0;
}
int InHashTable(HashTable* t, BigInt key) {/*检测key是否在表中*/
    int index;
	BigInt Index=remainder(key,t->m);
    ListNode *node;
    if (TbIsEmpty(t))
        return 0;
	index= *((long*)(Index.value->nil->next->key));/*计算key的hash函数值*/
	clrBigInt(&Index);
    node = listSearch(t->table[index], &key);/*到指定槽位中去查找*/
    if (node!=t->table[index]->nil)/*若找到*/
        return 1;
    return 0;
}
int HashInsert(HashTable* t, BigInt key) {
    if (!InHashTable(t,key)) {/*若表中无key*/
		BigInt Index=remainder(key, t->m);
		long index=*((long*)(Index.value->nil->next->key));/*计算key的hash函数值*/
		clrBigInt(&Index);
        listPushFront(t->table[index], &key);/*在指定槽位连表中插入*/
        t->n++;
		return 1;
    }
    return 0;/*表中已有key*/
}
int HashDelete(HashTable* t, BigInt key) {
    long index;
    ListNode *node;
	BigInt Index=remainder(key,t->m);
    if (TbIsEmpty(t))
        return 0;
	index = *((long*)(Index.value->nil->next->key));/*计算key的hash函数值*/
    node = listSearch(t->table[index], &key);/*在指定槽位连表中查找*/
    if (node!=t->table[index]->nil) {/*找到*/
        listDelete(t->table[index], node);
        t->n--;
		free(node);
		return 1;
    }
    return 0;/*表中无key*/
}
