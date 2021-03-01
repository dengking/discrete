/* 
 * File:   test.c
 * Author: ?����???
 *
 * Created on 2008��11��4��, ����11:42
 */

#include <stdio.h>
#include <stdlib.h>
/*
 * 
 */
/*
#include "matrixchain.h"
int main(int argc, char** argv) {
    int p[]={30, 35, 15, 5, 10, 20, 25};
    int *s,*m;
    pair r=matrixChainOrder(p,6);
    m=(int*)r.first;
    s=(int*)r.second;
    printOptimalParens(s,1,6,6);
    printf("\n");
    printf("%d\n",m[13]);
    return (EXIT_SUCCESS);
}
*/
/*
#include "lcs.h"
#include "../Utility/compare.h"
#include "../Utility/output.h"
int main(){
    char *x="ACCGGTCGAGTGCGCGGAAGCCGGCCGAA",
            *y="GTCGTTCGGAATGCCGTTGCTCTGTAAA";
    int *c,a[]={389,207,155,300,299,170,158,65},
            b[]={389,300,299,207,170,158,155,65};
    c=lcsLength(x,y,sizeof(char),29,28,charLess);
    printLcs(c,28,x,y,sizeof(char),29,28,charLess,charOutput);
    printf("\n");
    c=lcsLength(a,b,sizeof(int),8,8,intLess);
    printLcs(c,8,a,b,sizeof(int),8,8,intLess,intOutput);
    printf("\n");
    return (EXIT_SUCCESS);
}
*/
#include "knapsack.h"
int main(){
/*
	int w[]={2,3,4,5},v[]={3,4,5,7};
*/
	int w[]={6,3,5,4,6},v[]={6,3,5,4,6};//,v[]={6,3,5,4,6}w[]={2,2,6,5,4};
	int *m,*x,i;
/*
	m=knapsack(w,v,4,9);
	x=build_solution(m,w,9,4);
*/
	m=knapsack(w,v,5,12);
	x=build_solution(m,w,12,5);
	for(i=0;i<5;i++)
		printf("%d ",x[i]);
	printf("\n");
        free(m);m=NULL;
        free(x);x=NULL;
    return (EXIT_SUCCESS);
}
/*#include "floyd.h"
int main(){
    double w[]={0,3,8,dblInfy,-4,
                dblInfy,0,dblInfy,1,7,
                dblInfy,4,0,dblInfy,dblInfy,
                2,dblInfy,-5,0,dblInfy,
                dblInfy,dblInfy,dblInfy,6,0},
            *d;
    int n=5;

    double w[]={0,7,8,4,
                3,0,1,100,
                2,100,0,6,
                100,2,100,0},
            *d;
    int n=4;
*/
/*
    double w[]={0,3,2,4,
                3,0,1,2,
                2,1,0,6,
                4,2,6,0},
            *d;
    int n=4;
    int i,j,k,*pi;
    pair r;
    r=floydWarshall(w,n);
    d=(double*)r.first;
    pi=(int*)r.second;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printAllPairsShotestPath(pi,n,i,j);
            printf(":%1.1f\n",d[i*n+j]);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf("%1.1f ",d[i*n+j]);
        printf("\n");
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf("%d ",pi[i*n+j]);
        printf("\n");
    }
    return (EXIT_SUCCESS);
}
*/



