/* 
 * File:   test.cpp
 * Author: ?����???
 *
 * Created on 2008��9��18��, ����10:29
 */

#include "marixchain.h"

/*
 * 
 */
int main(int argc, char** argv) {
    int p[]={30, 35, 15, 5, 10, 20, 25};
    int *s,*m;
//    struct pair r=matrix_chain_order(p,6);
    pair<int*,int*> r=matrix_chain_order(p,6);
    m=r.first;
    s=r.second;
    print_optimal_parens(s,1,6,6);
//    printf("\n");
    cout<<endl;
//    printf("%d\n",m[13]);
    cout<<m[13]<<endl;
    return (EXIT_SUCCESS);
}

