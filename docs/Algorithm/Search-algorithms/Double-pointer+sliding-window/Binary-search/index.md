# Binary-search

Binary-search的应用范围比较广泛，`nums`中可能存在0个、1个、多个target。

| Left bound             | Right bound            |
| ---------------------- | ---------------------- |
| 小于target的最大的数   | 大于target的最小的数   |
| 等于target的最左边的数 | 等于target的最右边的数 |
|                        |                        |

left bound和right bound相较于exact，应用范围是更加广泛的。

wikipedia [Binary search algorithm](https://en.wikipedia.org/wiki/Binary_search_algorithm) 

> binary search can be used to solve a wider range of problems, such as finding the **next-smallest** or **next-largest** element in the array relative to the **target** even if it is absent from the array

## wikipedia [Binary search algorithm](https://en.wikipedia.org/wiki/Binary_search_algorithm) 

In [computer science](https://en.wikipedia.org/wiki/Computer_science), **binary search**, also known as **half-interval search**, **logarithmic search**, or **binary chop**, is a [search algorithm](https://en.wikipedia.org/wiki/Search_algorithm) that finds the position of a target value within a [sorted array](https://en.wikipedia.org/wiki/Sorted_array). Binary search compares the target value to the middle element of the array. If they are not equal, the half in which the target cannot lie is eliminated and the search continues on the remaining half, again taking the middle element to compare to the target value, and repeating this until the target value is found. If the search ends with the remaining half being empty, the target is not in the array.

Binary search runs in [logarithmic time](https://en.wikipedia.org/wiki/Time_complexity#Logarithmic_time) in the [worst case](https://en.wikipedia.org/wiki/Best,_worst_and_average_case), making $ O(\log n) $ comparisons, where $ n $ is the number of elements in the array, the $ O $ is [Big O notation](https://en.wikipedia.org/wiki/Big_O_notation), and $ \log $​ is the [logarithm](https://en.wikipedia.org/wiki/Logarithm). Binary search is faster than [linear search](https://en.wikipedia.org/wiki/Linear_search) except for small arrays. However, the array must be sorted first to be able to apply binary search. There are specialized [data structures](https://en.wikipedia.org/wiki/Data_structures) designed for fast searching, such as [hash tables](https://en.wikipedia.org/wiki/Hash_tables), that can be searched more efficiently than binary search. However, binary search can be used to solve a wider range of problems, such as finding the **next-smallest** or **next-largest** element in the array relative to the **target** even if it is absent from the array.

> NOTE:
>
> 一. 

There are numerous variations of binary search. In particular, [fractional cascading](https://en.wikipedia.org/wiki/Fractional_cascading) speeds up binary searches for the same value in multiple arrays. Fractional cascading efficiently solves a number of search problems in [computational geometry](https://en.wikipedia.org/wiki/Computational_geometry) and in numerous other fields. [Exponential search](https://en.wikipedia.org/wiki/Exponential_search) extends binary search to unbounded lists. The [binary search tree](https://en.wikipedia.org/wiki/Binary_search_tree) and [B-tree](https://en.wikipedia.org/wiki/B-tree) data structures are based on binary search.

> NOTE: 
>
> 总结得非常好

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

In the above procedure, the algorithm checks whether the middle element ($ m $) is **equal to** the target ($ T $) in every iteration. Some implementations leave out this check during each iteration. The algorithm would perform this check only when one element is left (when $ L=R $). This results in a faster comparison loop, as one comparison is eliminated per iteration. However, it requires one more iteration on average.[[8\]](https://en.wikipedia.org/wiki/Binary_search_algorithm#cite_note-Bottenbruch1962-8)

[Hermann Bottenbruch](https://en.wikipedia.org/wiki/Hermann_Bottenbruch) published the first implementation to leave out this check in 1962.[[8\]](https://en.wikipedia.org/wiki/Binary_search_algorithm#cite_note-Bottenbruch1962-8)[[9\]](https://en.wikipedia.org/wiki/Binary_search_algorithm#cite_note-FOOTNOTEKnuth1998§6.2.1_("Searching_an_ordered_table"),_subsection_"History_and_bibliography"-9)

1、 Set $ L $ to $ 0 $ and $ R $ to $ n-1 $.

2、 While $ L\neq R $ ,

      1. Set $ m $ (the position of the middle element) to the [ceiling](https://en.wikipedia.org/wiki/Floor_and_ceiling_functions)（天花板） of $ {\frac {L+R}{2}} $, which is the least integer greater than or equal to $ {\frac {L+R}{2}} $.（此处为什么是 [ceiling](https://en.wikipedia.org/wiki/Floor_and_ceiling_functions) of $ {\frac {L+R}{2}} $？如果不是会怎样？）
      2. If $ A_{m}>T $, set $ R $ to $ m-1 $.
      3. Else, $ A_{m}\leq T $; set $ L $ to $ m $.

3、 Now $ L=R $, the search is done. If $ A_{L}=T $, return $ L $. Otherwise, the search terminates as unsuccessful.

Where `ceil` is the ceiling function, the pseudocode for this version is:

```
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
> Set $ m $ (the position of the middle element) to the [ceiling](https://en.wikipedia.org/wiki/Floor_and_ceiling_functions)（天花板） of $ {\frac {L+R}{2}} $是否可以使用floor呢？是有差别的：当最终数组只剩下两个元素的时候，如果使用floor，则此时m会一直等于left，如果`A[m] <= T`，则程序会一直进入到上述伪代码中的else分支中，以下就是例子：
>
> ```C++
> #include<iostream>
> #include<vector>
> using namespace std;
> 
> 
> int search(vector<int>& nums, int target) {
>         int right = nums.size() - 1;
>         int left = 0;
>         int middle = 0;
>         while(left!=right){
>             middle = (left + right) / 2;
>             cout<<middle <<endl;
> 
>             if(nums[middle]>target){
>                 right = middle - 1;
>             } else{
>                 left = middle;
>             }
>         }
>         if(nums[left]==target) return left;
>         return -1;
>     }
> 
> int main(){
> vector<int> nums{-1,0,3,5,9,12};
> int target=9;
> search(nums,target);
> }
> ```
>
> 



#### Duplicate elements

The procedure may return any index whose element is equal to the target value, even if there are duplicate elements in the array. For example, if the array to be searched was $ [1,2,3,4,4,5,6,7] $ and the target was $ 4 $, then it would be correct for the algorithm to either return the 4th (index 3) or 5th (index 4) element. The regular procedure would return the 4th element (index 3) in this case. It does not always return the **first** duplicate (consider $ [1,2,4,4,4,5,6,7] $ which still returns the 4th element). However, it is sometimes necessary to find the **leftmost** element or the **rightmost** element for a target value that is duplicated in the array. In the above example, the 4th element is the **leftmost** element of the value 4, while the 5th element is the **rightmost** element of the value 4. The alternative procedure above will always return the index of the **rightmost** element if such an element exists.[[9\]](https://en.wikipedia.org/wiki/Binary_search_algorithm#cite_note-FOOTNOTEKnuth1998§6.2.1_("Searching_an_ordered_table"),_subsection_"History_and_bibliography"-9) 

> NOTE: 
>
> 这些其实就是left bound 和 right bound，在 **labuladong** [我作了首诗，保你闭着眼睛也能写对二分查找](https://mp.weixin.qq.com/s/M1KfTfNlu4OCK8i9PSAmug) 中有着非常好的分析

#### Approximate matches

The above procedure only performs *exact* matches, finding the position of a target value. However, it is trivial to extend binary search to perform approximate matches because binary search operates on sorted arrays. For example, binary search can be used to compute, for a given value, its 

一、rank (the number of smaller elements), 

> NOTE: 
>
> 一、例子
>
> [LeetCode-35. 搜索插入位置](https://leetcode.cn/problems/search-insert-position/) 

二、predecessor (next-smallest element),

三、successor (next-largest element), and 

四、[nearest neighbor](https://en.wikipedia.org/wiki/Nearest_neighbor_search). 

五、[Range queries](https://en.wikipedia.org/wiki/Range_query_(data_structures)) seeking the number of elements between two values can be performed with two rank queries.

> NOTE: 
>
> 一、例子
>
> [LeetCode-34. 在排序数组中查找元素的第一个和最后一个位置](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/)



1、Rank queries can be performed with the [procedure for finding the leftmost element](https://en.wikipedia.org/wiki/Binary_search_algorithm#Procedure_for_finding_the_leftmost_element). The number of elements *less than* the target value is returned by the procedure.

2、Predecessor queries can be performed with rank queries. If the rank of the target value is $r$, its predecessor is $r-1$.

3、For successor queries, the [procedure for finding the rightmost element](https://en.wikipedia.org/wiki/Binary_search_algorithm#Procedure_for_finding_the_rightmost_element) can be used. If the result of running the procedure for the target value is $ r$, then the successor of the target value is $r+1$.

4、The nearest neighbor of the target value is either its predecessor or successor, whichever is closer.

5、Range queries are also straightforward. Once the ranks of the two values are known, the number of elements greater than or equal to the first value and less than the second is the difference of the two ranks. This count can be adjusted up or down by one according to whether the endpoints of the range should be considered to be part of the range and whether the array contains entries matching those endpoints.

> NOTE: 
>
> 总结得非常好

### Performance

> NOTE:
>
> 一. 对binary search的complexity-analysis在 `O(logN)` 中也有描述
>
> 

## Library support

C++'s Standard Template Library provides the functions binary_search(), lower_bound(), upper_bound() and equal_range().



## 素材

一、LeetCode

1、[LeetBook 列表](https://leetcode.cn/leetbook/)/[二分查找](https://leetcode.cn/leetbook/detail/binary-search/)

2、[学习计划广场](https://leetcode.cn/study-plan/)→专项突破→[二分查找](https://leetcode.cn/study-plan/binary-search/)



二、[随心源](https://leetcode.cn/u/sui-xin-yuan/) 

1、[随心源](https://leetcode.cn/u/sui-xin-yuan/) # [34. 蓝红二分法单模板秒杀二分查找](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/solution/lan-hong-hua-fen-fa-dan-mo-ban-miao-sha-e7r40/) 

2、[随心源](https://leetcode.cn/u/sui-xin-yuan/) # [1201. 蓝红二分法分左右](https://leetcode.cn/problems/ugly-number-iii/solution/by-sui-xin-yuan-o8zd/) 

3、[随心源](https://leetcode.cn/u/sui-xin-yuan/) # [二分查找模块全解](https://leetcode.cn/circle/article/xYBtLt/) 

4、[随心源](https://leetcode.cn/u/sui-xin-yuan/) # [二分查找模块全解](https://leetcode.cn/circle/article/xYBtLt/)



三、labuladong

**labuladong** [二分搜索只能用来查找元素吗？](https://mp.weixin.qq.com/s/QC24hyg0ZgjR7-LgnEzMYg)

**labuladong** [我作了首诗，保你闭着眼睛也能写对二分查找](https://mp.weixin.qq.com/s/M1KfTfNlu4OCK8i9PSAmug) 



四、wikipedia [Binary search algorithm](https://en.wikipedia.org/wiki/Binary_search_algorithm) 



五、programmingpraxis [Binary Search With Duplicates](https://programmingpraxis.com/2017/11/07/binary-search-with-duplicates/)



## 习题整理

一、[随心源](https://leetcode.cn/u/sui-xin-yuan/) 

1、[随心源](https://leetcode.cn/u/sui-xin-yuan/) # [34. 蓝红二分法单模板秒杀二分查找](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/solution/lan-hong-hua-fen-fa-dan-mo-ban-miao-sha-e7r40/) 

2、[随心源](https://leetcode.cn/u/sui-xin-yuan/) # [1201. 蓝红二分法分左右](https://leetcode.cn/problems/ugly-number-iii/solution/by-sui-xin-yuan-o8zd/) 

3、[随心源](https://leetcode.cn/u/sui-xin-yuan/) # [二分查找模块全解](https://leetcode.cn/circle/article/xYBtLt/) 



## Binary-search-逼近

在一定范围内搜索符合条件的数(可能多个数)，这是binary search的典型应用，有两种变形：

一、有序数组n-sum系列

结果不一定存在，参见 `n-sum系列` 章节。

二、旋转数组中的最小数字

结果一定存在，参见 `旋转数组最小数字系列` 。

三、binary-search-逼近-求最值

后面有整理。



## Binary-search-子序列

素材:

一、labuladong [二分查找的妙用：判定子序列](https://mp.weixin.qq.com/s/hWi2hTrQewL_YKioGkXQJg)

二、labuladong  [动态规划设计之最长递增子序列 # 二分查找解法](https://mp.weixin.qq.com/s/02o_OPgePjaz3dXnw9TA1w)



### LeetCode

[LeetCode-392. 判断子序列-简单](https://leetcode.cn/problems/is-subsequence/) 

[LeetCode-300. 最长递增子序列-中等](https://leetcode.cn/problems/longest-increasing-subsequence/) 



## Binary-search-virtual-solution-space

这种类型的问题，它的virtual-3s-space是需要由programmer挖掘的，它的virtual-3s-space是sorted的，因此可以使用binary-search-algorithm，下面是素材:

一、labuladong [二分搜索只能用来查找元素吗？](https://mp.weixin.qq.com/s/QC24hyg0ZgjR7-LgnEzMYg) 



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



### Binary-search-rank

素材:



#### LeetCode

[LeetCode-878. 第 N 个神奇数字-困难](https://leetcode.cn/problems/nth-magical-number/)

[LeetCode-1201 丑数 III-中等](https://leetcode.cn/problems/ugly-number-iii/)



## TODO



### top K、quick select

labuladong [快排亲兄弟：快速选择算法详解](https://mp.weixin.qq.com/s/TRO3FOKT90Mpvn3hQWVBAQ) 	

### 有序序列的中位数

二分搜索一种都在找中点，对于有序数组，它的中点就是中位数。

[LeetCode-4. 寻找两个正序数组的中位数-hard](https://leetcode.cn/problems/median-of-two-sorted-arrays/) 

