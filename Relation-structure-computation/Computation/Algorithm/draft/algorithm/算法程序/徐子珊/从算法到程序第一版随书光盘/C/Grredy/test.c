/* 
 * File:   test.c
 * Author: 徐子珊
 *
 * Created on 2008年10月3日, 下午5:21
 */
/*
#include "actsel.h"
int main(int argc, char** argv) {
    int i,*x=(int*)malloc(12*sizeof(int));
    int s[]={0,1,3,0,5,3,5,6,8,8,2,12,1000},f[]={0,4,5,6,7,8,9,10,11,12,13,14,1000};
    recurcive_activity_selector(s,f,x,0,12);
    for(i=1;i<12;i++)
        printf("%d ",x[i]);
    printf("\n");
    return (EXIT_SUCCESS);
}
*/
/*
#include "dijkstra.h"
int main(int argc, char** argv) {
    pair r;
    double a[]={0,10,0,5,0,
               0,0,1,2,0,
               0,0,0,0,4,
               0,3,9,0,2,
               7,0,6,0,0},
            *d;
    int *pi,i,n=5;
    r=dijkstra(a,5,0);
    d=r.first;
    pi=r.second;
    for(i=0;i<n;i++){
        if(i!=0){
            printPath(pi,i);
            printf("\n%f\n",d[i]);
        }
    }
    return (EXIT_SUCCESS);
}
*/
/*
#include "huffman.h"
int main(int argc, char** argv) {
    int f[]={45,13,12,16,9,5},i;
    char d[]={'a','b','c','d','e','f'};
    BinaryTree *h=huffman (f,d,6);
    printCode(h,"");
    clearTree(h);
    h=NULL;
    return (EXIT_SUCCESS);
}

#include "prim.h"
int main(int argc, char** argv) {
    double a[81]={0,4,0,0,0,0,0,8,0,
		 4,0,8,0,0,0,0,11,0,
		 0,8,0,7,0,4,0,0,2,
		 0,0,7,0,9,14,0,0,0,
		 0,0,0,9,0,10,0,0,0,
		 0,0,4,14,10,0,2,0,0,
		 0,0,0,0,0,2,0,1,6,
		 8,11,0,0,0,0,1,0,7,
		 0,0,2,0,0,0,6,7,0};//计算MST的测试数据
    pair r;
    double *key,weight=0.0;
    int *pi,i,n=9;
    r=mstPrim(a,n,0);
    key=r.first;
    pi=r.second;
    for(i=0;i<n;i++){//输出MST中的各条边及其权值
        weight+=key[i];
        if(pi[i]>=0)
            printf("<%d,%d> ",pi[i],i);
    }
    printf("\nweight: %1.1f\n",weight);
    return (EXIT_SUCCESS);
}*/
#include "prim.h"
#include <math.h>
typedef struct{
    int x;
    int y;
}point;
int main(int argc, char** argv) {
    point points[4]={{0,100},{0,300},{0,600},{150,750}};
    double w[16],*key;
    int *pi,i,j,P=4,S=2;
    pair r;
    for(i=0;i<P;i++)
        for(j=0;j<P;j++)
            w[i*P+j]=sqrt(pow(points[i].x-points[j].x,2)+pow(points[i].y-points[j].y,2));
    r=mstPrim(w,P,0);
    key=r.first;
    pi=r.second;
    for(i=0;i<P;i++){//输出MST中的各条边及其权值
        if(pi[i]>=0)
            printf("<%d,%d> %f\n",pi[i],i,key[i]);
    }
    return (EXIT_SUCCESS);
}


