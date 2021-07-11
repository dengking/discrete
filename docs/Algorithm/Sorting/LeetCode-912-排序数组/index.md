# leetcode [912. 排序数组](https://leetcode-cn.com/problems/sort-an-array/)

## 我的解题

### Quick sort



```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	vector<int> sortArray(vector<int> &nums)
	{

	}
	void quickSort(vector<int> &nums, int start, int end)
	{

	}
	int partition(vector<int> &nums, int start, int end)
	{
		int pivot = nums[start];
		int slow = start;
		int fast = start + 1;
		for (; fast <= end; ++fast)
		{
			if (nums[fast] < pivot)
			{
				swap(nums[slow++], nums[fast]);
			}
		}
		swap(nums[start], nums[slow - 1]);
		return slow - 1;
	}
};

```

