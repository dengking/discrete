#include <algorithm>
#include <unordered_map>
#include <vector>
#include <unordered_set>

using namespace std;

struct Node {
    int x_{0};
    int y_{0};
    Node *next_{nullptr};
    Node *parent_{nullptr};
    std::size_t size_{1};
    bool flipFlag_{true}; // 是否翻转标志
    Node(int x, int y, bool flipFlag) : x_{x}, y_{y}, flipFlag_{flipFlag} {
        next_ = this;
        parent_ = this;
    }

    bool isRoot() {
        return parent_ == this;
    }
};

class DisjointSet {
    std::vector<Node *> nodes_;
    std::size_t maxRow_{0};
    std::size_t maxCol_{0};
    std::unordered_set<Node *> roots_;

private:
    Node *&getNode(std::size_t row, std::size_t col) {
        return nodes_[row * maxCol_ + col];
    }

    bool isBorder(int x, int y) {
        return x == 0 || x == maxRow_ - 1 ||
               y == 0 || y == maxCol_ - 1;
    }

public:
    DisjointSet(std::size_t maxRow, std::size_t maxCol) : nodes_(maxRow * maxCol, nullptr), maxRow_{maxRow},
                                                          maxCol_{maxCol} {
    }

    Node *add(int x, int y) {
        Node *node = new Node(x, y, !isBorder(x, y));
        getNode(x, y) = node;
        roots_.insert(node);
        return node;
    }

    /// @brief path split
    /// @param x
    /// @param y
    /// @return
    Node *find(int x, int y) {
        Node *node = getNode(x, y);
        while (!node->isRoot()) {
            Node *temp = node->parent_;
            node->parent_ = node->parent_->parent_;
            node = temp;
        }
        return node;
    }

    Node *Union(int x1, int y1, int x2, int y2) {
        Node *node1 = find(x1, y1); // 后续一直作为新的root
        Node *node2 = find(x2, y2);
        if (node1 != node2) {
            Node *tmp = node2->next_;
            node2->next_ = node1->next_;
            node1->next_ = tmp;
            if (node2->size_ < node1->size_) // node1 要挂到 node2上
            {
                std::swap(node1, node2);
            }
            node2->parent_ = node1;
            roots_.erase(node2);
            node1->flipFlag_ &= node2->flipFlag_;
            node1->size_ += node2->size_;
        }
        return node1;
    }

    std::unordered_set<Node *> &getSets() {
        return roots_;
    }
};

class Solution {
    int maxCol_{0};
    int maxRow_{0};

public:
    void solve(vector<vector<char>> &board) {
        maxRow_ = board.size();
        maxCol_ = board[0].size();
        DisjointSet disjointSet(maxRow_, maxCol_);
        for (int x = 0; x < maxRow_; ++x) {
            for (int y = 0; y < maxCol_; ++y) {
                if (board[x][y] == 'O') {
                    disjointSet.add(x, y);
                    int aboveX = x - 1;
                    if (aboveX >= 0 && board[aboveX][y] == 'O') // 存在above
                    {
                        disjointSet.Union(x, y, aboveX, y);
                    }
                    int leftY = y - 1;
                    if (leftY >= 0 && board[x][leftY] == 'O') // 存在left
                    {
                        disjointSet.Union(x, y, x, leftY);
                    }
                }
            }
        }
        for (auto &&root: disjointSet.getSets()) {
            if (root->flipFlag_) {
                board[root->x_][root->y_] = 'X';
                Node *node = root->next_;
                while (root != node) {
                    board[node->x_][node->y_] = 'X';
                    node = node->next_;
                }
            }
        }
    }
};

int main() {
    vector<vector<char>> board{{'X', 'X', 'X', 'X'},
                               {'X', 'O', 'O', 'X'},
                               {'X', 'X', 'O', 'X'},
                               {'X', 'O', 'X', 'X'}};
    Solution s;
    s.solve(board);
}