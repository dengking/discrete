# Static problem、dynamic problem

是在wikipedia [Computational geometry](https://en.wikipedia.org/wiki/Computational_geometry) 中发现这个topic的:

> Yet another major class is the [dynamic problems](https://en.wikipedia.org/wiki/Dynamic_problem_(algorithms)), in which the goal is to find an efficient algorithm for finding a solution repeatedly after each incremental modification of the input data (addition or deletion input geometric elements). Algorithms for problems of this type typically involve [dynamic data structures](https://en.wikipedia.org/wiki/Dynamic_data_structures). Any of the computational geometric problems may be converted into a dynamic one, at the cost of increased processing time. For example, the [range searching](https://en.wikipedia.org/wiki/Range_searching) problem may be converted into the [dynamic range searching](https://en.wikipedia.org/w/index.php?title=Dynamic_range_searching&action=edit&redlink=1) problem by providing for addition and/or deletion of the points. The [dynamic convex hull](https://en.wikipedia.org/wiki/Dynamic_convex_hull) problem is to keep track of the convex hull, e.g., for the dynamically changing set of points, i.e., while the input points are inserted or deleted.

## wikipedia [Dynamic problem (algorithms)](https://en.wikipedia.org/wiki/Dynamic_problem_(algorithms))



### Special cases

**Incremental algorithms**, or [online algorithms](https://en.wikipedia.org/wiki/Online_algorithm), are algorithms in which only additions of elements are allowed, possibly starting from the empty/trivial input data.

**Decremental algorithms** are algorithms in which only deletions of elements are allowed, starting with an initialization of a full data structure.

If both additions and deletions are allowed, the algorithm is sometimes called **fully dynamic**.
