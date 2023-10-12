# [LeetCode-215. 数组中的第K个最大元素](https://leetcode.cn/problems/kth-largest-element-in-an-array/)

在阅读 labuladong [快排亲兄弟：快速选择算法详解](https://mp.weixin.qq.com/s/TRO3FOKT90Mpvn3hQWVBAQ) 时发现的这道题。

## Heap select

```c++
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, std::greater<int>> q;
        for (auto &&num : nums)
        {
            if (q.size() < k || num > q.top())
            {
                if (q.size() == k)
                {
                    q.pop();
                }
                q.push(num);
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



## Quick select



### random

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



### Hoare partition scheme+median of three

```c++
#include <vector>
#include <queue>
#include <random>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }

    int quickSelect(vector<int> &nums, int lo, int hi, int k) {
        int p = randomizedPartition(nums, lo, hi);
        if (p == k) {
            return nums[p];
        } else if (p > k) {
            return quickSelect(nums, lo, p - 1, k);
        } else {
            return quickSelect(nums, p + 1, hi, k);
        }
    }

    int randomizedPartition(vector<int> &nums, int lo, int hi) {
        if (lo == hi) { // 必须加这个判定，否则当nums只有一个元素的时候，则必然会导致nums[++left]发生越界访问
            return lo;
        }
        // median of three
        int mid = lo + (hi - lo) / 2;
        if (nums[hi] < nums[mid]) {
            std::swap(nums[hi], nums[mid]);
        }
        if (nums[hi] < nums[lo]) {
            std::swap(nums[hi], nums[lo]);
        }
        if (nums[lo] < nums[mid]) {
            std::swap(nums[lo], nums[mid]);
        }
        int pivot = nums[lo];
        int left = lo, right = hi + 1;
        while (true) {
            while (nums[++left] < pivot) {
                if (left == hi)
                    break;
            }
            while (nums[--right] > pivot) {
                if (right == lo)
                    break;
            }

            if (left >= right)
                break;
            std::swap(nums[left], nums[right]);
        }
        std::swap(nums[lo], nums[right]);
        return right;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1};
    solution.findKthLargest(nums, 1);
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

