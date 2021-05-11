# leetcode [26. 删除有序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)



## 我的解答

```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int removeDuplicates(vector<int> &nums)
	{
		int n = nums.size();
		if (n == 0)
		{
			return 0;
		}
		int slow = 0, fast = 1;
		while (fast < n)
		{
			if (nums[fast] != nums[slow])
			{
				++slow;
				nums[slow] = nums[fast];
			}
			++fast;
		}
		return slow + 1;
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
	cout << s.removeDuplicates(nums) << endl;

	cout << nums << endl;
}
// g++ test.cpp -pedantic -Wall -Wextra --std=c++11

```

