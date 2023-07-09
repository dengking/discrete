# [LeetCode-307. Range Sum Query-Mutable-Medium](https://leetcode.cn/problems/range-sum-query-mutable/)



## segment tree



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

