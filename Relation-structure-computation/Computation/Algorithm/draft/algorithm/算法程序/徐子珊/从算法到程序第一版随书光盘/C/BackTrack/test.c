/* 
 * File:   test.c
 * Author: 徐子珊
 *
 * Created on 2008年11月14日, 上午11:03
 */
#include <stdio.h>
#include <stdlib.h>
#include "../Utility/general.h"
#include "threecolor.h"
#include "nqueens.h"
#include "subsetsum.h"
#include "hamilton.h"
#include "tsp.h"
int main(int argc, char** argv) {
    int a[25]={0,1,1,0,0,
               1,0,0,1,1,
               1,0,0,1,1,
               0,1,1,0,1,
               0,1,1,1,0},
        c[]={0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,
            1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
            0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,
            0,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,
            0,1,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,
            0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,0,
            0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,
            0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,
            0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,
            1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0,
            0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,
            0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,
            0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,
            1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0},
    n=5,m=3;
    double d[]={0,3,1,5,8,
    3,0,6,7,9,
    1,6,0,4,2,
    5,7,4,0,3,
    8,9,2,3,0};
    int b[]={1,2,3,4};
/*
    CombineProblem *p;
    SpacialProblem *t=createSubsetSum(b,4,6);
    subsetTreeBacktrack(t);
    p=createMColor(a,n,m);
    backtrack(p,generalExplore);
    n=4;
    int b[]={1,2,3,4};
    n=4;
    p=createSubsetSum(b,n,6);
    backtrack(p,subsetTreeExplore);
    p=createHamilton(c,20,2);
    backtrack(p,generalExplore);
*/
    OptimalProblem *q;
    q=createTsp(d,5,1);
    optimopalBacktrack(q,generalOptimalExplore);
    optprobClear(q);
    SpacialProblem *p=createNQueens(4);
    permuteTreeBacktrack(p);
    spcprobClear(p);
    return (EXIT_SUCCESS);
}

