/* 
 * File:   BinTree.h
 * Author: 徐子�? *
 * Created on 2008�?�?1�? 下午2:03
 */

#ifndef _BINTREE_H
#define	_BINTREE_H
#include<stdlib.h>
struct BinaryTree {
    int key;
    char data;
    struct BinaryTree *left;
    struct BinaryTree *right;
};
typedef  struct BinaryTree BinaryTree;
BinaryTree* buildTree(int k,char d,BinaryTree *l,BinaryTree *r){
    BinaryTree *root = (BinaryTree *) malloc(sizeof (BinaryTree));
    root->key = k;
    root->data = d;
    root->left = l;
    root->right = r;
    return root;
}
void inorderWalk( BinaryTree *root) {
    if (root->left != NULL)
        inorderWalk(root->left);
    printf("%c,%d ", root->data, root->key);
    if (root->right != NULL)
        inorderWalk(root->right);
}
void clearTree(BinaryTree *root){
    if(root->left==NULL&&root->right==NULL)//叶子节点
        return;
    if(root->left!=NULL){//清理左孩子
        clearTree(root->left);
        free(root->left);
        root->left=NULL;
    }
    if(root->right!=NULL){//清理右孩子
        clearTree(root->right);
        free(root->right);
        root->right=NULL;
    }
}
#endif	/* _BINTREE_H */


