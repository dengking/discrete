#include <vector>

/// @brief
class DisjointSet
{
public:
    DisjointSet(std::size_t n) : parent_(n), set_cnt_{n}
    {
        for (int i = 0; i < n; ++i)
        {
            parent_[i] = i; // 初始化的时候，每个节点都是一棵单点树
            size_[i] = 1;
            rank_[i] = 0;
        }
    }

    /// @brief 使用recursion的方式实现find set representative/root
    /// @param idex
    /// @return
    int find_by_recursion(int idx)
    {
        if (parent_[idx] != idx)
        {
            // 在向上寻找的过程中同时进行优化: 它会将从idx到set representative/root的这条路上的所有的节点都设置为指向set representative/root
            parent_[idx] = find_by_recursion(parent_[idx]);
            return parent_[idx]; // 需要注意，它返回的是修改后的值
        }
        else
        {
            return parent_[idx];
        }
    }

    /// @brief 使用iteration的方式实现find set representative/root
    /// @param idx
    /// @return
    int find_by_two_pass_iteration(int idx)
    {
        int root = idx;
        while (parent_[root] != root) // 找到set representative/root
        {
            root = parent_[root];
        }
        while (parent_[idx] != idx) // 优化: 它会将从idx到set representative/root的这条路上的所有的节点都设置为指向set representative/root
        {
            int parent = parent_[idx];
            parent_[idx] = root;
            idx = parent;
        }
        return root;
    }
    /// @brief
    /// @param idx
    /// @return
    int find_by_path_split(int idx)
    {
        while (parent_[idx] != idx)
        {
            int grandparent = parent_[parent_[idx]];
            int parent = parent_[idx];
            parent_[idx] = grandparent; // Path splitting replaces every parent pointer on that path by a pointer to the node's grandparent
            idx = parent;               // iteration
        }
        return idx;
    }

    int find_by_path_halving(int idx)
    {
        while (parent_[idx] != idx)
        {
            int grandparent = parent_[parent_[idx]];
            parent_[idx] = grandparent; // Path halving works similarly but replaces only every other parent pointer
            idx = parent_[idx];         // iteration
        }
        return idx;
    }
    /// @brief 判断idx是否是set representative/root
    /// @param
    /// @return
    bool is_root(int idx)
    {
        return parent_[idx] == idx;
    }

    void Union(int i, int j)
    {
        int i_root = find_by_path_split(i);
        int j_root = find_by_path_split(j);
        if (i_root != j_root)
        {
            parent_[i_root] = j_root;
            --set_cnt_;
        }
    }
    /// @brief union by size
    /// @param i
    /// @param j
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
            --set_cnt_;
        }
    }

    /// @brief union by rank
    /// @param i
    /// @param j
    void union_by_rank(int i, int j)
    {
        int i_root = find_by_path_split(i);
        int j_root = find_by_path_split(j);
        if (i_root != j_root)
        {
            if (rank_[i_root] < rank_[j_root])
            {
                parent_[i_root] = j_root;
            }
            else if (rank_[i_root] > rank_[j_root])
            {
                parent_[j_root] = i_root;
            }
            else
            {
                parent_[j_root] = i_root;
                rank_[i_root] += 1;
            }
            --set_cnt_;
        }
    }

private:
    std::vector<int> parent_;
    std::vector<int> size_;
    std::vector<int> rank_;
    std::size_t set_cnt_{0}; // disjoint set的个数
};

int main()
{
}
