
#include <queue>


#include <vector>

/* 
 * File:   test.cpp
 * Author: ?����???
 *
 * Created on 2008��10��21��, ����4:59
 */
#include <iostream>
#include<iterator>
using namespace std;
/*
 * 
 */
#include<stack.h>
#include<vector>
#include<list>
#include<time.h>
#include "mergesort.h"
#include "quicksort.h"
#include "heapsort.h"
#include "../DataStructure/queue.h"
int main(int argc, char** argv) {
    srand((int)time(0));
    int a[]={5,1,9,4,6,2,0,3,8,7},i;
    string b[]={"ChongQing","ShangHai","AoMen","TianJin","BeiJing","XiangGang"};
    double c[]={8.5,6.3,1.7,9.2,0.5,2.3,4.1,7.4,5.9,3.7};
    vector<string> vb=vector<string>(b,b+6);
    list<double> lc=list<double>(c,c+10);
    mergeSort(a,a+10);
//    heapSort(a,a+10,less<int>());
//    make_heap(a,a+10);
//    sort_heap(a,a+10);
//    quickSort(a,a+10,greater<int>());
    copy(a,a+10, ostream_iterator<int>(cout, " "));
    cout<<endl<<count1<<endl;
//    heapSort(vb.begin(),vb.end(),greater<string>());
//    make_heap(vb.begin(),vb.end());
//    sort_heap(vb.begin(),vb.end());
//    mergeSort<vector<string>::iterator,less<string> >(vb.begin(),vb.end());
//    quickSort(vb.begin(),vb.end(),greater<string>());
//    copy(vb.begin(),vb.end(), ostream_iterator<string>(cout, " "));
//    cout<<endl;
//    mergeSort<list<double>::iterator,greater<double> >(lc.begin(),lc.end());
//    heapSort<double,list<double>::iterator>(lc.begin(),lc.end());
//    quickSort(lc.begin(),lc.end(),less<double>());
//    copy(lc.begin(),lc.end(), ostream_iterator<double>(cout, " "));
//    cout<<endl;
    return (EXIT_SUCCESS);
}
//#include<algorithm>
//int main(int argc, char** argv) {
//    int h[]={4,1,3,2,16,9,10,14,8,7};
//    make_heap(h,h+10,less<int>());
//    cout<<"max heap:"<<endl;
//    copy(h,h+10,ostream_iterator<int>(cout, " "));
//    cout<<endl;
//    make_heap(h,h+10,greater<int>());
//    cout<<"min heap:"<<endl;
//    copy(h,h+10,ostream_iterator<int>(cout, " "));
//    cout<<endl;
//    return (EXIT_SUCCESS);
//}
//int main(int argc, char** argv) {
//    int a[]={5,1,9,4,6,2,0,3,8,7},i;
//    string b[]={"ChongQing","ShangHai","AoMen","TianJin","BeiJing","XiangGang"};
//    double c[]={8.5,6.3,1.7,9.2,0.5,2.3,4.1,7.4,5.9,3.7};
//    priority_queue<int,vector<int>,less<int> > p;
//    for(i=0;i<10;i++)
//        p.push(a[i]);
//    while(!p.empty()){
//        cout<<p.top()<<" ";
//        p.pop();
//    }
//    cout<<endl;
//    priority_queue<string,vector<string>,greater<string> > p1;
//    for(i=0;i<6;i++)
//        p1.push(b[i]);
//    while(!p1.empty()){
//        cout<<p1.top()<<" ";
//        p1.pop();
//    }
//    cout<<endl;
//    priority_queue<double,vector<double>,less<double> > p2;
//    for(i=0;i<10;i++)
//        p2.push(c[i]);
//    while(!p2.empty()){
//        cout<<p2.top()<<" ";
//        p2.pop();
//    }
//    cout<<endl;
//    PrioQueue<int,less<int> > q;
//    for(i=0;i<10;i++)
//        q.enQueue(a[i]);
//    while(!q.empty())
//        cout<<q.deQueue()<<endl;
//    PrioQueue<string,greater<string> > q1;
//    for(i=0;i<6;i++)
//        q1.enQueue(b[i]);
//    while(!q1.empty())
//        cout<<q1.deQueue()<<endl;
//    PrioQueue<double,less<double> > q2;
//    for(i=0;i<10;i++)
//        q2.enQueue(c[i]);
//    while(!q2.empty())
//        cout<<q2.deQueue()<<endl;
//    return (EXIT_SUCCESS);
//}

