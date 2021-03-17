/* 
 * File:   test.cpp
 * Author: 徐子珊
 *
 * Created on 2008年10月11日, 下午6:05
 */

#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<functional>
using namespace std;
#include "../Utility/partition.h"
#include "../Utility/merge.h"
#include "insertionsort.h"
int main(int argc, char** argv){
//    int a[]={1,2,5,8,9,0,3,4,6,7},i;
    int a[]={9,8,5,2,1,7,6,4,3,0},i;
    string b[]={"AoMen","BeiJing","ShangHai","ChongQing","TianJin","XiangGang"};
//    double c[]={0.5,3.7,6.3,8.5,9.2,1.7,2.3,4.1,5.9,7.4};
    double c[]={9.2,8.5,6.3,3.7,0.5,7.4,5.9,4.1,2.3,1.7};
    vector<string> vb=vector<string>(b,b+6);
    list<double> lc=list<double>(c,c+10);
//    insertionSort<int*,less<int> >(a,a+10);
    merge<int*,greater<int> >(a,a+5,a+10);
//    inplace_merge(a,a+5,a+10,greater<int>());
    copy(a,a+10, ostream_iterator<int>(cout, " "));
    cout<<endl;
    merge(vb.begin(),vb.begin()+3,vb.end());
//    inplace_merge(vb.begin(),vb.begin()+3,vb.end());
//    insertionSort<vector<string>::iterator,less<string> >(vb.begin(),vb.end());
    copy(vb.begin(),vb.end(), ostream_iterator<string>(cout, " "));
    cout<<endl;
    list<double>::iterator m=lc.begin();
    advance(m,5);
    merge<list<double>::iterator,greater<double> >(lc.begin(),m,lc.end());
//    inplace_merge(lc.begin(),m,lc.end(),greater<double>());
//    insertionSort<list<double>::iterator,less<double> >(lc.begin(),lc.end());
    copy(lc.begin(),lc.end(), ostream_iterator<double>(cout, " "));
    cout<<endl;
    return (EXIT_SUCCESS);
}
/*
 
int main(int argc, char** argv) {
    int a[]={5,1,9,4,6,2,0,3,8,7},i;
    string b[]={"ChongQing","AoMen","TianJin","BeiJing","XiangGang","ShangHai"};
    double c[]={8.5,6.3,1.7,9.2,0.5,2.3,4.1,7.4,5.9,3.7};
    vector<string> vb=vector<string>(b,b+6);
    list<double> lc=list<double>(c,c+10);
    i=distance(a,stable_partition(a, a+10,bind2nd(less_equal<int>(), a[0])));
    copy(a,a+10, ostream_iterator<int>(cout, " "));
    cout<<endl<<i<<endl;
    i=distance(vb.begin(),stable_partition(vb.begin(), vb.end(),bind2nd(greater_equal<string>(), *(vb.begin()))));
    copy(vb.begin(),vb.end(),ostream_iterator<string>(cout, " "));
    cout<<endl<<i<<endl;
    i=distance(lc.begin(),stable_partition(lc.begin(), lc.end(),bind2nd(less_equal<double>(), *(lc.begin()))));
    copy(lc.begin(),lc.end(), ostream_iterator<double>(cout, " "));
    cout<<endl<<i<<endl;
    return (EXIT_SUCCESS);
}
*/