# Divide-and-conquer

分治的思想是: 对于难以直接求解的问题，可以考虑把这个问题分解成若干规模较小的相同子问题，从而各个击破，分而治之。

它是典型的自顶向下进行分析，"divide-and-conquer"是非常重要的计算思想，它简单然而强大，它的计算方式是one-by-one。

## wikipedia [Divide-and-conquer algorithm](https://en.wikipedia.org/wiki/Divide-and-conquer_algorithm)

In [computer science](https://en.wikipedia.org/wiki/Computer_science), **divide and conquer** is an [algorithm design paradigm](https://en.wikipedia.org/wiki/Algorithm_design_paradigm) based on multi-branched [recursion](https://en.wikipedia.org/wiki/Recursion). A divide-and-conquer [algorithm](https://en.wikipedia.org/wiki/Algorithm) works by recursively breaking down a problem into two or more sub-problems of the same or related type, until these become simple enough to be solved directly. The solutions to the sub-problems are then combined to give a solution to the original problem.

> NOTE: 
>
> 1、"multi-branched recursion"如何理解
>
> 典型的，当"multi=2"的时候，就二分法了，这是经常采用的。
>
> 2、显然，"divide"几份，就对应了几个branch

This divide-and-conquer technique is the basis of efficient algorithms for all kinds of problems, such as [sorting](https://en.wikipedia.org/wiki/Sorting_algorithm) (e.g., [quicksort](https://en.wikipedia.org/wiki/Quicksort), [merge sort](https://en.wikipedia.org/wiki/Merge_sort)), [multiplying large numbers](https://en.wikipedia.org/wiki/Multiplication_algorithm) (e.g. the [Karatsuba algorithm](https://en.wikipedia.org/wiki/Karatsuba_algorithm)), finding the [closest pair of points](https://en.wikipedia.org/wiki/Closest_pair_of_points_problem), [syntactic analysis](https://en.wikipedia.org/wiki/Syntactic_analysis)(e.g., [top-down parsers](https://en.wikipedia.org/wiki/Top-down_parser)), and computing the [discrete Fourier transform](https://en.wikipedia.org/wiki/Discrete_Fourier_transform) ([FFT](https://en.wikipedia.org/wiki/Fast_Fourier_transform)).

Understanding and designing divide-and-conquer algorithms is a complex skill that requires a good understanding of the nature of the underlying problem to be solved. As when proving a [theorem](https://en.wikipedia.org/wiki/Theorem) by [induction](https://en.wikipedia.org/wiki/Mathematical_induction), it is often necessary to replace the original problem with a more general or complicated problem in order to initialize the recursion, and there is no systematic method for finding the proper generalization.[*clarification needed*] These divide-and-conquer complications are seen when optimizing the calculation of a [Fibonacci number with efficient double recursion](https://en.wikipedia.org/wiki/Fibonacci_number#Matrix_form).[*why?*][*citation needed*]

> NOTE:
>
> 1、正如使用induction来证明一个定理，为了初始化递归，需要使用一个更加general或者更加complicate问题来替换原问题。
>
> 


The correctness of a divide-and-conquer algorithm is usually proved by [mathematical induction](https://en.wikipedia.org/wiki/Mathematical_induction), and its computational cost is often determined by solving [recurrence relations](https://en.wikipedia.org/wiki/Recurrence_relation).

> NOTE: 
>
> 1、[recurrence relations](https://en.wikipedia.org/wiki/Recurrence_relation) 的意思是：递推关系
>
> 2、[mathematical induction](https://en.wikipedia.org/wiki/Mathematical_induction) 的意思是: 数学归纳法



### Decrease and conquer

These algorithms can be implemented more efficiently than general divide-and-conquer algorithms; in particular, if they use [tail recursion](https://infogalactic.com/info/Tail_recursion), they can be converted into simple [loops](https://infogalactic.com/info/Loop_(computing)). 

> NOTE:
>
> 1、tail recursion: recursion to loop

### Advantages



#### Solving difficult problems



#### Algorithm efficiency



#### Parallelism

> NOTE: 
>
> 1、需要思考，如何并行化divide and conquer algorithm

#### Memory access

> NOTE: 
>
> 1、这一段关于 memory、cache的论述是非常好的

#### Roundoff control

> NOTE: 
>
> 1、"Roundoff"的含义是 "圆整"



## Divide-and-conquer-and-merge 算法的框架

这种算法的典型是merge-sort，这种算法的实现一般基于DFS-recursion-two-direction:

1、top-down~reduce~pre-order~action

2、bottom-up~produce~post-order~action



### <计算机算法设计与分析>第四版王晓东编著

**分治法**的基本思想是将一个规模为`n`的问题分解为`k`个规模较小的**子问题**，这些**子问题**互相独立切与原问题相同。**递归**的解这些**子问题**，然后将各子问题的解**合并**得到原问题的解；它的一般算法设计模式如下：

```C++
divide-and-conquer(P){
	if(|p|<=n0) adhoc(P);
	divid P into smaller instances P1,P2...,Pk;
	for(i=1;i<=k;i++){
		yi = divide-and-conquer(Pi);
	}
	return merge(y1, y2...,yk);
}
```

1、其中`|P|`表示问题P的规模，`n0`为一阈值，表示当问题P的规模不超过`n0`时，问题已经容易解出，不必再继续分解。

2、`adhoc(P)`是该分治法的**基本子算法**，用于直解小规模的问题P。当P的规模不超过`n0`时，直接用算法`adhoc(P)`求解。

3、`merge(y1,y2…,yk)`是该**分治法**中的**合并子算法**，用于将`P`的子问题`P1，P3…，PK`合并为`P`的解。

根据分治法的分割原则应把原问题分为多少个子问题才比较合适宜？每个子问题是否规模相同或怎样才为适当？这些问题很难予以肯定的回答。但人们从大量实践中发现，在用**分治法**设计算法时最好使子问题的规模大致相同。即将一个问题分解为大小相等的`K`个子问题的处理方法是行之有效的。许多问题可以取`K=2`（即二分）。这种使子问题规模大致相等的做法出自一种**平衡子问题**的思想，它几乎总是比子问题规模不等的做法要好。

从分治法的一般设计模式可以看出，用它设计出的程序一般是**递归算法**。因此分治法的计算效率通常可以用**递归方程**来进行分析。一个分制法将规模为n的问题分解成k个规模为`n/m`的子问题去解。为方便起见，设分解阈值`n0=1`，且`adhoc`解规模为1的问题的耗费一个单位时间。另外，在设将原问题分解为K个子问题及用`merge`将k个子问题的解合并为原问题的解需要`f(n)`个单位时间。如果用`T(n)`表示该分治法解规模为P等于N的问题所需的计算时间，则有 
$$
T(n) =
\begin{cases}
O(1),  & n =1 \\
kT(n/m), & n \gt 1
\end{cases}
$$





上述所给出的是分治法的通用的**算法复杂度公式**，下面列举一些比较常见的使用分治法的算法的复杂度：



## Divide-and-conquer and parallel computing

distributed computing、parallel computing 都蕴含着 divide-and-conquer思想。

### Parallel computing 加速 divide-and-conquer

Parallel computing、distributed computing能够加速divide-and-conquer的性能

一、"fork and join parallel divide-and-conquer"

典型的例子就是 "APUE 11.6.8 Barriers" 中的merge sort的例子。

二、"distributed computing parallel divide-and-conquer"



### 使用divide-and-conquer来分解

> NOTE: 
>
> 1、这是在阅读 "drdobbs [How Much Scalability Do You Have or Need?](https://www.drdobbs.com/parallel/how-much-scalability-do-you-have-or-need/201202924) # O(N): Scalable Throughput And the Free Lunch" 时，想到的，其中将此称为 "**natural parallelism**"。我们将此称为"fork-join-parallel-divide-and-conquer-and-merge-quicksort-natural parallelism"

1、当今"parallel computing是主流"，我们更应该使用"divide-and-conquer"来对structure进行分解，让各个sub structure被并行地计算

2、distributed computing、parallel computing 都 蕴含着 divide-and-conquer思想



### 参见

1、"wikipedia [Divide-and-conquer algorithm](https://en.wikipedia.org/wiki/Divide-and-conquer_algorithm) # Parallelism"章节

2、工程"Parallel-computing"的`Fork–join-model`章节

3、stackoverflow [difference of divide and conquer & fork and join](https://stackoverflow.com/questions/29686964/difference-of-divide-and-conquer-fork-and-join)



## 重叠子问题

对于重叠子问题，我们可以将它们的解保存下来，用于后续的使用，从而提高性能。

1、重叠子问题，参见 `Overlapping-subproblem` 章节

2、"time and space tradeoff"，参见 `Space-time-tradeoff` 章节 



## 素材

一、labuladong [手把手搞懂接雨水问题的多种解法](https://mp.weixin.qq.com/s/mFqrlhqYEPhRa9p4ewl3Xw)

> 对于这种问题，我们不要想整体，而应该去想局部；就像之前的文章写的动态规划问题处理字符串问题，不要考虑如何处理整个字符串，而是去思考应该如何处理每一个字符。
>
> 这么一想，可以发现这道题的思路其实很简单。具体来说，仅仅对于位置`i`，能装下多少水呢？



二、programiz [Divide and Conquer Algorithm](https://www.programiz.com/dsa/divide-and-conquer) 

三、softwareengineering.stackexchange [Divide and Conquer algorithms – Why not split in more parts than two?](https://softwareengineering.stackexchange.com/questions/197107/divide-and-conquer-algorithms-why-not-split-in-more-parts-than-two) # [A](https://softwareengineering.stackexchange.com/a/197111)  

非常好的解释


四、https://www.khanacademy.org/computing/computer-science/algorithms/merge-sort/a/divide-and-conquer-algorithms

