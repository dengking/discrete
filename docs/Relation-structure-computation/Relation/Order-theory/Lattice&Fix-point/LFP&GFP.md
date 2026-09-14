# LFP / GFP（Hopcroft 自动机&数据流分析语境）

> LFP = **Least Fixed Point** 最小不动点
> GFP = **Greatest Fixed Point** 最大不动点
> 出自 Hopcroft、Ullman《龙书/自动机理论、语言和计算导论》，在格（Lattice）+单调函数框架下，广泛用于：$\varepsilon$-闭包计算、数据流分析、NFA子集构造。

## 基础定义（格上单调函数）

设 $(L,\sqsubseteq)$ 是完备格，函数 $f:L\to L$ 单调：$a\sqsubseteq b \implies f(a)\sqsubseteq f(b)$

- **不动点 fixed point**：元素 $x\in L$，满足 $f(x)=x$
- **LFP 最小不动点**：所有不动点里**最小**的那个元素（$\text{lfp}(f)$）
- **GFP 最大不动点**：所有不动点里**最大**的那个元素（$\text{gfp}(f)$）

### 迭代求解思路

1. **LFP（最小不动点，自底向上迭代）**
    初始取格底元 $\bot$，反复应用 $f$：$x_0=\bot,\quad x_{n+1}=f(x_n)$
    
    序列单调递增 $x_0\sqsubseteq x_1\sqsubseteq x_2\dots$，收敛到 $\boldsymbol{\text{lfp}(f)}$
   
   > 典型例子：**$\varepsilon$-closure 空闭包**。
   > 求从起点能到达的全部状态，从空集合开始不断添加可达状态，直到不再变化。集合越算越大，直到不动点，就是LFP。

2. **GFP（最大不动点，自顶向下迭代）**
    初始取格顶元 $\top$，反复应用 $f$：$x_0=\top,\quad x_{n+1}=f(x_n)$
    
    序列单调递减 $x_0\sqsupseteq x_1\sqsupseteq x_2\dots$，收敛到 $\boldsymbol{\text{gfp}(f)}$
   
   > 典型例子：**确定分析、不可达代码/必须满足的性质**。
   > 一开始假设全部状态都成立，不断剔除不满足条件元素，集合不断缩小直到稳定，得到GFP。

## 集合格视角（幂集格，最常用，对应NFA）

全集为所有状态集合 $Q$，格是幂集格 $\mathcal{P}(Q)$，偏序 $\sqsubseteq$ 就是集合包含 $\subseteq$

- 底元 $\bot=\emptyset$（空集）
- 顶元 $\top=Q$（全部状态）
- 并 $\sqcup = \cup$，交 $\sqcap = \cap$
  - LFP：从空集开始不断并集扩充（求可达集合：\(\varepsilon\)闭包）
  - GFP：从全集开始不断剔除元素

## Hopcroft & Ullman 书中的典型场景

1. ✅ **\(\varepsilon\)-closure 计算 = LFP**
    函数 $\(f(S)=S \cup \{\text{所有经1步\)$\varepsilon$\(转移从S可达的状态}\}\)$
    从空集迭代，不断加入新状态，直到集合不变。得到最小不动点。
   
   > 正好是刚才维基文本中 $\varepsilon$ 闭包的算法底层数学基础。

2. 数据流分析（龙书编译原理）
   
   - 正向数据流：可达定义、可用表达式 → **LFP**
   - 反向数据流：活跃变量 → **LFP**
   - 必须性质（must-analysis），例如到达所有路径的常量传播，常求 **GFP**

## 关键性质（Knaster–Tarski 定理，Hopcroft教材核心）

> 任意完备格上**单调函数一定存在最小不动点和最大不动点**。
> 所有不动点构成一个子格，$\text{lfp}(f)$ 是不动点集合下界，$\text{gfp}(f)$ 是不动点集合上界。

## 一句话区分

- **LFP（最小不动点）：收集“能到达、可能成立”的信息，从小到大迭代（从空开始，不断加元素）**
- **GFP（最大不动点）：保留“所有路径都一定成立”的信息，从大到小迭代（全集起步，不断删元素）**

## 术语中英

| 缩写                     | 全称                   | 中文    |
| ---------------------- | -------------------- | ----- |
| LFP                    | Least Fixed Point    | 最小不动点 |
| GFP                    | Greatest Fixed Point | 最大不动点 |
| Knaster–Tarski theorem | 克纳斯特–塔尔斯基定理          |       |
| complete lattice       | 完备格                  |       |
| monotonic function     | 单调函数                 |       |

如果你需要，我可以写一段**伪代码**分别演示LFP求\(\varepsilon\)闭包，和GFP迭代。或者整理成markdown笔记版本。
