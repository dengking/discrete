# Stream algorithm



## wikipedia [Streaming algorithm](https://en.wikipedia.org/wiki/Streaming_algorithm)

In [computer science](https://en.wikipedia.org/wiki/Computer_science), **streaming algorithms** are algorithms for processing [data streams](https://en.wikipedia.org/wiki/Data_stream) in which the input is presented as a [sequence](https://en.wikipedia.org/wiki/Sequence) of items and can be examined in only a few passes (typically [just one](https://en.wikipedia.org/wiki/One-pass_algorithm)). In most models, these algorithms have access to limited memory (generally [logarithmic](https://en.wikipedia.org/wiki/L_(complexity)) in the size of and/or the maximum value in the stream). They may also have limited processing time per item.

### Models

#### Data stream model



#### Turnstile and cash register models



#### Sliding window model

### Evaluation

These algorithms have many similarities with [online algorithms](https://en.wikipedia.org/wiki/Online_algorithms) since they both require decisions to be made before all data are available, but they are not identical. Data stream algorithms only have limited memory available but they may be able to defer action until a group of points arrive, while online algorithms are required to take action as soon as each point arrives.

### Some streaming problems

#### Frequency moments

> NOTE:
>
> [CSC 2420: Lecture 10 Streaming Algorithms: Frequency Moments and Count-Min Sketch](https://people.cs.pitt.edu/~kirk/cs2150/Notes/L10.pdf)

#### Frequent elements

> NOTE:
>
> 一、参见 `Frequent-elements-problem` 章节

#### Counting distinct elements

> NOTE:
>
> 一、Google "counting distinct elements in a data stream leetcode"





## LeetCode

https://leetcode.cn/problemset/all/?search=%E6%B5%81

| LeetCode                                                     | 算法 |      |
| ------------------------------------------------------------ | ---- | ---- |
| [LeetCode-1032. 字符流-困难](https://leetcode.cn/problems/stream-of-characters/) |      |      |
| [LeetCode-1656. 设计有序流](https://leetcode.cn/problems/design-an-ordered-stream/) |      |      |
| [LeetCode-面试题 10.10. 数字流的秩](https://leetcode.cn/problems/rank-from-stream-lcci/) |      |      |
|                                                              |      |      |
| [LeetCode-703. 数据流中的第 K 大元素](https://leetcode.cn/problems/kth-largest-element-in-a-stream/) |      |      |
| [LeetCode-487. 最大连续1的个数 II](https://leetcode.cn/problems/max-consecutive-ones-ii/) | DP   |      |
| [LeetCode-295. 数据流的中位数-中等](https://leetcode-cn.com/problems/find-median-from-data-stream/) |      |      |
| Reservoir Sampling(水塘抽样)                                 |      |      |
|                                                              |      |      |
| [LeetCode-901. 股票价格跨度-中等](https://leetcode.cn/problems/online-stock-span/) |      |      |
|                                                              |      |      |
|                                                              |      |      |
|                                                              |      |      |





### ds design

很多都是基于DS来实现的

[LeetCode-1429. 第一个唯一数字-中等](https://leetcode.cn/problems/first-unique-number/)



其实，从这个角度来看，LFU和LRU都是stream algorithm ds。



### medium [Leetcode-Data Stream](https://yunrui-li.medium.com/leetcode-data-stream-a5b43c7cebc5)