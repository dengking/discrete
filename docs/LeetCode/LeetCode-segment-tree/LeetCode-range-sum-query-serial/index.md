# Range sum query

## [LeetCode-303. Range Sum Query - Immutable-easy](https://leetcode.cn/problems/range-sum-query-immutable/)

一、prefix sum

二、segment tree



### prefix sum

#### 使用左闭右闭的方式来定义prefix sum 

一、下面使用左闭右闭的方式来进行定义: 

```C++
prefixSum[0] = num[0]
prefixSum[i] = prefixSum[i - 1] + num[i]

sum[i, j] = prefixSum[j] - prefixSum[i - 1] 
```

通过后面的code可知，上述定义是有错误的，错误在于当 i 为 0的时候，当i为0时，上述定义就会导致负数索引，这在很多语言中都是错误的。

#### 第一次的code

我第一次写的code如下:

```C++
class NumArray {
	vector<int> preSum_;
public:
	NumArray(vector<int>& nums) {
		preSum_.resize(nums.size());
		preSum_[0] = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			preSum_[i] = preSum_[i - 1] + nums[i];
		}
	}
	// [left, right]
	int sumRange(int left, int right) {
		return preSum_[right] - preSum_[left - 1];
	}
};
```

上述代码运行时错误如下:

```C++
Line 1038: Char 34: runtime error: addition of unsigned offset to 0x603000000280 overflowed to 0x60300000027c (stl_vector.h)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior /usr/bin/../lib/gcc/x86_64-linux-gnu/9/../../../../include/c++/9/bits/stl_vector.h:1043:34
```

错误原因在于:

`sumRange(0, 1)`，则执行  `preSum_[left - 1]` 就会触发异常。

#### 第二次的code

```C++
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class NumArray {
	vector<int> preSum_;
public:
	NumArray(vector<int>& nums) {
		preSum_.resize(nums.size());
		preSum_[0] = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			preSum_[i] = preSum_[i - 1] + nums[i];
		}
	}
	// [left, right]
	int sumRange(int left, int right) {
		if (left > 0)
			return preSum_[right] - preSum_[left - 1];
		else {
			return preSum_[right];
		}
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

int main()
{
	
	vector<int> nums{ -2, 0, 3, -5, 2, -1 };
	NumArray s(nums);
	cout << s.sumRange(0, 2) << endl;
	cout << s.sumRange(2, 5) << endl;

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -Werror

```



由于数组的index涉及到减法，就需要处理0的问题，因为0减去一个数后是负数，而 [std::vector<T,Allocator>::operator[]](https://en.cppreference.com/w/cpp/container/vector/operator_at) 的入参类似是`size_type`:

```C++
reference operator[]( size_type pos );
```

根据 stackoverflow [vector::size_type in C++](https://stackoverflow.com/questions/4849632/vectorintsize-type-in-c) # [A](https://stackoverflow.com/a/4849646/10173843) 可知:

> `size_type` is a *(static) member type* of the type `vector<int>`. Usually, it is a `typedef` for `std::size_t`, which itself is usually a `typedef` for `unsigned int` or `unsigned long long`.

因此此时就会触发第一次的code中的异常。更好的做法是按照 labuladong [小而美的算法技巧：前缀和数组](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247494095&idx=2&sn=19a2609f33eadbbda1f6b75e2298d931&scene=21#wechat_redirect) 中使用的是另外一种定义方式，它避免了"index subtraction"的问题。



### segment tree



```c++
#include <unordered_map>
#include <iostream>
#include <format>
#include <vector>
using namespace std;

class NumArray
{
    vector<int> segmentTree_;
    int length;

private:
    void buildSegmentTree(vector<int> &nums, int treeIndex, int segmentLowIndex, int segmentHighIndex)
    {
        if (segmentLowIndex == segmentHighIndex)
        {
            segmentTree_[treeIndex] = nums[segmentLowIndex];
            return;
        }
        int mid = segmentLowIndex + (segmentHighIndex - segmentLowIndex) / 2;
        buildSegmentTree(nums, treeIndex * 2 + 1, segmentLowIndex, mid);
        buildSegmentTree(nums, treeIndex * 2 + 2, mid + 1, segmentHighIndex);
        segmentTree_[treeIndex] = segmentTree_[treeIndex * 2 + 1] + segmentTree_[treeIndex * 2 + 2];
    }

    static inline bool isSegmentInsideRange(int segmentLowIndex, int segmentHighIndex, int rangeLeftIndex, int rangeRightIndex)
    {
        return rangeLeftIndex <= segmentLowIndex && rangeRightIndex >= segmentHighIndex;
    }

    int querySegmentTree(int treeIndex, int segmentLowIndex, int segmentHighIndex, int rangeLeftIndex, int rangeRightIndex)
    {
        if (rangeLeftIndex > segmentHighIndex || rangeRightIndex < segmentLowIndex)
        {
            return 0;
        }
        if (isSegmentInsideRange(segmentLowIndex, segmentHighIndex, rangeLeftIndex, rangeRightIndex))
        {
            return segmentTree_[treeIndex];
        }
        int segmentMidIndex = segmentLowIndex + (segmentHighIndex - segmentLowIndex) / 2;
        if (rangeLeftIndex > segmentMidIndex) // 位于右子树
        {
            return querySegmentTree(treeIndex * 2 + 2, segmentMidIndex + 1, segmentHighIndex, rangeLeftIndex, rangeRightIndex);
        }
        else if (rangeRightIndex <= segmentMidIndex) // 位于左子树
        {
            return querySegmentTree(treeIndex * 2 + 1, segmentLowIndex, segmentMidIndex, rangeLeftIndex, rangeRightIndex);
        }
        else
        {
            return querySegmentTree(treeIndex * 2 + 1, segmentLowIndex, segmentMidIndex, rangeLeftIndex, segmentMidIndex) +
                   querySegmentTree(treeIndex * 2 + 2, segmentMidIndex + 1, segmentHighIndex, segmentMidIndex + 1, rangeRightIndex);
        }
    }

public:
    NumArray(vector<int> &nums)
    {
        length = nums.size();
        segmentTree_.resize(length * 4);
        buildSegmentTree(nums, 0, 0, length - 1);
    }

    int sumRange(int left, int right)
    {
        return querySegmentTree(0, 0, length - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

int main()
{
    vector<int> nums; // = {-2, 0, 3, -5, 2, -1};
    nums.push_back(-2);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(-5);
    nums.push_back(2);
    nums.push_back(-1);
    NumArray arr(nums);
    arr.sumRange(0, 2);
}
```





## [LeetCode-304. Range Sum Query 2D - Immutable-medium](https://leetcode.cn/problems/range-sum-query-2d-immutable/)





## [LeetCode-307. Range Sum Query - Mutable-medium](https://leetcode.cn/problems/range-sum-query-mutable/)



### segment tree



```c++
#include <unordered_map>
#include <iostream>
#include <format>
#include <vector>

/// @brief segment、range
class SegmentTree
{
    std::vector<int> tree_;
    int segmentTotalLength_;

public:
    SegmentTree(const std::vector<int> &nums)
    {
        segmentTotalLength_ = nums.size();
        tree_.resize(4 * segmentTotalLength_);

        buildTreeRecursive(nums, 0, 0, segmentTotalLength_ - 1);
    }
    void update(int index, int val)
    {
        updateTreeRecursive(0, 0, segmentTotalLength_ - 1, index, val);
    }
    int query(int rangeLeft, int rangeRight)
    {
        return queryTreeRecursive(0, 0, segmentTotalLength_ - 1, rangeLeft, rangeRight);
    }

private:
    /// @brief
    /// @param rootIndex index of root node
    void buildTreeRecursive(const std::vector<int> &nums, int rootIndex, int segmentLow, int segmentHigh)
    {
        if (segmentLow == segmentHigh)
        {
            tree_[rootIndex] = nums[segmentLow];
            return;
        }
        int segmentMid = segmentLow + (segmentHigh - segmentLow) / 2;
        buildTreeRecursive(nums, getLeftChildIndex(rootIndex), segmentLow, segmentMid);
        buildTreeRecursive(nums, getRightChildIndex(rootIndex), segmentMid + 1, segmentHigh);
        tree_[rootIndex] = tree_[getLeftChildIndex(rootIndex)] + tree_[getRightChildIndex(rootIndex)];
    }

    void updateTreeRecursive(int rootIndex, int segmentLow, int segmentHigh, int arrIndex, int val)
    {
        if (segmentLow == segmentHigh)
        {
            tree_[rootIndex] = val;
            return;
        }
        int segmentMid = segmentLow + (segmentHigh - segmentLow) / 2;

        if (arrIndex > segmentMid) // 位于右子树
        {
            updateTreeRecursive(getRightChildIndex(rootIndex), segmentMid + 1, segmentHigh, arrIndex, val);
        }
        else
        {
            updateTreeRecursive(getLeftChildIndex(rootIndex), segmentLow, segmentMid, arrIndex, val);
        }
        tree_[rootIndex] = tree_[getLeftChildIndex(rootIndex)] + tree_[getRightChildIndex(rootIndex)];
    }

    static inline int getLeftChildIndex(int nodeIndex)
    {
        return nodeIndex * 2 + 1;
    }

    static inline int getRightChildIndex(int nodeIndex)
    {
        return nodeIndex * 2 + 2;
    }

    int queryTreeRecursive(int rootIndex, int segmentLow, int segmentHigh, int rangeLeft, int rangeRight)
    {
        if (rangeLeft > segmentHigh || rangeRight < segmentLow)
        {
            return 0;
        }
        if (rangeLeft <= segmentLow && rangeRight >= segmentHigh)
        {
            return tree_[rootIndex];
        }
        int segmentMidIndex = segmentLow + (segmentHigh - segmentLow) / 2;
        if (rangeLeft > segmentMidIndex) // 位于右子树
        {
            return queryTreeRecursive(rootIndex * 2 + 2, segmentMidIndex + 1, segmentHigh, rangeLeft, rangeRight);
        }
        else if (rangeRight <= segmentMidIndex) // 位于左子树
        {
            return queryTreeRecursive(rootIndex * 2 + 1, segmentLow, segmentMidIndex, rangeLeft, rangeRight);
        }
        else // 左右子树中都有
        {
            return queryTreeRecursive(rootIndex * 2 + 1, segmentLow, segmentMidIndex, rangeLeft, segmentMidIndex) +
                   queryTreeRecursive(rootIndex * 2 + 2, segmentMidIndex + 1, segmentHigh, segmentMidIndex + 1, rangeRight);
        }
    }
};

using namespace std;

class NumArray
{
    SegmentTree segmentTree;

public:
    NumArray(vector<int> &nums) : segmentTree(nums)
    {
    }

    void update(int index, int val)
    {
        segmentTree.update(index, val);
    }

    int sumRange(int left, int right)
    {
        return segmentTree.query(left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

int main()
{
    vector<int> nums; // = {-2, 0, 3, -5, 2, -1};
    nums.push_back(-2);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(-5);
    nums.push_back(2);
    nums.push_back(-1);
    NumArray arr(nums);
    arr.sumRange(0, 2);
}
```





## [LeetCode-938. Range Sum of BST-easy](https://leetcode.cn/problems/range-sum-of-bst/)