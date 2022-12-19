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
};

int main()
{
}