# Formal analysis of quick sort

zhihu [【算法分析选例】快速排序（1）](https://zhuanlan.zhihu.com/p/35180653)



## wikipedia [Quicksort](https://en.wikipedia.org/wiki/Quicksort) # [Formal analysis](https://en.wikipedia.org/wiki/Quicksort#Formal_analysis)

> NOTE: 
>
> 一、以下分析是使用quicksort中所执行的比较的次数来作为复杂性计算的单位的；
>
> 其实quicksort的比较都是发生在`partition`函数中；
>
> 二、为了便于分析，可以以quick sort一个长度为5的array为例来进行说明
>
> ![](./quick-sort-activation-tree.jpg)
>
> 

#### Worst-case analysis

The most unbalanced partition occurs when one of the **sublists** returned by the partitioning routine is of size *n* − 1.[[27\]](https://en.wikipedia.org/wiki/Quicksort#cite_note-unbalanced-27) This may occur if the **pivot** happens to be the smallest or largest element in the list, or in some implementations (e.g., the Lomuto partition scheme as described above) when all the elements are equal.

If this happens repeatedly in every partition, then each recursive call processes a list of size one less than the previous list. Consequently, we can make *n* − 1 nested calls before we reach a list of size 1. This means that the [call tree](https://en.wikipedia.org/wiki/Call_stack) is a linear chain of *n* − 1 nested calls. The *i*th call does *O*(*n* − *i*) work to do the partition, and $ \textstyle \sum _{i=0}{n}(n-i)=O(n^{2}) $, so in that case Quicksort takes *O*(*n*²) time.

> NOTE: 
>
> 一、其实这种情况本质上是BST退化为了linked list，此时树的高度为$n$。
>
> 第0次调用quicksort需要进行n此比较，第1次调用quicksort需要进行n-1次比较，依次类推，所以总的耗费为n此调用之和；所以就是$ \textstyle \sum _{i=0}{n}(n-i)=O(n^{2}) $；
>
> 这种情况其实就是[Bubble sort](https://en.wikipedia.org/wiki/Bubble_sort)，算法复杂度就是$O(n^{2})$
>
> 二、以quick sort一个长度为5的array为例来进行说明
>
> 

#### Best-case analysis

In the most **balanced** case, each time we perform a partition we divide the list into two nearly equal pieces. This means each recursive call processes a list of half the size. Consequently, we can make only $log_2{n}$ nested calls before we reach a list of size 1. This means that the depth of the [call tree](https://en.wikipedia.org/wiki/Call_stack) is $log_2{n}$. But no two calls at the same level of the call tree process the same part of the original list; thus, each level of calls needs only *O*(*n*) time all together (each call has some constant overhead, but since there are only *O*(*n*) calls at each level, this is subsumed in the *O*(*n*) factor). The result is that the algorithm uses only *O*(*n* log *n*) time.

> NOTE: 
>
> 一、上述分析是能够帮助我们理解quick sort的computation complexity的，它是非常简单易懂的
>
> 二、上述complexity analysis，使用到了 binary search 的 computation complexity analysis: 
>
> 在均衡的情况下，树的高度为$logn$，每层的比较次数为$n$，因此总的computation complexity为: *O*(*n* log *n*) 
>
> 三、best-case其实是非常类似于balanced binary search tree的；
>
> 

#### Average-case analysis

> NOTE: 下面设计了很多的数学推导，比较难以理解，我们重点关注"Using a binary search tree"

To sort an array of *n* distinct elements, quicksort takes *O*(*n* log *n*) time in expectation, averaged over all *n*! permutations of *n* elements with [equal probability](https://en.wikipedia.org/wiki/Uniform_distribution_(discrete)). We list here three common proofs to this claim providing different insights into quicksort's workings.

##### Using percentiles百分位数值

##### Using recurrences



##### Using a binary search tree

> NOTE: 
>
> 一、quick sort隐式地构造了一颗BST

To each execution of **quicksort** corresponds the following [binary search tree](https://en.wikipedia.org/wiki/Binary_search_tree) (BST): 

the **initial pivot** is the **root node**; 

the **pivot of the left half** is the **root of the left subtree**, 

the **pivot of the right half** is the **root of the right subtree**, and so on. 

The number of comparisons of the execution of quicksort equals the number of comparisons during the construction of the BST by a sequence of insertions. So, the average number of comparisons for randomized quicksort equals the average cost of constructing a BST when the values inserted $ (x_{1},x_{2},\ldots ,x_{n}) $ form a random permutation.

Consider a BST created by insertion of a sequence $ (x_{1},x_{2},\ldots ,x_{n}) $ of values forming a random permutation. Let *C* denote the cost of creation of the BST. We have $ C=\sum *{i}\sum *{j<i}c*{i,j} $, where $ c*{i,j} $ is an binary random variable expressing whether during the insertion of $ x_{i} $ there was a comparison to $ x_{j} $.

By [linearity of expectation](https://en.wikipedia.org/wiki/Expected_value#Linearity), the expected value $ \operatorname {E} [C] $ of *C* is $ \operatorname {E} [C]=\sum _{i}\sum *{j<i}\Pr(c*{i,j}) $.

Fix *i* and *j*<*i*. The values $ {x_{1},x_{2},\ldots ,x_{j}} $, once sorted, define *j*+1 intervals. The core structural observation is that $ x_{i} $ is compared to $ x_{j} $ in the algorithm if and only if $ x_{i} $ falls inside one of the two intervals adjacent to $ x_{j} $.

Observe that since $ (x_{1},x_{2},\ldots ,x_{n}) $ is a random permutation, $ (x_{1},x_{2},\ldots ,x_{j},x_{i}) $ is also a random permutation, so the probability that $ x_{i} $ is adjacent to $ x_{j} $ is exactly $ {\frac {2}{j+1}} $.

We end with a short calculation:

$ \operatorname {E} [C]=\sum _{i}\sum _{j<i}{\frac {2}{j+1}}=O\left(\sum _{i}\log i\right)=O(n\log n). $



