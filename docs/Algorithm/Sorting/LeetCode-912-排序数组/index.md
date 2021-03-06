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

当原数组本身是有序的时候，如果每次都选择第一个元素作为pivot，那么将导致quick sort退化，下面是源自: https://leetcode-cn.com/submissions/detail/194476777/testcase/ 

```C++
[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52, ......50000]
```

这种情况下是会超时的。

### Randomized quick sort

通过随机化的方式来避免退化

```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	vector<int> sortArray(vector<int> &nums)
	{
		srand((unsigned) time(NULL));
		quickSort(nums, 0, nums.size() - 1);
		return nums;
	}
private:
	void quickSort(vector<int> &nums, int start, int end)
	{
		if (start < end)
		{
			int partition_pos = randomized_partition(nums, start, end);
			quickSort(nums, start, partition_pos - 1);
			quickSort(nums, partition_pos + 1, end);
		}
	}
	int randomized_partition(vector<int> &nums, int start, int end)
	{
		int i = rand() % (end - start + 1) + start; // 随机选一个作为我们的主元
		swap(nums[start], nums[i]);
		return partition(nums, start, end);
	}
	/**
	 * @brief
	 *
	 * @param nums
	 * @param start
	 * @param end
	 * @return
	 */
	int partition(vector<int> &nums, int start, int end)
	{
		int pivot = nums[start];
		int slow = start + 1;
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

