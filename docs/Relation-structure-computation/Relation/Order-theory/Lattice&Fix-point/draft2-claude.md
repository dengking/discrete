# 子集构造的 Python 实现

下面是一份**可直接运行**的完整实现。我按照前面几轮的格论视角组织代码，每个函数上都标注了它对应哪个数学对象：

| 代码                    | 数学对象                                                                                        |
| --------------------- | ------------------------------------------------------------------------------------------- |
| `epsilon_closure`     | $(2^Q,\subseteq)$ 上 $X\mapsto S\cup\mathrm{post}_\varepsilon(X)$ 的 **lfp**（worklist = 混沌迭代） |
| `move`                | $\delta(\cdot,a)$ 沿"$2^Q$ 是自由完备并半格"的唯一保并提升 $\hat\delta$                                     |
| `determinize`         | $(2^{2^Q},\subseteq)$ 上 $\mathrm{Step}$ 的 **lfp**（惰性/可达部分）                                  |
| `determinize_layered` | 同上，但逐层 $\mathrm{Step}^n(\varnothing)$，**看得见 Kleene 迭代**                                     |
| `minimize`            | 划分格 $\Pi(Q)$ 上最大同余的 **gfp**（Hopcroft）                                                       |

## 运行结果（节选）

```
① ε-闭包：为什么必须是最小不动点
  lfp = ε-cl({1}) = {1,2}
  但 F({1,2,3}) = {1,2,3} → 它也是不动点，即 gfp
  lfp = 只承认有有限证明树的成员资格。✓

② Kleene 迭代：Step^n(∅) 逐层展开
  Step^0(∅)：0 个子集
  Step^1(∅)：1 个子集
  Step^2(∅)：3 个子集
  Step^3(∅)：4 个子集
  Step^4(∅)：5 个子集
  Step^5(∅)：5 个子集   ← 稳定
  收敛后 |Dstates| = 5（格高度是 2^14，实际只用了 直径+1 步）

④ 状态爆炸
   n | NFA |  DFA  | 最小 DFA |  2^n  | 格高度 2^|Q|
  ---+-----+-------+----------+-------+--------------
   1 |   2 |     2 |        2 |     2 |            4
   ...
  10 |  11 |  1024 |     1024 |  1024 |         2048
```

---

## 练习题（按难度递增）

**热身**

1. 给 `determinize` 加上 `max_states` 上限，超过就抛异常——这就是真实工具（RE2、Rust `regex`）里 DFA 缓存的做法。
2. 实现 `DFA.complement()`（交换 $F$ 和 $Q\setminus F$，**必须先 `complete()`**——想清楚为什么偏 DFA 直接取反是错的）。

**核心**

3. **乘积构造**：`product(d1, d2, op)`，状态集 $Q_1\times Q_2$，`op ∈ {∩, ∪, \, △}`。用它 + `equivalent` 验证 $L(r_1)\cap L(r_2)$ 的正则性。
4. **$\varepsilon$-移除**：写 `remove_epsilon(nfa) -> NFA`（不确定化，只消 ε）。验证它与原 NFA 等价。
5. **Brzozowski 最小化**：`minimize2 = determinize ∘ reverse ∘ determinize ∘ reverse`。惊人地只需 4 行，且**自动最小**。用它交叉验证你的 Hopcroft。
6. **区分表（Moore）**：实现 $O(n^2)$ 的表填充法，和 Hopcroft 对拍。

**格论视角**

7. 把 `epsilon_closure` 和 `determinize` 抽象成一个通用的
   
   ```python
   def lfp(bottom, step, join):  # 通用 Kleene 迭代 + worklist
   ```
   
   然后用**同一个** `lfp` 实现：ε-闭包、子集构造、正则文法的 FIRST 集、图的可达性。体会"换个格换个算子，算法不变"。

8. 统计 `determinize` 中 `dstep` 的调用次数，画出 $n$ vs 调用数的曲线，对比理论上界 $|\Sigma|\cdot 2^{|Q|}$。

9. 用 `dict` 把 $2^Q$ 换成 **bitmask 整数**（`frozenset` → `int`，`|`/`&`/`popcount`），测一下 $n=16$ 的 $L_n$ 提速多少。

**进阶**

10. **惰性 DFA + LRU 缓存**：不预先构造，边匹配边建，缓存满了就清空。这是工业正则引擎的真实架构。
11. **反向确定化（co-determinization）**：把 $\hat F(S)=[S\cap F\ne\varnothing]$ 换成 $[S\subseteq F]$，看看得到什么语言——这对应 universal automaton，是"提升到共半格"的那一侧。
12. 给 NFA 加**权**（$\mathbb N$ 或 tropical 半环），实现加权确定化，观察它**何时不终止**——因为 $\mathcal P$ 换成了别的单子，底层格不再有限高度。
