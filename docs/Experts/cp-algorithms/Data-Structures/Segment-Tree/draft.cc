#include <algorithm>
#include <vector>
#include <iostream>
#include <concepts>

template <typename T, std::invocable<T> MergeFunc>
class SegmentTree
{
private:
    std::vector<T> tree_;
    const MergeFunc &mergeFunc;

public:
    SegmentTree(const std::vector<T> &arr, MergeFunc &&mergeFunc) : mergeFunc(mergeFunc)
    {
        tree_.resize(arr.size() * 4);
        lazy_.resize(arr.size() * 4);
        build(0, 0, arr.size() - 1);
    }
    /// @brief 将arr[i, j]范围内的元素的值设置为newVal
    /// @param i
    /// @param j
    /// @param newVal
    void rangeAdd(int i, int j, T &&newVal)
    {
    }

private:
    void build(int rootIdx, int lo, int hi, const std::vector<T> &arr)
    {
        if (lo == hi) // Leaf node
        {
            tree_[rootIdx] = arr[rootIdx];
        }
        else
        {
            int mid = lo + (hi - lo) / 2;
            int left = rootIdx * 2 + 1, right = rootIdx * 2 + 2;
            build(left, lo, mid, arr);
            build(right, mid + 1, hi, arr);
            tree_[rootIdx] = T(); // internal node
        }
    }

    void update(int rootIdx, int lo, int hi, int idx, T newVal)
    {
    }
};