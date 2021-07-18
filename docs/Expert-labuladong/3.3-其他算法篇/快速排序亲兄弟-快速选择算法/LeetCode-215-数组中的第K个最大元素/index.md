# leetcode [215. 数组中的第K个最大元素](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/)



## 我的解题

### `priority_queue`

```c++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int findKthLargest(vector<int> &nums, int k)
	{
		priority_queue<int, std::vector<int>, std::greater<int>> q; // min heap
		int len = nums.size();
		for (int i = 0; i < len; ++i)
		{
			q.push(nums[i]);
			if (i + 1 > k)
			{
				q.pop(); // 弹出小元素，留下大元素
			}
		}
		return q.top();
	}
};

int main()
{

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

### quick select

