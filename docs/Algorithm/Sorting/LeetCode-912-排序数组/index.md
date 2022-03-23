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

#### 写法一

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

#### 写法二

```C++
#include <vector>
#include <algorithm>
#include <random>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Solution {
public:
	vector<int> sortArray(vector<int>& nums) {
		shuffleArray(nums);
		sortArrayImpl(nums, 0, nums.size() - 1);
		return nums;

	}
	void sortArrayImpl(vector<int>& nums, int start, int end) {
		if (start >= end) {
			return;
		}
		int p = partition(nums, start, end);
		sortArrayImpl(nums, start, p - 1);
		sortArrayImpl(nums, p + 1, end);
	}
	int partition(vector<int>& nums, int start, int end) {
		int left = start, right = end + 1;
		int pivot = nums[start];
		while (true) {
			while (nums[++left] < pivot && left < end);
			while (nums[--right] > pivot && right > start);
			if (left >= right)
				break;
			swap(nums[left], nums[right]);
		}
		swap(nums[start], nums[right]);
		return right;
	}
	// 采用Fisher–Yates-shuffle算法
	void shuffleArray(vector<int>& nums) {
		srand(time(0));
		int len = nums.size();
		for (int i = 0; i < len; ++i) {
			int j = rand() % (len - i);
			swap(nums[i], nums[j]);
		}
	}
};

int main()
{
	vector<int> nums{ 5,2,3,1 };
	Solution s;
	s.sortArray(nums);
}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -Werror

```



### Merge sort

```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
	vector<int> temp; // 保存临时排序结果
public:
	vector<int> sortArray(vector<int> &nums)
	{
		temp.resize((int) nums.size(), 0);
		mergeSort(nums, 0, nums.size() - 1);
		return nums;
	}
private:
	void mergeSort(vector<int> &nums, int left, int right)
	{
		if (left >= right) // base case
		{
			return;
		}
		int mid = (left + right) >> 1;
		mergeSort(nums, left, mid);
		mergeSort(nums, mid + 1, right);
		int i = left, j = mid + 1;
		int count = 0;
		while (i <= mid && j <= right)
		{
			if (nums[i] <= nums[j])
			{
				temp[count++] = nums[i++];
			}
			else
			{
				temp[count++] = nums[j++];
			}
		}
		while (i <= mid)
		{
			temp[count++] = nums[i++];
		}
		while (j <= right)
		{
			temp[count++] = nums[j++];
		}
		for (int i = 0; i < right - left + 1; ++i)
		{
			nums[i + left] = temp[i];
		}
	}
};

int main()
{

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```





## 三刷

### quick sort

```c++

class Solution
{
public:
  vector<int> sortArray(vector<int> &nums)
  {
    std::random_device rd;
    std::mt19937 mt{rd()};
    std::shuffle(nums.begin(), nums.end(), mt);
    sortArrayImpl(nums, 0, nums.size() - 1);
    return nums;
  }

private:
  void sortArrayImpl(vector<int> &nums, int start, int end)
  {
    if (start < end)
    {
      int p = partition(nums, start, end);
      sortArrayImpl(nums, start, p - 1);
      sortArrayImpl(nums, p + 1, end);
    }
  }

  int partition(vector<int> &nums, int start, int end)
  {
    int left = start, right = end + 1;
    int pivot = nums[start];
    while (true)
    {
      while (nums[++left] < pivot)
      {
        if (left == end)
          break;
      }
      while (nums[--right] > pivot)
      {
        if (right == start)
          break;
      }
      if (left >= right)
        break;
      swap(nums[left], nums[right]);
    }
    swap(nums[start], nums[right]);
    return right;
  }
};

```

### merge sort

```c++
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <numeric>
#include <climits>
#include <random>

using namespace std;

class Solution
{
  std::vector<int> tmp;

public:
  vector<int> sortArray(vector<int> &nums)
  {
    tmp.reserve(nums.size());
    sortArray(nums, 0, nums.size() - 1);
    return nums;
  }

private:
  void sortArray(vector<int> &nums, int start, int stop)
  {
    if (start < stop)
    {
      int mid = start + (stop - start) / 2;
      sortArray(nums, start, mid);
      sortArray(nums, mid + 1, stop);
      merge(nums, start, mid, stop);
    }
  }
  void merge(vector<int> &nums, int start, int mid, int stop)
  {
    int cnt = 0;
    int first = start;
    int second = mid + 1;
    while (first <= mid && second <= stop)
    {
      if (nums[first] < nums[second])
      {
        tmp[cnt++] = nums[first++];
      }
      else
      {
        tmp[cnt++] = nums[second++];
      }
    }
    while (first <= mid)
    {
      tmp[cnt++] = nums[first++];
    }
    while (second <= stop)
    {
      tmp[cnt++] = nums[second++];
    }
    int len = stop - start + 1;
    for (int i = 0; i < len; ++i)
    {
      nums[i + start] = tmp[i];
    }
  }
};

int main()
{
}
```

