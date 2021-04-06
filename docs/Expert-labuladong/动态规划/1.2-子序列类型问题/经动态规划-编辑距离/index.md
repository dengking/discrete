# labuladong [经动态规划：编辑距离](https://mp.weixin.qq.com/s/uWzSvWWI-bWAV3UANBtyOw)

## 一、思路

前文 [最长公共子序列](http://mp.weixin.qq.com/s?__biz=MzU0MDg5OTYyOQ==&mid=2247484418&idx=1&sn=98b1aa8c105467efab24e677fb17ff1a&chksm=fb336440cc44ed564f10ace689aa8e88e6d4a684cda2d2c07e81fad45cb4a70d1c27f4309ec4&scene=21#wechat_redirect) 说过，**解决两个字符串的动态规划问题，一般都是用两个指针`i,j`分别指向两个字符串的最后，然后一步步往前走，缩小问题的规模**。

> NOTE:  
>
> 一、这一段总结非常好，它让我想到了:
>
> 1、divide and conquer-problem and sub problem-原问题-子问题
>
> 2、递归公式，比如最长公共子序列的递归公式如下:
> $$
> c[i][j]=
> \begin{cases}
> 0 & i=0, j=0 \\
> c[i-1][j-1] + 1 & i,j \gt 0 ; x_i = y_j \\
> \max\{ c[i][j-1], c[i-1][j] \} i,j \gt 0 ;x_i \ne y_j
> \end{cases}
> $$
>
> 显然，是符合上面这段话的思想的。
>
> 

### Example

设两个字符串分别为 "rad" 和 "apple"，为了把`s1`变成`s2`，算法会这样进行：

![图片](https://mmbiz.qpic.cn/mmbiz_gif/map09icNxZ4k5NKSib1ss6fnzSpHpahjDwNspIxXESlO67S5rXRWM3pAHq31mhXKzG0GWEk3M1vwIgDhrfawIZOA/640?wx_fmt=gif&tp=webp&wxfrom=5&wx_lazy=1)

![图片](https://mmbiz.qpic.cn/mmbiz_jpg/map09icNxZ4k5NKSib1ss6fnzSpHpahjDwPWHFNiarMEtcficJ3dSrLWWlKAiadJo63dazeyy4HV1icl9Rhg4cpbYdiaQ/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



请记住这个 GIF 过程，这样就能算出编辑距离。关键在于如何做出正确的操作，稍后会讲。

> NOTE: 
>
> 1、当两个字符不相等的时候，可以尝试: 更新、插入，那到底选择哪一种呢？