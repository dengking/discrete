# Merge interval

一、素材：

1、emre [Coding Patterns: Merge Intervals](https://emre.me/coding-patterns/merge-intervals/)

2、**甜姨的奇妙冒险** [秒懂力扣区间题目：重叠区间、合并区间、插入区间](https://mp.weixin.qq.com/s/ioUlNa4ZToCrun3qb4y4Ow)



二、例题

1、[LeetCode-56. 合并区间](https://leetcode.cn/problems/merge-intervals/) 

2、[LeetCode-57. 插入区间](https://leetcode.cn/problems/insert-interval/) 



## 算法总结



### left- right double pointer

合并区间问题其实也是可以使用left- right double pointer来进行解释的，关于这一点，是在 [LeetCode-56. 合并区间](https://leetcode.cn/problems/merge-intervals/) # [Ikaruga](https://leetcode.cn/u/ikaruga/) [【合并区间】排序 + 双指针](https://leetcode.cn/problems/merge-intervals/solution/merge-intervals-by-ikaruga/) 中提出的。



## 辗转merge、stack machine、消消乐

1、[LeetCode-56. 合并区间](https://leetcode.cn/problems/merge-intervals/) 

2、[LeetCode-57. 插入区间](https://leetcode.cn/problems/insert-interval/) 

都是辗转merge的代表，它们是形象的消消乐，都可以使用stack machine来进行理解:



### stack machine、append to tail&flush

使用栈机可以保存活状态，也就是当前区间，因为:

当下一个区间和当前区间存在交集的时候，它需要进行merge；

当下一个区间和当前区间不存在交集的时候，它不需要merge，此时它可以将当前区间flush到结果集中；

其实 [LeetCode-56. 合并区间](https://leetcode.cn/problems/merge-intervals/) 和本题都是基于上述思路，由于它仅仅涉及两个区间，因此它不需要显示地使用一个stack。

其实这两道题能够体现append-to-tail&flush和stack machine之间的关联。

