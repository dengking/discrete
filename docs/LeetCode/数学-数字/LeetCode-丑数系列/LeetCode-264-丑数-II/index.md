# LeetCode [264. 丑数 II](https://leetcode.cn/problems/ugly-number-ii/)

**丑数** 就是只包含质因数 `2`、`3` 和/或 `5` 的正整数。

> NOTE:
>
> 只能由这三个数相乘得到。

## 宫水三叶 [【多路归并】从朴素优先队列到多路归并](https://mp.weixin.qq.com/s?__biz=MzU4NDE3MTEyMA==&mid=2247490029&idx=1&sn=bba9ddff88d247db310406ee418d5a15&chksm=fd9cb2f2caeb3be4b1f84962677337dcb5884374e5b6b80340834eaff79298d11151da2dd5f7&token=252055586&lang=zh_CN#rd)



## 我的解题

### min heap

```C++

class Solution
{
public:
  int nthUglyNumber(int n)
  {
    std::unordered_set<long long> nums; // 去重
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;
    // algorithm initialization
    pq.push(1);
    nums.insert(1);
    long long res = 0; //下面涉及乘法，因此需要使用更宽的类型，否则会触发: runtime error: signed integer overflow: 429981696 * 5 cannot be represented in type 'int'
    for (int i = 0; i < n; ++i)
    {
      res = pq.top();
      pq.pop();
      long long next = res * 2;
      if (!nums.count(next))
      {
        pq.push(next);
        nums.insert(next);
      }
      next = res * 3;
      if (!nums.count(next))
      {
        pq.push(next);
        nums.insert(next);
      }
      next = res * 5;
      if (!nums.count(next))
      {
        pq.push(next);
        nums.insert(next);
      }
    }
    return res;
  }
};

```

### 三指针

```c++
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <random>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
		std::vector<long long> nums(n+1);
		nums[0] = 1;
		nums[1] = 1;

		int a = 1;
		int b = 1;
		int c = 1;
		for (int i = 2; i <= n; ++i) {
			long long next_a = nums[a] * 2;
			long long next_b = nums[a] * 3;
			long long next_c = nums[a] * 5;

			long long next = min(next_a, min(next_b, next_c));
			if (next = next_a) ++a;
			if (next = next_b) ++b;
			if (next = next_c) ++c;
			nums[i] = next;
		}
		return nums[n];
	}
};

int main()
{
	Solution s;
	vector<int> nums{ 1,2,3,4 };
	int k = 5;
}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -Werror

```

