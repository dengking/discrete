/* 
 * File:   problem.h
 * Author: 徐子珊
 *
 * Created on 2008年11月17日, 下午4:29
 */

#ifndef _PROBLEM_H
#define	_PROBLEM_H
#include<vector>
using namespace std;
template<typename T1, typename T2>
class CombineProblem{
public:
    T1 *a;//描述问题的数据
    T2 *x;//解向量
    int n;//解向量最大长度
    bool flag;//有解标志
    virtual bool isPartial(int k){};//判断x[1..k]是否部分合法
    virtual void printSolution(int k){};//打印合法解x[1..k]
    virtual bool isComplete(int k){};//判断x[1..k]是否完整合法
    virtual vector<T2> makeIterms(int k){};//生成解向量第k个分量的取值集合
};
template<typename T1, typename T2>
class OptimalProblem:public CombineProblem<T1,T2>{
public:
    T2 *current;
    double most;
    double currentValue;
    virtual double objValue(double v,int k){};
    virtual bool isOptimal(int k){};
};
template<typename T>
class SpacialProblem{
public:
    T *a;//描述问题的数据
    int *x;//解向量
    int n;//解向量最大长度
    bool flag;//有解标志
    virtual bool isPartial(int k){};//判断x[1..k]是否部分合法
    virtual void printSolution(int k){};//打印合法解x[1..k]
    virtual bool isComplete(int k){};//判断x[1..k]是否完整合法
};
template<typename T>
class OptSpecialProblem:public SpacialProblem<T>{
public:
    int *current;
    double most;
    double currentValue;
    virtual double objValue(double v, int k){};
    virtual bool isOptimal(int k){};
};
#endif	/* _PROBLEM_H */

