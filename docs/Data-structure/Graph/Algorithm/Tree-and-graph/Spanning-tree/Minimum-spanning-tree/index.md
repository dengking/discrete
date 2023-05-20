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



## LeetCode

https://leetcode.cn/tag/minimum-spanning-tree/problemset/



