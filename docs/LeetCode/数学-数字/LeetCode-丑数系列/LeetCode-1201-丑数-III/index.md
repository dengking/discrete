# leetcode [1201. 丑数 III](https://leetcode-cn.com/problems/ugly-number-iii/)



## 宫水三叶 [【多路归并】从朴素优先队列到多路归并](https://mp.weixin.qq.com/s?__biz=MzU4NDE3MTEyMA==&mid=2247490029&idx=1&sn=bba9ddff88d247db310406ee418d5a15&chksm=fd9cb2f2caeb3be4b1f84962677337dcb5884374e5b6b80340834eaff79298d11151da2dd5f7&token=252055586&lang=zh_CN#rd)



```C++
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

class Solution
{
public:
  int nthUglyNumber(int n, int a, int b, int c)
  {
    std::unordered_set<long long> nums; // 去重
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;
    int index_a = 1;
    int index_b = 1;
    int index_c = 1;
    long long res = 1; //下面涉及乘法，因此需要使用更宽的类型，否则会触发: runtime error: signed integer overflow: 429981696 * 5 cannot be represented in type 'int'
    for (int i = 0; i < n; ++i)
    {
      long long next = res * a;
      if (!nums.count(next))
      {
        pq.push(next);
        nums.insert(next);
      }
      next = res * b;
      if (!nums.count(next))
      {
        pq.push(next);
        nums.insert(next);
      }
      next = res * c;
      if (!nums.count(next))
      {
        pq.push(next);
        nums.insert(next);
      }
      res = pq.top();
      pq.pop();
    }
    return res;
  }
};

// Driver code
int main()
{

  Solution solu;
  vector<int> prices{7, 1, 5, 3, 6, 4};
  solu.nthUglyNumber(8, 2, 3, 4);
  return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```



