#include <vector>

using namespace std;

class RangSumSegmentTree {
    std::vector<int> tree_;
    const std::vector<int> &nums_;

public:
    RangSumSegmentTree(const std::vector<int> &nums) : nums_(nums), tree_(nums.size() * 4) {
        buildTree(0, 0, nums_.size() - 1);
    }

    int query(int left, int right) {
        return query(0, 0, nums_.size() - 1, left, right);
    }

private:
    void buildTree(int root, int lo, int hi) {
        if (lo == hi) {
            tree_[root] = nums_[lo];
        } else {
            int mid = lo + (hi - lo) / 2;
            int left = root * 2 + 1;
            int right = root * 2 + 2;
            buildTree(left, lo, mid);
            buildTree(right, mid + 1, hi);
            tree_[root] = tree_[left] + tree_[right];
        }
    }

    int query(int root, int lo, int hi, int i, int j) {
        if (lo > j || hi < i) { // segment completely outside range
            return 0; // represents a null node
        } else if (i <= lo && j >= hi) { // segment completely inside range
            return tree_[root];
        } else {
            int mid = lo + (hi - lo) / 2;
            int left = root * 2 + 1;
            int right = root * 2 + 2;
            if (j <= mid) { // 位于左子树
                return query(left, lo, mid, i, j);
            } else if (i > mid) { // 位于右子树
                return query(right, mid + 1, hi, i, j);
            } else {
                return query(left, lo, mid, i, mid) + query(right, mid + 1, hi, mid + 1, j);
            }
        }
    }
};

class NumArray {
    RangSumSegmentTree segmentTree_;
public:
    NumArray(vector<int> &nums) : segmentTree_{nums} {

    }

    int sumRange(int left, int right) {
        return segmentTree_.query(left, right);
    }
};