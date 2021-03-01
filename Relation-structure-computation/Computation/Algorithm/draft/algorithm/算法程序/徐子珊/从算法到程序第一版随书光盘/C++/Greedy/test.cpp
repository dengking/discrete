/* 
 * File:   test.cpp
 * Author: 徐子珊
 *
 * Created on 2008年9月20日, 上午10:56
 */

//#include "actsel.h"
#include <limits>
#include<iostream>
using namespace std;
//int main(int argc, char** argv) {
//    int *x;
//    int s[]={0,1,3,0,5,3,5,6,8,8,2,12,numeric_limits<int>::max()},
//            f[]={0,4,5,6,7,8,9,10,11,12,13,14,numeric_limits<int>::max()};
//    x=recurcive_activity_selector(s,f,0,12);
//    for(int i=1;i<12;i++)
//        cout<<x[i]<<" ";
//    cout<<endl;
//    return (EXIT_SUCCESS);
//}
#include "huffman.h"
int main(int argc, char** argv) {
    int f[]={45,13,12,16,9,5},i;
    char d[]={'a','b','c','d','e','f'};
    BinaryTree *h=huffman (f,d,6);
    printCode(h,"");
    h->clearTree();
    return (EXIT_SUCCESS);
}
//#include "prim.h"
//int main(int argc, char** argv) {
//    double a[81]={0,4,0,0,0,0,0,8,0,
//		 4,0,8,0,0,0,0,11,0,
//		 0,8,0,7,0,4,0,0,2,
//		 0,0,7,0,9,14,0,0,0,
//		 0,0,0,9,0,10,0,0,0,
//		 0,0,4,14,10,0,2,0,0,
//		 0,0,0,0,0,2,0,1,6,
//		 8,11,0,0,0,0,1,0,7,
//		 0,0,2,0,0,0,6,7,0};//计算MST的测试数据
//    double weight=0.0,*key;
//    int i,*pi,n=9;
//    pair<double*,int*> r;
//    r=mstPrime(a,n,0);
//    key=r.first;pi=r.second;
//    for(i=0;i<n;i++){//输出MST中的各条边及其权值
//        weight+=key[i];
//        if(pi[i]>=0)
//            cout<<'<'<<pi[i]<<','<<i<<"> ";
//    }
//    cout<<endl<<"weight: "<<weight<<endl;
//    return (EXIT_SUCCESS);
//}
//#include "dijkstra.h"
//int main(int argc, char** argv) {
//    pair<double*,int*> r;
//    double a[]={0,10,0,5,0,
//               0,0,1,2,0,
//               0,0,0,0,4,
//               0,3,9,0,2,
//               7,0,6,0,0},*d;
//    int *pi,i,s=0,n=5;
//    r=dijkstra(a,n,s);
//    d=r.first;
//    pi=r.second;
//    for(i=0;i<n;i++){
//        if(i!=s){
//            printPath(pi,s,i);
//            cout<<endl<<d[i]<<endl;
//        }
//    }
//    return (EXIT_SUCCESS);
//}
