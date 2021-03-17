/* 
 * File:   test.cpp
 * Author: ?����???
 *
 * Created on 2008��11��4��, ����4:23
 */


/*
 * 
 */
//#include "matrixchain.h"
//int main(int argc, char** argv) {
//    int p[]={30, 35, 15, 5, 10, 20, 25};
//    int *s,*m;
//    pair<int*,int*> r=matrixChainOrder(p,6);
//    m=r.first;
//    s=r.second;
//    printOptimalParens(s,1,6,6);
//    cout<<endl;
//    cout<<m[13]<<endl;
//    return (EXIT_SUCCESS);
//}
//#include "lcs.h"
//int main(){
//    char *x="ACCGGTCGAGTGCGCGGAAGCCGGCCGAA",
//            *y="GTCGTTCGGAATGCCGTTGCTCTGTAAA";
//    //char *x="xzyzzyx",
//    //	*y="zxyyzxz";
//    int *c,a[]={389,207,155,300,299,170,158,65},
//            b[]={389,300,299,207,170,158,155,65};
//    c=lcsLength(x,y,29,28);
//    printLcs(c,28,x,y,29,28);
//    cout<<endl;
//    c=lcsLength(a,b,8,8);
//    printLcs(c,8,a,b,8,8);
//    cout<<endl;
//    return (EXIT_SUCCESS);
//}
#include<iostream>
#include<iterator>
using namespace std;
#include "knapsack.h"
int main(){
	int w[]={2,3,4,5},v[]={3,4,5,7};
//	int w[]={2,2,6,5,4},v[]={6,3,5,4,6};
	int *m,*x,i;
	m=knapsack(w,v,4,9);
	x=build_solution(m,w,9,4);
//	m=knapsack(w,v,5,10);
//	x=build_solution(m,w,10,5);
        copy(x,x+4,ostream_iterator<int>(cout, " "));
	cout<<endl;
    return (EXIT_SUCCESS);
}

