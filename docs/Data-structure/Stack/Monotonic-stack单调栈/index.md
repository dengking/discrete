# Monotonic stack

一、monotonic stack的含义

1、使栈中的元素维持一定的次序，比如自栈底到栈顶**递增**或者**递减**

二、如何实现monotonic stack?

由于栈的操作只有`push`、`pop`、`top`，无法进行swap，因此对于当使用栈进行排序的时候，一般采用的是如下方式: 

1、坚持"monotonic order"，即保持当前stack中的element的"monotonic order"，一旦，待`push`的element和`top`之间不满足"monotonic order"，那么就需要将当前stack中与待`push`的element不满足"monotonic order"的元素全部"pop"掉。

三、monotonic stack的优势:

1、能够保证相对顺序，比如"All-nearest-smaller-values"、"[下一个更大元素-Next Greater Number](https://leetcode-cn.com/problems/next-greater-element-i/)"

四、介绍这个algorithm最好的文章是：wikipedia [All nearest smaller values](https://en.wikipedia.org/wiki/All_nearest_smaller_values) 



素材:

一、[Expert-labuladong 单调栈解题模板秒杀三道算法题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247487704&idx=1&sn=eb9ac24c644aa0950638c9b20384e982&scene=21#wechat_redirect) 

二、gitbook [Expert-liuzhenglaichn **Monotonic Stack**](https://liuzhenglaichn.gitbook.io/algorithm/monotonic-stack)



