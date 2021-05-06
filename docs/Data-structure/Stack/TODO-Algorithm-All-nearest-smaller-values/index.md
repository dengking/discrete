# wikipedia [All nearest smaller values](https://en.wikipedia.org/wiki/All_nearest_smaller_values)

> NOTE: 
>
> 两个限制：
>
> - nearest 最近
> - smaller 更小

In [computer science](https://en.wikipedia.org/wiki/Computer_science), the **all nearest smaller values** problem is the following task: 

for each position in a sequence of numbers, search among the previous positions for the **last position**（也就是最近的nearest ） that contains a **smaller** value. This problem can be solved efficiently both by parallel and non-parallel algorithms: [Berkman, Schieber & Vishkin (1993)](https://en.wikipedia.org/wiki/All_nearest_smaller_values#CITEREFBerkmanSchieberVishkin1993), who first identified the procedure as a useful subroutine for other parallel programs, developed efficient [algorithms](https://en.wikipedia.org/wiki/Parallel_algorithms) to solve it in the [Parallel Random Access Machine](https://en.wikipedia.org/wiki/Parallel_Random_Access_Machine) model; it may also be solved in [linear time](https://en.wikipedia.org/wiki/Linear_time) on a non-parallel computer using a [stack](https://en.wikipedia.org/wiki/Stack_(data_structure))-based algorithm. Later researchers have studied algorithms to solve it in other models of parallel computation. 

## Example

 Suppose that the input is the binary [van der Corput sequence](https://en.wikipedia.org/wiki/Van_der_Corput_sequence) 

 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15. 

 The first element of the sequence (0) has no previous value. The nearest (only) smaller value previous to 8 and to 4 is 0. All three values previous to 12 are smaller, but the **nearest** one is 4. Continuing in the same way, the nearest previous smaller values for this sequence (indicating the nonexistence of a previous smaller value by a dash) are 

 —, 0, 0, 4, 0, 2, 2, 6, 0, 1, 1, 5, 1, 3, 3, 7. 

 In most applications, the positions of the **nearest smaller values**, and not the values themselves, should be computed, and in many applications the same computation should be computed for the reversal of the sequence in order to find the following smaller value that is closest in the sequence. 

## Applications

[Berkman, Schieber & Vishkin (1993)](https://en.wikipedia.org/wiki/All_nearest_smaller_values#CITEREFBerkmanSchieberVishkin1993) mention many other problems that may be solved efficiently in parallel using a nearest smaller values computation. Among them, they include the following:

1、[Merge algorithms](https://en.wikipedia.org/wiki/Merge_algorithm), computing the merge step of a [merge sort](https://en.wikipedia.org/wiki/Merge_sort). The input to these algorithms consists of two sorted arrays of numbers; the desired output is the same set of numbers in a single sorted array. If one concatenates the two sorted arrays, the first in ascending order and the second in descending order, then the predecessor of each value in the output is either its closest previous smaller value or its closest following smaller value (whichever of the two is larger), and the position of each value in the sorted output array may easily be calculated from the positions of these two nearest smaller values.

- Construction of [Cartesian trees](https://en.wikipedia.org/wiki/Cartesian_tree). A Cartesian tree is a [data structure](https://en.wikipedia.org/wiki/Data_structure) introduced by [Vuillemin (1980)](https://en.wikipedia.org/wiki/All_nearest_smaller_values#CITEREFVuillemin1980) and further studied by [Gabow, Bentley & Tarjan (1984)](https://en.wikipedia.org/wiki/All_nearest_smaller_values#CITEREFGabowBentleyTarjan1984) for [range searching](https://en.wikipedia.org/wiki/Range_searching) applications. Cartesian trees also arise in the definition of the [treap](https://en.wikipedia.org/wiki/Treap) and [randomized binary search tree](https://en.wikipedia.org/wiki/Randomized_binary_search_tree) data structures for [binary searching](https://en.wikipedia.org/wiki/Binary_search). The Cartesian tree of a sequence of values has a node for each value. The root of the tree is the minimum value of the sequence; for every other node, the parent of the node is either its closest previous smaller value or its closest following smaller value (whichever of the two exists and is larger). Thus, Cartesian trees may be constructed in linear time based on an all nearest smaller values algorithm.
- Matching [parentheses](https://en.wikipedia.org/wiki/Parenthesis). If a sequence of open and close parenthesis characters is given as input, together with the nesting depth of each parenthesis, then the match to each open parenthesis is the next close parenthesis with no larger nesting depth, so it can be found by an all nearest smaller values computation that breaks ties in favor of close parentheses. If the nesting depths are not given, they can be calculated using a [prefix sum](https://en.wikipedia.org/wiki/Prefix_sum)computation.

Similar techniques may also be applied to problems of [polygon triangulation](https://en.wikipedia.org/wiki/Polygon_triangulation), [convex hull](https://en.wikipedia.org/wiki/Convex_hull) construction (parallelizing the sequential [Graham scan](https://en.wikipedia.org/wiki/Graham_scan) convex hull algorithm), reconstruction of trees from two of the trees' traversal orderings, and quadtree construction.[[1\]](https://en.wikipedia.org/wiki/All_nearest_smaller_values#cite_note-1)

## Sequential algorithm

On a sequential computer, it is straightforward to compute all nearest smaller values using a [stack data structure](https://en.wikipedia.org/wiki/Stack_(data_structure)): one processes the values in sequence order, using the stack to maintain a subsequence of the values that have been processed so far and are smaller than any later value that has already been processed. In [pseudocode](https://en.wikipedia.org/wiki/Pseudocode), the algorithm is as follows. 

```pseudocode
S = new empty stack data structure
for x in the input sequence:
    while S is nonempty and the top element of S is greater than or equal to x:
        pop S
    if S is empty:
        x has no preceding smaller value
    else:
        the nearest smaller value to x is the top element of S
    push x onto S
```

> NOTE: 	该算法的目的是寻找最近的并且比我小的元素，显然它有两个需求：
>
> 1、最近
>
> 2、比我小（肯定要基于比较）
>
> 对这个问题的分析要搞清楚的是，它的最值是在**最近**上，而不是在**最小**上，栈的这种后进先出的特性是非常适合于本问题所需求的**最近**，借助栈，我们可以将过去的状态保留下来，所以对于每个新元素，从栈顶到栈底，距离它越来越远；我们需要考虑的是结合问题的特性来决定何时pop，从算法的实现上来看，这个算法所操作的仅仅是栈顶的元素：
>
> ```
> while S is nonempty and the top element of S is greater than or equal to x:
>     pop S
> ```
>
> 这是决定何时出栈，本算法的需求是求**最近比我小的元素**，当我发现此时栈顶的元素还比我大的时候，显然这个元素既没有我更近，也没我更小，所以按照这两个标准，我是能够替代它的，所以可以将**他们**全部pop，即将他们都淘汰；
>
> 以下是几个典型的例子：
>
> 1、2、3、4、5、6、7、8、1
>
> 这个例子是序列是递增的，显然，会一直压栈知道第二个1出现，此时会接入`while`循环，`while`循环不停地出栈，直到栈为空；
>
> 2、3、4、5、6、7、8、9、1



Despite having a nested loop structure, the running time of this algorithm is linear, because every iteration of the inner loop removes an item that had been added in some previous iteration of the outer loop. It is closely related to an algorithm of [Knuth](https://en.wikipedia.org/wiki/Donald_Knuth) for [sorting with a stack](https://en.wikipedia.org/wiki/Stack-sortable_permutation) (for inputs that can be sorted in this way).[[2\]](https://en.wikipedia.org/wiki/All_nearest_smaller_values#cite_note-2)

An even simpler linear-time sequential algorithm ([Barbay, Fischer & Navarro (2012)](https://en.wikipedia.org/wiki/All_nearest_smaller_values#CITEREFBarbayFischerNavarro2012), Lemma 1) does not even need a stack; it assumes that the input sequence is given as an array A[1,n], and stores the index `j` of the preceding smaller value of the i'th value A[i] in P[i]. We assume an artificial（假设的） overall minimum at A[0]:

```pseudocode
for i from 1 to n:
    j = i-1
    while A[j] >= A[i]:
        j = P[j]
    P[i] = j
```

> NOTE: 
>
> 其实通过上述算法发现这个问题存在着一定的递归性（第n+1个元素的nearest smaller元素要么是它的前一个元素要么就是它的前一个元素的nearest smaller元素）的意味：要想获得第`i`个元素的结果，其实只需要做两件事：
>
> 1、和它的前一个元素进行比较，如果前一个元素比他还小，则结果就是它的前一个元素，否则
>
> 2、和它的前一个元素的结果进行比较，如此往复，直至找到了目标值；
>
> 



### 比较

比较这两种算法的实现思路：

算法1使用的数据结构是栈，栈顶元素，它对输入数据所使用的数据结构没有任何的限制；算法2要求输入数据是支持random access的，它使用数组`p`来保存结果，这样它能够充分利用这个问题的递归性，如果从这个角度来进行分析的话，算法1中的栈其实也是原来保存结果的，只不过它具有一定的优化（使用了淘汰机制）；其实从这个角度也看出了数据结构和算法的紧密关联；

