#include "binarytree.h"
#include <string.h>
BTreeNode *creatBTreeNode(void *key, int size) {/*创建节点*/
    BTreeNode *x = (BTreeNode*) malloc(sizeof (BTreeNode));
    x->key = (void*) malloc(size);
    memcpy(x->key, key, size);
    x->p = x->left = x->right = NULL;
    return x;
}

void clrBTreeNode(BTreeNode* r,void(*proc)(void*)) {/*清理二叉树节点*/
    r->p = r->left = r->right = NULL;
    if(proc)
        proc(r->key);
    free(r->key);
}
BTreeNode *creatBTree(void *k, int size, BTreeNode* l, BTreeNode* r) {/*创建树*/
    BTreeNode *t= creatBTreeNode(k,size);/*生成根节点*/
    t->left = l;/*设置根节点的左孩子*/
    t->right = r;/*设置根节点的右孩子*/
	if(l)
		l->p=t;/*设置左、右孩子的父节点*/
	if(r)
		r->p=t;
    return t;
}
void clrBTree(BTreeNode *r,void(*proc)(void*)){
    if (r->left)/*清理左子树*/
        clrBTree(r->left,proc);
    if (r->right)/*清理右子树*/
        clrBTree(r->right,proc);
    clrBTreeNode(r,proc); /*清理本节点*/
	free(r);
}

void inorderTreeWalk(BTreeNode *r, void (*proc)(void *)) {/*中序遍历以r为根的二叉树*/
	if(!r)
		return;
	inorderTreeWalk(r->left,proc);
	proc(r->key);
	inorderTreeWalk(r->right,proc);
}
void preorderTreeWalk(BTreeNode *r, void (*proc)(void *)){/*前序遍历*/
	if(!r)
		return;
	proc(r->key);
	preorderTreeWalk(r->left,proc);
	preorderTreeWalk(r->right,proc);
}
void postorderTreeWalk(BTreeNode *r, void (*proc)(void *)){/*后序遍历*/
	if(!r)
		return;
	postorderTreeWalk(r->left,proc);
	postorderTreeWalk(r->right,proc);
	proc(r->key);
}
