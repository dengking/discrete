# R-tree



## wikipedia [R-tree](https://en.wikipedia.org/wiki/R-tree)

**R-trees** are [tree data structures](https://en.wikipedia.org/wiki/Tree_data_structure) used for [spatial access methods](https://en.wikipedia.org/wiki/Spatial_index), i.e., for indexing multi-dimensional information such as [geographical coordinates](https://en.wikipedia.org/wiki/Geographic_coordinate_system), [rectangles](https://en.wikipedia.org/wiki/Rectangle) or [polygons](https://en.wikipedia.org/wiki/Polygon). 

### R-tree idea

The key idea of the data structure is to group nearby objects and represent them with their [minimum bounding rectangle](https://en.wikipedia.org/wiki/Minimum_bounding_rectangle) in the next higher level of the tree; the "R" in R-tree is for rectangle. Since all objects lie within this **bounding rectangle**, a query that does not intersect(相交) the **bounding rectangle** also cannot intersect any of the contained objects. At the leaf level, each rectangle describes a single object; at higher levels the aggregation includes an increasing number of objects. This can also be seen as an increasingly coarse approximation of the data set.

> NOTE:
>
> 一、"At the leaf level, each rectangle describes a single object; at higher levels the aggregation includes an increasing number of objects. This can also be seen as an increasingly coarse approximation of the data set."
>
> 最后一句话的意思: "这也可以看作是对数据集的一种越来越粗糙的近似"，因为在更高层，范围越广泛

Similar to the [B-tree](https://en.wikipedia.org/wiki/B-tree), the R-tree is also a **balanced search tree** (so all leaf nodes are at the same depth), organizes the data in pages, and is designed for storage on disk (as used in [databases](https://en.wikipedia.org/wiki/Database)). Each page can contain a maximum number of entries, often denoted as $M$. It also guarantees a **minimum fill** (except for the root node), however best performance has been experienced with a **minimum fill** of 30%–40% of the maximum number of entries (B-trees guarantee 50% page fill, and [B*-trees](https://en.wikipedia.org/wiki/B*-tree) even 66%). The reason for this is the more complex balancing required for spatial data as opposed to linear data stored in B-trees.

> NOTE:
>
> 一、上述**minimum fill**，参见:
>
> 1、stackoverflow [B-tree minimum internal children count explanation](https://stackoverflow.com/questions/59362113/b-tree-minimum-internal-children-count-explanation)
>
> 

As with most trees, the searching algorithms (e.g., [intersection](https://en.wikipedia.org/wiki/Intersection_(set_theory)), containment, [nearest neighbor search](https://en.wikipedia.org/wiki/Nearest_neighbor_search)) are rather simple. The key idea is to use the bounding boxes to decide whether or not to search inside a subtree. In this way, most of the nodes in the tree are never read during a search.

> NOTE:
>
> 一、上面这段话让我有如下思考:
>
> 典型的tree-contain关系: 
>
> 区域、range、范围、括号、disjoin、 [intersection](https://en.wikipedia.org/wiki/Intersection_(set_theory)), containment,  [nearest neighbor search](https://en.wikipedia.org/wiki/Nearest_neighbor_search) 
>
> 空间范围是能够很好地划分开来的

Like B-trees, R-trees are suitable for large data sets and [databases](https://en.wikipedia.org/wiki/Database), where nodes can be paged to memory when needed, and the whole tree cannot be kept in main memory. Even if data can be fit in memory (or cached), the R-trees in most practical applications will usually provide performance advantages over naive check of all objects when the number of objects is more than few hundred or so. However, for in-memory applications, there are similar alternatives that can provide slightly better performance or be simpler to implement in practice. To maintain in-memory computing for R-tree in a computer cluster where computing nodes are connected by a network, researchers have used RDMA ([Remote Direct Memory Access](https://en.wikipedia.org/wiki/Remote_direct_memory_access)) to implement data-intensive applications under R-tree in a distributed environment.[[6\]](https://en.wikipedia.org/wiki/R-tree#cite_note-6) This approach is scalable for increasingly large applications and achieves high throughput and low latency performance for R-tree.



## TODO

zhihu [什么是R树？](https://zhuanlan.zhihu.com/p/62639268)