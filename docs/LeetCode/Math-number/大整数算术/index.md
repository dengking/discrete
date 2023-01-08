# 大整数算术

思路非常简单: 使用容器来表示大数，一般使用`std::vector`，然后模拟算术。



## 数的表示

### 计算机表示

大端模式: 从左到右、从高位到低位；高位放在索引小的地方；

小端模式: 从左到右，从低位到高位；高位放在索引大的地方；



需要根据题目的意思灵活地选择表示方式。

#### 数位和位置

位置指的是表示数的容器的索引下标。

**数位**和**位置**相对应: 比如**十位**的1表示的是10，它和**个位**的数进行运算，那么它们的结果肯定是要放到**十位**的，为了简化运算: 直接将它们的结果放到最终算术结果的十位即可，这样是可以省去将各个数位上的数与base(比如十位是10、百位是$10^2$)相乘的。



### 数学表示

这在 [**LeetCode** 字符串相乘 # 官方解题](https://leetcode.cn/problems/multiply-strings/solution/zi-fu-chuan-xiang-cheng-by-leetcode-solution/) 中给出了多项式表示方法。





## 大数乘法

素材:

1、labuladong [教计算机做算术：字符串乘法](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484466&idx=1&sn=0281340cc1f41230e4512e905b9d27dd&scene=21#wechat_redirect)

2、 [**LeetCode** 字符串相乘 # 官方解题](https://leetcode.cn/problems/multiply-strings/solution/zi-fu-chuan-xiang-cheng-by-leetcode-solution/) 

3、

CSDN [大整数乘法-面试题](https://blog.csdn.net/weixin_42804808/article/details/109724408)

CSDN [华为经典面试题---大数乘法的c++实现](https://blog.csdn.net/LucasDove/article/details/50728508)



labuladong [教计算机做算术：字符串乘法](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484466&idx=1&sn=0281340cc1f41230e4512e905b9d27dd&scene=21#wechat_redirect) 中描述的思路其实就是 [**LeetCode** 字符串相乘 # 官方解题](https://leetcode.cn/problems/multiply-strings/solution/zi-fu-chuan-xiang-cheng-by-leetcode-solution/) 中的"方法二：做乘法"，并且在 [**LeetCode** 字符串相乘 # 官方解题](https://leetcode.cn/problems/multiply-strings/solution/zi-fu-chuan-xiang-cheng-by-leetcode-solution/) 中提出了如下更加容易理解的思路:

"""

方法二还可以用另外一种方法改写。我们把两个数相乘看成是两个多项式相乘，因为任何一个数都可以表示成为
$$
\sum_{i = 0}^{n - 1} a_i \times 10^i
$$



的形式，也就相当于对多项式

> NOTE:
>
> 上面的这种形式是小端模式

也就相当于对多项式

$$
A(x) = \sum_{i = 0} ^ {n - 1} a_i x^i
$$



在 $x = 10$ 处求值。

当两个数 $N_a$ 、$N_b$  相乘的时候，我们也可以认为这两个数是两个多项式

$$
\left\{ \begin{aligned} & A(x) = \sum_{i = 0} ^ {n - 1} a_i x^i \\ & B(x) = \sum_{i = 0} ^ {m - 1} b_i x^i \end{aligned} \right.
$$


相乘的结果 $C(x) = A(x) \times B(x)$ 在 $x = 10$ 处求值。我们可以这样表示 $C(x)$：

$$
C(x) = \sum_{i = 0}^{n + m - 2} c_i x^i
$$

这里

$$
c_i = \sum_{k = 0} ^ {i} a_k b_{i - k}
$$

于是我们就可以顺序求解 $c_i$ ，每次 $O(i)$ 地选取下标和为 $i$ 的一组 $(a_k, b_{i - k})$。求到 $c_i$序列之后，再处理**进位**即可得到答案。

> NOTE:
>
> "下标和为 $i$ 的一组"所表示的其实是类似于如下的意思:
> $$
> 100 * 100
> $$
> 它们的结果应该放到万位上，它非常好的模拟了错位相乘。

对比这两种做法：

......

它们的本质是一样的，并且时间复杂度都是 $O(\max \{ n, m\} ^2)$。我们再仔细的观察 $c_i$的形式：
$$
c_i = \sum_{k = 0}^{i} a_k b_{i - k}
$$


它揭示了多项式乘法的另一面：$c_i$ 序列其实是 $a_i$ 序列和 $b_i$ 序列的卷积，即：
$$
\vec{c} = \vec{a} * \vec{b}
$$

至此，



"""

1、上面是使用的数学语言来描述大数相乘的过程



### 我的一点总结

结合一个具体的例子来进行理解:

```
    123
    456
```

从最终目标入手，首先需要明确两数相乘的结果的长度为 `m + n` 。

其次，我们平时做乘法的时候，需要错位，其实那是考虑了它所处的位(个位、十位、百位)

两个数相乘其实是可以拆解位多个数相乘然后进行相加。

运算顺序: 从低位到高位，需要从低位向高位进行计算。

累加模式

进位



### 试题

**LeetCode** [415. 字符串相加](https://leetcode.cn/problems/add-strings/) 和 **LeetCode** [43. 字符串相乘](https://leetcode.cn/problems/multiply-strings/) 都是采用的大端表示，两者都是从低位到高位。

#### **LeetCode** [415. 字符串相加](https://leetcode.cn/problems/add-strings/)

#### **LeetCode** [43. 字符串相乘](https://leetcode.cn/problems/multiply-strings/)

它的官方解题时比较复杂的。



## 大数加法

素材: 

CSDN [C++ 高精度整数，两个大数相加如何处理](https://blog.csdn.net/qq_36770641/article/details/88899812)

CSDN [C++大数相加](https://blog.csdn.net/qq_1932568757/article/details/82754127)

cnblogs [面试题：如何实现大整数相加](https://www.cnblogs.com/alimayun/p/12792454.html)

cnblogs [大整数加法 面试题](https://www.cnblogs.com/meihao1203/p/8023524.html)



### 试题

### 链表大数加法系列

[LeetCode-2. 两数相加](https://leetcode.cn/problems/add-two-numbers/)

[LeetCode-445. 两数相加 II](https://leetcode.cn/problems/add-two-numbers-ii/)

[LeetCode-面试题 02.05. 链表求和](https://leetcode.cn/problems/sum-lists-lcci/)

