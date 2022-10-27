# [LeetCode-134. 加油站](https://leetcode.cn/problems/gas-station/)



## 我的解题

按照 labuladong [当老司机学会了贪心算法](https://mp.weixin.qq.com/s/k-z_oewAqMYc3vpmOm4gEQ) 中的写法；

### 贪心算法

```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
	{
		int len = gas.size();
		int sum = 0;
		for (int i = 0; i < len; ++i)
		{
			sum += gas[i] - cost[i];
		}
		if (sum < 0)
		{
			return -1;
		}
		int start = 0;
		int tank = 0; // 油箱的量
		for (int i = 0; i < len; ++i)
		{
			tank += gas[i] - cost[i];
			if (tank < 0)
			{
				start = i + 1;
				tank = 0;
			}
		}
		return start == len ? 0 : start;
	}
};

int main()
{

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```

