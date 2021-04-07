# labuladong [经动态规划：编辑距离](https://mp.weixin.qq.com/s/uWzSvWWI-bWAV3UANBtyOw)

## 一、思路

### divide and conquer-problem and sub problem-原问题-子问题

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
> 二、上面这段话所描述的思想是写出递归公式的基础
>
> 

### Example

设两个字符串分别为 "rad" 和 "apple"，为了把`s1`变成`s2`，算法会这样进行：

![图片](https://mmbiz.qpic.cn/mmbiz_gif/map09icNxZ4k5NKSib1ss6fnzSpHpahjDwNspIxXESlO67S5rXRWM3pAHq31mhXKzG0GWEk3M1vwIgDhrfawIZOA/640?wx_fmt=gif&tp=webp&wxfrom=5&wx_lazy=1)

![图片](https://mmbiz.qpic.cn/mmbiz_jpg/map09icNxZ4k5NKSib1ss6fnzSpHpahjDwPWHFNiarMEtcficJ3dSrLWWlKAiadJo63dazeyy4HV1icl9Rhg4cpbYdiaQ/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



请记住这个 GIF 过程，这样就能算出编辑距离。关键在于如何做出正确的操作，稍后会讲。

> NOTE: 
>
> 1、当两个字符不相等的时候，可以执行的操作有: 更新、插入、删除，那到底选择哪一种呢？

### 第四种操作: skip(贪心选择)

根据上面的 GIF，可以发现操作不只有三个，其实还有第四个操作，就是什么都不要做（skip）。比如这个情况：

![图片](https://mmbiz.qpic.cn/mmbiz_jpg/map09icNxZ4k5NKSib1ss6fnzSpHpahjDws5icmBo1nJHEp16pfWf5m68iaDR4cLpUsozaicmF3biaiabRVb1ot33Nnicw/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

因为这两个字符本来就相同，为了使编辑距离最小，显然不应该对它们有任何操作，直接往前移动`i,j`即可。

> NOTE: 
>
> 1、greedy selection-maximum and minimum-最值问题

### 特殊操作: 直接删除

还有一个很容易处理的情况，就是`j`走完`s2`时，如果`i`还没走完`s1`，那么只能用删除操作把`s1`缩短为`s2`。比如这个情况：

![图片](https://mmbiz.qpic.cn/mmbiz_jpg/map09icNxZ4k5NKSib1ss6fnzSpHpahjDwgibumtGZ45Z2PfBB9bMt1ME3olHKsZePNXfLibnFF5nuZRhtQicPTslVA/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

### 特殊操作: 直接插入

类似的，如果`i`走完`s1`时`j`还没走完了`s2`，那就只能用插入操作把`s2`剩下的字符全部插入`s1`。等会会看到，这两种情况就是算法的 **base case**。

下面详解一下如何将这个思路转化成代码，坐稳，准备发车了。

## 二、代码详解

先梳理一下之前的思路：

base case 是`i`走完`s1`或`j`走完`s2`，可以直接返回另一个字符串剩下的长度。

对于每对儿字符`s1[i]`和`s2[j]`，可以有四种操作：

```pseudocode
if s1[i] == s2[j]:
    啥都别做（skip）
    i, j 同时向前移动
else:
    三选一：
        插入（insert）
        删除（delete）
        替换（replace）
```

有这个框架，问题就已经解决了。读者也许会问，这个「三选一」到底该怎么选择呢？很简单，全试一遍，哪个操作最后得到的编辑距离最小，就选谁。这里需要递归技巧，理解需要点技巧，先看下代码：

![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4k6I9qSKsoaKwsIQEBSv3CAtkTUphy9rfUMmnibuwQOib5OBwc0BNF4OBCrRnoYp3gNO3icM8Ywgm1Ww/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

下面来详细解释一下这段递归代码，base case 应该不用解释了，主要解释一下递归部分。

### Base case

> NOTE: 
>
> 1、如何理解base case？虽然原文说"base case 应该不用解释"，但是我初次阅读的时候，还是对base case感到疑惑。
>
> 

`dp(i, j)`求解的是`s1[0:i]`、`s2[0:j]`的编辑距离，因此`dp(0, 0)`表示的是`s1[0]`、`s2[0]`的编辑距离。

#### index为0

i、j为0，并不表示空串，而是表示的是单一字符，它们的编辑距离由两者是否相等而决定，如果它们相等，则它们的编辑距离是0，否则它们的编辑距离是1.

可以代入具体的例子到上述code中。

#### index为-1

字符串为空的情况对应的值是 -1，此时是可以直接求解的。为什么要`+1`？

当`i==-1`，说明`s1`为空，因此，编辑距离就是`s2`的长度(`s1`中需要插入所有`s2`中的元素)，那此时`s2`的长度是多少呢？

由于`i`、`j`表示的都是index，此时要求解的是长度，而index和长度的对应关系就是`+1`，因此通过`+1`就可以求解得到长度。

当`j==-1`，说明`s2`为空，此时编辑距离就是`s1`的长度: `s1`需要将所有的元素删除。

### Index and length

1、上述是典型的index 和 length之间的转换

2、在上述例子中，`i`、`j`其实表示的是index:

index一般从0开始编号，index为-1表示的length为0

length一般从0开始编号，length为1，对应的index为0

3、length = index + 1

---

### `s1[i] == s2[j]`

都说递归代码的可解释性很好，这是有道理的，只要理解函数的定义，就能很清楚地理解算法的逻辑。我们这里 `dp(i, j)` 函数的定义是这样的：

```
def dp(i, j) -> int
# 返回 s1[0..i] 和 s2[0..j] 的最小编辑距离
```

**记住这个定义**之后，先来看这段代码：

```
if s1[i] == s2[j]:
    return dp(i - 1, j - 1)  # 啥都不做
# 解释：
# 本来就相等，不需要任何操作
# s1[0..i] 和 s2[0..j] 的最小编辑距离等于
# s1[0..i-1] 和 s2[0..j-1] 的最小编辑距离
# 也就是说 dp(i, j) 等于 dp(i-1, j-1)
```

### `s1[i]！=s2[j]`

如果`s1[i]！=s2[j]`，就要对三个操作递归了，稍微需要点思考：

#### 插入

```
dp(i, j - 1) + 1,    # 插入
# 解释：
# 我直接在 s1[i] 插入一个和 s2[j] 一样的字符
# 那么 s2[j] 就被匹配了，前移 j，继续跟 i 对比
# 别忘了操作数加一
```

![图片](https://mmbiz.qpic.cn/mmbiz_gif/map09icNxZ4k5NKSib1ss6fnzSpHpahjDwDWaTd2WiarM2SKZ2n2hBAqo5ibGV6tPG6LRFU7RYvSJoBsKBovkcJFZw/640?wx_fmt=gif&tp=webp&wxfrom=5&wx_lazy=1)

#### 删除



```
dp(i - 1, j) + 1,    # 删除
# 解释：
# 我直接把 s[i] 这个字符删掉
# 前移 i，继续跟 j 对比
# 操作数加一
```

![图片](https://mmbiz.qpic.cn/mmbiz_gif/map09icNxZ4k5NKSib1ss6fnzSpHpahjDwuTKibtrfGicWI5YUQVH9wicLRD2L3enLyKOsicEhYxXDdlrHc59W4reVEA/640?wx_fmt=gif&tp=webp&wxfrom=5&wx_lazy=1)



#### 替换

```
dp(i - 1, j - 1) + 1 # 替换
# 解释：
# 我直接把 s1[i] 替换成 s2[j]，这样它俩就匹配了
# 同时前移 i，j 继续对比
# 操作数加一
```

![图片](https://mmbiz.qpic.cn/mmbiz_gif/map09icNxZ4k5NKSib1ss6fnzSpHpahjDwibcickW7rH7o6REHNppGh33Ric4uOR263RRc9EjPQC1WH6I8LHSCemhiaA/640?wx_fmt=gif&tp=webp&wxfrom=5&wx_lazy=1)

现在，你应该完全理解这段短小精悍的代码了。

### 暴力破解的重叠子问题

还有点小问题就是，这个解法是暴力解法，存在重叠子问题，需要用动态规划技巧来优化。

**怎么能一眼看出存在重叠子问题呢**？前文 [动态规划之正则表达式](http://mp.weixin.qq.com/s?__biz=MzU0MDg5OTYyOQ==&mid=2247483976&idx=1&sn=c268f7343732e33035cfd75da2d17052&chksm=fb33620acc44eb1ca6d80cf5af2564e7b81fc8ee5ce53cef8f1b159a881aa06796fed3e2a363&scene=21#wechat_redirect) 有提过，这里再简单提一下，需要抽象出本文算法的递归框架：

```Python
def dp(i, j):
    dp(i - 1, j - 1) #1
    dp(i, j - 1)     #2
    dp(i - 1, j)     #3
```

对于子问题`dp(i-1,j-1)`，如何通过原问题`dp(i,j)`得到呢？有不止一条路径，比如`dp(i,j)->#1`和`dp(i,j)->#2->#3`。一旦发现一条重复路径，就说明存在巨量重复路径，也就是重叠子问题。

## 三、动态规划优化

对于重叠子问题呢，前文 [动态规划详解](http://mp.weixin.qq.com/s?__biz=MzU0MDg5OTYyOQ==&mid=2247483818&idx=1&sn=6035f861d1b2bfd0178e842f26ac4836&chksm=fb3361e8cc44e8fe331154bfd32bd7b3b4f159bfad5d38d4a6b0b9f0d7e3485b93b828ee72cc&scene=21#wechat_redirect) 介绍过，优化方法无非是备忘录或者 DP table。

### 备忘录优化

备忘录很好加，原来的代码稍加修改即可：

```python
def minDistance(s1, s2) -> int:

    memo = dict() # 备忘录
    def dp(i, j):
        if (i, j) in memo: 
            return memo[(i, j)]
        ...

        if s1[i] == s2[j]:
            memo[(i, j)] = ...  
        else:
            memo[(i, j)] = ...
        return memo[(i, j)]

    return dp(len(s1) - 1, len(s2) - 1)
```

### DP table

**主要说下 DP table 的解法**：

首先明确 dp 数组的含义，dp 数组是一个二维数组，长这样：

![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4k5NKSib1ss6fnzSpHpahjDw3B41UlTr2jOIH3SH7jvaYZTK5Qic2ZIHTEOztTRmpwd1K5v5FXrZHhw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



`dp[i][j]`的含义和之前的 dp 函数类似：

```python
def dp(i, j) -> int
# 返回 s1[0..i] 和 s2[0..j] 的最小编辑距离

dp[i-1][j-1]
# 存储 s1[0..i] 和 s2[0..j] 的最小编辑距离
```

#### base case

有了之前递归解法的铺垫，应该很容易理解。`dp` 函数的 base case 是`i,j`等于 -1，而数组索引至少是 0，所以 `dp` 数组会偏移一位，`dp[..][0]`和`dp[0][..]`对应 base case。。

#### Index and length

下面code中，`i`、`j`对应的是length，因此，当需要access string element的时候，需要`-1`，对应的是如下code:

```java
if(s1.charAt(i-1) == s2.charAt(j-1))
```

这是非常容易出错的。

#### code

既然 `dp` 数组和递归 `dp` 函数含义一样，也就可以直接套用之前的思路写代码，**唯一不同的是，DP table 是自底向上求解，递归解法是自顶向下求解**：

![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4k6I9qSKsoaKwsIQEBSv3CAzicJibicyvZEtPKm5nH0CEteRqJCBKQVkW6mMArhZsephVmMYrB3wSGoA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

> NOTE: 
>
> 1、上述两层嵌套for，是典型的brute-force
>
> 2、

## 三、扩展延伸

一般来说，处理两个字符串的动态规划问题，都是按本文的思路处理，建立 DP table。为什么呢，因为易于找出状态转移的关系，比如编辑距离的 DP table：

![图片](https://mmbiz.qpic.cn/mmbiz_jpg/map09icNxZ4k6I9qSKsoaKwsIQEBSv3CAQuJ6WodnmbqKfLuzrzebJjvTqyKkYCAfYmxWsXic3yg5k7SYD5RhbPw/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



### 状态压缩

还有一个细节，既然每个`dp[i][j]`只和它附近的三个状态有关，空间复杂度是可以压缩成 *O*(*m**i**n*(*M*,*N*)) 的（M，N 是两个字符串的长度）。不难，但是可解释性大大降低，读者可以自己尝试优化一下。

> NOTE: 
>
> 1、关于状态压缩，参见 **labuladong** [状态压缩技巧：动态规划的降维打击](https://mp.weixin.qq.com/s/SnyN1Gn6DTLm0uJyp5l6CQ)
>
> 



### 记录具体操作

你可能还会问，**这里只求出了最小的编辑距离，那具体的操作是什么**？之前举的修改公众号文章的例子，只有一个最小编辑距离肯定不够，还得知道具体怎么修改才行。

这个其实很简单，代码稍加修改，给 dp 数组增加额外的信息即可：

```C++
// int[][] dp;
Node[][] dp;

class Node {
    int val;
    int choice;
    // 0 代表啥都不做
    // 1 代表插入
    // 2 代表删除
    // 3 代表替换
}
```

`val`属性就是之前的 dp 数组的数值，`choice`属性代表操作。在做最优选择时，顺便把操作记录下来，然后就从结果反推具体操作。

我们的最终结果不是`dp[m][n]`吗，这里的`val`存着最小编辑距离，`choice`存着最后一个操作，比如说是插入操作，那么就可以左移一格：

![图片](https://mmbiz.qpic.cn/mmbiz_jpg/map09icNxZ4k5NKSib1ss6fnzSpHpahjDwPic6ETIOfaibRXA8h17eaMHtt5czDoYO41voq5KFgEsdeL5HIeIpCz1Q/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



重复此过程，可以一步步回到起点`dp[0][0]`，形成一条路径，按这条路径上的操作编辑对应索引的字符，就是最佳方案：

![图片](https://mmbiz.qpic.cn/mmbiz_jpg/map09icNxZ4k6I9qSKsoaKwsIQEBSv3CA6o6Owk8vm9obM9bgcgibT6LuQxGfnpJRGb8ianHwIzFLnFs716Z5jhOg/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

这就是编辑距离算法的全部内容，希望本文对你有帮助。