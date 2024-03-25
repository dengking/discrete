# [CS166 String](https://web.stanford.edu/class/cs166/)

Tries and Suffix Trees、Suffix and LCP Arrays、[stanford-cs166.1166-Aho-Corasick Automata](https://web.stanford.edu/class/archive/cs/cs166/cs166.1166/lectures/02/Slides02.pdf) 都是基于trie的，由此可见trie的强大之处，那trie的什么特性使得它能够适用于string呢？[CS166 String](https://web.stanford.edu/class/cs166/) # [Tries and Suffix Trees](https://web.stanford.edu/class/cs166/lectures/04/Slides04.pdf) 中的下面一段话能够带来一些启发:

> ... [**tries**](https://en.wikipedia.org/wiki/Trie) and **suffix trees**, two powerful data structures for exposing **shared structures** in strings.



## Tries and Suffix Trees

April 18

To kick off our discussion of string data structures, we'll be exploring tries, Patricia tries, and, most importantly, suffix trees. These data structures provide fast solutions to a number of algorithmic problems and are much more versatile than they might initially seem. What makes them so useful? What properties of strings do they capture? And what intuitions can we build from them?

Slides:

- [Lecture Slides](https://web.stanford.edu/class/cs166/lectures/04/Slides04.pdf)
- [Condensed Slides](https://web.stanford.edu/class/cs166/lectures/04/Small04.pdf)

Assignments:

- [Problem Set 2](https://web.stanford.edu/class/cs166/handouts/070 Problem Set 2.pdf) | [LaTeX Template](https://web.stanford.edu/class/cs166/assignments/ps2_template.tex)
- [Pugh, William. *Skip Lists: A Probabilistic Alternative to Balanced Trees*](https://web.stanford.edu/class/cs166/restricted/papers/PughSkipLists.pdf)





## Suffix and LCP Arrays

April 20

What makes **suffix trees** so useful as a data structure? Surprisingly, much of their utility and flexibility can be attributed purely to two facts: 

1. they keep the suffixes sorted, and 
2. they expose the **branching words** in the string. 

By representing this information in a different way, we can get much of the benefit of suffix trees without the huge space cost.

Slides:

- [Lecture Slides](https://web.stanford.edu/class/cs166/lectures/05/Slides05.pdf)
- [Condensed Slides](https://web.stanford.edu/class/cs166/lectures/05/Small05.pdf)

Readings:

- Manber, Udi and Myers, Gene *[Suffix Arrays: A New Method for On-Line String Searches](https://web.stanford.edu/class/cs166/restricted/papers/ManberMyersSuffixArrays.pdf)*
- Kasai, Toru et al. *[Linear-Time Longest-Common-Prefix Computation in Suffix Arrays and Its Applications](https://web.stanford.edu/class/cs166/restricted/papers/KasaiEtAlLCP.pdf)*



## [stanford-cs166.1166-Aho-Corasick Automata](https://web.stanford.edu/class/archive/cs/cs166/cs166.1166/lectures/02/Slides02.pdf) 