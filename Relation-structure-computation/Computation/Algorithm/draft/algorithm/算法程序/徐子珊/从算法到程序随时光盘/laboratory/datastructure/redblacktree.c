#include<string.h>
#include "redblacktree.h"
static RBNode nil={NULL,NULL,NULL,BLACK,NULL};/*�ڱ��ڵ�*/
RBNode *creatRBNode(void *key, int size) {/*�����ڵ�*/
    RBNode *x = (RBNode*) malloc(sizeof (RBNode));
    x->key = (void*) malloc(size);
    memcpy(x->key, key, size);
    x->p = x->left = x->right = &nil;
    x->color=RED;
    return x;
}
void clrRBNode(RBNode* r,void(*proc)(void*)) {/*����������ڵ�*/
    r->p = r->left = r->right = NULL;
    if(proc)
        proc(r->key);
    free(r->key);
}

RBTree  *creatRBTree(int size, int(*comp)(void *,void *)) {/*������*/
    RBTree *t = (RBTree*)malloc(sizeof(RBTree));/*����ռ�*/
	t->nodeSize=size;
	t->comp=comp;
	t->nil=&nil;
	t->root=t->nil;
    return t;
}

void clrTree(RBNode *r,void(*proc)(void*)) {/*���������*/
	if(r==&nil)
		return;
    if (r->left != &nil)/*����������*/
        clrTree(r->left,proc);
    if (r->right != &nil)/*����������*/
        clrTree(r->right,proc);
    clrRBNode(r,proc); /*�����ڵ�*/
	free(r);
}
void clrRBTree(RBTree *t,void(*proc)(void*)){
	clrTree(t->root,proc);
}
//static void inorder(RBNode *r, void(*proc)(void*)) {/*���������rΪ���Ķ�����*/
//    if(r->left!=&nil)/*����������*/
//        inorder(r->left,proc);
//    proc(r->key);/*������ڵ�����*/
//    printf("%s ",r->color==RED?"RED":"BLACK");
//    if(r->p!=&nil){
//        printf("patrent: ");
//        proc(r->p->key);
//    }else
//        printf("root ");
//    if(r->right!=&nil)/*����������*/
//        inorder(r->right,proc);
//}
static void inorder(RBNode *r, void(*proc)(void*)) {/*���������rΪ���Ķ�����*/
    if(r->left!=&nil)/*����������*/
        inorder(r->left,proc);
    proc(r->key);/*������ڵ�����*/
    if(r->right!=&nil)/*����������*/
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

static RBNode* treeMini(RBNode *t){/*����t����Сֵ�ڵ�*/
    while(t->left!=&nil)/*�ҵ�������������ߵĽڵ�*/
        t=t->left;
    return t;
}
RBNode* rbMini(RBTree *t){
	if(t->root==t->nil)
		return NULL;
	return treeMini(t->root);
}
static RBNode* treeMax(RBNode *t){/*����t�����ֵ�ڵ�*/
    while(t->right!=&nil)/*�ҵ������������ұߵĽڵ�*/
        t=t->right;
    return t;
}
RBNode* rbMax(RBTree *t){
	if(t->root==t->nil)
		return NULL;
	return treeMax(t->root);
}
RBNode* treeSuccessor(RBNode *r){/*��ڵ�r�����е���һ���ڵ�*/
	RBNode *y;
    if(r->right!=&nil)/*���������ǿ�*/
        return treeMini(r->right);/*��һ���ڵ����������е���Сֵ�ڵ�*/
    y=r->p;
    while(y!=&nil&&r==y->right){/**/
        r=y;
        y=y->p;
    }
    return y;
}

RBNode* treePredecessor(RBNode *r){/*��ڵ�r�����е���һ���ڵ�*/
	RBNode *y;
    if(r->left!=&nil)/*���������ǿ�*/
        return treeMax(r->left);/*��һ���ڵ����������е���Сֵ�ڵ�*/
    y=r->p;
    while(y!=&nil&&r==y->left){/**/
        r=y;
        y=y->p;
    }
    return y;
}

static void leftRotate(RBTree *t,RBNode *x){/*��t���Խڵ�xΪ������ת*/
    RBNode *y=x->right;/*����y*/
    x->right=y->left;/*��y������������Ϊx��������*/
    y->left->p=x;
    y->p=x->p;/*��x���ӵ�y�ĸ��ڵ�*/
    if(x->p==t->nil)
		t->root=y;
    else if(x==x->p->left)
        x->p->left=y;
    else
        x->p->right=y;
    y->left=x;/*��x��Ϊy������*/
    x->p=y;
}

static void rightRotate(RBTree *t,RBNode *x){
    RBNode *y=x->left;/*����y*/
    x->left=y->right;/*��y������������Ϊx��������*/
    y->right->p=x;
    y->p=x->p;/*��x���ӵ�y�ĸ��ڵ�*/
    if(x->p==t->nil)
		t->root=y;
    else if(x==x->p->right)
        x->p->right=y;
    else
        x->p->left=y;
    y->right=x;/*��x��Ϊy���Һ���*/
    x->p=y;
}

static void insertFixup(RBTree *t,RBNode *z){/*�������*/
    RBNode *y;
    while(z->p->color==RED)/*ֻҪz��z�ĸ��ڵ��Ϊ��ɫ*/
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
    while(x!=t->nil){/*ȷ��z�ĸ��ڵ�*/
        y=x;/*yָ����һ��x�ĸ��ڵ�*/
        if(comp(z->key,x->key)<0)
            x=x->left;
        else
            x=x->right;
    }
    z->p=y;/*z��y�ĺ���*/
    if(y==t->nil)/*t��һ�ÿ���*/
		t->root=z;
    else if(comp(z->key,y->key)<0)/*�½ڵ�Ĺؼ�ֵС�ڸ��ڵ�Ĺؼ�ֵ*/
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

