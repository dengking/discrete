# cp-algorithms [Aho-Corasick algorithm](https://cp-algorithms.com/string/aho_corasick.html)

The Aho-Corasick algorithm allows us to quickly search for multiple patterns in a text. The set of pattern strings is also called a *dictionary*. 

## Construction of the trie[¶](https://cp-algorithms.com/string/aho_corasick.html#construction-of-the-trie)



### Code



```C++
#include <vector>
#include <algorithm>
#include <string>

const int K = 26;

struct Vertex
{
    int next[K];
    bool output = false;

    Vertex()
    {
        std::fill(std::begin(next), std::end(next), -1);
    }
};

std::vector<Vertex> trie(1); // 将trie存储于array中

void add_string(std::string const &s)
{
    int v = 0;
    for (char ch : s)
    {
        int c = ch - 'a';
        if (trie[v].next[c] == -1)
        {
            trie[v].next[c] = trie.size();
            trie.emplace_back(); // 新增一个node
        }
        v = trie[v].next[c];
    }
    trie[v].output = true;
}
```



## Construction of an automaton

Suppose we have built a trie for the given set of strings. Now let's look at it from a different side. If we look at any vertex, the string that corresponds to it is a **prefix** of one or more strings in the set, thus each vertex of the trie can be interpreted as a position in one or more strings from the set.

> NOTE:
>
> 一、翻译如下:
>
> "假设我们已经为给定的字符串集构建了一个trie。现在让我们从另一个角度来看。如果我们观察任意顶点，与它对应的字符串是集合中一个或多个字符串的前缀，因此，树的每个顶点可以被解释为集合中一个或多个字符串中的位置。"

In fact, the trie vertices can be interpreted as states in a **finite deterministic automaton**. From any state we can **transition** - using some input letter - to other states, i.e., to another position in the set of strings. For example, if there is only one string  
$abc$  in the dictionary, and we are standing at vertex $ab$ , then using the letter  $c$  we can go to the vertex  $abc$ .

> NOTE:
>
> 一、trie、finite deterministic automaton 都可以看作是weighted directed graph

Thus we can understand the edges of the trie as transitions in an automaton according to the corresponding letter. However, in an automaton we need to have transitions for each combination of a state and a letter. If we try to perform a transition using a letter, and there is no corresponding edge in the trie, then we nevertheless must go into some state.

More precisely, suppose we are in a state corresponding to a string  $t$ , and we want to transition to a different state using the character  $c$ :

- If there is an edge labeled with this letter  $c$ , then we can simply go over this edge, and get the vertex corresponding to  
  $t + c$ . 

- If there is no such edge, since we want to maintain the **invariant** that the current state is the **longest partial match** in the processed string, we must find the **longest string** in the trie that's a **proper suffix** of the string  $t$ , and try to perform a transition from there.

  > NOTE:
  >
  > 一、
  >
  > 上面这段话中的**longest partial match**、**proper suffix**，其实和 [Knuth–Morris–Pratt algorithm](https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm) 中的含义相同，关于此，可以参加 wikipedia [Knuth–Morris–Pratt algorithm](https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm) 。
  >
  > 从后面的内容可知，此时需要使用suffix link进行transition。

For example, let the trie be constructed by the strings  $ab$  and  $bc$ , and we are currently at the vertex corresponding to  $ab$ , which is a  $\text{output}$ . To transition with the letter  $c$ , we are forced to go to the state corresponding to the string  $b$ , and from there follow the edge with the letter  $c$ .

![](A_diagram_of_the_Aho-Corasick_string_search_algorithm.svg)

*An **Aho-Corasick automaton** based on words "a", "ab", "bc", "bca", "c" and "caa".*

*Blue arrows are **suffix links**, green arrows are **terminal links**.*

A **suffix link** for a vertex  $p$  is an edge that points to the **longest proper suffix** of the string corresponding to the vertex  
$p$​ . The only special case is the root of the trie, whose suffix link will point to itself. Now we can reformulate the statement about the transitions in the automaton like this: while(当) there is no transition from the current vertex of the trie using the current letter (or until we reach the root), we follow the **suffix link**.

> NOTE:
>
> 一、
>
> vertex  $p$ 所对应的substring的suffix可能是其它string的prefix，suffix link就是起到这个作用的。

Thus we reduced the problem of constructing an **automaton** to the problem of finding **suffix links** for all vertices of the trie. However, we will build these **suffix links**, oddly enough, using the transitions constructed in the **automaton**.

The **suffix links** of the **root vertex** and all its immediate children point to the **root vertex**. For any vertex  $v$  deeper in the tree, we can calculate the **suffix link** as follows: 

if  $p$  is the ancestor of  $v$  with  $c$  being the letter labeling the edge from  $p$  to  $v$ , go to  $p$ , then follow its **suffix link**, and perform the transition with the letter  $c$  from there.

Thus, the problem of finding the transitions has been reduced to the problem of finding **suffix links**, and the problem of finding **suffix links** has been reduced to the problem of finding a **suffix link** and a transition, except for vertices closer to the root. So we have a **recursive dependence** that we can resolve in linear time.

