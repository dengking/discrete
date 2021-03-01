#include<stdlib.h>
typedef struct node{/*二叉树节点类型*/
    struct node *p;/*父节点指针*/
    struct node *left;/*左孩子节点指针*/
    struct node *right;/*右孩子节点指针*/
    void *key;/*数据域指针*/
}BTreeNode;
BTreeNode *creatBTreeNode(void *key, int size);/*创建节点*/
void clrBTreeNode(BTreeNode* r,void(*proc)(void*));/*清理二叉树节点*/
BTreeNode* creatBTree(void *k, int size, BTreeNode* l, BTreeNode* r);/*创建树*/
void clrBTree(BTreeNode *r,void(*proc)(void*));/*清理二叉树*/
void inorderTreeWalk(BTreeNode *r, void (*proc)(void *)) ;/*中序遍历以r为根的二叉树*/
void preorderTreeWalk(BTreeNode *r, void (*proc)(void *));/*前序遍历*/
void postorderTreeWalk(BTreeNode *r, void (*proc)(void *));/*后序遍历*/
