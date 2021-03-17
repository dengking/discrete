/* 
 * File:   huffman.h
 * Author: 徐子珊
 *
 * Created on 2008年9月21日, 下午3:46
 */

#ifndef _HUFFMAN_H
#define	_HUFFMAN_H
#include "../DataStructure/BinTree.h"
#include "../DataStructure/queue.h"
#include "../Utility/compare.h"
struct BinaryTree *huffman(int *f,char *d,int n){
    BinaryTree *x,*y,**z=(BinaryTree**)malloc(sizeof(BinaryTree*));
    priorityQueue Q=heapAlloc(sizeof(BinaryTree*),n);
    int i;
    for(i=0;i<n;i++){
        *z=buildTree(f[i],d[i],NULL,NULL);
        enQueue(&Q,sizeof(BinaryTree*),z,treeLess);
    }
    for(i=0;i<n-1;i++){
        x=*(BinaryTree **)deQueue(&Q,sizeof(BinaryTree*),treeLess);
        y=*(BinaryTree **)deQueue(&Q,sizeof(BinaryTree*),treeLess);
        *z=buildTree(x->key+y->key,'*',x,y);
        enQueue(&Q,sizeof(BinaryTree*),z,treeLess);
    }
    x=*(BinaryTree**)deQueue(&Q,sizeof(BinaryTree*),treeLess);
    pqueueClear(&Q);
    return x;
}
void printCode( BinaryTree *root,char *c) {
    int l=strlen(c);
    char *c1=(char*)malloc((l+2)*sizeof(char));
    if (root->left!= NULL){/*向左探索*/
        strcpy(c1,c);
        strcat(c1,"0");
        printCode(root->left,c1);
    }
    if (root->right != NULL){/*向右探索*/
        strcpy(c1,c);
        strcat(c1,"1");
        printCode(root->right,c1);
    }
    if(root->left==NULL&&root->right== NULL)/*叶子节点*/
        printf("character:%c frequency: %d code: %s\n",root->data, root->key, c);
}
#endif	/* _HUFFMAN_H */

