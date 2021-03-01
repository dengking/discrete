#include<stdlib.h>
typedef struct node{/*�������ڵ�����*/
    struct node *p;/*���ڵ�ָ��*/
    struct node *left;/*���ӽڵ�ָ��*/
    struct node *right;/*�Һ��ӽڵ�ָ��*/
    void *key;/*������ָ��*/
}BTreeNode;
BTreeNode *creatBTreeNode(void *key, int size);/*�����ڵ�*/
void clrBTreeNode(BTreeNode* r,void(*proc)(void*));/*����������ڵ�*/
BTreeNode* creatBTree(void *k, int size, BTreeNode* l, BTreeNode* r);/*������*/
void clrBTree(BTreeNode *r,void(*proc)(void*));/*���������*/
void inorderTreeWalk(BTreeNode *r, void (*proc)(void *)) ;/*���������rΪ���Ķ�����*/
void preorderTreeWalk(BTreeNode *r, void (*proc)(void *));/*ǰ�����*/
void postorderTreeWalk(BTreeNode *r, void (*proc)(void *));/*�������*/
