/* 
 * File:   tree.h
 * Author: ����ɺ
 *
 * Created on 2010��12��10��, ����8:53
 */

#ifndef _RBNode_H
#define	_RBNode_H

#ifdef	__cplusplus
extern "C" {
#endif
/*���������������*/
#include <stdlib.h>
typedef enum {RED, BLACK} Color;
typedef struct node{/*�������ڵ�����*/
    struct node *p;/*���ڵ�ָ��*/
    struct node *left;/*���ӽڵ�ָ��*/
    struct node *right;/*�Һ��ӽڵ�ָ��*/
    Color color;
    void *key;/*������ָ��*/
}RBNode;
RBNode *creatRBNode(void *key, int size);/*�����ڵ�*/
void clrRBNode(RBNode* r,void(*proc)(void*));/*����������ڵ�*/
typedef struct{
	unsigned nodeSize;
	int (*comp)(void*, void*);
	RBNode *root;
	RBNode *nil;
}RBTree;
RBTree* creatRBTree(int size, int(*comp)(void *,void *));/*��������*/
void clrRBTree(RBTree *t,void(*proc)(void*));/*���������*/
void inorderRBWalk(RBTree *t, void (*proc)(void *)) ;/*���������rΪ���Ķ�����*/
/*�����������Ĳ���*/
RBNode* rbMini(RBTree *t);/*������Сֵ*/
RBNode* rbMax(RBTree *t);/*�������ֵ*/
RBNode* treeSuccessor(RBNode *r);/*����r�ĺ��*/
RBNode* treePredecessor(RBNode *r);/*����r��ǰ��*/
RBNode* rbSearch(RBTree* t,void* k);/*���������в���*/
RBNode* rbInsert(RBTree* t,void *key);/*������������Ԫ��*/
RBNode* rbDelete(RBTree *t,RBNode *x);
#ifdef	__cplusplus
}
#endif

#endif	/* _RBNode_H */

