#include<limits.h>
#include<stdlib.h>
#include<stdio.h>
/*
*程序4-2
*/
//#include "actsel.h"
//int main(int argc, char** argv) {
//    int s[]={0,1,3,0,5,3,5,6,8,8,2,12,INT_MAX},
//    f[]={0,4,5,6,7,8,9,10,11,12,13,14,INT_MAX},
//    i;
//    x=(int*)malloc(12*sizeof(int));
//    recurciveActivitySelector(s,f,0,12);
//    for(i=1;i<12;i++)
//        printf("%d ",x[i]);
//    printf("\n");
//    free(x);
//    return (EXIT_SUCCESS);
//}
/*
*程序4-14
*/
//#include "huffman.h"
//int main(int argc, char** argv) {
//    int f[]={45,13,12,16,9,5};
//    char d[]={'a','b','c','d','e','f'};
//    BinaryTree *h=huffman (f,d,6);
//    printCode(h,"");
//    clearTree(h);
//    h=NULL;
//    return (EXIT_SUCCESS);
//}

/*
*程序4-20
*/
//#include "prim.h"
//int main(int argc, char** argv) {
//    double a[81]={0,4,0,0,0,0,0,8,0,
//		 	4,0,8,0,0,0,0,11,0,
//		     0,8,0,7,0,4,0,0,2,
//		     0,0,7,0,9,14,0,0,0,
//		     0,0,0,9,0,10,0,0,0,
//		     0,0,4,14,10,0,2,0,0,
//		     0,0,0,0,0,2,0,1,6,
//		     8,11,0,0,0,0,1,0,7,
//		     0,0,2,0,0,0,6,7,0};
//    pair r;
//    double *key,weight=0.0;
//    int *pi,i,n=9;
//    r=mstPrim(a,n,0);
//    key=(double*)(r.first);
//    pi=(int*)(r.second);
//    for(i=0;i<n;i++){
//        weight+=key[i];
//        if(pi[i]>=0)
//            printf("<%d,%d>",pi[i],i);
//    }
//    printf("\nweight:%1.1f\n",weight);
// 	free(key);
// 	free(pi);
//    return (EXIT_SUCCESS);
//}
/*
*程序4-30
*/
#include "dijkstra.h"
int main(int argc, char** argv) {
    pair r;
    double a[]={0,10,0,5,0,
               0,0,1,2,0,
               0,0,0,0,4,
               0,3,9,0,2,
               7,0,6,0,0},
            *d;
    int *pi,i,n=5,s=0;
    r=dijkstra(a,5,0);
    d=r.first;
    pi=r.second;
    for(i=0;i<n;i++){
        if(i!=0){
            printPath(pi, s, i);
            printf("\n%f\n",d[i]);
        }
    }
    free(d);
    free(pi);
    return (EXIT_SUCCESS);
}
