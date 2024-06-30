# Binary-search

素材: 

一. LeetCode

- [LeetBook 列表](https://leetcode.cn/leetbook/)/[二分查找](https://leetcode.cn/leetbook/detail/binary-search/)

- [学习计划广场](https://leetcode.cn/study-plan/)→专项突破→[二分查找](https://leetcode.cn/study-plan/binary-search/)

二. [随心源](https://leetcode.cn/u/sui-xin-yuan/) 

- [随心源](https://leetcode.cn/u/sui-xin-yuan/) # [34. 蓝红二分法单模板秒杀二分查找](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/solution/lan-hong-hua-fen-fa-dan-mo-ban-miao-sha-e7r40/) 

- [随心源](https://leetcode.cn/u/sui-xin-yuan/) # [1201. 蓝红二分法分左右](https://leetcode.cn/problems/ugly-number-iii/solution/by-sui-xin-yuan-o8zd/) 

- [随心源](https://leetcode.cn/u/sui-xin-yuan/) # [二分查找模块全解](https://leetcode.cn/circle/article/xYBtLt/) 

- [随心源](https://leetcode.cn/u/sui-xin-yuan/) # [二分查找模块全解](https://leetcode.cn/circle/article/xYBtLt/)

三. labuladong

**labuladong** [二分搜索只能用来查找元素吗？](https://mp.weixin.qq.com/s/QC24hyg0ZgjR7-LgnEzMYg)

**labuladong** [我作了首诗，保你闭着眼睛也能写对二分查找](https://mp.weixin.qq.com/s/M1KfTfNlu4OCK8i9PSAmug) 

四. wikipedia [Binary search algorithm](https://en.wikipedia.org/wiki/Binary_search_algorithm) 

五. programmingpraxis [Binary Search With Duplicates](https://programmingpraxis.com/2017/11/07/binary-search-with-duplicates/)



## wikipedia [Binary search algorithm](https://en.wikipedia.org/wiki/Binary_search_algorithm) 

In [computer science](https://en.wikipedia.org/wiki/Computer_science), **binary search**, also known as **half-interval search**, **logarithmic search**, or **binary chop**, is a [search algorithm](https://en.wikipedia.org/wiki/Search_algorithm) that finds the position of a target value within a [sorted array](https://en.wikipedia.org/wiki/Sorted_array). Binary search compares the target value to the middle element of the array. If they are not equal, the half in which the target cannot lie is eliminated and the search continues on the remaining half, again taking the middle element to compare to the target value, and repeating this until the target value is found. If the search ends with the remaining half being empty, the target is not in the array.

Binary search runs in [logarithmic time](https://en.wikipedia.org/wiki/Time_complexity#Logarithmic_time) in the [worst case](https://en.wikipedia.org/wiki/Best,_worst_and_average_case), making $ O(\log n) $ comparisons, where $ n $ is the number of elements in the array, the $ O $ is [Big O notation](https://en.wikipedia.org/wiki/Big_O_notation), and $ \log $​ is the [logarithm](https://en.wikipedia.org/wiki/Logarithm). Binary search is faster than [linear search](https://en.wikipedia.org/wiki/Linear_search) except for small arrays. However, the array must be sorted first to be able to apply binary search. There are specialized [data structures](https://en.wikipedia.org/wiki/Data_structures) designed for fast searching, such as [hash tables](https://en.wikipedia.org/wiki/Hash_tables), that can be searched more efficiently than binary search. However, binary search can be used to solve a wider range of problems, such as finding the **next-smallest** or **next-largest** element in the array relative to the **target** even if it is absent from the array.

There are numerous variations of binary search. In particular, [fractional cascading](https://en.wikipedia.org/wiki/Fractional_cascading) speeds up binary searches for the same value in multiple arrays. **Fractional cascading** efficiently solves a number of search problems in [computational geometry](https://en.wikipedia.org/wiki/Computational_geometry) and in numerous other fields. [Exponential search](https://en.wikipedia.org/wiki/Exponential_search) extends binary search to unbounded lists. The [binary search tree](https://en.wikipedia.org/wiki/Binary_search_tree) and [B-tree](https://en.wikipedia.org/wiki/B-tree) data structures are based on binary search.

> NOTE: 
>
> 一. [fractional cascading](https://en.wikipedia.org/wiki/Fractional_cascading) 即 分数级连

### Algorithm

#### Procedure

```pseudocode
function binary_search(A, n, T):
    L := 0
    R := n − 1
    while L <= R:
        m := floor((L + R) / 2)
        if A[m] < T:
            L := m + 1
        else if A[m] > T:
            R := m - 1
        else:
            return m
    return unsuccessful
```

##### Alternative procedure

In the above procedure, the algorithm checks whether the middle element ($ m $) is **equal to** the target ($ T $) in every iteration. Some implementations leave out this check during each iteration. The algorithm would perform this check only when one element is left (when $ L=R $). This results in a faster comparison loop, as one comparison is eliminated per iteration. However, it requires one more iteration on average.

[Hermann Bottenbruch](https://en.wikipedia.org/wiki/Hermann_Bottenbruch) published the first implementation to leave out this check in 1962.

```pseudocode
function binary_search_alternative(A, n, T):
    L := 0
    R := n − 1
    while L != R:
        m := ceil((L + R) / 2)
        if A[m] > T:
            R := m - 1
        else:
            L := m
    if A[L] == T:
        return L
    return unsuccessful
```

> NOTE: 
>
> 这种实现方式和上面那种的实现方式的差异在于上面的那种方式在每次循环中对target和中间元素（后续为了描述遍历，将它称为pivot）进行了两次比较：
>
> - **大于**的比较
> - **小于**的比较
>
> 由于进行了两次的比较所以它能够将整个序列分为三份：pivot、左边一份（不包括pivot）和右边一份（不包括pivot），所以程序可以非常准确地判断要进入到哪个分支中；
>
> 但是这种算法，由于只进行了一次比较，所以它只能够将这个序列分成两部分，并且由于没有进行等于的判断，所以不能够确定pivot是否是target，所以只能够将它归入左边分支后者右边分支。上述算法中将pivot归入了右边分支，所以左边分支就可以不需要考虑pivot了，所以`R := m - 1`；
>
> Set $ m $ (the position of the middle element) to the [ceiling](https://en.wikipedia.org/wiki/Floor_and_ceiling_functions)（天花板） of $ {\frac {L+R}{2}} $是否可以使用floor呢？是有差别的：当最终数组只剩下两个元素的时候，如果使用floor，则此时m会一直等于left，如果`A[m] <= T`，则程序会一直进入到上述伪代码中的else分支中。
>



#### Duplicate elements

> NOTE:
>
> 1. 本节中给出的pseudocode是假设有多个target是存在于array中的

The procedure may return any index whose element is equal to the **target value**, even if there are duplicate elements in the array. For example, if the array to be searched was $ [1,2,3,4,4,5,6,7] $ and the target was $ 4 $, then it would be correct for the algorithm to either return the 4th (index 3) or 5th (index 4) element. The regular procedure would return the 4th element (index 3) in this case. It does not always return the **first** duplicate (consider $ [1,2,4,4,4,5,6,7] $ which still returns the 4th element). However, it is sometimes necessary to find the **leftmost** element or the **rightmost** element for a target value that is duplicated in the array. In the above example, the 4th element is the **leftmost** element of the value 4, while the 5th element is the **rightmost** element of the value 4. The alternative procedure above will always return the index of the **rightmost** element if such an element exists.

> NOTE: 
>
> 这些其实就是left bound 和 right bound，在 **labuladong** [我作了首诗，保你闭着眼睛也能写对二分查找](https://mp.weixin.qq.com/s/M1KfTfNlu4OCK8i9PSAmug) 中有着非常好的分析 

##### Procedure for finding the leftmost element

```pseudocode
function binary_search_leftmost(A, n, T):
    L := 0
    R := n
    while L < R:
        m := floor((L + R) / 2)
        if A[m] < T:
            L := m + 1
        else:
            R := m
    return L
```

##### Procedure for finding the rightmost element

```pseudocode
function binary_search_rightmost(A, n, T):
    L := 0
    R := n
    while L < R:
        m := floor((L + R) / 2)
        if A[m] > T:
            R := m
        else:
            L := m + 1
    return R - 1
```



#### Approximate matches

The above procedure only performs ***exact* matches**, finding the position of a target value. However, it is trivial to extend **binary search** to perform **approximate matches** because binary search operates on sorted arrays. For example, binary search can be used to compute, for a given value, its 

- rank (the number of smaller elements), 

  > NOTE: 
  >
  > 1. 例子 [LeetCode-35. 搜索插入位置](https://leetcode.cn/problems/search-insert-position/) 

- predecessor (next-smallest element)

- successor (next-largest element), and 

- [nearest neighbor](https://en.wikipedia.org/wiki/Nearest_neighbor_search) 

- [Range queries](https://en.wikipedia.org/wiki/Range_query_(data_structures)) 



[Range queries](https://en.wikipedia.org/wiki/Range_query_(data_structures)) seeking the number of elements between two values can be performed with two rank queries.

> NOTE: 
>
> 一、例子
>
> [LeetCode-34. 在排序数组中查找元素的第一个和最后一个位置](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/)

1. Rank queries can be performed with the [procedure for finding the leftmost element](https://en.wikipedia.org/wiki/Binary_search_algorithm#Procedure_for_finding_the_leftmost_element). The number of elements *less than* the target value is returned by the procedure.
2. Predecessor queries can be performed with rank queries. If the rank of the target value is $r$, its predecessor is $r-1$.
3. For successor queries, the [procedure for finding the rightmost element](https://en.wikipedia.org/wiki/Binary_search_algorithm#Procedure_for_finding_the_rightmost_element) can be used. If the result of running the procedure for the target value is $ r$, then the successor of the target value is $r+1$.
4. The nearest neighbor of the target value is either its predecessor or successor, whichever is closer.
5. Range queries are also straightforward. Once the ranks of the two values are known, the number of elements greater than or equal to the first value and less than the second is the difference of the two ranks. This count can be adjusted up or down by one according to whether the endpoints of the range should be considered to be part of the range and whether the array contains entries matching those endpoints.



### Performance

> NOTE:
>
> 一. 对binary search的complexity-analysis在 `O(logN)` 中也有描述
>
> 

### Library support

C++'s Standard Template Library provides the functions `binary_search()`, `lower_bound()`, `upper_bound()` and `equal_range()`.



## Search space

为了描述方便，使用range来表示**搜索区间**，使用 `left`、`right` 对 **range** 进行界定: 

1. **左闭右闭** 
   - 区间非空的条件是 left <= right
   - 初始化: left=0, right=N-1

2. **左闭右开**
   - 区间非空的条件是 left < right，需要注意是不能够取等于的，因为是左闭右开，当取等于的时候，区间已经空了
   - 初始化: left=0, right=N

**搜索区间的界定是要统一的，在开始搜索前和搜索中，在搜索中，需要不断地变化搜索区间，需要始终保持区间策略的一致**。

## Bindery search approximation

二分搜索能够保证range不断地缩小， `left`、`right` 不断地向target**逼近**(approximation)，这是binary search的原理，是理解它的基础。

渐渐地**range**的长度会缩减为2(即此时left pointer 和 right pointer**相遇**)，然后缩减为1(即此时left pointer 和 right pointer**重叠**)，最终缩减为0退出while loop。



## 四种写法

Binary-search的应用范围比较广泛:

- *exact* matches: 用于准确地搜索target
- *approximate* matches: 用于搜索和target相近的元素

*approximate* matches 相较于 *exact* matches，应用范围是更加广泛的。

`nums`中可能存在0个、1个、多个target。

| Left/leftmost bound                                    | Right/rightmost bound                               |
| ------------------------------------------------------ | --------------------------------------------------- |
| predecessor/next-smallest element/小于target的最大的数 | successor/next-largest element/大于target的最小的数 |
| 等于target的最左边的数/leftmost target                 | 等于target的最右边的数/rightmost target             |
|                                                        |                                                     |



### Naive exact match1

#### `while` loop

while的条件是基于range，while循环体也是对range进行操作。 

`while`的条件: **range**非空，即当搜索区间非空的时候(只有一个元素也是非空的)，需要进行搜索。

`while`的退出:

- 未找到target，最终循环条件不满足，range为空

- 找到target，从循环中break



### Naive exact match2



### Left bound、right bound

基本的naive exact match binary search是比较容易理解，难点是 **left bound** 和 **right bound**。

对于left bound、right bound，当`nums[mid] == target`时，它会将`nums[mid]`从range中剔除以控制range往指定的方向移动(后面会进行详细讨论)，因此while的退出肯定是因为range为空。

说明: 下面的讨论假定range是 **左闭右闭** 

#### 详细说明

1. targe存在于`nums`中

   最终left、right肯定会逼近目标元素，最终的终止条件是left > right，即`left==right+1` ，即left在right的右侧；
   
   |              | left bound                                                   | right bound                                                  |
   | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
   | **移动方向** | 控制**range**往left方向移动以找到left bound                  | 控制**range**往right方向移动以找到right bound                |
   | **返回值**   | `left`                                                       | `right`                                                      |
   |              | 当命中target的时候，不断地缩小right以控制**range**往left方向移动，最终，right错过target，指向target的左侧，当循环条件不满足，即`left== right+1`，left指向target，因此最终返回left； | 当命中target的时候，不断地增大left以控制**range**往right方向移动，最终，left错过target，指向target的右侧，当循环条件不满足，即`left==right+1`，right指向target，因此最终返回right； |
   | **越界保护** | 由于算法最终返回left，并且算法中执行left + 1，当target不存在的时候是可能越界的，因此在返回left之前是需要进行越界保护的，因此需要考虑left超过array的范围（overflow） | 由于算法最终返回right，并且算法中执行right - 1，当target不存在的时候是可能越界的，因此在返回right之前是需要进行越界保护的，因此需要考虑right超过array的范围（underflow） |




2. target不存在于`nums`中: 

   - target比所有的都小，因此最终left、right都位于左侧
     - 对于**left bound**: 最终返回的是left，此时left是安全的，不会越界；
     - 对于**right bound**: 最终返回的是right，此时right是不安全的，可能越界(比如left为0，那么right就是-1)，显然这是越界；

   - target比所有的都大，因此最终left、right都位于右侧
     - 对于**left bound**: 最终返回的是left，此时left是不安全的，可能越界；
     - 对于**right bound**: 最终返回的是right，此时right是安全的，不会越界

   可以看到: 可能的情况是非常多的



[LeetCode-34. Find First and Last Position of Element in Sorted Array](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/) 

```python
from typing import *


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        return [self.left_bound(nums, target), self.right_bound(nums, target)]

    def left_bound(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = l + (r - l) // 2
            if nums[mid] == target:
                r = mid - 1
            elif nums[mid] > target:
                r = mid - 1
            else:
                l = mid + 1
        if l < len(nums) and nums[l] == target:
            return l
        else:
            return -1

    def right_bound(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = l + (r - l) // 2
            if nums[mid] == target:
                l = mid + 1
            elif nums[mid] > target:
                r = mid - 1
            else:
                l = mid + 1
        if r >= 0 and nums[r] == target:
            return r
        else:
            return -1


if __name__ == '__main__':
    pass

```



## Application



### Binary-search-逼近

在一定范围内搜索符合条件的数(可能多个数)，这是binary search的典型应用，有两种变形：

一、有序数组n-sum系列

结果不一定存在，参见 `n-sum系列` 章节。

二、旋转数组中的最小数字

结果一定存在，参见 `旋转数组最小数字系列` 。

三、binary-search-逼近-求最值

后面有整理。

### Binary-search-逼近-求最值

一、逼近原理求解最小值

[LeetCode-875. 爱吃香蕉的珂珂-中等](https://leetcode.cn/problems/koko-eating-bananas/) 

题目求解 "`H`小时内吃完香蕉的最小速度`k`"，首先思考 `k` 的取值范围

[LeetCode-1011. 在 D 天内送达包裹的能力-中等](https://leetcode.cn/problems/capacity-to-ship-packages-within-d-days/) 

[LeetCode-14. 最长公共前缀-简单](https://leetcode.cn/problems/longest-common-prefix/)

这道题的二分查找解法是非常的典型，它是典型的二分查找的推广。

`[0, minLen]` 之间找一个数，这个数字表示最长公共前缀，这个数字必然存在。

通过 `isCommonPrefix` 来判断是在`mid`左侧还是在`mid`右侧进行寻找。

搜索区间必须是有序的。

[LeetCode-633. 平方数之和](https://leetcode.cn/problems/sum-of-square-numbers/) 



### Binary-search-子序列

素材:

- labuladong [二分查找的妙用：判定子序列](https://mp.weixin.qq.com/s/hWi2hTrQewL_YKioGkXQJg)

- labuladong  [动态规划设计之最长递增子序列 # 二分查找解法](https://mp.weixin.qq.com/s/02o_OPgePjaz3dXnw9TA1w)

#### LeetCode

[LeetCode-392. 判断子序列-简单](https://leetcode.cn/problems/is-subsequence/) 

[LeetCode-300. 最长递增子序列-中等](https://leetcode.cn/problems/longest-increasing-subsequence/) 





### Binary-search-virtual-solution-space

这种类型的问题，它的virtual-3s-space是需要由programmer挖掘的，它的virtual-3s-space是sorted的，因此可以使用binary-search-algorithm，下面是素材:

一、labuladong [二分搜索只能用来查找元素吗？](https://mp.weixin.qq.com/s/QC24hyg0ZgjR7-LgnEzMYg) 





### Binary-search-rank



#### LeetCode

[LeetCode-878. 第 N 个神奇数字-困难](https://leetcode.cn/problems/nth-magical-number/)

[LeetCode-1201 丑数 III-中等](https://leetcode.cn/problems/ugly-number-iii/)



### 习题整理

一、[随心源](https://leetcode.cn/u/sui-xin-yuan/) 

1、[随心源](https://leetcode.cn/u/sui-xin-yuan/) # [34. 蓝红二分法单模板秒杀二分查找](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/solution/lan-hong-hua-fen-fa-dan-mo-ban-miao-sha-e7r40/) 

2、[随心源](https://leetcode.cn/u/sui-xin-yuan/) # [1201. 蓝红二分法分左右](https://leetcode.cn/problems/ugly-number-iii/solution/by-sui-xin-yuan-o8zd/) 

3、[随心源](https://leetcode.cn/u/sui-xin-yuan/) # [二分查找模块全解](https://leetcode.cn/circle/article/xYBtLt/) 



### 有序序列的中位数

二分搜索一种都在找中点，对于有序数组，它的中点就是中位数。

[LeetCode-4. 寻找两个正序数组的中位数-hard](https://leetcode.cn/problems/median-of-two-sorted-arrays/) 



## TODO



### top K、quick select

labuladong [快排亲兄弟：快速选择算法详解](https://mp.weixin.qq.com/s/TRO3FOKT90Mpvn3hQWVBAQ) 	

