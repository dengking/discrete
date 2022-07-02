# Space–time tradeoff

一、当存在overlapping subproblem的时候，就需要考虑"以空间换时间"来提升性能。

二、当超时的时候，就需要考虑如何以空间换时间。

## Examples

### Dynamic programming / 动态规划

这是最最典型的以空间换时间，将子问题的解保存下来，在下面文章中，有着非常好的分析: 

1、labuladong [动态规划设计之最长递增子序列](https://mp.weixin.qq.com/s/02o_OPgePjaz3dXnw9TA1w)



### 数组算法中的以空间换时间

下面描述的四个数组相关的算法，其实存在着如下的相似点:

1、区间在扩大



一、min、max

股票买卖问题

求一个不断扩展的区间中的min、max，可以通过维护min、max而实现，这在 labuladong [LeetCode 股票问题的一种通用解法](https://mp.weixin.qq.com/s/TrN7mMdLEPCmT5mOXzgP5A) 中，进行了详细的说明。

它可以看做是 "以空间换时间"，将 $O(n^2)$​ 穷举 转换为 $O(n)$​ 穷举。



二、最大子数组和问题

这在 `Expert-labuladong\1-动态规划系列\1.2-子序列类型问题\最大子数组` 章节中，进行了讨论。最最常规的实现方式是$O(n^3)$，通过观察递归关系，记录子问题的解，然后根据递归关系，获取更大问题的解，可以将其转换为$O(n^2)$​。

#### 找数算法、hash map以空间换时间

##### LeetCode [1711. 大餐计数](https://leetcode.cn/problems/count-good-meals/)

使用hash map保持数字出现的次数。

> NOTE: 
>
> 在很多的地方都使用了这种用法，比如:
>
> 1、滑动窗口

##### LeetCode  [1. 两数之和](https://leetcode.cn/problems/two-sum/)

以空间换时间



#### 子数组问题

1、最大子数组和问题

上面对它进行了详细的描述。

2、LeetCode [413. 等差数列划分](https://leetcode.cn/problems/arithmetic-slices/) 中等



### 滑动窗口以空间换时间

参见 labuladong [我写了套框架，把滑动窗口算法变成了默写题](https://mp.weixin.qq.com/s/ioKXTMZufDECBUwRRp3zaA) :

```C++
/* 滑动窗口算法框架 */
void slidingWindow(string s, string t) {
    // 预处理字符串
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;

    int left = 0, right = 0;
    int valid = 0; 
    while (right < s.size()) {
        // c 是将移入窗口的字符
        char c = s[right];
        // 右移窗口
        right++;
        // 进行窗口内数据的一系列更新
        ...

        /*** debug 输出的位置 ***/
        printf("window: [%d, %d)\n", left, right);
        /********************/

        // 判断左侧窗口是否要收缩
        while (window needs shrink) {
            // d 是将移出窗口的字符
            char d = s[left];
            // 左移窗口
            left++;
            // 进行窗口内数据的一系列更新
            ...
        }
    }
}
```





### 预处理字符串-加速匹配

一、binary search 二分查找优化subsequence子序列匹配

labuladong [二分查找的妙用：判定子序列](https://mp.weixin.qq.com/s/hWi2hTrQewL_YKioGkXQJg)

LeetCode [392. 判断子序列](https://leetcode.cn/problems/is-subsequence/) 简单



二、KMP algorithm



三、滑动窗口



### LeetCode [解数独](https://leetcode.cn/problems/sudoku-solver/solution/jie-shu-du-by-leetcode-solution/)

其中就用"以空间换时间"来进行优化。



## Algorithms use memory to gain performance improvement

使用空间换取时间

https://www.sciencedirect.com/topics/computer-science/performance-gain

https://stackoverflow.com/questions/1898161/memory-vs-performance



## wikipedia [Space-time tradeoff](https://infogalactic.com/info/Space%E2%80%93time_tradeoff)



### Types of tradeoff

#### Lookup tables vs. recalculation

> NOTE: 
>
> 这是典型的以空间，换时间换时间

The most common situation is an algorithm involving a [lookup table](https://infogalactic.com/info/Lookup_table): 

an implementation can include the entire table, which reduces computing time, but increases the amount of memory needed, or it can compute table entries as needed, increasing computing time, but reducing memory requirements.

#### Compressed vs. uncompressed data

A space–time tradeoff can be applied to the problem of data storage. If data is stored uncompressed, it takes more space but less time than if the data were stored compressed (since compressing the data reduces the amount of space it takes, but it takes time to run the [decompression algorithm](https://infogalactic.com/info/Data_compression)). Depending on the particular instance of the problem, either way is practical. There are also rare instances where it is possible to directly work with compressed data, such as in the case of compressed [bitmap indices](https://infogalactic.com/info/Bitmap_index), where it is faster to work with compression than without compression.



#### Re-rendering vs. stored images

Storing only the [LaTeX](https://infogalactic.com/info/LaTeX) source and rendering it as an image every time the page is requested would be trading time for space; more time used, but less space. Rendering the image when the page is changed and storing the rendered images would be trading space for time; more space used, but less time. This technique is more generally known as [caching](https://infogalactic.com/info/Cache_(computing)).



#### Smaller code vs. loop unrolling

Larger code size can be traded for higher program speed when applying [loop unrolling](https://infogalactic.com/info/Loop_unrolling). This technique makes the code longer for each iteration of a loop, but saves the computation time required for jumping back to the beginning of the loop at the end of each iteration.