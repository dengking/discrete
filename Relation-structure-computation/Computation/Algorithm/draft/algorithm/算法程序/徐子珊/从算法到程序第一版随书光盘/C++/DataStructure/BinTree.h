/* 
 * File:   BinTree.h
 * Author: 徐子�? *
 * Created on 2008�?�?1�? 下午2:03
 */

#ifndef _BINTREE_H
#define	_BINTREE_H
#include<iostream>
using namespace std;
class BinaryTree{
protected:
    int key;
    char data;
    BinaryTree *left;
    BinaryTree *right;
public:
    BinaryTree(int k,char d,BinaryTree *l=NULL,BinaryTree *r=NULL):key(k),data(d),left(l),right(r){}
    ~BinaryTree(){}
    bool operator>(BinaryTree a){
        return key>a.key;
    }
    void inorderWalk(){
        if(left!=NULL)
            left->inorderWalk();
        cout<<data<<','<<key<<' ';
        if(right!=NULL)
            right->inorderWalk();
    }
    void clearTree(){
        if(left==NULL&&right==NULL)
            return;
        if(left!=NULL){
            left->clearTree();
            delete left;
            left=NULL;
        }
        if(right!=NULL){
            right->clearTree();
            delete right;
            right=NULL;
        }
    }
    friend BinaryTree *huffman(int *f,char *d,int n);
    friend void printCode(BinaryTree *t,string c);
};
#endif	/* _BINTREE_H */


