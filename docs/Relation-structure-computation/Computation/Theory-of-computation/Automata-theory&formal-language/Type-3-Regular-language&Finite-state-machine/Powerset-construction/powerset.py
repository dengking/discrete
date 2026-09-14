"""
powerset.py — 子集构造（Powerset / Subset Construction）：NFA → DFA

包含：
  * ε-NFA / DFA 数据结构
  * ε-闭包（lfp，worklist 混沌迭代）
  * 惰性子集构造 + 分层 Kleene 迭代版本
  * Hopcroft 最小化（gfp）
  * DFA 等价性判定（乘积 BFS，带反例见证）
  * Thompson 构造：正则表达式 → ε-NFA
  * Graphviz DOT 输出
"""

from __future__ import annotations

from collections import defaultdict, deque
from typing import (Dict, FrozenSet, Hashable, Iterable, Iterator, List,
                    Optional, Set, Tuple)

State = Hashable
Symbol = Hashable
EPSILON: None = None                      # ε 用 None 表示


def _fmt(s) -> str:
    """把 frozenset 状态打印成 {a,b,c}。"""
    if isinstance(s, frozenset):
        return "{" + ",".join(sorted(_fmt(x) for x in s)) + "}" if s else "∅"
    return str(s)


# ══════════════════════════════════════════════════════════════════
#  1. NFA
# ══════════════════════════════════════════════════════════════════
class NFA:
    """带 ε 转移的非确定有限自动机。

    transitions: {(state, symbol_or_EPSILON): iterable_of_states}
    start:       单个状态，或状态集合
    """

    def __init__(self, states, alphabet, transitions, start, accepting):
        self.states: FrozenSet[State] = frozenset(states)
        self.alphabet: FrozenSet[Symbol] = frozenset(alphabet)
        self.start: FrozenSet[State] = (
            frozenset(start) if isinstance(start, (set, frozenset, list, tuple))
            else frozenset([start])
        )
        self.accepting: FrozenSet[State] = frozenset(accepting)

        d: Dict[Tuple[State, Optional[Symbol]], Set[State]] = defaultdict(set)
        for (q, a), targets in transitions.items():
            if q not in self.states:
                raise ValueError(f"未知状态 {q!r}")
            if a is not EPSILON and a not in self.alphabet:
                raise ValueError(f"未知符号 {a!r}")
            for r in targets:
                if r not in self.states:
                    raise ValueError(f"未知目标状态 {r!r}")
                d[(q, a)].add(r)
        self.delta: Dict[Tuple[State, Optional[Symbol]], FrozenSet[State]] = {
            k: frozenset(v) for k, v in d.items()
        }
        if not self.start <= self.states:
            raise ValueError("初始状态不在状态集中")
        if not self.accepting <= self.states:
            raise ValueError("接受状态不在状态集中")

        self._cl_cache: Dict[FrozenSet[State], FrozenSet[State]] = {}

    # ── ε-闭包：(2^Q, ⊆) 上的最小不动点 ────────────────────────────
    def epsilon_closure(self, S: Iterable[State]) -> FrozenSet[State]:
        """lfp( X ↦ S ∪ post_ε(X) )。

        Tarski 读法：含 S 且对 ε 边封闭的最小集合。
        Kleene 读法：从 S 出发不断加入 ε 后继，直到稳定。
        实现是 worklist（混沌迭代 / semi-naive）：只推进"新加入"的元素，
        总代价 O(|E_ε|)，而不是 O(|Q|·|E|)。
        用 lfp 而非 gfp 的关键：ε-自环不会凭空"自我供养"出虚假状态。
        """
        key = frozenset(S)
        hit = self._cl_cache.get(key)
        if hit is not None:
            return hit

        closure = set(key)
        stack = list(key)
        while stack:                                   # ← Kleene 迭代
            q = stack.pop()
            for r in self.delta.get((q, EPSILON), ()):
                if r not in closure:                   # ← 只推进新元素
                    closure.add(r)
                    stack.append(r)

        result = frozenset(closure)
        self._cl_cache[key] = result
        return result

    # ── δ̂ ：δ(·,a) 的唯一保并提升 ─────────────────────────────────
    def move(self, S: Iterable[State], a: Symbol) -> FrozenSet[State]:
        """δ̂(S,a) = ⋃_{q∈S} δ(q,a)。

        这不是"约定"：2^Q 是 Q 上的自由完备并半格，
        任何 f: Q → L（L 完备并半格）唯一地扩张为保并的 f̂(S)=⋁_{q∈S} f(q)。
        取 f = δ(·,a) 就逼出了这个并集。
        """
        out: Set[State] = set()
        for q in S:
            out |= self.delta.get((q, a), frozenset())
        return frozenset(out)

    def dstep(self, S: Iterable[State], a: Symbol) -> FrozenSet[State]:
        """DFA 的一步：ε-cl ∘ move。

        为什么每次都要再取一次闭包？因为 ε-cl 是 2^Q 上的闭包算子，
        DFA 状态必须住在它的不动点子格里；move 会把你踢出去，得投影回来。
        """
        return self.epsilon_closure(self.move(S, a))

    # ── 直接模拟（其实就是"在线的"子集构造）────────────────────────
    def accepts(self, word: Iterable[Symbol]) -> bool:
        S = self.epsilon_closure(self.start)
        for a in word:
            if a not in self.alphabet:
                return False
            S = self.dstep(S, a)
            if not S:                                   # ⊥：已死
                return False
        return bool(S & self.accepting)                 # F̂(S) = [S ∩ F ≠ ∅]

    def __repr__(self) -> str:
        n_eps = sum(len(v) for (q, a), v in self.delta.items() if a is EPSILON)
        return (f"NFA(|Q|={len(self.states)}, |Σ|={len(self.alphabet)}, "
                f"边={sum(map(len, self.delta.values()))}（其中 ε 边 {n_eps}）)")


# ══════════════════════════════════════════════════════════════════
#  2. DFA
# ══════════════════════════════════════════════════════════════════
class DFA:
    def __init__(self, states, alphabet, delta, start, accepting):
        self.states: FrozenSet[State] = frozenset(states)
        self.alphabet: FrozenSet[Symbol] = frozenset(alphabet)
        self.delta: Dict[Tuple[State, Symbol], State] = dict(delta)
        self.start: State = start
        self.accepting: FrozenSet[State] = frozenset(accepting)

    # ── 基本操作 ──────────────────────────────────────────────────
    def accepts(self, word: Iterable[Symbol]) -> bool:
        q = self.start
        for a in word:
            nxt = self.delta.get((q, a))
            if nxt is None:                             # 偏 DFA：卡住 = 拒绝
                return False
            q = nxt
        return q in self.accepting

    def is_total(self) -> bool:
        return all((q, a) in self.delta
                   for q in self.states for a in self.alphabet)

    def complete(self, sink: State = "⊥") -> "DFA":
        """补全为全函数 DFA（补一个陷阱状态）。Hopcroft 需要全 DFA。"""
        if self.is_total():
            return self
        while sink in self.states:
            sink = str(sink) + "'"
        states = self.states | {sink}
        delta = dict(self.delta)
        for q in states:
            for a in self.alphabet:
                delta.setdefault((q, a), sink)
        return DFA(states, self.alphabet, delta, self.start, self.accepting)

    def trim_unreachable(self) -> "DFA":
        """限制到 lfp(Step)：删掉不可达状态。注意这不是最小化。"""
        seen = {self.start}
        work = deque([self.start])
        while work:
            q = work.popleft()
            for a in self.alphabet:
                r = self.delta.get((q, a))
                if r is not None and r not in seen:
                    seen.add(r)
                    work.append(r)
        delta = {(q, a): r for (q, a), r in self.delta.items() if q in seen}
        return DFA(seen, self.alphabet, delta,
                   self.start, self.accepting & seen)

    def relabel(self, prefix: str = "q") -> "DFA":
        """按 BFS 顺序重命名为 q0, q1, ...（便于打印/比较）。"""
        order: List[State] = []
        seen = {self.start}
        work = deque([self.start])
        syms = sorted(self.alphabet, key=repr)
        while work:
            q = work.popleft()
            order.append(q)
            for a in syms:
                r = self.delta.get((q, a))
                if r is not None and r not in seen:
                    seen.add(r)
                    work.append(r)
        order += sorted(self.states - seen, key=repr)
        name = {q: f"{prefix}{i}" for i, q in enumerate(order)}
        return DFA(
            name.values(), self.alphabet,
            {(name[q], a): name[r] for (q, a), r in self.delta.items()},
            name[self.start], {name[q] for q in self.accepting},
        )

    # ── 输出 ──────────────────────────────────────────────────────
    def to_dot(self, name: str = "DFA") -> str:
        lines = [f'digraph {name} {{', '  rankdir=LR;',
                 '  __start [shape=point,label=""];']
        for q in sorted(self.states, key=lambda s: _fmt(s)):
            shape = "doublecircle" if q in self.accepting else "circle"
            lines.append(f'  "{_fmt(q)}" [shape={shape}];')
        lines.append(f'  __start -> "{_fmt(self.start)}";')
        merged: Dict[Tuple[State, State], List[str]] = defaultdict(list)
        for (q, a), r in self.delta.items():
            merged[(q, r)].append(str(a))
        for (q, r), syms in merged.items():
            lines.append(f'  "{_fmt(q)}" -> "{_fmt(r)}" '
                         f'[label="{",".join(sorted(syms))}"];')
        lines.append("}")
        return "\n".join(lines)

    def table(self) -> str:
        syms = sorted(self.alphabet, key=repr)
        w = max([len(_fmt(q)) for q in self.states] + [6]) + 2
        head = "  " + "state".ljust(w) + "".join(str(a).ljust(w) for a in syms)
        rows = [head, "  " + "-" * len(head)]
        order = sorted(self.states, key=lambda q: (q != self.start, _fmt(q)))
        for q in order:
            mark = ("→" if q == self.start else " ") + \
                   ("*" if q in self.accepting else " ")
            row = mark + _fmt(q).ljust(w)
            row += "".join(_fmt(self.delta.get((q, a), "—")).ljust(w)
                           for a in syms)
            rows.append(row)
        return "\n".join(rows)

    def __len__(self) -> int:
        return len(self.states)

    def __repr__(self) -> str:
        return (f"DFA(|Q|={len(self.states)}, |Σ|={len(self.alphabet)}, "
                f"|F|={len(self.accepting)}, total={self.is_total()})")


# ══════════════════════════════════════════════════════════════════
#  3. 子集构造：(2^(2^Q), ⊆) 上的 lfp
# ══════════════════════════════════════════════════════════════════
def determinize(nfa: NFA, keep_sink: bool = True) -> DFA:
    """惰性子集构造。

    Dstates = lfp( 𝓡 ↦ {s₀} ∪ { δ̂(S,a) : S∈𝓡, a∈Σ } )  在 (2^(2^Q), ⊆) 上。

    Tarski：含 s₀ 且对 δ̂ 封闭的最小子集族。
    Kleene：worklist（BFS 即按输入长度分层）。
    终止性：格高度 2^|Q| —— "状态爆炸"就是这个格的尺寸，不是算法的缺陷。

    keep_sink=False 则丢弃 ∅（得到偏 DFA，更小）。
    """
    s0 = nfa.epsilon_closure(nfa.start)
    dstates: Set[FrozenSet[State]] = {s0}
    work: deque = deque([s0])
    dtran: Dict[Tuple[FrozenSet[State], Symbol], FrozenSet[State]] = {}
    syms = sorted(nfa.alphabet, key=repr)

    while work:                                         # ← Kleene 迭代
        S = work.popleft()
        for a in syms:
            T = nfa.dstep(S, a)
            if not T and not keep_sink:
                continue
            if T not in dstates:                        # ← 只推进新元素
                dstates.add(T)
                work.append(T)
            dtran[(S, a)] = T

    accepting = {S for S in dstates if S & nfa.accepting}
    return DFA(dstates, nfa.alphabet, dtran, s0, accepting)


def determinize_layered(nfa: NFA) -> Iterator[Tuple[int, FrozenSet]]:
    """逐层给出 Step^n(∅)，把 Kleene 迭代显式暴露出来。

    Step^n(∅) = { δ̂*(s₀, w) : |w| < n }，即按输入长度 BFS 分层。
    实际收敛步数 = DFA 直径 + 1，通常远小于格高度 2^|Q|。
    """
    s0 = nfa.epsilon_closure(nfa.start)
    R: FrozenSet[FrozenSet[State]] = frozenset()
    n = 0
    while True:
        yield n, R
        nxt = frozenset([s0]) | frozenset(
            nfa.dstep(S, a) for S in R for a in nfa.alphabet
        )
        if nxt == R:                                    # 到达 lfp
            return
        R, n = nxt, n + 1


# ══════════════════════════════════════════════════════════════════
#  4. 最小化：划分格 Π(Q) 上的 gfp（Hopcroft）
# ══════════════════════════════════════════════════════════════════
def minimize(dfa: DFA) -> DFA:
    """Hopcroft 分划细化。O(|Q|·|Σ|·log|Q|)。

    构造阶段用 lfp（往上灌水，2^Q 布尔分配、worklist 就够）；
    这里用 gfp（最大双模拟 / 最粗同余），舞台是划分格 Π(Q)——
    它从 3 个元素起就含钻石 M₃，非模非分配，∨ 要取传递闭包。
    算法之所以更精巧，正是因为格更难看。
    """
    d = dfa.trim_unreachable().complete()
    F, NF = d.accepting & d.states, d.states - d.accepting

    P: Set[FrozenSet[State]] = {b for b in (frozenset(F), frozenset(NF)) if b}
    W: Set[FrozenSet[State]] = set(P)

    pre: Dict[Tuple[Symbol, State], Set[State]] = defaultdict(set)
    for (p, a), q in d.delta.items():
        pre[(a, q)].add(p)

    while W:
        A = W.pop()
        for a in d.alphabet:
            X: Set[State] = set()
            for q in A:
                X |= pre[(a, q)]
            if not X:
                continue
            for Y in [Y for Y in P if not Y.isdisjoint(X) and not Y <= X]:
                inter, diff = frozenset(Y & X), frozenset(Y - X)
                P.discard(Y); P.add(inter); P.add(diff)
                if Y in W:
                    W.discard(Y); W.add(inter); W.add(diff)
                else:
                    W.add(inter if len(inter) <= len(diff) else diff)

    rep = {q: block for block in P for q in block}
    delta = {}
    for block in P:
        q = next(iter(block))
        for a in d.alphabet:
            delta[(block, a)] = rep[d.delta[(q, a)]]
    return DFA(P, d.alphabet, delta, rep[d.start],
               {b for b in P if b & F})


# ══════════════════════════════════════════════════════════════════
#  5. 等价性判定（乘积 BFS，带反例）
# ══════════════════════════════════════════════════════════════════
def equivalent(d1: DFA, d2: DFA) -> Tuple[bool, Optional[str]]:
    """返回 (是否等价, 区分二者的最短串)。"""
    if d1.alphabet != d2.alphabet:
        raise ValueError("字母表不同")
    a1, a2 = d1.complete("⊥1"), d2.complete("⊥2")
    syms = sorted(a1.alphabet, key=repr)
    start = (a1.start, a2.start)
    seen = {start}
    work = deque([(start, "")])
    while work:
        (p, q), w = work.popleft()
        if (p in a1.accepting) != (q in a2.accepting):
            return False, w
        for a in syms:
            nxt = (a1.delta[(p, a)], a2.delta[(q, a)])
            if nxt not in seen:
                seen.add(nxt)
                work.append((nxt, w + str(a)))
    return True, None


# ══════════════════════════════════════════════════════════════════
#  6. Thompson 构造：regex → ε-NFA
# ══════════════════════════════════════════════════════════════════
class _Thompson:
    """语法： r ::= r '|' r | rr | r('*'|'+'|'?') | '(' r ')' | char | '\\' char
       空串用空的分支表示，例如 "(a|)"。"""

    META = set("|*+?()\\")

    def __init__(self, pattern: str):
        self.s, self.i, self.n = pattern, 0, 0
        self.trans: Dict[Tuple[int, Optional[str]], Set[int]] = defaultdict(set)
        self.sigma: Set[str] = set()

    # -- 底层 --
    def _new(self) -> int:
        self.n += 1
        return self.n - 1

    def _add(self, p, a, q):
        self.trans[(p, a)].add(q)

    # -- 词法 --
    def _peek(self):
        return self.s[self.i] if self.i < len(self.s) else None

    def _eat(self, c=None):
        ch = self._peek()
        if c is not None and ch != c:
            raise SyntaxError(f"位置 {self.i}: 期望 {c!r}，得到 {ch!r}")
        self.i += 1
        return ch

    # -- 语法（返回 (start, end) 片段）--
    def _regex(self):
        frag = self._term()
        while self._peek() == "|":
            self._eat("|")
            frag = self._alt(frag, self._term())
        return frag

    def _term(self):
        frag = None
        while self._peek() not in (None, "|", ")"):
            f = self._factor()
            frag = f if frag is None else self._cat(frag, f)
        return frag if frag is not None else self._eps()

    def _factor(self):
        frag = self._atom()
        while self._peek() in ("*", "+", "?"):
            op = self._eat()
            frag = {"*": self._star, "+": self._plus, "?": self._opt}[op](frag)
        return frag

    def _atom(self):
        c = self._peek()
        if c == "(":
            self._eat("(")
            frag = self._regex()
            self._eat(")")
            return frag
        if c == "\\":
            self._eat("\\")
            return self._char(self._eat())
        if c is None or c in self.META:
            raise SyntaxError(f"位置 {self.i}: 意外的 {c!r}")
        return self._char(self._eat())

    # -- 片段构造子 --
    def _char(self, c):
        s, e = self._new(), self._new()
        self._add(s, c, e)
        self.sigma.add(c)
        return (s, e)

    def _eps(self):
        s, e = self._new(), self._new()
        self._add(s, EPSILON, e)
        return (s, e)

    def _cat(self, f, g):
        self._add(f[1], EPSILON, g[0])
        return (f[0], g[1])

    def _alt(self, f, g):
        s, e = self._new(), self._new()
        for x in (f, g):
            self._add(s, EPSILON, x[0]); self._add(x[1], EPSILON, e)
        return (s, e)

    def _star(self, f):
        s, e = self._new(), self._new()
        self._add(s, EPSILON, f[0]); self._add(f[1], EPSILON, f[0])
        self._add(f[1], EPSILON, e); self._add(s, EPSILON, e)
        return (s, e)

    def _plus(self, f):
        s, e = self._new(), self._new()
        self._add(s, EPSILON, f[0]); self._add(f[1], EPSILON, f[0])
        self._add(f[1], EPSILON, e)
        return (s, e)

    def _opt(self, f):
        s, e = self._new(), self._new()
        self._add(s, EPSILON, f[0]); self._add(f[1], EPSILON, e)
        self._add(s, EPSILON, e)
        return (s, e)


def regex_to_nfa(pattern: str) -> NFA:
    t = _Thompson(pattern)
    start, end = t._regex()
    if t.i != len(t.s):
        raise SyntaxError(f"位置 {t.i}: 多余字符 {t.s[t.i:]!r}")
    return NFA(range(t.n), t.sigma, dict(t.trans), start, {end})


# ══════════════════════════════════════════════════════════════════
#  7. 工具：穷举短串做交叉验证
# ══════════════════════════════════════════════════════════════════
def all_words(alphabet: Iterable[Symbol], max_len: int) -> Iterator[str]:
    syms = sorted(alphabet, key=repr)
    frontier = [""]
    yield ""
    for _ in range(max_len):
        frontier = [w + str(a) for w in frontier for a in syms]
        yield from frontier


def cross_check(nfa: NFA, dfa: DFA, max_len: int = 8) -> None:
    for w in all_words(nfa.alphabet, max_len):
        assert nfa.accepts(w) == dfa.accepts(w), \
            f"不一致：{w!r} NFA={nfa.accepts(w)} DFA={dfa.accepts(w)}"


# ══════════════════════════════════════════════════════════════════
#  8. 演示
# ══════════════════════════════════════════════════════════════════
def demo_epsilon_lfp():
    print("═" * 62)
    print("① ε-闭包：为什么必须是最小不动点")
    print("═" * 62)
    #  1 ──ε──> 2 ,  3 ──ε──> 3（自环，与 1 无关）
    nfa = NFA(states={1, 2, 3}, alphabet={"a"},
              transitions={(1, EPSILON): {2}, (3, EPSILON): {3}},
              start=1, accepting={2})
    print("  ε 边：1→2，3→3（自环）")
    print("  lfp = ε-cl({1}) =", _fmt(nfa.epsilon_closure({1})))
    F = lambda X: frozenset({1}) | nfa.move(X, EPSILON)
    top = frozenset({1, 2, 3})
    print("  但 F({1,2,3}) =", _fmt(F(top)), "→ 它也是不动点，即 gfp")
    print("  gfp 里的状态 3 靠自环'自我供养'，没有来自 {1} 的真实 ε 路径。")
    print("  lfp = 只承认有有限证明树的成员资格。✓\n")


def demo_layered():
    print("═" * 62)
    print("② Kleene 迭代：Step^n(∅) 逐层展开   regex = (a|b)*abb")
    print("═" * 62)
    nfa = regex_to_nfa("(a|b)*abb")
    print(" ", nfa)
    for n, R in determinize_layered(nfa):
        tag = "  ← 稳定 = lfp" if n and R == frozenset(
            [s for s in R]) and False else ""
        print(f"  Step^{n}(∅)：{len(R)} 个子集")
    dfa = determinize(nfa)
    print(f"  收敛后 |Dstates| = {len(dfa)}（格高度是 2^{len(nfa.states)}，"
          f"实际只用了 直径+1 步）\n")


def demo_pipeline():
    print("═" * 62)
    print("③ 完整流水线：regex → ε-NFA → DFA → 最小 DFA")
    print("═" * 62)
    for pattern in ["(a|b)*abb", "a(b|c)*", "(0|1)*1(0|1)(0|1)"]:
        nfa = regex_to_nfa(pattern)
        dfa = determinize(nfa)
        mini = minimize(dfa).relabel()
        cross_check(nfa, dfa, max_len=7)
        cross_check(nfa, mini, max_len=7)
        ok, _ = equivalent(dfa, mini)
        assert ok
        print(f"  {pattern:<22} NFA {len(nfa.states):>3} 态 "
              f"→ DFA {len(dfa):>3} 态 → 最小 {len(mini):>3} 态  ✓")
    print()
    print("  详细看一个： (a|b)*abb 的最小 DFA")
    print(minimize(determinize(regex_to_nfa("(a|b)*abb"))).relabel().table())
    print()


def demo_blowup():
    print("═" * 62)
    print("④ 状态爆炸：L_n = {w : 倒数第 n 个符号是 a}")
    print("═" * 62)

    def make(n: int) -> NFA:
        tr = {(0, "a"): {0, 1}, (0, "b"): {0}}
        for i in range(1, n):
            tr[(i, "a")] = {i + 1}
            tr[(i, "b")] = {i + 1}
        return NFA(range(n + 1), {"a", "b"}, tr, 0, {n})

    print("   n | NFA |  DFA  | 最小 DFA |  2^n  | 格高度 2^|Q|")
    print("  ---+-----+-------+----------+-------+--------------")
    for n in range(1, 11):
        nfa = make(n)
        dfa = determinize(nfa, keep_sink=False)
        mini = minimize(dfa)
        print(f"  {n:>2} | {len(nfa.states):>3} | {len(dfa):>5} | "
              f"{len(mini):>8} | {2**n:>5} | {2**len(nfa.states):>12}")
    print("\n  最小 DFA 恰好 2^n ⇒ 指数是 lfp 真实填满了整个 2^[n]，")
    print("  不是算法的缺陷，而是格本身的尺寸。\n")


def demo_trim_vs_minimize():
    print("═" * 62)
    print("⑤ 去不可达 ≠ 最小化（lfp 限制 vs Π 上的 gfp 商）")
    print("═" * 62)
    nfa = regex_to_nfa("(a|b)*abb")
    full = determinize(nfa)                    # 已经只含可达状态
    mini = minimize(full)
    print(f"  子集构造（= lfp，天然只含可达状态）: {len(full)} 态")
    print(f"  Hopcroft（= Π(Q) 上最大同余 gfp）  : {len(mini)} 态")
    print("  两者差的那一个状态，是被合并掉的不可区分状态：")
    for block in sorted(mini.states, key=lambda b: sorted(map(_fmt, b))):
        if len(block) > 1:
            print("    合并 →", " ≡ ".join(sorted(_fmt(s) for s in block)))
    print()


if __name__ == "__main__":
    demo_epsilon_lfp()
    demo_layered()
    demo_pipeline()
    demo_blowup()
    demo_trim_vs_minimize()

    print("═" * 62)
    print("⑥ Graphviz（dot -Tpng -o out.png）")
    print("═" * 62)
    print(minimize(determinize(regex_to_nfa("(a|b)*abb"))).relabel().to_dot())