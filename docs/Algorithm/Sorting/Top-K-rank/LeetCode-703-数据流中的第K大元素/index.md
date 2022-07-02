# LeetCode [703. 数据流中的第 K 大元素](https://leetcode.cn/problems/kth-largest-element-in-a-stream/)



csdn [【leetcode/BST】数据流中的第k大元素（BST综合+优先队列引入）](https://blog.csdn.net/qq_43338695/article/details/102645827)

## 我的解题

```C++
#include <bits/stdc++.h>
using namespace std;
class KthLargest
{
	priority_queue<int, vector<int>, std::greater<int>> q;
	int k { 0 };
public:
	KthLargest(int k, vector<int> &nums) :
					k { k }
	{
		for (auto &&n : nums)
		{
			q.emplace(n);
			if (q.size() > k)
			{
				q.pop();
			}
		}
	}

	int add(int val)
	{
		q.emplace(val);
		if (q.size() > k)
		{
			q.pop();
		}
		return q.top();
	}
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
int main()
{

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

