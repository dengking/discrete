# Minimum spanning tree

 最小生成树。

## wikipedia [Minimum spanning tree](https://en.wikipedia.org/wiki/Minimum_spanning_tree) 

More generally, any edge-weighted undirected graph (not necessarily connected) has a **minimum spanning forest**, which is a union of the minimum spanning trees for its [connected components](https://en.wikipedia.org/wiki/Connected_component_(graph_theory)).



[![img](https://upload.wikimedia.org/wikipedia/commons/thumb/d/d2/Minimum_spanning_tree.svg/300px-Minimum_spanning_tree.svg.png)](https://en.wikipedia.org/wiki/File:Minimum_spanning_tree.svg)



> A [planar graph](https://en.wikipedia.org/wiki/Planar_graph) and its minimum spanning tree. Each edge is labeled with its weight, which here is roughly proportional to its length.



### Algorithms

| 发现次序 | algorithm                                                    |                  |
| -------- | ------------------------------------------------------------ | ---------------- |
| first    | [Borůvka's algorithm](https://en.wikipedia.org/wiki/Borůvka's_algorithm) | greedy algorithm |
| second   | [Prim's algorithm](https://en.wikipedia.org/wiki/Prim's_algorithm) | greedy algorithm |
| third    | [Kruskal's algorithm](https://en.wikipedia.org/wiki/Kruskal's_algorithm) | greedy algorithm |
| fourth   | [Reverse-delete algorithm](https://en.wikipedia.org/wiki/Reverse-delete_algorithm) | greedy algorithm |

All four of these are [greedy algorithms](https://en.wikipedia.org/wiki/Greedy_algorithm). Since they run in polynomial time, the problem of finding such trees is in **[FP](https://en.wikipedia.org/wiki/FP_(complexity))**, and related [decision problems](https://en.wikipedia.org/wiki/Decision_problem) such as determining whether a particular edge is in the MST or determining if the minimum total weight exceeds a certain value are in **[P](https://en.wikipedia.org/wiki/P_(complexity))**.

### Applications

Minimum spanning trees have direct applications in the design of networks, including [computer networks](https://en.wikipedia.org/wiki/Computer_network), [telecommunications networks](https://en.wikipedia.org/wiki/Telecommunications_network), [transportation networks](https://en.wikipedia.org/wiki/Transport_network), [water supply networks](https://en.wikipedia.org/wiki/Water_supply_network), and [electrical grids](https://en.wikipedia.org/wiki/Electrical_grid) (which they were first invented for, as mentioned above).[[17\]](https://en.wikipedia.org/wiki/Minimum_spanning_tree#cite_note-17) 

They are invoked as subroutines in algorithms for other problems, including:

1、the [Christofides algorithm](https://en.wikipedia.org/wiki/Christofides_algorithm) for approximating the [traveling salesman problem](https://en.wikipedia.org/wiki/Traveling_salesman_problem),[[18\]](https://en.wikipedia.org/wiki/Minimum_spanning_tree#cite_note-18) 

2、approximating the multi-terminal minimum cut problem (which is equivalent in the single-terminal case to the [maximum flow problem](https://en.wikipedia.org/wiki/Maximum_flow_problem)),[[19\]](https://en.wikipedia.org/wiki/Minimum_spanning_tree#cite_note-19) 

3、approximating the minimum-cost weighted perfect [matching](https://en.wikipedia.org/wiki/Matching_(graph_theory)).[[20\]](https://en.wikipedia.org/wiki/Minimum_spanning_tree#cite_note-20)



Other practical applications based on minimal spanning trees include:

[Taxonomy](https://en.wikipedia.org/wiki/Taxonomy_(general)).[[21\]](https://en.wikipedia.org/wiki/Minimum_spanning_tree#cite_note-21) 

> NOTE:
>
> 一、分类学 

[Cluster analysis](https://en.wikipedia.org/wiki/Cluster_analysis): clustering points in the plane,[[22\]](https://en.wikipedia.org/wiki/Minimum_spanning_tree#cite_note-22) [single-linkage clustering](https://en.wikipedia.org/wiki/Single-linkage_clustering) (a method of [hierarchical clustering](https://en.wikipedia.org/wiki/Hierarchical_clustering)),[[23\]](https://en.wikipedia.org/wiki/Minimum_spanning_tree#cite_note-23) graph-theoretic clustering,[[24\]](https://en.wikipedia.org/wiki/Minimum_spanning_tree#cite_note-24) and clustering [gene expression](https://en.wikipedia.org/wiki/Gene_expression) data.[[25\]](https://en.wikipedia.org/wiki/Minimum_spanning_tree#cite_note-25)



Constructing trees for [broadcasting](https://en.wikipedia.org/wiki/Broadcasting_(networking)) in computer networks.[[26\]](https://en.wikipedia.org/wiki/Minimum_spanning_tree#cite_note-26)



[Image registration](https://en.wikipedia.org/wiki/Image_registration)[[27\]](https://en.wikipedia.org/wiki/Minimum_spanning_tree#cite_note-27) and [segmentation](https://en.wikipedia.org/wiki/Image_segmentation)[[28\]](https://en.wikipedia.org/wiki/Minimum_spanning_tree#cite_note-28) – see [minimum spanning tree-based segmentation](https://en.wikipedia.org/wiki/Minimum_spanning_tree-based_segmentation).



Curvilinear [feature extraction](https://en.wikipedia.org/wiki/Feature_extraction) in [computer vision](https://en.wikipedia.org/wiki/Computer_vision).[[29\]](https://en.wikipedia.org/wiki/Minimum_spanning_tree#cite_note-29)



[Handwriting recognition](https://en.wikipedia.org/wiki/Handwriting_recognition) of mathematical expressions.[[30\]](https://en.wikipedia.org/wiki/Minimum_spanning_tree#cite_note-30)



[Circuit design](https://en.wikipedia.org/wiki/Circuit_design): implementing efficient multiple constant multiplications, as used in [finite impulse response](https://en.wikipedia.org/wiki/Finite_impulse_response) filters.[[31\]](https://en.wikipedia.org/wiki/Minimum_spanning_tree#cite_note-31)



[Regionalisation](https://en.wikipedia.org/wiki/Regionalisation) of socio-geographic areas, the grouping of areas into homogeneous, contiguous regions.[[32\]](https://en.wikipedia.org/wiki/Minimum_spanning_tree#cite_note-32)



Comparing [ecotoxicology](https://en.wikipedia.org/wiki/Ecotoxicology) data.[[33\]](https://en.wikipedia.org/wiki/Minimum_spanning_tree#cite_note-33)



Topological [observability](https://en.wikipedia.org/wiki/Observability) in power systems.[[34\]](https://en.wikipedia.org/wiki/Minimum_spanning_tree#cite_note-34)



Measuring homogeneity of two-dimensional materials.[[35\]](https://en.wikipedia.org/wiki/Minimum_spanning_tree#cite_note-35)



Minimax [process control](https://en.wikipedia.org/wiki/Process_control).[[36\]](https://en.wikipedia.org/wiki/Minimum_spanning_tree#cite_note-36)



Minimum spanning trees can also be used to describe financial markets.[[37\]](https://en.wikipedia.org/wiki/Minimum_spanning_tree#cite_note-37)[[38\]](https://en.wikipedia.org/wiki/Minimum_spanning_tree#cite_note-38) A correlation matrix can be created by calculating a coefficient of correlation between any two stocks. This matrix can be represented topologically as a complex network and a minimum spanning tree can be constructed to visualize relationships.



## Prim's algorithm



### wikipedia [Prim's algorithm](https://en.wikipedia.org/wiki/Prim%27s_algorithm)





## Borůvka's algorithm



### wikipedia [Borůvka's algorithm](https://en.wikipedia.org/wiki/Bor%C5%AFvka%27s_algorithm)



## Kruskal's algorithm



### wikipedia [Kruskal's algorithm](https://en.wikipedia.org/wiki/Kruskal%27s_algorithm)

**Kruskal's algorithm**[[1\]](https://en.wikipedia.org/wiki/Kruskal's_algorithm#cite_note-1) finds a [minimum spanning forest](https://en.wikipedia.org/wiki/Minimum_spanning_tree) of an undirected [edge-weighted graph](https://en.wikipedia.org/wiki/Weighted_graph). 

If the graph is [connected](https://en.wikipedia.org/wiki/Connectivity_(graph_theory)), it finds a [minimum spanning tree](https://en.wikipedia.org/wiki/Minimum_spanning_tree). (A minimum spanning tree of a connected graph is a subset of the [edges](https://en.wikipedia.org/wiki/Edge_(graph_theory)) that forms a tree that includes every [vertex](https://en.wikipedia.org/wiki/Vertex_(graph_theory)), where the sum of the [weights](https://en.wikipedia.org/wiki/Weighted_graph) of all the edges in the tree is minimized. 

For a disconnected graph, a minimum spanning forest is composed of a minimum spanning tree for each [connected component](https://en.wikipedia.org/wiki/Connected_component_(graph_theory)).) 

It is a [greedy algorithm](https://en.wikipedia.org/wiki/Greedy_algorithm) in [graph theory](https://en.wikipedia.org/wiki/Graph_theory) as in each step it adds the next lowest-weight edge that will not form a [cycle](https://en.wikipedia.org/wiki/Cycle_(graph_theory)) to the **minimum spanning forest**.

> NOTE:
>
> 一、
>
> 1、undirected
>
> 2、forest
>
> 3、connected、disconnected
>
> 4、edge-driven



#### Algorithm

1、create a forest *F* (a set of trees), where each vertex in the graph is a separate [tree](https://en.wikipedia.org/wiki/Tree_(graph_theory))

2、create a sorted set *S* containing all the edges in the graph

3、while *S* is [nonempty](https://en.wikipedia.org/wiki/Nonempty) and *F* is not yet [spanning](https://en.wikipedia.org/wiki/Spanning_tree)

- remove an edge with minimum weight from *S*
- if the removed edge connects two different trees then add it to the forest *F*, combining two trees into a single tree



#### Pseudocode

The following code is implemented with a [disjoint-set data structure](https://en.wikipedia.org/wiki/Disjoint-set_data_structure). Here, we represent our forest *F* as a set of edges, and use the disjoint-set data structure to efficiently determine whether two vertices are part of the same tree.

```pseudocode
algorithm Kruskal(G) is
    F:= ∅
    for each v ∈ G.V do
        MAKE-SET(v)
    for each (u, v) in G.E ordered by weight(u, v), increasing do
        if FIND-SET(u) ≠ FIND-SET(v) then
            F:= F ∪ {(u, v)} ∪ {(v, u)}
            UNION(FIND-SET(u), FIND-SET(v))
    return F
```



## Implementation

```c++
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
```



## LeetCode

https://leetcode.cn/tag/minimum-spanning-tree/problemset/



[LeetCode-1489. Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree-中等](https://leetcode.cn/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/)

[LeetCode-1584. Min Cost to Connect All Points-中等](https://leetcode.cn/problems/min-cost-to-connect-all-points/)





