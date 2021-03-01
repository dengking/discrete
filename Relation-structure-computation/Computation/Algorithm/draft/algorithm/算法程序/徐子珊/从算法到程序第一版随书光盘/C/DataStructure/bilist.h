/* 
 * File:   bilist.h
 * Author:  徐子珊
 *
 * Created on 2008年10月10日, 上午9:04
 */

#ifndef _BILIST_H
#define	_BILIST_H
struct Node{
    void* data;
    struct Node* pre;
    struct Node* next;
};
typedef struct Node Node;
Node* builtList(void *array,int n,int size){
    int i;
    Node *l=(Node *)malloc(sizeof(Node)),*p,*t;
    l->data=(void*)malloc(size);
    memcpy(l->data,array,size);/*设置链表头节点*/
    l->pre=l->next=NULL;
    t=l;/*t指向链表尾节点*/
    for(i=1;i<n;i++){/*依次设置链表中的各节点*/
        p=(Node *)malloc(sizeof(Node));/*分配空间*/
        t->next=p;/*链接到链表尾部*/
        p->next=NULL;/*尾节点next域置空*/
        p->data=(void*)malloc(size);
        memcpy(p->data,array+i*size,size);/*设置节点中的数据*/
        p->pre=t;/*链接前序节点*/
        t=p;/*修改尾节点指针*/
    }
    return l;
}
void bilistClear(Node *bl){
    if(bl->data!=NULL){
        free((char*)bl->data);
        bl->data=NULL;
    }
    if(bl->pre!=NULL)
        bl->pre->next=NULL;
    bl->pre=NULL;
    if(bl->next==NULL)
        return;
    bilistClear(bl->next);
    free(bl->next);
    bl->next=NULL;
}
typedef struct List{
    void *data;
    struct List* next;
};
typedef struct List List;
void listPushBegin(List **l,void *e){
    List *p=(List*)malloc(sizeof(List));
    p->data=e;
    p->next=*l;
    *l=p;
}
void listPushBack(List **l,void *e){
    List *p=(List*)malloc(sizeof(List));
    p->data=e;
    p->next=NULL;
    if(*l!=NULL)
        (*l)->next=p;
    *l=p;
}
void *listDeleteBeging(List **l){
    void *e=NULL;
    if(*l!=NULL){
        e=(*l)->data;
        *l=(*l)->next;
    }
    return e;
}
void listClear(List *l){
    if(l->data!=NULL){/*清理数据域*/
        free(l->data);
        l->data=NULL;
    }
    if(l->next==NULL)/*无后继*/
        return;
    listClear(l->next);/*清理后继*/
    free(l->next);
    l->next=NULL;
}
#endif	/* _BILIST_H */
