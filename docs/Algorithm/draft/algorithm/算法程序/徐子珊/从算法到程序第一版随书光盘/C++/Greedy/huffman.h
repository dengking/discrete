/* 
 * File:   huffman.h
 * Author: 徐子珊
 *
 * Created on 2008年9月21日, 下午3:46
 */

#ifndef _HUFFMAN_H
#define	_HUFFMAN_H
#include<stack.h>
#include "../DataStructure/BinTree.h"
#include "../Utility/compare.h"
BinaryTree *huffman(int *f,char *d,int n){
    priority_queue<BinaryTree*,
                   vector<BinaryTree*>,
                   Greater<BinaryTree> > q;//优先队列
    int i;
    for(i=0;i<n;i++)//初始化队列q
        q.push(new BinaryTree(f[i],d[i]));
    for(i=0;i<n-1;i++){
        BinaryTree *x,*y,*z;
        x=q.top(); q.pop();//弹出q的队首存于x
        y=q.top(); q.pop();//弹出q的队首存于y
        z=new BinaryTree(x->key+y->key,'*',x,y);
        q.push(z);//z插入队列q
    }
    return q.top();
}
void printCode(BinaryTree *t,string c){
    if(t->left!= NULL)//向左探索
        printCode(t->left,c+"0");
    if(t->right != NULL)//向右探索
        printCode(t->right,c+"1");
    if(t->left==NULL&&t->right== NULL)//叶子节点
        cout<<"character:"<<t->data<<" frequency:"<<t->key<<" code:"<<c<<endl;
}
#endif	/* _HUFFMAN_H */
