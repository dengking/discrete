# 大数乘法



## labuladong [教计算机做算术：字符串乘法](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484466&idx=1&sn=0281340cc1f41230e4512e905b9d27dd&scene=21#wechat_redirect)



## 算法

```
    123
    456

```

从最终目标入手，首先需要明确两数相乘的结果的长度为 `m + n` 。

其次，我们平时做乘法的时候，需要错位，其实那是考虑了它所处的位(个位、十位、百位)





### 数到表示

大端模式: 从左到右、从高位到低位

累加模式

进位

#### 数位和位置

数位和位置相对应，因此可以简化运算: 比如十位的1表示的是10，它和各位的数进行运算，那么它们的结果肯定是要放到十位的，那么位将它们的结果放到最终运输结果的十位即可，显然这极大的简化了运算。

### 算法

两个数相乘其实是可以拆解位多个数相乘然后进行相加。

运算顺序: 从低位到高位，需要从低位向高位进行计算。

## 试题

**LeetCode** [43. 字符串相乘](https://leetcode.cn/problems/multiply-strings/)

它的官方解题时比较复杂的。



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





## CSDN [大整数乘法-面试题](https://blog.csdn.net/weixin_42804808/article/details/109724408)



## CSDN [华为经典面试题---大数乘法的c++实现](https://blog.csdn.net/LucasDove/article/details/50728508)

