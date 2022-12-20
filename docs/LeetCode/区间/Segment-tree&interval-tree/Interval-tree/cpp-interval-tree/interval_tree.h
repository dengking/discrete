#include <memory>
#include <algorithm>
#include <limits>

/// @brief 区间
struct Interval
{
    int low_{0}, high_{0};
    Interval(int low, int high) : low_{low}, high_{high}
    {
    }
    /// @brief this 和 other是否相交
    /// @param other
    /// @return
    bool Overlap(const Interval &other) const
    {
        if (this->high_ < other.low_ || this->low_ > other.high_)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

/// @brief 树节点
struct Node
{
    Interval i_;
    int max_{std::numeric_limits<int>::min()};
    std::unique_ptr<Node> left_{nullptr};
    std::unique_ptr<Node> right_{nullptr};
    Node(int low, int high) : i_{low, high}
    {
    }
};

class IntervalTree
{
    std::unique_ptr<Node> root_;

public:
    IntervalTree() = default;

    /// @brief 通过insert来构建BST
    /// @param low
    /// @param high
    void Insert(int low, int high)
    {
        InsertImpl(root_, low, high);
    }
    /// @brief 搜索与i相交的interval
    /// @param i
    /// @return
    Interval *OverlapSearch(const Interval &i) const
    {
        return OverlapSearchImpl(root_, i);
    }

private:
    /// @brief 使用递归的方式来实现insert
    /// @param root
    /// @param low
    /// @param high
    void InsertImpl(std::unique_ptr<Node> &root, int low, int high)
    {
        if (root)
        {
            if (root_->i_.low_ < low)
            {
                InsertImpl(root_->right_, low, high);
            }
            else
            {
                InsertImpl(root_->left_, low, high);
            }
        }
        else
        {
            root = std::make_unique<Node>(low, high);
        }
        root->max_ = std::max(root->max_, high);
    }
    /// @brief
    /// @param root
    /// @param i
    /// @return
    Interval *OverlapSearchImpl(const std::unique_ptr<Node> &root, const Interval &i) const
    {
        
    }
};

int main()
{
}