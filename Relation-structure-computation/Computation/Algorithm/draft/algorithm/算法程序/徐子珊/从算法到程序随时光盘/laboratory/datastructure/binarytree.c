#include "binarytree.h"
#include <string.h>
BTreeNode *creatBTreeNode(void *key, int size) {/*�����ڵ�*/
    BTreeNode *x = (BTreeNode*) malloc(sizeof (BTreeNode));
    x->key = (void*) malloc(size);
    memcpy(x->key, key, size);
    x->p = x->left = x->right = NULL;
    return x;
}

void clrBTreeNode(BTreeNode* r,void(*proc)(void*)) {/*����������ڵ�*/
    r->p = r->left = r->right = NULL;
    if(proc)
        proc(r->key);
    free(r->key);
}
BTreeNode *creatBTree(void *k, int size, BTreeNode* l, BTreeNode* r) {/*������*/
    BTreeNode *t= creatBTreeNode(k,size);/*���ɸ��ڵ�*/
    t->left = l;/*���ø��ڵ������*/
    t->right = r;/*���ø��ڵ���Һ���*/
	if(l)
		l->p=t;/*�������Һ��ӵĸ��ڵ�*/
	if(r)
		r->p=t;
    return t;
}
void clrBTree(BTreeNode *r,void(*proc)(void*)){
    if (r->left)/*����������*/
        clrBTree(r->left,proc);
    if (r->right)/*����������*/
        clrBTree(r->right,proc);
    clrBTreeNode(r,proc); /*�����ڵ�*/
	free(r);
}

void inorderTreeWalk(BTreeNode *r, void (*proc)(void *)) {/*���������rΪ���Ķ�����*/
	if(!r)
		return;
	inorderTreeWalk(r->left,proc);
	proc(r->key);
	inorderTreeWalk(r->right,proc);
}
void preorderTreeWalk(BTreeNode *r, void (*proc)(void *)){/*ǰ�����*/
	if(!r)
		return;
	proc(r->key);
	preorderTreeWalk(r->left,proc);
	preorderTreeWalk(r->right,proc);
}
void postorderTreeWalk(BTreeNode *r, void (*proc)(void *)){/*�������*/
	if(!r)
		return;
	postorderTreeWalk(r->left,proc);
	postorderTreeWalk(r->right,proc);
	proc(r->key);
}
