/* 
 * File:   BinTree.h
 * Author: 徐子珊
 *
 * Created on 2008年9月21日, 下午2:03
 */

#ifndef _BINTREE_H
#define	_BINTREE_H
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;
struct vertex{
    int key;
    char data;
    struct vertex *left;
    struct vertex *right;
};
void inorderWalk(struct vertex *root){
    if(root->left!=NULL)
        inorderWalk(root->left);
    printf("data:%c key:%d ",root->data,root->key);
    if(root->right!=NULL)
        inorderWalk(root->right);
}
struct vertex * buildTree(int key,char data,struct vertex *left,struct vertex *right){
    struct vertex *root=(struct vertex *)malloc(sizeof(struct vertex));
    root->key=key;
    root->data=data;
    root->left=left;
    root->right=right;
    return root;
}
template<typename T1,typename T2>
class BinaryTree{
private:
    T1 key;
    T2 data;
    BinaryTree *left;
    BinaryTree *right;
public:
    BinaryTree(T1 k,T2 d,BinaryTree *l=NULL,BinaryTree *r=NULL):key(k),data(d),left(l),right(r){}
    ~BinaryTree(){}
    bool operator>(BinaryTree a){
        return key>a.key;
    }
    T1 getKey(){
        return key;
    }
    void inorderWalk(){
        if(left!=NULL)
            left->inorderWalk();
        cout<<data<<','<<key<<' ';
        if(right!=NULL)
            right->inorderWalk();
    }
};
template<typename T1, typename T2>
class treeCompare{
public:
    bool operator ()(BinaryTree<T1,T2> *x,BinaryTree<T1,T2> *y){
        return *x>*y;
    }
};
#endif	/* _BINTREE_H */


