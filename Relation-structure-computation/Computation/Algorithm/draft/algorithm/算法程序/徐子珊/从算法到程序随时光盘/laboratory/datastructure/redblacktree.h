/* 
 * File:   tree.h
 * Author: 徐子珊
 *
 * Created on 2010年12月10日, 下午8:53
 */

#ifndef _RBNode_H
#define	_RBNode_H

#ifdef	__cplusplus
extern "C" {
#endif
/*二叉树定义与操作*/
#include <stdlib.h>
typedef enum {RED, BLACK} Color;
typedef struct node{/*二叉树节点类型*/
    struct node *p;/*父节点指针*/
    struct node *left;/*左孩子节点指针*/
    struct node *right;/*右孩子节点指针*/
    Color color;
    void *key;/*数据域指针*/
}RBNode;
RBNode *creatRBNode(void *key, int size);/*创建节点*/
void clrRBNode(RBNode* r,void(*proc)(void*));/*清理二叉树节点*/
typedef struct{
	unsigned nodeSize;
	int (*comp)(void*, void*);
	RBNode *root;
	RBNode *nil;
}RBTree;
RBTree* creatRBTree(int size, int(*comp)(void *,void *));/*创建空树*/
void clrRBTree(RBTree *t,void(*proc)(void*));/*清理二叉树*/
void inorderRBWalk(RBTree *t, void (*proc)(void *)) ;/*中序遍历以r为根的二叉树*/
/*二叉搜索树的操作*/
RBNode* rbMini(RBTree *t);/*计算最小值*/
RBNode* rbMax(RBTree *t);/*计算最大值*/
RBNode* treeSuccessor(RBNode *r);/*计算r的后继*/
RBNode* treePredecessor(RBNode *r);/*计算r的前驱*/
RBNode* rbSearch(RBTree* t,void* k);/*在搜索树中查找*/
RBNode* rbInsert(RBTree* t,void *key);/*向搜索树插入元素*/
RBNode* rbDelete(RBTree *t,RBNode *x);
#ifdef	__cplusplus
}
#endif

#endif	/* _RBNode_H */

