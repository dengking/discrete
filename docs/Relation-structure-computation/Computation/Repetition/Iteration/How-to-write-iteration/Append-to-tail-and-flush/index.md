# Append to tail and flush

一、flush标志



二、何时将current flush到result中



三、最后一个元素的处理

由于最后一个元素没有flush标志，因此对于最后一个元素的flush，通常有如下两种做法:

1、需要在循环外进行处理，最最典型的例子就是merge interval、计算器。

2、增加一个pseudo-flag，这种方式的优势是能够以相同的逻辑进行处理从而简化代码，下面是一些素材：

a、[文慕阳](https://leetcode-cn.com/u/wen-mu-yang/) # [C++ 利用哨兵👨‍✈️，维护一个单调栈📈(图解，直观掌握)](ttps://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/c-li-yong-shao-bing-wei-hu-yi-ge-dan-diao-zhan-tu-/m/) 中列举的哨兵（Sentinel）。

b、在parsing algorithm中，会手工加入一个结束标志，它能够触发自动机来进行reduction。



## 例题



### merge interval

一、[LeetCode-56. 合并区间](https://leetcode-cn.com/problems/merge-intervals/) 

<https://mp.weixin.qq.com/s/ioUlNa4ZToCrun3qb4y4Ow>

<https://emre.me/coding-patterns/merge-intervals/>

二、[LeetCode-57. 插入区间](https://leetcode-cn.com/problems/insert-interval/) 



### 计算器

<https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484903&idx=1&sn=184beaad36a71c9a8dd93c41a8ba74ac&scene=21#wechat_redirect>