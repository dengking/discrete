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

```C++
class Solution {
public:
    int quickSelect(vector<int>& a, int l, int r, int index) {
        int q = randomPartition(a, l, r);
        if (q == index) {
            return a[q];
        } else {
            return q < index ? quickSelect(a, q + 1, r, index) : quickSelect(a, l, q - 1, index);
        }
    }

    inline int randomPartition(vector<int>& a, int l, int r) {
        int i = rand() % (r - l + 1) + l;
        swap(a[i], a[r]);
        return partition(a, l, r);
    }

    inline int partition(vector<int>& a, int l, int r) {
        int x = a[r], i = l - 1;
        for (int j = l; j < r; ++j) {
            if (a[j] <= x) {
                swap(a[++i], a[j]);
            }
        }
        swap(a[i + 1], a[r]);
        return i + 1;
    }

    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
};


```

