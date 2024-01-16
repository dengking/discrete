# String-searching algorithm

---

> References:
>
> - wikipedia [String-searching algorithm](https://en.wikipedia.org/wiki/String-searching_algorithm) 

---



String search algorithm所要解决的问题是在字符串 `text` 中搜索 `patten` (substring)，对于这类问题，可以double pointer( `first=i` 指向`text`; ` second=j` 指向 `pattern` ) 来进行描述。最为对照，下面是naive string search algorithm:

```python
class StringSearchAlgorithms:
    """字符串搜索算法"""

    @classmethod
    def naive_search_algorithm(cls, text: str, pattern: str) -> int:
        """
        在text中搜索pattern
        :param text:
        :param pattern:
        :return:
        """
        i, j = 0, 0
        while i < len(text) and j < len(pattern):
            if text[i] == pattern[j]:
                i += 1
                j += 1
            else:
                # mismatch，则从头再来
                i += 1
                j = 0
        if j == len(pattern):
            return i - j
        else:
            return -1

```



## wikipedia [String-searching algorithm](https://en.wikipedia.org/wiki/String-searching_algorithm) 

In [computer science](https://en.wikipedia.org/wiki/Computer_science), **string-searching algorithms**, sometimes called **string-matching algorithms**, are an important class of [string algorithms](https://en.wikipedia.org/wiki/String_algorithms) that try to find a place where one or several [strings](https://en.wikipedia.org/wiki/String_(computer_science)) (also called patterns) are found within a larger string or text.

### Basic classification of search algorithms

The various [algorithms](https://en.wikipedia.org/wiki/Algorithm) can be classified by the number of patterns each uses.

> NOTE: 这种分类方式是根据pattern的个数作为标准

#### Single-pattern algorithms

Let *m* be the length of the pattern, *n* be the length of the searchable text and *k* = |Σ| be the size of the alphabet.

|                          Algorithm                           | Preprocessing time | Matching time[[1\]](https://en.wikipedia.org/wiki/String-searching_algorithm#endnote_Asymptotic_times) | Space |
| :----------------------------------------------------------: | :----------------: | :----------------------------------------------------------: | :---: |
|                Naïve string-search algorithm                 |        none        |                            Θ(nm)                             | none  |
| [Rabin–Karp algorithm](https://en.wikipedia.org/wiki/Rabin–Karp_algorithm) |        Θ(m)        |              average Θ(n + m), worst Θ((n−m)m)               | O(1)  |
| [Knuth–Morris–Pratt algorithm](https://en.wikipedia.org/wiki/Knuth–Morris–Pratt_algorithm) |        Θ(m)        |                             Θ(n)                             | Θ(m)  |
| [Boyer–Moore string-search algorithm](https://en.wikipedia.org/wiki/Boyer–Moore_string-search_algorithm) |      Θ(m + k)      |                   best Ω(n/m), worst O(mn)                   | Θ(k)  |
| [Bitap algorithm](https://en.wikipedia.org/wiki/Bitap_algorithm) (*shift-or*, *shift-and*, *Baeza–Yates–Gonnet*; fuzzy; agrep) |      Θ(m + k)      |                            O(mn)                             |       |
| [Two-way string-matching algorithm](https://en.wikipedia.org/wiki/Two-way_string-matching_algorithm) (glibc memmem/strstr)[[3\]](https://en.wikipedia.org/wiki/String-searching_algorithm#cite_note-3) |        Θ(m)        |                            O(n+m)                            | O(1)  |
| BNDM (Backward Non-Deterministic DAWG Matching) (fuzzy + regex; nrgrep)[[4\]](https://en.wikipedia.org/wiki/String-searching_algorithm#cite_note-4) |        O(m)        |                             O(n)                             |       |
| BOM (Backward Oracle Matching)[[5\]](https://en.wikipedia.org/wiki/String-searching_algorithm#cite_note-5) |        O(m)        |                            O(mn)                             |       |

1.**[^](https://en.wikipedia.org/wiki/String-searching_algorithm#ref_Asymptotic_times)** Asymptotic times are expressed using [O, Ω, and Θ notation](https://en.wikipedia.org/wiki/Big_O_notation).

The **[Boyer–Moore string-search algorithm](https://en.wikipedia.org/wiki/Boyer–Moore_string-search_algorithm)** has been the standard benchmark for the practical string-search literature.[[6\]](https://en.wikipedia.org/wiki/String-searching_algorithm#cite_note-:0-6)

#### Algorithms using a finite set of patterns

1、[Aho–Corasick string matching algorithm](https://en.wikipedia.org/wiki/Aho–Corasick_string_matching_algorithm) (extension of Knuth-Morris-Pratt)

2、[Commentz-Walter algorithm](https://en.wikipedia.org/wiki/Commentz-Walter_algorithm) (extension of Boyer-Moore)

3、Set-BOM (extension of Backward Oracle Matching)

4、[Rabin–Karp string search algorithm](https://en.wikipedia.org/wiki/Rabin–Karp_string_search_algorithm)

#### Algorithms using an infinite number of patterns

Naturally, the patterns can not be enumerated finitely in this case. They are represented usually by a [regular grammar](https://en.wikipedia.org/wiki/Regular_grammar) or [regular expression](https://en.wikipedia.org/wiki/Regular_expression).



### Other classification

Other classification approaches are possible. One of the most common uses preprocessing as main criteria.

**Classes of string searching algorithms**[[7\]](https://en.wikipedia.org/wiki/String-searching_algorithm#cite_note-7)

|                               |   Text not preprocessed    |                      Text preprocessed                       |
| :---------------------------: | :------------------------: | :----------------------------------------------------------: |
| **Patterns not preprocessed** |   Elementary algorithms    |                        Index methods                         |
|   **Patterns preprocessed**   | Constructed search engines | Signature methods :[[8\]](https://en.wikipedia.org/wiki/String-searching_algorithm#cite_note-8) |

Another one classifies the algorithms by their matching strategy:[[9\]](https://en.wikipedia.org/wiki/String-searching_algorithm#cite_note-9)

- Match the prefix first (Knuth-Morris-Pratt, Shift-And, Aho-Corasick)
- Match the suffix first (Boyer-Moore and variants, Commentz-Walter)
- Match the best factor first (BNDM, BOM, Set-BOM)
- Other strategy (Naive, Rabin-Karp)



### Naïve string search

A simple and inefficient way to see where one string occurs inside another is to check each place it could be, one by one, to see if it's there. So first we see if there's a copy of the needle in the first character of the haystack; if not, we look to see if there's a copy of the needle starting at the second character of the haystack; if not, we look starting at the third character, and so forth. In the normal case, we only have to look at one or two characters for each wrong position to see that it is a wrong position, so in the average case, this takes [O](https://en.wikipedia.org/wiki/Big_O_notation)(*n* + *m*) steps, where *n* is the length of the haystack and *m* is the length of the needle; but in the worst case, searching for a string like "aaaab" in a string like "aaaaaaaaab", it takes [O](https://en.wikipedia.org/wiki/Big_O_notation)(*nm*)



### Finite-state-automaton-based search

In this approach, we avoid backtracking by constructing a [deterministic finite automaton](https://en.wikipedia.org/wiki/Deterministic_finite_automaton) (DFA) that recognizes stored search string. These are expensive to construct—they are usually created using the [powerset construction](https://en.wikipedia.org/wiki/Powerset_construction)—but are very quick to use. For example, the [DFA](https://en.wikipedia.org/wiki/Deterministic_finite_automaton) shown to the right recognizes the word "MOMMY". This approach is frequently generalized in practice to search for arbitrary [regular expressions](https://en.wikipedia.org/wiki/Regular_expression).



### Stubs

[Knuth–Morris–Pratt](https://en.wikipedia.org/wiki/Knuth–Morris–Pratt_algorithm) computes a [DFA](https://en.wikipedia.org/wiki/Deterministic_finite_automaton) that recognizes inputs with the string to search for as a suffix, [Boyer–Moore](https://en.wikipedia.org/wiki/Boyer–Moore_string_search_algorithm) starts searching from the end of the needle, so it can usually jump ahead a whole needle-length at each step. Baeza–Yates keeps track of whether the previous *j* characters were a prefix of the search string, and is therefore adaptable to [fuzzy string searching](https://en.wikipedia.org/wiki/Fuzzy_string_searching). The [bitap algorithm](https://en.wikipedia.org/wiki/Bitap_algorithm) is an application of Baeza–Yates' approach.



### Index methods

Faster search algorithms preprocess the text. After building a [substring index](https://en.wikipedia.org/wiki/Substring_index), for example a [suffix tree](https://en.wikipedia.org/wiki/Suffix_tree) or [suffix array](https://en.wikipedia.org/wiki/Suffix_array), the occurrences of a pattern can be found quickly. As an example, a suffix tree can be built in $ \Theta (n) $ time, and all $ z $ occurrences of a pattern can be found in $ O(m) $ time under the assumption that the alphabet has a constant size and all inner nodes in the suffix tree know what leaves are underneath them. The latter can be accomplished by running a [DFS algorithm](https://en.wikipedia.org/wiki/Depth-first_search) from the root of the suffix tree.

> NOTE: https://github.com/fxsjy/jieba



### Other variants

Some search methods, for instance [trigram search](https://en.wikipedia.org/wiki/Trigram_search), are intended to find a "closeness" score between the search string and the text rather than a "match/non-match". These are sometimes called ["fuzzy" searches](https://en.wikipedia.org/wiki/Approximate_string_matching).



## Preprocess Pattern or Preoprocess Text?

本节标题源自geeksforgeeks [Pattern Searching using Suffix Tree](https://www.geeksforgeeks.org/pattern-searching-using-suffix-tree/) 

> We have discussed the following algorithms in the previous posts:
>
> [KMP Algorithm](https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/)
> [Rabin Karp Algorithm](https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/)
> [Finite Automata based Algorithm](https://www.geeksforgeeks.org/finite-automata-algorithm-for-pattern-searching/)
> [Boyer Moore Algorithm](https://www.geeksforgeeks.org/pattern-searching-set-7-boyer-moore-algorithm-bad-character-heuristic/)
>
> All of the above algorithms preprocess the **pattern** to make the pattern searching faster. The best time complexity that we could get by preprocessing pattern is `O(n)` where `n` is length of the text. In this post, we will discuss an approach that preprocesses the **text**. A **suffix tree** is built of the text. After preprocessing text (building suffix tree of text), we can search any pattern in `O(m)` time where `m` is length of the pattern.



## Sliding window and string search

1、[Rabin–Karp algorithm](https://en.wikipedia.org/wiki/Rabin%E2%80%93Karp_algorithm) 的  [rolling hash](https://en.wikipedia.org/wiki/Rolling_hash) 可以看做是一种sliding window algorithm

2、stackoverflow [Are KMP and Rabin-Karp Sliding window algorithms for pattern match?](https://stackoverflow.com/questions/72157919/are-kmp-and-rabin-karp-sliding-window-algorithms-for-pattern-match)

3、naive string search其实可以看做是将pattern沿着txt进行slide从而寻找匹配的字符串，关于这一点，参见:

[LeetCode-Pattern Recognition: Knuth Morris Pratt Algorithm & (Time Complexity Comparison with sliding window)](https://leetcode.com/problems/implement-strstr/discuss/1020967/pattern-recognition-knuth-morris-pratt-algorithm-time-complexity-comparison-with-sliding-window)





## LeetCode

汇总整理素材:

1、[LeetCode-『 字符串哈希、KMP 』掌握模板，快乐其实很简单 🤣](https://leetcode.cn/problems/longest-happy-prefix/solution/by-flix-k4p3/) 



| 题目                                                         |                                                              |      |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ---- |
| [LeetCode-28. 实现 strStr()-简单](https://leetcode.cn/problems/implement-strstr/) | [Rabin-Karp with comments](https://leetcode.com/problems/implement-strstr/discuss/279941/rabin-karp-with-comments) |      |
| [LeetCode-214. 最短回文串-困难](https://leetcode.cn/problems/shortest-palindrome/) | [Clean KMP solution with super detailed explanation](https://leetcode.com/problems/shortest-palindrome/discuss/60113/clean-kmp-solution-with-super-detailed-explanation) |      |
| [LeetCode-686. Repeated String Match-中等](https://leetcode.com/problems/repeated-string-match/) |                                                              |      |
| [LeetCode-1392. 最长快乐前缀-困难](https://leetcode.cn/problems/longest-happy-prefix/) | https://leetcode.com/problems/longest-happy-prefix/discuss/549465/kmp-algorithm |      |
| [LeetCode-1910. 删除一个字符串中所有出现的给定子字符串](https://leetcode.cn/problems/remove-all-occurrences-of-a-substring/) | https://leetcode.com/problems/remove-all-occurrences-of-a-substring/discuss/1299275/True-O(n-%2B-m)-KMP/989600/ |      |
|                                                              |                                                              |      |

## KMP vs Rabin-Karp

stackoverflow [When to use Rabin-Karp or KMP algorithms?](https://stackoverflow.com/questions/23336807/when-to-use-rabin-karp-or-kmp-algorithms)

quora [**Which is better and efficient between the KMP algorithm and the Rabin-Karp algorithm?**](https://www.quora.com/Which-is-better-and-efficient-between-the-KMP-algorithm-and-the-Rabin-Karp-algorithm)



> The most important difference between them is how reliable they are in finding a match. KMP guarantees 100% reliability. You cannot guarantee 100% with Rabin Karp because of a chance of collision during hash table lookup. But with good hash generation algorithms that do exist today, it is possible that Rabin Karp can yield very close to 100% reliability in finding a match. And both have complexity of O(n). Also Rabin Karp is easier to implement than KMP it works based on a rolling hash whereas KMP works based on a failure function.