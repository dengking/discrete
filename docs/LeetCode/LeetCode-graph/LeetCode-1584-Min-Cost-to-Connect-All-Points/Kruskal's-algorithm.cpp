#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/// @brief
class DisjointSet
{
public:
    DisjointSet(int n) : parent_(n), size_(n)
    {
        for (int i = 0; i < n; ++i)
        {
            parent_[i] = i;
            size_[i] = 1;
        }
    }
    /// @brief
    /// @param idx
    /// @return
    int find_by_path_split(int idx)
    {
        while (parent_[idx] != idx)
        {
            int parent = parent_[idx];
            parent_[idx] = parent_[parent_[idx]]; // Path splitting replaces every parent pointer on that path by a pointer to the node's grandparent
            idx = parent;                         // iteration
        }
        return idx;
    }

    void union_by_size(int i, int j)
    {
        int i_root = find_by_path_split(i);
        int j_root = find_by_path_split(j);
        if (i_root != j_root)
        {
            if (size_[i_root] < size_[j_root])
            {
                parent_[i_root] = j_root;
                size_[j_root] += size_[i_root];
            }
            else
            {
                parent_[j_root] = i_root;
                size_[i_root] += size_[j_root];
            }
        }
    }

private:
    vector<int> parent_;
    vector<int> size_;
};

/// @brief
class Solution
{
    struct Edge
    {
        int p1_;
        int p2_;
        int weight_;
        Edge(int p1, int p2, int weight) : p1_{p1}, p2_{p2}, weight_{weight}
        {
        }

        bool operator<(const Edge &other) const
        {
            return this->weight_ < other.weight_;
        }
    };

public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        vector<Edge> edges;
        std::size_t edge_cnt = (points.size() * (points.size() - 1)) / 2;
        edges.reserve(edge_cnt);
        DisjointSet disjoint_set(points.size());
        for (int i = 0; i < points.size(); ++i)
        {
            for (int j = i + 1; j < points.size(); ++j)
            {
                edges.emplace_back(i, j, manhattan_distance(points[i], points[j]));
            }
        }
        std::sort(edges.begin(), edges.end());
        int result = 0;
        for (auto &&edge : edges)
        {
            if (disjoint_set.find_by_path_split(edge.p1_) != disjoint_set.find_by_path_split(edge.p2_))
            {
                disjoint_set.union_by_size(edge.p1_, edge.p2_);
                result += edge.weight_;
            }
        }
        return result;
    }
    int manhattan_distance(const vector<int> &p1, const vector<int> &p2)
    {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
};

int main()
{
}