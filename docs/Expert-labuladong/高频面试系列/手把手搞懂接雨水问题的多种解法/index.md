# labuladong [手把手搞懂接雨水问题的多种解法](https://mp.weixin.qq.com/s/mFqrlhqYEPhRa9p4ewl3Xw)

接雨水这道题目挺有意思，在面试题中出现频率还挺高的，本文就来步步优化，讲解一下这道题：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_png/gibkIz0MVqdETSibChZ6NaonURayySXExwkiaibkEUf1MleYZqhmb8LibB6xlAhRWKKJj6FVE9546U1NYZ9ibnicNpiceQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



就是用一个数组表示一个条形图，问你这个条形图最多能接多少水，函数签名如下：

```
int trap(int[] height);
```

下面就来由浅入深介绍**暴力解法 -> 备忘录解法 -> 双指针解法**，在 O(N) 时间 O(1) 空间内解决这个问题。



## 三、双指针解法

> NOTE: 
>
> 1、只要确保右侧有更高的，那么就可以积水