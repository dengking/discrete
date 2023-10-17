# divide-and-conquer-and-merge 算法的框架





## 《计算机算法设计与分析》第四版王晓东编著

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

### 二分算法

下面是一些典型的二分算法，即取k=2。

#### [二分搜索](https://en.wikipedia.org/wiki/Binary_search_algorithm)

$$
T(n) = 2T(n/2) = \log_2 n
$$


wikipedia [二分搜索](https://en.wikipedia.org/wiki/Binary_search_algorithm)


参见《`algorithm-analysis-binary-search.md`》

#### [合并排序](https://en.wikipedia.org/wiki/Merge_sort)

$$
T(n) =
\begin{cases}
O(1),  & n \le 1 \\
2T(n/2) + O(n), & n \gt 1
\end{cases}
$$

解上述递归方程，可知
$$
T(n) = O(n\log n)
$$



wikipedia [合并排序](https://en.wikipedia.org/wiki/Merge_sort)


#### [快速排序](https://en.wikipedia.org/wiki/Quicksort)

$$
T(n) =
\begin{cases}
O(1),  & n \le 1 \\
2T(n/2) + O(n), & n \gt 1
\end{cases}
$$

解上述递归方程，可知
$$
T(n) = O(n\log n)
$$

wikipedia [快速排序](https://en.wikipedia.org/wiki/Quicksort) 

#### 补充: 使用二分思想的算法

1、[LeetCode-23. 合并K个升序链表](https://leetcode.cn/problems/merge-k-sorted-lists/)  # 方法三：分治合并

自顶向下

2、quick select

参见  labuladong [快排亲兄弟：快速选择算法详解](https://mp.weixin.qq.com/s/TRO3FOKT90Mpvn3hQWVBAQ) 。

3、merge sort

参见 labuladong [东哥手把手带你套框架刷通二叉树|第一期](https://mp.weixin.qq.com/s/izZ5uiWzTagagJec6Y7RvQ) 

```C++
void sort(int[] nums, int lo, int hi) {
    int mid = (lo + hi) / 2;
    sort(nums, lo, mid);
    sort(nums, mid + 1, hi);

    /****** 后序遍历位置 ******/
    // 合并两个排好序的子数组
    merge(nums, lo, mid, hi);
    /************************/
}
```

4、两数之和、三数之和

参见 labuladong [双指针技巧汇总](https://mp.weixin.qq.com/s/yLc7-CZdti8gEMGWhd0JTg) 





tag-DFS-recursion-two-direction=top-down~reduce~pre-order~action+bottom-up~produce~post-order~action-merge-sort
