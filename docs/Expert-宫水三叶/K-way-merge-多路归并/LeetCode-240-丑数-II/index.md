# LeetCode [264. 丑数 II](https://leetcode-cn.com/problems/ugly-number-ii/)



## 宫水三叶 [【多路归并】从朴素优先队列到多路归并](https://mp.weixin.qq.com/s?__biz=MzU4NDE3MTEyMA==&mid=2247490029&idx=1&sn=bba9ddff88d247db310406ee418d5a15&chksm=fd9cb2f2caeb3be4b1f84962677337dcb5884374e5b6b80340834eaff79298d11151da2dd5f7&token=252055586&lang=zh_CN#rd)



## 我的解题

### min heap

```C++
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
		std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;
		pq.push(1); // 1是最小的
		set<int> se;
		se.insert(1);
		long long res = 0;
		for (int i = 0; i < n; ++i) {
			res = pq.top();
			pq.pop();
			int next = 2 * res;
			if (se.find(next) == se.end()) {
				se.insert(next);
				pq.push(next);
			}
			next = 3 * res;
			if (se.find(next) == se.end()) {
				se.insert(next);
				pq.push(next);

			}
			next = 5 * res;
			if (se.find(next) == se.end()) {
				se.insert(next);
				pq.push(next);

			}
		}
		return res;
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

### 三指针

