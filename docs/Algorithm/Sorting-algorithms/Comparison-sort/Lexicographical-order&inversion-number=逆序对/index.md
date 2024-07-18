# Lexicographical order&inversion-number

lexicographical order: 字典序

inversion-number: 逆序对

## Lexicographical order

### baike [字典序](https://baike.baidu.com/item/%E5%AD%97%E5%85%B8%E5%BA%8F/7786229?fr=aladdin)

对于数字1、2、3......n的排列，不同排列的先后关系是从左到右逐个比较对应的数字的先后来决定的。例如对于5个数字的排列 12354和12345，排列12345在前，排列12354在后。按照这样的规定，5个数字的所有的排列中最前面的是12345，最后面的是 54321。



### [wikipedia-Lexicographical order](https://en.wikipedia.org/wiki/Lexicographic_order)



### stackoverflow [What is lexicographical order?](https://stackoverflow.com/questions/45950646/what-is-lexicographical-order)



[A](https://stackoverflow.com/a/45950665)

lexicographical order **is** alphabetical order. The other type is numerical ordering. Consider the following values,

```
1, 10, 2
```

Those values are in lexicographical order. 10 comes after 2 in numerical order, but 10 comes before 2 in "alphabetical" order.



### LeetCode 字典序

https://leetcode.cn/problemset/all/?search=%E5%AD%97%E5%85%B8%E5%BA%8F

### Lexicographical order tree

典型的就是 [LeetCode-386. 字典序排数](https://leetcode.cn/problems/lexicographical-numbers/) 中等，理解"Lexicographical order tree"，是解决基于它的问题的基础。

### Monotonic-stack解Max-min字典序subsequence(子序列)

[LeetCode-316. 去除重复字母](https://leetcode.cn/problems/remove-duplicate-letters/) ( LeetCode [1081. 不同字符的最小子序列](https://leetcode.cn/problems/smallest-subsequence-of-distinct-characters/) )

[LeetCode-402. 移掉K位数字](https://leetcode.cn/problems/remove-k-digits/)

[LeetCode-321. 拼接最大数](https://leetcode.cn/problems/create-maximum-number/)



参见:

1、labuladong [啊这，一道数组去重的算法题把东哥整不会了…](https://mp.weixin.qq.com/s/Yq49ZBEW3DJx6nXk1fMusw)

2、`Data-structure\Stack\Monotonic-stack单调栈\Monotonic-stack解Max-min-subsequence(子序列)`

3、[LeetCode-402. 移掉K位数字](https://leetcode.cn/problems/remove-k-digits/) # [一招吃遍力扣四道题，妈妈再也不用担心我被套路啦～](https://leetcode.cn/problems/remove-k-digits/solution/yi-zhao-chi-bian-li-kou-si-dao-ti-ma-ma-zai-ye-b-5/)



### 生成字典序序列



| 题目                                                         |      |
| ------------------------------------------------------------ | ---- |
| [LeetCode-31. 下一个排列](https://leetcode.cn/problems/next-permutation/) |      |
| [LeetCode-556. 下一个更大元素 III](https://leetcode.cn/problems/next-greater-element-iii/) |      |



| 题目                                                         |      |
| ------------------------------------------------------------ | ---- |
| [LeetCode-386. 字典序排数](https://leetcode.cn/problems/lexicographical-numbers/) |      |
| [LeetCode-440. 字典序的第K小数字](https://leetcode.cn/problems/k-th-smallest-in-lexicographical-order/) |      |
|                                                              |      |





## LeetCode-逆序对、逆序数

[baike-反序数](https://baike.baidu.com/item/%E5%8F%8D%E5%BA%8F%E6%95%B0/8674073?fromtitle=%E9%80%86%E5%BA%8F%E6%95%B0&fromid=3334502&fr=aladdin)



### [wikipedia-Inversion (discrete mathematics)](https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics))

In [computer science](https://en.wikipedia.org/wiki/Computer_science) and [discrete mathematics](https://en.wikipedia.org/wiki/Discrete_mathematics), an **inversion** in a sequence is a pair of elements that are out of their natural [order](https://en.wikipedia.org/wiki/Total_order).

[![img](https://upload.wikimedia.org/wikipedia/commons/thumb/8/80/Inversion_qtl1.svg/220px-Inversion_qtl1.svg.png)](https://en.wikipedia.org/wiki/File:Inversion_qtl1.svg)

Permutation with one of its inversions highlighted. An inversion may be denoted by the pair of places (2, 4) or the pair of elements (5, 2). The inversions of this permutation using element-based notation are: (3, 1), (3, 2), (5, 1), (5, 2), and (5,4).



### Example



https://qb.zuoyebang.com/xfe-question/question/7d0dad98b783f55d32ba3a4924d08c90.html



> 跟标准列相反序数的总和
> 比如说
> 标准列是1 2 3 4 5
> 那么 5 4 3 2 1 的逆序数算法：
> 看第二个,4之前有一个5,在标准列中5在4的后面,所以记1个
> 类似的,第三个 3 之前有 4 5 都是在标准列中3的后面,所以记2个
> 同样的,2 之前有3个,1之前有4个
> 将这些数加起来就是逆序数=1+2+3+4=10
> 再举一个 2 4 3 1 5
> 4 之前有0个
> 3 之前有1个
> 1 之前有3个
> 5 之前有0个
> 所以逆序数就是1+3=4
> 这样能明白吗



### LeetCode

[LeetCode-剑指 Offer 51. 数组中的逆序对-困难](https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/) 

[LeetCode-629. K个逆序对数组-困难](https://leetcode.cn/problems/k-inverse-pairs-array/) 

[LeetCode-LCR 170. 交易逆序对的总数-困难](https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/)	

[LeetCode-3193. 统计逆序对的数目-困难](https://leetcode.cn/problems/count-the-number-of-inversions/) 

[LeetCode-99. 恢复二叉搜索树-中等](https://leetcode.cn/problems/recover-binary-search-tree/) 

通过inorder-DFS(中序遍历)得到一个有序数组，这样将这个问题转换为有序数组中中调换两个数，找出被调换的两个数字(逆序对)。

