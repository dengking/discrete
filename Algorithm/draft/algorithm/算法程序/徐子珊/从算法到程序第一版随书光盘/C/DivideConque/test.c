/* 
 * File:   test.c
 * Author: 徐子珊
 *
 * Created on 2008年10月19日, 下午5:23
 */

#include <stdio.h>
#include <stdlib.h>
#include "../Utility/compare.h"
#include "quicksort.h"
/*
#include "hanoi.h"
int main(int argc, char** argv) {
    disk disks[]={{'A','C'},{'A','A'},{'A','B'},{'B','B'},{'B','B'}};
    char A='A',B='B',C='C';
    newHanoi(disks,5);
    return (EXIT_SUCCESS);
}
*/
/*
#include "mergesort.h"
*/
/*
#include "heapsort.h"
#include<time.h>
int main(int argc, char** argv) {
    srand((int)time(0));
    int a[]={5,1,9,4,6,2,0,3,8,7},i;
    char *b[]={"ChongQing","ShangHai","AoMen","TianJin","BeiJing","XiangGang","TaiBei"};
    double c[]={8.5,6.3,1.7,9.2,0.5,2.3,4.1,7.4,5.9,3.7};
    mergeSort(a,sizeof(int),0,9,intGreater);
    quickSort(a,sizeof(int),0,9,intCompare);
    heapSort(a,sizeof(int),10,intGreater);
    for(i=0;i<10;i++)
        printf("%d ",a[i]);
    printf("\n");
    mergeSort(b,sizeof(char *),0,6,strLess);
    quickSort(b,sizeof(char *),0,5,strCompare);
    heapSort(b,sizeof(char *),6,strLess);
    for(i=0;i<6;i++)
        printf("%s ",b[i]);
    printf("\n");
    mergeSort(c,sizeof(double),0,9,doubleGreater);
    quickSort(c,sizeof(double),0,9,doubleCompare);
    heapSort(c,sizeof(double),10,doubleGreater);
    for(i=0;i<10;i++)
        printf("%1.1f ",c[i]);
    printf("\n");
    return (EXIT_SUCCESS);
}
*/
/*
#include "../Utility/heap.h"
int main(int argc, char** argv) {
    int h[]={4,1,3,2,16,9,10,14,8,7},i;
    buildHeap(h,sizeof(int),10,intLess);
    printf("max heap:\n");
    for(i=0;i<10;i++)
        printf("%d ",h[i]);
    printf("\n");
    buildHeap(h,sizeof(int),10,intGreater);
    printf("min heap:\n");
    for(i=0;i<10;i++)
        printf("%d ",h[i]);
    printf("\n");
    return (EXIT_SUCCESS);
}
*/
/*
#include "mergesort.h"
int main(int argc, char** argv) {
    srand((int)time(0));
    int a[]={5,1,9,4,6,2,0,3,8,7},i;
    char *b[]={"ChongQing","ShangHai","AoMen","TianJin","BeiJing","XiangGang","TaiBei"};
    double c[]={8.5,6.3,1.7,9.2,0.5,2.3,4.1,7.4,5.9,3.7};
    quickSort(a,sizeof(int),0,9,intLess);
    mergeSort(a,sizeof(int),0,9,intLess);
    heapSort(a,sizeof(int),10,intLess);
    for(i=0;i<10;i++)
        printf("%d ",a[i]);
    printf("\n");
    quickSort(b,sizeof(char *),0,5,strGreater);
    mergeSort(b,sizeof(char *),0,5,strGreater);
    heapSort(b,sizeof(char*),6,strCompare);
    for(i=0;i<6;i++)
        printf("%s ",b[i]);
    printf("\n");
    quickSort(c,sizeof(double),0,9,doubleLess);
    heapSort(c,sizeof(double),10,doubleLess);
    mergeSort(c,sizeof(double),0,9,doubleLess);
    for(i=0;i<10;i++)
        printf("%1.1f ",c[i]);
    printf("\n");
    return (EXIT_SUCCESS);
}
int intComp(void *x, void *y){
    return (**(int**)x-**(int**)y);
}
*/
#include "../DataStructure/queue.h"
int main(int argc, char** argv) {
    int a[]={5,1,9,4,6,2,0,3,8,7},i;
    char *b[]={"ChongQing","ShangHai","AoMen","TianJin","BeiJing","XiangGang"};
    double c[]={8.5,6.3,1.7,9.2,0.5,2.3,4.1,7.4,5.9,3.7};
    priorityQueue q=heapAlloc(sizeof(int),10);
    for(i=0;i<10;i++){
        enQueue(&q,sizeof(int),a+i,intLess);
    }
    while(!empty(q))
        printf("%d ",*(int*)deQueue(&q,sizeof(int),intLess));
    printf("\n");
    pqueueClear(&q);
    q=heapAlloc(sizeof(char*),6);
    for(i=0;i<6;i++){
        enQueue(&q,sizeof(char*),b+i,strGreater);
    }
    while(!empty(q))
        printf("%s ",*(char**)deQueue(&q,sizeof(char*),strGreater));
    printf("\n");
    pqueueClear(&q);
    q=heapAlloc(sizeof(double),10);
    for(i=0;i<10;i++){
        enQueue(&q,sizeof(double),c+i,doubleLess);
    }
    while(!empty(q))
        printf("%1.1f ",*(double*)deQueue(&q,sizeof(double),doubleLess));
    printf("\n");
    pqueueClear(&q);
    return (EXIT_SUCCESS);
}
