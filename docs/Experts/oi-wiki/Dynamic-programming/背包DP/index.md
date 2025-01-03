# [oi-wiki-背包 DP](https://oi-wiki.org/dp/knapsack/) 

## 引入

[「USACO07 DEC」Charm Bracelet](https://www.luogu.com.cn/problem/P2871)



在上述例题中，由于每个物体只有两种可能的状态（取与不取），对应二进制中的 $0$ 和 $1$，这类问题便被称为「0-1 背包问题」。

## 0-1 背包

### 解释

例题中已知条件有第 $i$ 个物品的重量 $w_{i}$，价值 $v_{i}$，以及背包的总容量 ![W](data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7)。

设 DP 状态 $f_{i,j}$ 为在只能放前 $i$ 个物品的情况下，容量为 $j$ 的背包所能达到的**最大总价值**。

考虑转移。假设当前已经处理好了前 $i-1$ 个物品的所有状态，那么对于第 $i$ 个物品，当其不放入背包时，背包的剩余容量不变，背包中物品的总价值也不变，故这种情况的最大价值为 $f_{i-1,j}$；当其放入背包时，背包的剩余容量会减小 $w_{i}$，背包中物品的总价值会增大 $v_{i}$，故这种情况的最大价值为 $f_{i-1,j-w_{i}}+v_{i}$。

> NOTE:
>
> 一、$j-w_{i}$ 的原因是由于题目要求解的是最优值，所以尽可能的将背包装满

由此可以得出**状态转移方程**：

 $f_{i,j}=\max(f_{i-1,j},f_{i-1,j-w_{i}}+v_{i})$ 

这里如果直接采用**二维数组**对**状态**进行记录，会出现 MLE。可以考虑改用**滚动数组**的形式来优化。

由于对 $f_i$ 有影响的只有 $f_{i-1}$，可以去掉第一维，直接用 $f_{j}$ 来表示处理到当前物品时背包容量为 $j$ 的最大价值，得出以下方程：
 $f_j=\max \left(f_j,f_{j-w_i}+v_i\right)$ 

> NOTE:
>
> 一、上面说的"第一维"指的是 $f_{i,j}$ 中的 $i$ 

**务必牢记并理解这个转移方程，因为大部分背包问题的转移方程都是在此基础上推导出来的。**

### 实现

还有一点需要注意的是，很容易写出这样的 **错误核心代码**：

```c++
for (int i = 1; i <= n; i++)
  for (int l = 0; l <= W - w[i]; l++)
    // f[l] + v[i]   将第i个物品放入背包中
    // f[l + w[i]] 不将第i个物品放入背包中
    f[l + w[i]] = max(f[l] + v[i], f[l + w[i]]);
    // 由 f[i][l + w[i]] = max(max(f[i - 1][l + w[i]], f[i - 1][l] + w[i]), f[i][l + w[i]]); 简化而来
```

这段代码哪里错了呢？枚举顺序错了。

仔细观察代码可以发现：对于当前处理的物品 $i$ 和当前状态 $f_{i,j}$，在 $j\geqslant w_{i}$ 时，$f_{i,j}$ 是会被 $f_{i,j-w_{i}}$ 所影响的。这就相当于物品 $i$ 可以多次被放入背包，与题意不符。（事实上，这正是**完全背包**问题的解法)

为了避免这种情况发生，我们可以改变枚举的顺序，从 $W$ 枚举到 $w_{i}$，这样就不会出现上述的错误，因为 $f_{i,j}$ 总是在 $f_{i,j-w_{i}}$ 前被更新。

因此实际核心代码为

```c
for (int i = 1; i <= n; i++)
  for (int l = W; l >= w[i]; l--) // l的最小值为w[i]，这就保证了下面按照下标访问的安全性，这是简短代码
    f[l] = max(f[l], f[l - w[i]] + v[i]);
```



> NOTE:
>
> 一、如果没有结合0-1背包DP、完全背包DP的代码debug一下，那么上面的内容是很难读懂的。上面的内容是比较抽象的，并且它的实现方式是使用**滚动数组**进行**状态压缩**(即只使用了**一维数组**)，所以在循环体中需要考虑从**一维数组**中读取到的是$i-1$状态(未使用第$i$个物品更新的状态: $f_{i-1,j-w_{i}}$ )、$i$状态(使用第$i$个物品更新过的状态: $f_{i,j-w_{i}}$ )，下面对上面的内容进行说明: 
>
> 1、"在 $j\geqslant w_{i}$ 时，$f_{i,j}$ 是会被 $f_{i,j-w_{i}}$ 所影响的" 这段话指出了问题的所在，0-1背包的**递归关系**是 $f_{i,j}=\max(f_{i-1,j},f_{i-1,j-w_{i}}+v_{i})$ ，注意: 差别是:
>
> - $f_{i-1,j-w_{i}}$
>
> - $f_{i,j-w_{i}}$ ，如果使用它，则表示重复使用第$i$个物品
>
> 这正是**0-1背包**和**完全背包**的差别所在。
>
> 2、"因为 $f_{i,j}$ 总是在 $f_{i,j-w_{i}}$ 前被更新"
>
> 



## 完全背包

### 解释

完全背包模型与 0-1 背包类似，与 0-1 背包的区别仅在于一个物品可以选取无限次，而非仅能选取一次。

我们可以借鉴 0-1 背包的思路，进行状态定义：设 $f_{i,j}$ 为只能选前 $i$ 个物品时，容量为 $j$ 的背包可以达到的**最大价值**。

需要注意的是，虽然定义与 0-1 背包类似，但是其**状态转移方程**与 0-1 背包并不相同。

### 过程

可以考虑一个朴素的做法：对于第 $i$ 件物品，枚举其选了多少个来转移。这样做的时间复杂度是 $O(n^3)$ 的。

状态转移方程如下：

$f_{i,j}=\max_{k=0}^{+\infty}(f_{i-1,j-k\times w_i}+v_i\times k)$ 

> NOTE:
>
> 一、$k$ 是选取的个数

考虑做一个简单的优化。可以发现，对于 $f_{i,j}$，只要通过 $f_{i,j-w_i}$ 转移就可以了。因此**状态转移方程**为：

 $f_{i,j}=\max(f_{i-1,j},f_{i,j-w_i}+v_i)$ 

理由是当我们这样转移时，$f_{i,j-w_i}$ 已经由 $f_{i,j-2\times w_i}$ 更新过，那么 $f_{i,j-w_i}$ 就是充分考虑了第 $i$ 件物品所选次数后得到的最优结果。换言之，我们通过**局部最优子结构**的性质重复使用了之前的枚举过程，优化了枚举的复杂度。

> NOTE:
>
> 一、结合上一节0-1背包DP的内容就能够读懂上面这段话: 
>
> "$f_{i,j-w_i}$ 已经由 $f_{i,j-2\times w_i}$ 更新过，那么 $f_{i,j-w_i}$ 就是充分考虑了第 $i$ 件物品所选次数后得到的最优结果" 结合具体的例子来理解这段话: $f_{3, 5}$ 从 $f_{3, 4}$ 转移而来，它们都考虑了第3个物品，这就相当于第i个物品被重复选择了。
>
> 这应该就是这段话中的 **局部最优子结构** 的含义。
>
> 二、虽然是可以无限的取，但是还是受背包容量的限制，所以实际只能够取有限次数

与 **0-1 背包**相同，我们可以将第一维去掉来优化空间复杂度。如果理解了 0-1 背包的优化方式，就不难明白压缩后的循环是正向的（也就是上文中提到的错误优化）。



> NOTE:
>
> 一、需要对比它和0-1背包的状态转移方程:
>
> |                     0-1背包                     |                           完全背包                           |
> | :---------------------------------------------: | :----------------------------------------------------------: |
> | $f_{i,j}=\max(f_{i-1,j},f_{i-1,j-w_{i}}+v_{i})$ | $f_{i,j}=\max_{k=0}^{+\infty}(f_{i-1,j-k\times w_i}+v_i\times k)$ |
> |    $f_j=\max \left(f_j,f_{j-w_i}+v_i\right)$    |          $f_{i,j}=\max(f_{i-1,j},f_{i,j-w_i}+v_i)$           |
> |                                                 |                                                              |
>
> 0-1背包 $f_{i,j}=\max(f_{i-1,j},f_{i-1,j-w_{i}}+v_{i})$ 和 完全背包 $f_{i,j}=\max(f_{i-1,j},f_{i,j-w_i}+v_i)$  之间的细微差别在于 TODO(一个使用的是前i-1个物品、一个使用的是当前的物品)，这和它们的实现代码有着非常好的对应。



## 多重背包

**多重背包**也是 **0-1 背包**的一个变式。与 **0-1 背包**的区别在于每种物品有 $k_i$ 个，而非一个。

一个很朴素的想法就是：把「每种物品选 $k_i$ 次」等价转换为「有 $k_i$ 个相同的物品，每个物品选一次」。这样就转换成了一个 0-1 背包模型，套用上文所述的方法就可已解决。**状态转移方程**如下：

$f_{i,j}=\max_{k=0}^{k_i}(f_{i-1,j-k\times w_i}+v_i\times k)$ 

时间复杂度 $O(W\sum_{i=1}^nk_i)$。

### 二进制分组优化



考虑优化。我们仍考虑把多重背包转化成 0-1 背包模型来求解。

### 解释

显然，复杂度中的 $O(nW)$ 部分无法再优化了，我们只能从 $O(\sum k_i)$ 处入手。为了表述方便，我们用 $A_{i,j}$ 代表第 $i$ 种物品拆分出的第 $j$ 个物品。

在朴素的做法中，$\forall j\le k_i$，$A_{i,j}$ 均表示相同物品。那么我们效率低的原因主要在于我们进行了大量重复性的工作。举例来说，我们考虑了「同时选 $A_{i,1},A_{i,2}$」与「同时选 $A_{i,2},A_{i,3}$」这两个完全等效的情况。这样的重复性工作我们进行了许多次。那么优化拆分方式就成为了解决问题的突破口。

### 过程

> NOTE:
>
> 一、在 [jianshu-背包问题九讲 超全归纳](https://www.jianshu.com/p/830de6df0207) 中，对此有着更好的描述:
>
> > 由于**每组物品的件数均不一样**，所以**不能使用完全背包的优化方法**（具体件数不可控），因此采用另一种思路——**二进制优化**。
> >
> > 将每一种物品由1.2.4.8.16.128...的件数打包，不足一组的零头重新打包，转化为**01背包问题** 
>
> 

我们可以通过「二进制分组」的方式使拆分方式更加优美。

具体地说就是令 $A_{i,j}\left(j\in\left[0,\lfloor \log_2(k_i+1)\rfloor-1\right]\right)$ 分别表示由 $2^{j}$ 个单个物品「捆绑」而成的大物品。特殊地，若 $k_i+1$ 不是 $2$ 的整数次幂，则需要在最后添加一个由 $k_i-2^{\lfloor \log_2(k_i+1)\rfloor-1}$ 个单个物品「捆绑」而成的大物品用于补足。


举几个例子：

- $6=1+2+3$
- $8=1+2+4+1$
- $18=1+2+4+8+3$
- $31=1+2+4+8+16$

显然，通过上述拆分方式，可以表示任意 $\le k_i$ 个物品的等效选择方式。将每种物品按照上述方式拆分后，使用 0-1 背包的方法解决即可。

时间复杂度 $O(W\sum_{i=1}^n\log_2k_i)$。

### 实现

```C++
index = 0;
for (int i = 1; i <= m; i++) {
  int c = 1, p, h, k;
  cin >> p >> h >> k;
  while (k > c) {
    k -= c;
    list[++index].w = c * p;
    list[index].v = c * h;
    c *= 2;
  }
  list[++index].w = p * k;
  list[index].v = h * k;
}

```



## 混合背包

混合背包就是将前面三种的背包问题混合起来，有的只能取一次，有的能取无限次，有的只能取 $k$ 次。

这种题目看起来很吓人，可是只要领悟了前面几种背包的中心思想，并将其合并在一起就可以了。下面给出伪代码：

### 过程

```c++
for (循环物品种类) {
  if (是 0 - 1 背包)
    套用 0 - 1 背包代码;
  else if (是完全背包)
    套用完全背包代码;
  else if (是多重背包)
    套用多重背包代码;
}
```



## 二维费用背包

[「Luogu P1855」榨取 kkksc03](https://www.luogu.com.cn/problem/P1855)

> 有 $n$ 个任务需要完成，完成第 $i$ 个任务需要花费 $t_i$ 分钟，产生 $c_i$ 元的开支。
>
> 现在有 $T$ 分钟时间，$W$ 元钱来处理这些任务，求最多能完成多少任务。

这道题是很明显的 0-1 背包问题，可是不同的是选一个物品会消耗两种价值（经费、时间），只需在状态中增加一维存放第二种价值即可。

这时候就要注意，再开一维存放物品编号就不合适了，因为容易 MLE。

### 实现

```c++
for (int k = 1; k <= n; k++)
  for (int i = m; i >= mi; i--)    // 对经费进行一层枚举
    for (int j = t; j >= ti; j--)  // 对时间进行一层枚举
      dp[i][j] = max(dp[i][j], dp[i - mi][j - ti] + 1);

```



## 分组背包

[「Luogu P1757」通天之分组背包](https://www.luogu.com.cn/problem/P1757)

> 有 $n$ 件物品和一个大小为 $m$ 的背包，第 $i$ 个物品的价值为 $w_i$，体积为 $v_i$。同时，每个物品属于一个组，同组内最多只能选择一个物品。求背包能装载物品的最大总价值。

这种题怎么想呢？其实是从「在所有物品中选择一件」变成了「从当前组中选择一件」，于是就对每一组进行一次 0-1 背包就可以了。

再说一说如何进行存储。我们可以将 $t_{k,i}$ 表示第 $k$ 组的第 $i$ 件物品的编号是多少，再用 $\mathit{cnt}_k$ 表示第 $k$ 组物品有多少个。

### 实现

```c++
for (int k = 1; k <= ts; k++)           // 循环每一组
  for (int i = m; i >= 0; i--) // 循环背包容量
    for (int j = 1; j <= cnt[k]; j++)   // 循环该组的每一个物品
      if (i >= w[t[k][j]])  // 背包容量充足
        dp[i] = max(dp[i], dp[i - w[t[k][j]]] + c[t[k][j]]);  // 像0-1背包一样状态转移

```

这里要注意：**一定不能搞错循环顺序**，这样才能保证正确性。

