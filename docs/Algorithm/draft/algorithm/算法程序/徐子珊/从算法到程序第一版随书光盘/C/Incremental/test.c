/* 
 * File:   test.c
 * Author: 徐子珊
 *
 * Created on 2008年10月9日,下午3:16
 */

#include <stdio.h>
#include<string.h>
#include "../Utility/compare.h"
#include "../Utility/merge.h"
#include "../Utility/partition.h"
#include "insertionsort.h"
/*
int main(int argc, char** argv) {
    int a[]={5,1,9,4,6,2,0,3,8,7},i;
    char *b[]={"ChongQing","ShangHai","AoMen","TianJin","BeiJing","XiangGang","TaiBei"};
    double c[]={8.5,6.3,1.7,9.2,0.5,2.3,4.1,7.4,5.9,3.7};
    insertionSort(a,10,sizeof(int),intGreater);
    for(i=0;i<10;i++)
        printf("%d ",a[i]);
    printf("\n");
    insertionSort(b,6,sizeof(char *),strLess);
    for(i=0;i<6;i++)
        printf("%s ",b[i]);
    printf("\n");
    insertionSort(c,10,sizeof(double),doubleGreater);
    for(i=0;i<10;i++)
        printf("%1.1f ",c[i]);
    printf("\n");
    return (EXIT_SUCCESS);
}

int main(int argc, char** argv) {
    int A[]={5,1,9,4,6,2,0,3,8,7},i;
    char *B[]={"ChongQing","ShangHai","AoMen","TianJin","BeiJing","XiangGang","TaiBei"};
    double C[]={8.5,6.3,1.7,9.2,0.5,2.3,4.1,7.4,5.9,3.7};
    struct Node *a,*b,*c,*t;
    a=builtList(A,10,sizeof(int));
    t=a;
    listInsertionSort(a,sizeof(int),intGreater);//对链表list做插入排序
    t=a;
    while(t!=NULL){//输出排好序的链表数据
        printf("%d ",*(int*)(t->data));
        t=t->next;
    }
    printf("\n");
    bilistClear(a);
    free(a);
    a=NULL;
    b=builtList(B,7,sizeof(char *));
    listInsertionSort(b,sizeof(char*),strLess);//对链表list做插入排序
    t=b;
    while(t!=NULL){//输出排好序的链表数据
        printf("%s ",*(char**)(t->data));
        t=t->next;
    }
    printf("\n");
    bilistClear(b);
    free(b);
    b=NULL;
    c=builtList(C,10,sizeof(double));
    listInsertionSort(c,sizeof(double),doubleGreater);//对链表list做插入排序
    t=c;
    while(t!=NULL){//输出排好序的链表数据
        printf("%1.1f ",*(double*)(t->data));
        t=t->next;
    }
    printf("\n");
    bilistClear(c);
    free(c);
    c=NULL;
    return (EXIT_SUCCESS);
}
*/

/*
int main(int argc, char** argv) {
    int a[]={1,2,5,8,9,0,3,4,6,7},i;
    char *b[]={"AoMen","BeiJing","ShangHai","ChongQing","TianJin","XiangGang"};
    double c[]={0.5,3.7,6.3,8.5,9.2,1.7,2.3,4.1,5.9,7.4};
    merge(a,sizeof(int),0,4,9,intGreater);
    for(i=0;i<10;i++)
        printf("%d ",a[i]);
    printf("\n");
    merge(b,sizeof(char *),0,2,5,strGreater);
    for(i=0;i<6;i++)
        printf("%s ",b[i]);
    printf("\n");
    merge(c,sizeof(double),0,4,9,doubleGreater);
    for(i=0;i<10;i++)
        printf("%1.1f ",c[i]);
    printf("\n");
    return 0;
}
*/
int main(int argc, char** argv) {
    int a[]={5,1,9,4,6,2,0,3,8,7},i,j;
    char *b[]={"ChongQing","AoMen","TianJin","BeiJing","XiangGang","ShangHai"};
    double c[]={8.5,6.3,1.7,9.2,0.5,2.3,4.1,7.4,5.9,3.7};
    j=partition(a,sizeof(int),0,9,intGreater);
    for(i=0;i<10;i++)
        printf("%d ",a[i]);
    printf("\n%d\n",j);
    j=partition(b,sizeof(char *),0,5,strLess);
    for(i=0;i<6;i++)
        printf("%s ",b[i]);
    printf("\n%d\n",j);
    j=partition(c,sizeof(double),0,9,doubleGreater);
    for(i=0;i<10;i++)
        printf("%1.1f ",c[i]);
    printf("\n%d\n",j);
    return 0;
}

