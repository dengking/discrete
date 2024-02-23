# [stanford-cs166.1166-Aho-Corasick Automata](https://web.stanford.edu/class/archive/cs/cs166/cs166.1166/lectures/02/Slides02.pdf)

> 这是我在阅读 [cp-algorithms-Aho-Corasick algorithm](https://cp-algorithms.com/string/aho_corasick.html) 的时候发现的。

其中关于string search的定义非常好。

## Use case

use case 1:

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

use case 2:

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





从最简单的naive approach介绍如何实现string search，然后介绍Aho-Corasick Automata是如何做的。



## Naïve approach

> Let's start with a naïve approach.

```
For each position in T:
     For each pattern string Pᵢ:
          Check if Pᵢ appears at that position
```

### Analyzing 

let *m* be the length of the text and *n* the total length of the pattern strings.

For each character of the text string *T*, in the worst case, we scan over all *n* total characters in the patterns.

Time complexity: $\mathcal{O}(mn)$.



## Parallel Searching

**Idea:** Rather than searching the pattern strings in *serial*, try searching them in *parallel*.

Intuitively, this should cut down on a lot of the unnecessary rescanning that we're doing.



## Trie



这一节非常好的展示了从trie的角度来分析naïve approach，它详细地展示了transition。

将text输入到Aho-Corasick Automata，text的每个character都将导致transition。





## 算法思想

$pattern_i$ 的后缀(suffix)和 $pattern_j$ 的prefix重合，则可构建fail link。

充分利用已经匹配的信息。
