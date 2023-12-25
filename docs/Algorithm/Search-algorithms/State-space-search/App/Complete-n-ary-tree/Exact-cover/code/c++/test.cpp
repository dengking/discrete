#include <unordered_map>
#include <iostream>
#include <format>
#include <vector>

using namespace std;

class NumArray {
    vector<int> tree_;
    int length;

private:
    void buildSegmentTree(vector<int> &nums, int root, int lo, int hi) {
        if (lo == hi) {
            tree_[root] = nums[lo];
            return;
        }
        int mid = lo + (hi - lo) / 2;
        buildSegmentTree(nums, root * 2 + 1, lo, mid);
        buildSegmentTree(nums, root * 2 + 2, mid + 1, hi);
        tree_[root] = tree_[root * 2 + 1] + tree_[root * 2 + 2];
    }

    static inline bool
    isSegmentInsideRange(int segmentLowIndex, int segmentHighIndex, int rangeLeftIndex, int rangeRightIndex) {
        return rangeLeftIndex <= segmentLowIndex && rangeRightIndex >= segmentHighIndex;
    }

    int querySegmentTree(int root, int lo, int hi, int i, int j) {
        if (i > hi || j < lo) {
            return 0;
        }
        if (isSegmentInsideRange(lo, hi, i, j)) {
            return tree_[root];
        }
        int segmentMidIndex = lo + (hi - lo) / 2;
        if (i > segmentMidIndex) // 位于右子树
        {
            return querySegmentTree(root * 2 + 2, segmentMidIndex + 1, hi, i,
                                    j);
        } else if (j <= segmentMidIndex) // 位于左子树
        {
            return querySegmentTree(root * 2 + 1, lo, segmentMidIndex, i,
                                    j);
        } else {
            return querySegmentTree(root * 2 + 1, lo, segmentMidIndex, i,
                                    segmentMidIndex) +
                   querySegmentTree(root * 2 + 2, segmentMidIndex + 1, hi, segmentMidIndex + 1,
                                    j);
        }
    }

public:
    NumArray(vector<int> &nums) {
        length = nums.size();
        tree_.resize(length * 4);
        buildSegmentTree(nums, 0, 0, length - 1);
    }

    int sumRange(int left, int right) {
        return querySegmentTree(0, 0, length - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

int main() {
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