# 大整数

## 蚂蚁集团面试题: 100!

```c++
// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <list>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <cmath>
#include <numeric>
#include <climits>
#include <random>
// example1.cpp
// new-delete-type-mismatch error
#include <memory>
#include <vector>
using namespace std;

#include <vector>
#include <iostream>

/**
 * @brief 将一个数转换为vector
 *
 * @param num
 * @return std::vector<int>
 */
std::vector<int> toVector(int num)
{
  std::vector<int> res;

  while (num != 0)
  {
    res.push_back(num % 10);
    num /= 10;
  }

  return res;
}

std::vector<int> add(std::vector<int> &left, std::vector<int> &right)
{
  // 双指针
  int first = 0;
  int second = 0;
  int adder = 0; // 进位
  std::vector<int> res;

  while (first < left.size() && second < right.size())
  {
    int sum = left[first] + right[second] + adder;
    res.push_back(sum % 10);
    adder = sum / 10;
    ++first;
    ++second;
  }
  while (first < left.size())
  {
    int sum = left[first] + adder;

    res.push_back(sum % 10);
    adder = sum / 10;
    ++first;
  }
  while (second < right.size())
  {
    int sum = right[second] + adder;
    res.push_back(sum % 10);
    adder = sum / 10;
    ++second;
  }
  // 0099 + 001 = 00001
  if (adder)
  {
    res.push_back(adder);
  }
  return res;
}
/**
 * @brief 各位分别与right相处，比如: 789 * 10 = 700 * 10 + 80 * 10 + 9 * 10
 *
 * @param left
 * @param right
 * @return std::vector<int>
 */
std::vector<int> multiply(std::vector<int> &left, int right)
{
  std::vector<int> sum;
  int multi = 1;
  for (auto &&bit : left)
  {
    sum.push_back(bit * multi * right);
    multi *= 10;
  }
  std::vector<int> res;
  for (auto &&num : sum)
  {
    auto numVec = toVector(num);
    res = add(res, numVec);
  }
  return res;
}

int main()
{
  std::vector<int> first = toVector(100);

  for (int i = 99; i >= 98; --i)
  {
    first = multiply(first, i);
  }
  std::copy(first.begin(), first.end(), std::ostream_iterator<int>(std::cout, " "));
}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```



## labuladong [教计算机做算术：字符串乘法](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484466&idx=1&sn=0281340cc1f41230e4512e905b9d27dd&scene=21#wechat_redirect)





## CSDN [C++ 高精度整数，两个大数相加如何处理](https://blog.csdn.net/qq_36770641/article/details/88899812)



## CSDN [C++大数相加](https://blog.csdn.net/qq_1932568757/article/details/82754127)



## CSDN [大整数乘法-面试题](https://blog.csdn.net/weixin_42804808/article/details/109724408)



## CSDN [华为经典面试题---大数乘法的c++实现](https://blog.csdn.net/LucasDove/article/details/50728508)



## cnblogs [面试题：如何实现大整数相加](https://www.cnblogs.com/alimayun/p/12792454.html)



## cnblogs [大整数加法 面试题](https://www.cnblogs.com/meihao1203/p/8023524.html)

