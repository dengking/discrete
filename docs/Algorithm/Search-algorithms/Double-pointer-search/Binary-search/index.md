# Binary-search

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

