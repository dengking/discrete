# labuladong [一文秒杀所有区间相关问题](https://mp.weixin.qq.com/s/Eb6ewVajH56cUlY9LetRJw)

所谓区间问题，就是**线段问题**，让你**合并**所有线段、找出线段的**交集**等等。主要有两个技巧：

**1、排序**。常见的排序方法就是按照区间**起点**排序，或者先按照**起点**升序排序，若**起点**相同，则按照**终点**降序排序。当然，如果你非要按照**终点**排序，无非对称操作，本质都是一样的。

**2、画图**。就是说不要偷懒，勤动手，两个区间的相对位置到底有几种可能，不同的相对位置我们的代码应该怎么去处理。



## 区间覆盖问题

> NOTE: 
>
> leetcode [1288. 删除被覆盖区间](https://leetcode.cn/problems/remove-covered-intervals/) 中等



## 区间合并问题

> NOTE: 
>
> leetcode [56. 合并区间](https://leetcode.cn/problems/merge-intervals/) 中等



## 区间交集问题

> NOTE: 
>
> LeetCode [986. 区间列表的交集](https://leetcode.cn/problems/interval-list-intersections/) 中等

