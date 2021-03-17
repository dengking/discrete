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
    Hash_Table *tab = (Hash_Table *) malloc(sizeof (Hash_Table));/*分配空间*/
    assert(tab);
    tab->m = c;/*设置槽位数*/
    tab->table = (LinkedList**) malloc(c * sizeof (LinkedList*));/*分配槽位*/
    assert(tab->table);
    tab->n = 0;/*元素个数初始化为0*/
    for (i = 0; i < c; i++)
        tab->table[i] = createList(sizeof(unsigned long long),ulongGreater);/*创建槽位链表*/
    return tab;
}
void clrTable(Hash_Table* t){
    size_t i;
    for (i = 0; i < t->m; i++)
        clrList(t->table[i], NULL); /*清理槽位链表*/
    free(t->table);/*释放槽位*/
}
int tbIsEmpty(Hash_Table* t) {
    return t->n == 0;
}
int inHashTable(Hash_Table* t, unsigned long long key) {/*检测key是否在表中*/
    int index;
    ListNode *node;
    if (tbIsEmpty(t))
        return 0;
    index= key % (t->m);/*计算key的hash函数值*/
    node = listSearch(t->table[index], &key);/*到指定槽位中去查找*/
    if (node!=t->table[index]->nil)/*若找到*/
        return 1;
    return 0;
}
int hashInsert(Hash_Table* t, unsigned long long key) {
    if (!inHashTable(t,key)) {/*若表中无key*/
		int index=key%t->m;/*计算key的hash函数值*/
        listPushFront(t->table[index], &key);/*在指定槽位连表中插入*/
        t->n++;
		return 1;
    }
    return 0;/*表中已有key*/
}
int hashDelete(Hash_Table* t, unsigned long long key) {
    int index;
    ListNode *node;
    if (tbIsEmpty(t))
        return 0;
    index = key % t->m;/*计算key的hash函数值*/
    node = listSearch(t->table[index], &key);/*在指定槽位连表中查找*/
    if (node!=t->table[index]->nil) {/*找到*/
        listDelete(t->table[index], node);
        t->n--;
		free(node);
		return 1;
    }
    return 0;/*表中无key*/
}
