# Powerset construction

## wikipedia [Powerset construction](https://en.wikipedia.org/wiki/Powerset_construction)

In the [theory of computation](https://en.wikipedia.org/wiki/Theory_of_computation) and [automata theory](https://en.wikipedia.org/wiki/Automata_theory), the **powerset construction** or **subset construction** is a standard method for [converting](https://en.wikipedia.org/wiki/Automata_construction) a [nondeterministic finite automaton](https://en.wikipedia.org/wiki/Nondeterministic_finite_automaton) (NFA) into a [deterministic finite automaton](https://en.wikipedia.org/wiki/Deterministic_finite_automaton) (DFA) which recognizes the same [formal language](https://en.wikipedia.org/wiki/Formal_language). It is important in theory because it establishes that NFAs, despite their additional flexibility, are unable to recognize any language that cannot be recognized by some DFA. It is also important in practice for converting easier-to-construct NFAs into more efficiently executable DFAs. However, if the NFA has *n* states, the resulting DFA may have up to $2^n$ states, an exponentially larger number, which sometimes makes the construction impractical for large NFAs.

> NOTE: NFA的识别能力和DFA相同

The construction, sometimes called the **Rabin–Scott powerset construction** (or **subset construction**) to distinguish it from similar constructions for other types of automata, was first published by [Michael O. Rabin](https://en.wikipedia.org/wiki/Michael_O._Rabin) and [Dana Scott](https://en.wikipedia.org/wiki/Dana_Scott) in 1959.

### Intuition

To simulate the operation of a DFA on a given input string, one needs to keep track of **a single state** at any time: the state that the automaton will reach after seeing a [prefix](https://en.wikipedia.org/wiki/Substring#Prefix) of the input. In contrast, to simulate an NFA, one needs to keep track of **a set of states**: all of the states that the automaton could reach after seeing the same prefix of the input, according to the nondeterministic choices made by the **automaton**. If, after a certain prefix of the input, a set *S* of states can be reached, then after the next input symbol *x* the set of reachable states is a deterministic function of *S* and *x*. Therefore, the **sets of reachable NFA states** play the same role in the **NFA simulation** as single DFA states play in the **DFA simulation**, and in fact the sets of **NFA states** appearing in this simulation may be re-interpreted as being states of a DFA.

> 翻译: 要模拟确定有限自动机（DFA）在给定输入串上的运行过程，**任意时刻只需维护单个状态**：即自动机读入输入串某**前缀（prefix）**之后所到达的状态。与之不同，模拟非确定有限自动机（NFA）时，则需要维护**一个状态集合**：依据自动机的非确定选择，读入该相同输入前缀后，自动机所有可能抵达的全部状态。
> 
> 若读入输入的某个前缀后，可达状态集合为 $S$；那么读入下一个输入符号 $x$ 之后，新的可达状态集合是关于 $S$ 和 $x$ 的确定函数。因此，在NFA模拟过程中的可达状态集合，扮演的角色等价于DFA模拟里的单个DFA状态。事实上，该模拟过程中出现的这些NFA状态集合，可以被重新解读为一台DFA的各个状态。

> NOTE: The difference between DFA and NFA can help to understand why **a single state** in DFA versus **a set of states** in NFA, below is come from [Finite-state machine](https://en.wikipedia.org/wiki/Finite-state_machine#Determinism):
> 
> In a deterministic automaton, every state has exactly one transition for each possible input. In a non-deterministic automaton, an input can lead to one, more than one, or no transition for a given state. The [powerset construction](https://en.wikipedia.org/wiki/Powerset_construction) algorithm can transform any nondeterministic automaton into a (usually more complex) deterministic automaton with identical functionality.

### Construction

The **powerset construction** applies most directly to an NFA that does not allow state transformations without consuming input symbols (aka: "$\varepsilon$-moves"). Such an automaton may be defined as a 5-tuple $(Q, \Sigma, T, q_0, F)$, in which: 

- $Q$ is the set of states

- $\Sigma$ is the set of input symbols

- $T$ is the transition function (mapping a state and an input symbol to a set of states)

- $q_0$ is the initial state

- $F$ is the set of accepting states

The corresponding DFA has states corresponding to subsets of $Q$. The initial state of the DFA is $\{q_0\}$, the (one-element) set of **initial states**. The **transition function** of the DFA maps a state $S$ (representing a subset of $Q$) and an input symbol $x$ to the set $T(S,x) = \bigcup\{T(q,x) \mid q \in S\}$, the set of all states that can be reached by an $x$-transition from a state in $S$. A state $S$ of the DFA is an accepting state if and only if at least one member of $S$ is an **accepting state** of the NFA.$^{[2][3]}$

In the simplest version of the **powerset construction**, the set of all states of the DFA is the **powerset** of $Q$, the set of all possible subsets of $Q$. However, many states of the resulting DFA may be useless as they may be unreachable from the **initial state**. An alternative version of the construction creates only the states that are actually reachable.$^{[4]}$

#### NFA with $\varepsilon$-moves

For an NFA with $\varepsilon$-moves (also called an $\varepsilon$-NFA), the construction must be modified to deal with these by computing the **$\varepsilon$-closure** of states: the set of all states reachable from some given state using only $\varepsilon$-moves. Van Noord recognizes three possible ways of incorporating this closure computation in the powerset construction:$^{[5]}$

1. Compute the $\varepsilon$-closure of the entire automaton as a preprocessing step, producing an equivalent NFA without $\varepsilon$-moves, then apply the regular powerset construction. This version, also discussed by Hopcroft and Ullman,$^{[6]}$ is straightforward to implement, but impractical for automata with large numbers of $\varepsilon$-moves, as commonly arise in natural language processing application.$^{[5]}$
2. During the powerset computation, compute the $\varepsilon$-closure $\{q' \mid q \to^*_\varepsilon q'\}$ of each state $q$ that is considered by the algorithm (and cache the result).
3. During the powerset computation, compute the $\varepsilon$-closure $\{q' \mid \exists q \in Q', q \to^*_\varepsilon q'\}$ of each subset of states $Q'$ that is considered by the algorithm, and add its elements to $Q'$.

#### Multiple initial states

If NFAs are defined to allow for multiple initial states,$^{[7]}$ the initial state of the corresponding DFA is the set of all initial states of the NFA, or (if the NFA also has $\varepsilon$-moves) the set of all states reachable from initial states by $\varepsilon$-moves.

## 指数爆炸

### 先明确概念：NFA 的「指数爆炸」是什么

**指数爆炸（Exponential Blowup）** 是**子集构造法（Subset Construction）**的理论最坏情况：将**非确定有限自动机（Nondeterministic Finite Automaton, NFA）**转换为**确定有限自动机（Deterministic Finite Automaton, DFA）**时，DFA 的状态数理论上界是 \(2^{\text{NFA状态数}}\)，即状态数随 NFA 规模呈指数级增长。

但这只是理论上界，工程实践中极少触发，而 `(a|b)*a(a|b)^n` 就是专门构造出来、刚好触碰到这个理论下界的经典最坏案例。

---

### 例子拆解：为什么 `(a|b)*a(a|b)^n` 会触发指数爆炸

### 1. 正则式的语义

这个正则式描述的语言是：

> 所有由 `a`、`b` 组成的字符串，且**倒数第 \(n+1\) 个字符必须是 `a`**。

- `(a|b)*`：前面可以是任意长度的 a/b 序列
- 中间的 `a`：那个必须出现在倒数第 \(n+1\) 位的字符
- `(a|b)^n`：这个 a 后面必须紧跟 n 个任意 a/b 字符

比如 \(n=2\) 时，就是匹配所有「倒数第 3 位是 a」的 a/b 串，例如 `aab`、`aba`、`baa` 都符合，`bba` 不符合。

### 2. 核心矛盾：必须记住完整的 n 位历史

自动机是**从左到右逐个字符扫描**的，并且**提前不知道字符串什么时候结束**。要在字符串结束的瞬间判断「倒数第 n+1 位是不是 a」，就必须在扫描的每一步，都完整记住**最近 n 个字符的全部组合**——相当于维护一个长度为 n 的滑动历史窗口。

原因很简单：每读入一个新字符，窗口就向右滑动一位，旧的最左字符被丢弃，新字符加入最右端；当字符串结束时，窗口的第一个字符，就是我们要判断的「倒数第 n+1 位」。

### 3. 指数级状态数的推导

窗口长度为 n，每个位置有 a、b 两种可能，因此**所有可能的窗口组合总共有 \(2^n\) 种**。
而 DFA 中每个状态必须对应一种唯一的窗口组合——因为不同的窗口组合，后续的接受判定结果不同，无法合并状态。

以 \(n=2\) 为例（窗口长度 2），共 \(2^2=4\) 个 DFA 状态：
| 状态（窗口内容） | 读入 a 后的新状态 | 读入 b 后的新状态 | 是否为接受态（窗口首位是a） |
|----------------|------------------|------------------|--------------------------|
| `bb`           | `ba`             | `bb`             | 否                       |
| `ba`           | `aa`             | `ab`             | 否                       |
| `ab`           | `ba`             | `bb`             | 是                       |
| `aa`           | `aa`             | `ab`             | 是                       |

可以看到：

- \(n=2\)：4 个状态（\(2^2\)）
- \(n=10\)：1024 个状态（\(2^{10}\)）
- \(n=20\)：超过 100 万个状态（\(2^{20}\)）

状态数随 n 指数增长，这就是「指数爆炸」。

### 4. NFA 与 DFA 的状态数对比

这个正则式对应的 NFA 状态数其实是**线性的**：只需要「初始循环态 → a 转移态 → n 个任意字符态 → 接受态」，总共约 \(n+2\) 个状态。
但经过子集构造转为 DFA 后，状态数直接膨胀到 \(2^n\)，从线性规模变成指数规模，完美触碰到了子集构造的理论下界。

---

### 为什么真实编译器中几乎不会发生：局部性（Locality）

真实编译器的词法规则（正则表达式/文法）具有极强的**局部性**，完全不会出现这种「需要记住 n 步历史才能区分分支」的情况：

1. **分支快速分化**：真实词法规则的不同分支，通常在第 1~2 个字符就完全区分开了。比如：
   - 关键字 `if` / `else` / `while`：首字母 `i` / `e` / `w` 直接区分
   - 标识符：以字母或下划线开头
   - 数字：以数字开头
   - 运算符：`+` / `-` / `*` / `/` 首字符各不相同
2. **无需长历史回溯**：决策只依赖当前局部的少数几个字符，不需要回溯很长的历史来确定分支。NFA 的不确定性只在极短的范围内存在，很快就收敛为确定状态。

因此在真实场景中，子集构造生成的 DFA 状态数几乎和 NFA 处于同一量级，接近线性增长，理论上的指数爆炸几乎永远不会实际发生。

---

### 为什么这是子集构造工程成功的原因

子集构造法在理论上有指数爆炸的最坏情况，但它有两个不可替代的优势：

1. 生成的 DFA 是**确定型线性扫描**，匹配速度极快，是词法分析的性能基石；
2. 真实输入的局部性让指数爆炸几乎从不出现，工程实际表现始终稳定优秀。

理论最坏情况从未发生，而确定性、高性能的优势可以充分发挥，这就是子集构造能成为 Lex/Flex 等工业级词法生成器核心算法、在工程上大获成功的根本原因。

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
