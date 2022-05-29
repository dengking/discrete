# leetcode [27. 移除元素](https://leetcode-cn.com/problems/remove-element/)



## 我的解答



```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int removeElement(vector<int> &nums, int val)
	{
		int n = nums.size();
		int slow = 0, fast = 0;
		while (fast < n)
		{
			if (nums[fast] != val) // 需要保留的值
			{
				nums[slow] = nums[fast];
				++slow;
			}
			++fast;
		}
		return slow; // 需要注意，slow记录的是个数
	}
};

template<typename ...Args>
ostream& operator <<(ostream &stream, vector<Args...> &v)
{
	for (auto &&i : v)
	{
		stream << i << " ";
	}
	return stream;
}
int main()
{
	vector<int> nums { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };

	Solution s;
	cout << s.removeElement(nums, 1) << endl;

	cout << nums << endl;
}
// g++ test.cpp -pedantic -Wall -Wextra --std=c++11

```

