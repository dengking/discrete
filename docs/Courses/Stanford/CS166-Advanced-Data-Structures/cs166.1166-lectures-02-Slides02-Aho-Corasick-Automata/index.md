# [stanford-cs166.1166-Aho-Corasick Automata](https://web.stanford.edu/class/archive/cs/cs166/cs166.1166/lectures/02/Slides02.pdf)

> 这是我在阅读 [cp-algorithms-Aho-Corasick algorithm](https://cp-algorithms.com/string/aho_corasick.html) 的时候发现的。

其中关于string search的定义非常好。

## Use case

### use case 1

**Pattern Strings**

```
ab
about
at
ate
be
bed
edge
get
```



**Text**

```
abedgetab
```

### use case 2

**Pattern Strings**

```
a
aa
aaa
aaaa

```

**Text**

```
aaaaaaaa
```



### use case 3

```
at
art
oars
soar
```

这是非常好的一个例子

```
soat
oart
```



## 行文思路

从最简单的naive approach介绍如何实现string search，然后介绍Aho-Corasick Automata是如何做的。



## Naïve approach(Page-9)

> Let's start with a naïve approach.

```pseudocode
For each position in T:
     For each pattern string Pᵢ:
          Check if Pᵢ appears at that position
```

### Analyzing 

let *m* be the length of the text and *n* the total length of the pattern strings.

For each character of the text string *T*, in the worst case, we scan over all *n* total characters in the patterns.

Time complexity: $\mathcal{O}(mn)$.



## Parallel Searching(Page-60)

**Idea:** Rather than searching the pattern strings in *serial*, try searching them in *parallel*.

Intuitively, this should cut down on a lot of the unnecessary rescanning that we're doing.

> NOTE:
>
> 一、如何理解标题的 "parallel" 的含义？下面是chatGPT对 Aho-Corasick Automata 的解释中的一段，其中的"simultaneous matching of multiple patterns against an input text"就是 "parallel"
>
> > It allows for simultaneous matching of multiple patterns against an input text in linear time relative to the length of the input plus the number of matched entries.

### Trie

这一节以trie为例，非常好的展示了finite-state-based-automata-string-search-algorithm的思路: 将text输入到Aho-Corasick Automata，text的每个character都将导致transition。



### Analyzing our New Algorithm(Page-77)

Let's suppose we've already constructed the **trie**. How much work is required to perform the match? 

For each character of *T*, we inspect as most as many characters as exist in the deepest branch of the trie.

Time complexity: $\mathcal{O}(mL_{max})$ , where $L_{max}$ is the length of the longest pattern string. *(Do you see why?)*

> NOTE:
>
> 一、[trie](https://en.wikipedia.org/wiki/Trie) 又称为 prefix tree，显然前缀相同的patterns会位于同一个树枝上，这样的结构是有益于multiple string search的，因为对于前缀相同的多个patterns，长的pattern可以在短的pattern的基础上继续匹配，无需从头开始，显然这能够提高品牌效率，这就是上面所说的"parallel"。 

In the (reasonable) case where $L_{max}$ is much smaller than *n*, this is a huge win over before. If $L_{max}$ is “objectively” small, this is a pretty good runtime.



### Building a Trie(Page-78)

**Claim:** Given a set of strings *P*1, ..., *Pₖ* of total length *n*, it's possible to build a trie for those strings in time $\mathcal{O}(n)$.



## Our Strategies(Page-102)

Following our foray into [RMQ](https://en.wikipedia.org/wiki/Range_minimum_query), we'll say that a solution to multi-string matching runs in time $\langle p(m, n), q(m, n)\rangle$ if the preprocessing time is $p(m, n)$ and the matching time is $q(m, n)$.

> NOTE:
>
> 一、RMQ是 [Range minimum query](https://en.wikipedia.org/wiki/Range_minimum_query) 

We now have two approaches:

- No preprocessing: $\langle \mathcal{O}(1), \mathcal{O}(mn)\rangle$.
- Trie searching: $\langle \mathcal{O}(n), \mathcal{O}(mL_{max})\rangle$.

**Can we do better?**

