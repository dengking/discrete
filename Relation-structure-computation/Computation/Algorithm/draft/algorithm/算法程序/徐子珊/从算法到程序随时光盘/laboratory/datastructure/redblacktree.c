#include<string.h>
#include "redblacktree.h"
static RBNode nil={NULL,NULL,NULL,BLACK,NULL};/*哨兵节点*/
RBNode *creatRBNode(void *key, int size) {/*创建节点*/
    RBNode *x = (RBNode*) malloc(sizeof (RBNode));
    x->key = (void*) malloc(size);
    memcpy(x->key, key, size);
    x->p = x->left = x->right = &nil;
    x->color=RED;
    return x;
}
void clrRBNode(RBNode* r,void(*proc)(void*)) {/*清理二叉树节点*/
    r->p = r->left = r->right = NULL;
    if(proc)
        proc(r->key);
    free(r->key);
}

RBTree  *creatRBTree(int size, int(*comp)(void *,void *)) {/*创建树*/
    RBTree *t = (RBTree*)malloc(sizeof(RBTree));/*分配空间*/
	t->nodeSize=size;
	t->comp=comp;
	t->nil=&nil;
	t->root=t->nil;
    return t;
}

void clrTree(RBNode *r,void(*proc)(void*)) {/*清理二叉树*/
	if(r==&nil)
		return;
    if (r->left != &nil)/*清理左子树*/
        clrTree(r->left,proc);
    if (r->right != &nil)/*清理右子树*/
        clrTree(r->right,proc);
    clrRBNode(r,proc); /*清理本节点*/
	free(r);
}
void clrRBTree(RBTree *t,void(*proc)(void*)){
	clrTree(t->root,proc);
}
//static void inorder(RBNode *r, void(*proc)(void*)) {/*中序遍历以r为根的二叉树*/
//    if(r->left!=&nil)/*遍历左子树*/
//        inorder(r->left,proc);
//    proc(r->key);/*处理根节点数据*/
//    printf("%s ",r->color==RED?"RED":"BLACK");
//    if(r->p!=&nil){
//        printf("patrent: ");
//        proc(r->p->key);
//    }else
//        printf("root ");
//    if(r->right!=&nil)/*遍历右子树*/
//        inorder(r->right,proc);
//}
static void inorder(RBNode *r, void(*proc)(void*)) {/*中序遍历以r为根的二叉树*/
    if(r->left!=&nil)/*遍历左子树*/
        inorder(r->left,proc);
    proc(r->key);/*处理根节点数据*/
    if(r->right!=&nil)/*遍历右子树*/
        inorder(r->right,proc);
}
void inorderRBWalk(RBTree *t, void (*proc)(void *)) {
	if(t->root==t->nil)
        return;
	inorder(t->root,proc);
}
RBNode* rbSearch(RBTree* t,void* k){
	int contrast;
	RBNode *r=t->root;
	while(r!=t->nil&&(contrast=t->comp(r->key,k))){
		if(contrast>0)
			r=r->left;
		else
			r=r->right;
	}
	if(r==t->nil)
        return &nil;
	return r;
}

static RBNode* treeMini(RBNode *t){/*求树t中最小值节点*/
    while(t->left!=&nil)/*找到左子树中最左边的节点*/
        t=t->left;
    return t;
}
RBNode* rbMini(RBTree *t){
	if(t->root==t->nil)
		return NULL;
	return treeMini(t->root);
}
static RBNode* treeMax(RBNode *t){/*求树t中最大值节点*/
    while(t->right!=&nil)/*找到右子树中最右边的节点*/
        t=t->right;
    return t;
}
RBNode* rbMax(RBTree *t){
	if(t->root==t->nil)
		return NULL;
	return treeMax(t->root);
}
RBNode* treeSuccessor(RBNode *r){/*求节点r在树中的下一个节点*/
	RBNode *y;
    if(r->right!=&nil)/*若右子树非空*/
        return treeMini(r->right);/*下一个节点是右子树中的最小值节点*/
    y=r->p;
    while(y!=&nil&&r==y->right){/**/
        r=y;
        y=y->p;
    }
    return y;
}

RBNode* treePredecessor(RBNode *r){/*求节点r在树中的下一个节点*/
	RBNode *y;
    if(r->left!=&nil)/*若右子树非空*/
        return treeMax(r->left);/*下一个节点是右子树中的最小值节点*/
    y=r->p;
    while(y!=&nil&&r==y->left){/**/
        r=y;
        y=y->p;
    }
    return y;
}

static void leftRotate(RBTree *t,RBNode *x){/*树t中以节点x为轴左旋转*/
    RBNode *y=x->right;/*设置y*/
    x->right=y->left;/*将y的左子树设置为x的右子树*/
    y->left->p=x;
    y->p=x->p;/*将x链接到y的父节点*/
    if(x->p==t->nil)
		t->root=y;
    else if(x==x->p->left)
        x->p->left=y;
    else
        x->p->right=y;
    y->left=x;/*将x置为y的左孩子*/
    x->p=y;
}

static void rightRotate(RBTree *t,RBNode *x){
    RBNode *y=x->left;/*设置y*/
    x->left=y->right;/*将y的右子树设置为x的左子树*/
    y->right->p=x;
    y->p=x->p;/*将x链接到y的父节点*/
    if(x->p==t->nil)
		t->root=y;
    else if(x==x->p->right)
        x->p->right=y;
    else
        x->p->left=y;
    y->right=x;/*将x置为y的右孩子*/
    x->p=y;
}

static void insertFixup(RBTree *t,RBNode *z){/*插入调整*/
    RBNode *y;
    while(z->p->color==RED)/*只要z和z的父节点均为红色*/
        if(z->p==z->p->p->left){
            y=z->p->p->right;
            if(y->color==RED){
                z->p->color=BLACK;
                y->color=BLACK;
                z->p->p->color=RED;
                z=z->p->p;
            }else{
                if(z==z->p->right){
                    z=z->p;
                    leftRotate(t,z);
                }
                z->p->color=BLACK;
                z->p->p->color=RED;
                rightRotate(t,z->p->p);
            }
        }else{
            y=z->p->p->left;
            if(y->color==RED){
                z->p->color=BLACK;
                y->color=BLACK;
                z->p->p->color=RED;
                z=z->p->p;
            }else{
                if(z==z->p->left){
                    z=z->p;
                    rightRotate(t,z);
                }
                z->p->color=BLACK;
                z->p->p->color=RED;
                leftRotate(t,z->p->p);
            }
        }
		t->root->color=BLACK;
}

RBNode* rbInsert(RBTree* t,void *data){
	int size=t->nodeSize;
	RBNode *x=t->root,*y=t->nil,*z=creatRBNode(data,size),*v=z;
	int (*comp)(void*,void*)=t->comp;
    while(x!=t->nil){/*确定z的父节点*/
        y=x;/*y指向下一轮x的父节点*/
        if(comp(z->key,x->key)<0)
            x=x->left;
        else
            x=x->right;
    }
    z->p=y;/*z是y的孩子*/
    if(y==t->nil)/*t是一棵空树*/
		t->root=z;
    else if(comp(z->key,y->key)<0)/*新节点的关键值小于父节点的关键值*/
        y->left=z;
    else
        y->right=z;
    z->color=RED;
	insertFixup(t,z);
	return v;
}

static void deleteFixup(RBTree *t,RBNode *x){
    RBNode *w;
	while((x!=t->root)&&(x->color==BLACK))
        if(x==(x->p->left)){
            w=x->p->right;
            if(w->color==RED){
                w->color=BLACK;
                x->p->color=RED;
                leftRotate(t,x->p);
                w=x->p->right;
            }
            if((w->left->color==BLACK)&&(w->right->color==BLACK)){
                w->color=RED;
                x=x->p;
            }else{
                if(w->right->color==BLACK){
                    w->left->color=BLACK;
                    w->color=RED;
                    rightRotate(t,w);
                    w=x->p->right;
                }
                w->color=x->p->color;
                x->p->color=BLACK;
                if(w!=t->nil)
                w->right->color=BLACK;
                leftRotate(t,x->p);
				x=t->root;
            }
        }else{
            w=x->p->left;
            if(w->color==RED){
                w->color=BLACK;
                x->p->color=RED;
                rightRotate(t,x->p);
                w=x->p->left;
            }
            if(w->right->color==BLACK&&w->left->color==BLACK){
                w->color=RED;
                x=x->p;
            }else{
                if(w->left->color==BLACK){
                    w->right->color=BLACK;
                    w->color=RED;
                    leftRotate(t,w);
                    w=x->p->left;
                }
                w->color=x->p->color;
                x->p->color=BLACK;
                if(w!=t->nil)
                    w->left->color=BLACK;
                rightRotate(t,x->p);
				x=t->root;
            }
        }
    x->color=BLACK;
}

RBNode* rbDelete(RBTree *t,RBNode *z){
    RBNode *y,*x;
    if(z->left==t->nil||z->right==t->nil)
        y=z;
    else
        y=treeSuccessor(z);
    if(y->left!=t->nil)
        x=y->left;
    else
        x=y->right;
    x->p=y->p;
    if(y->p==t->nil)
		t->root=x;
    else if(y==y->p->left)
        y->p->left=x;
    else
        y->p->right=x;
    if(y!=z)
		memcpy(z->key,y->key,t->nodeSize);
    if(y->color==BLACK&&x!=t->nil)
		deleteFixup(t,x);
    return y;
}

