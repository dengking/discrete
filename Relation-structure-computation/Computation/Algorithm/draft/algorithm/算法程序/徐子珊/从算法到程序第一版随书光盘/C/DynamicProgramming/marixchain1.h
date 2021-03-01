/* 
 * File:   marixchain.h
 * Author: 徐子珊
 *
 * Created on 2008年9月18日, 下午10:19
 */
#ifndef _MARIXCHAIN_H
#define	_MARIXCHAIN_H
#include<stdlib.h>
#include<stdio.h>
#include<pair.h>
#include<limits>
#include<iostream>
using namespace std;
//struct pair{//用来存储两个整数数组的结构体
//    int *first;
//    int *second;
//};
//struct pair matrix_chain_order(int *p,int n){//p为矩阵链的维数数组，n+1为p中元素个数
//    long i,l,j,k,q;
//    int *m=(int*)malloc((n+1)*(n+1)*sizeof(int));
//    int *s=(int*)malloc((n+1)*(n+1)*sizeof(int));
//    struct pair result;
//    for(i=0;i<=n;i++)//初始化长度为1的矩阵链最优加括号所涉及的数的乘法次数
//        m[i*(n+1)+i]=0;
//    for(l=2;l<=n;l++)//l为子矩阵链的长度
//        for(i=1;i<=n-l+1;i++){//计算每个长度为l的子矩阵链的最佳加括号法所涉及数的乘法次数
//            j=i+l-1;//j-i+1等于l
//            m[i*(n+1)+j]=1<<(8*sizeof(int)-2);//m[i,j]←∞
//            for(k=i;k<=j-1;k++){//检验i,j间所有可能的分裂点
//                q=m[i*(n+1)+k]+m[(k+1)*(n+1)+j]+p[i-1]*p[k]*p[j];
//                if(q<m[i*(n+1)+j]){
//                    m[i*(n+1)+j]=q;
//                    s[i*(n+1)+j]=k;//记录分裂点
//                }
//            }
//        }
//    result.first=m;
//    result.second=s;
//    return result;
//}
//void print_optimal_parens(int *s,int i,int j,int n){
//    if(i==j)
//        printf("A%d",i);
//    else{
//        printf("(");
//        print_optimal_parens(s,i,s[i*(n+1)+j],n);
//        print_optimal_parens(s,s[i*(n+1)+j]+1,j,n);
//        printf(")");
//    }
//}
pair<int*,int*> matrix_chain_order(int *p,int n){//p为矩阵链的维数数组，n+1为p中元素个数
    long i,l,j,k,q;
    int *m=new int[(n+1)*(n+1)];
    int *s=new int[(n+1)*(n+1)];
    pair<int*,int*> result;
    for(i=0;i<=n;i++)//初始化长度为1的矩阵链最优加括号所涉及的数的乘法次数
        m[i*(n+1)+i]=0;
    for(l=2;l<=n;l++)//l为子矩阵链的长度
        for(i=1;i<=n-l+1;i++){//计算每个长度为l的子矩阵链的最佳加括号法所涉及数的乘法次数
            j=i+l-1;//j-i+1等于l
            m[i*(n+1)+j]=numeric_limits<int>::max();//m[i,j]←∞
            for(k=i;k<=j-1;k++){//检验i,j间所有可能的分裂点
                q=m[i*(n+1)+k]+m[(k+1)*(n+1)+j]+p[i-1]*p[k]*p[j];
                if(q<m[i*(n+1)+j]){
                    m[i*(n+1)+j]=q;
                    s[i*(n+1)+j]=k;//记录分裂点
                }
            }
        }
    result.first=m;
    result.second=s;
    return result;
}
void print_optimal_parens(int *s,int i,int j,int n){
    if(i==j)
        cout<<'A'<<i;
    else{
        cout<<'(';
        print_optimal_parens(s,i,s[i*(n+1)+j],n);
        print_optimal_parens(s,s[i*(n+1)+j]+1,j,n);
        cout<<')';
    }
}
#endif	/* _MARIXCHAIN_H */

