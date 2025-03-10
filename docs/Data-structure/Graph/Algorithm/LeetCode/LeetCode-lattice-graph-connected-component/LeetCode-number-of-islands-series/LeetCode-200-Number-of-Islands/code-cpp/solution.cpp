#include <vector>
#include <unordered_set>
using namespace std;

struct Node
{
    int x_{0};
    int y_{0};
    Node *parent_{nullptr};
    std::size_t size_{1};
    Node(int x, int y) : x_{x}, y_{y}
    {
        parent_ = this;
    }

    bool isRoot()
    {
        return parent_ == this;
    }
};

class DisjointSet
{
    std::vector<Node *> nodes_;
    std::size_t maxRow_{0};
    std::size_t maxCol_{0};
    std::size_t rootCnt_{0};

private:
    Node *&getNode(std::size_t row, std::size_t col)
    {
        return nodes_[row * maxCol_ + col];
    }

    bool isBorder(int x, int y)
    {
        return x == 0 || x == maxRow_ - 1 ||
               y == 0 || y == maxCol_ - 1;
    }

public:
    DisjointSet(std::size_t maxRow, std::size_t maxCol) : nodes_(maxRow * maxCol, nullptr), maxRow_{maxRow},
                                                          maxCol_{maxCol}
    {
    }

    Node *add(int x, int y)
    {
        Node *node = new Node(x, y);
        getNode(x, y) = node;
        ++rootCnt_;
        return node;
    }

    /// @brief path split
    /// @param x
    /// @param y
    /// @return
    Node *find(int x, int y)
    {
        Node *node = getNode(x, y);
        while (!node->isRoot())
        {
            Node *temp = node->parent_;
            node->parent_ = node->parent_->parent_;
            node = temp;
        }
        return node;
    }

    Node *Union(int x1, int y1, int x2, int y2)
    {
        Node *node1 = find(x1, y1); // 后续一直作为新的root
        Node *node2 = find(x2, y2);
        if (node1 != node2)
        {

            if (node2->size_ < node1->size_) // node1 要挂到 node2上
            {
                std::swap(node1, node2);
            }
            node2->parent_ = node1;
            --rootCnt_;
            node1->size_ += node2->size_;
        }
        return node1;
    }

    std::size_t getRootCnt()
    {
        return rootCnt_;
    }
};

class Solution
{
    int maxCol_{0};
    int maxRow_{0};

public:
    int numIslands(vector<vector<char>> &grid)
    {
        maxRow_ = grid.size();
        maxCol_ = grid[0].size();
        DisjointSet disjointSet(maxRow_, maxCol_);
        for (int x = 0; x < maxRow_; ++x)
        {
            for (int y = 0; y < maxCol_; ++y)
            {
                if (grid[x][y] == '1')
                {
                    disjointSet.add(x, y);
                    int aboveX = x - 1;
                    if (aboveX >= 0 && grid[aboveX][y] == '1') // 存在above
                    {
                        disjointSet.Union(x, y, aboveX, y);
                    }
                    int leftY = y - 1;
                    if (leftY >= 0 && grid[x][leftY] == '1') // 存在left
                    {
                        disjointSet.Union(x, y, x, leftY);
                    }
                }
            }
        }
        return disjointSet.getRootCnt();
    }
};

int main()
{
}