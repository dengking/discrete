# Aho-Corasick-algorithm

## 素材

### zhihu [Aho-Corasick算法纵览（AC自动机）](https://zhuanlan.zhihu.com/p/368184958)

![img](https://pic4.zhimg.com/80/v2-94518a2b306d9b8f1d10e4b49911e567_1440w.jpg)

#### 什么是字典树（Trie）？



![img](https://pic1.zhimg.com/80/v2-a9081d3eff0ca0f0b06c8736a246eaa4_1440w.jpg)

而字典树又分为压缩字典树、非压缩字典树等，我们的AC自动机算法就是一棵典型的非压缩字典树。

AC自动机是一种典型的前缀搜索算法：

![img](https://pic3.zhimg.com/80/v2-6fc59897b84332efb8f05997ca41cb5e_1440w.jpg)

#### 那么什么是AC自动机呢？

AC自动机应当属于基于**前缀搜索**的**非压缩字典树**。

![img](https://pic2.zhimg.com/80/v2-4662e74f81c5c39547e6f4b689efca0d_1440w.jpg)

#### AC自动机的原理如下：



## wikipedia [Aho–Corasick algorithm](https://en.wikipedia.org/wiki/Aho%E2%80%93Corasick_algorithm)





## cp-algorithms [Aho-Corasick algorithm](https://cp-algorithms.com/string/aho_corasick.html)

Let there be a set of strings with the total length mm (sum of all lengths). The Aho-Corasick algorithm constructs a data structure similar to a trie with some additional links, and then constructs a **finite state machine** (automaton) in $O(mk)$ time, where $k$ is the size of the used alphabet.

The algorithm was proposed by Alfred Aho and Margaret Corasick in 1975.

### Construction of the trie

Formally a trie is a rooted tree, where each edge of the tree is labeled by some letter. All outgoing edge from one vertex mush have different labels.

Consider any path in the trie from the root to any vertex. If we write out the labels of all edges on the path, we get a string that corresponds to this path. For any vertex in the trie we will associate the string from the root to the vertex.

Each vertex will also have a flag `leaf` which will be true, if any string from the given set corresponds to this vertex.

Accordingly to build a trie for a set of strings means to build a trie such that each `leaf` vertex will correspond to one string from the set, and conversely that each string of the set corresponds to one `leaf` vertex.

We now describe how to construct a trie for a given set of strings in linear time with respect to their total length.

We introduce a structure for the vertices of the tree.

```c++
const int K = 26;

struct Vertex {
    int next[K];
    bool leaf = false;

    Vertex() {
        fill(begin(next), end(next), -1);
    }
};

vector<Vertex> trie(1);
```

Here we store the trie as an array of `Vertex`. Each `Vertex` contains the flag `leaf`, and the edges in the form of ans array `next[]`, where `next[i]` is the index to the vertex that we reach by following the character `i`, or −1, if there is no such edge. Initially the trie consists of only one vertex - the root - with the index 0.

Now we implement a function that will add a string `s` to the trie. The implementation is extremely simple: we start at the root node, and as long as there are edges corresponding to the characters of `s` we follow them. If there is no edge for one character, we simply generate a new vertex and connect it via an edge. At the end of the process we mark the last vertex with flag `leaf`.

```c++
void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (trie[v].next[c] == -1) {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[c];
    }
    trie[v].leaf = true;
}
```

The implementation obviously runs in linear time. And since every vertex store `k` links, it will use `O(mk)` memory.

It is possible to decrease the memory consumption to O(m) by using a map instead of an array in each vertex. However this will increase the complexity to `O(nlogk)`.

### Construction of an automaton

Suppose we have built a trie for the given set of strings. Now let's look at it from a different side. If we look at any vertex. The string that corresponds to it is a prefix of one or more strings in the set, thus each vertex of the trie can be interpreted as a position in one or more strings from the set.

In fact the trie vertices can be interpreted as **states** in a **finite deterministic automaton**. From any state we can transition - using some input letter - to other states, i.e. to another position in the set of strings. For example, if there is only one string in the trie `abc`, and we are standing at vertex `2` (which corresponds to the string `ab`), then using the letter `c` we can transition to the state `3`.

Thus we can understand the edges of the trie as **transitions** in an automaton according to the corresponding letter. However for an automaton we cannot restrict the possible transitions for each state. If we try to perform a transition using a letter, and there is no corresponding edge in the trie, then we nevertheless must go into some state.

Thus we can understand the edges of the trie as transitions in an automaton according to the corresponding letter. However for an automaton we cannot restrict the possible transitions for each state. If we try to perform a transition using a letter, and there is no corresponding edge in the trie, then we nevertheless must go into some state.

## geeksforgeeks [Aho-Corasick Algorithm for Pattern Searching](https://www.geeksforgeeks.org/aho-corasick-algorithm-pattern-searching/)

Given an input text and an array of `k` words, `arr[]`, find all occurrences of all words in the input text. Let **n** be the length of text and **m** be the total number characters in all words, i.e. `m = length(arr[0]) + length(arr[1]) + … + length(arr[k-1])`. Here **k** is total numbers of input words.

Example:

```
Input: text = "ahishers"    
       arr[] = {"he", "she", "hers", "his"}

Output:
   Word his appears from 1 to 3
   Word he appears from 4 to 5
   Word she appears from 3 to 5
   Word hers appears from 4 to 7
```

If we use a linear time searching algorithm like **KMP**, then we need to one by one search all words in text[]. This gives us total time complexity as `O(n + length(word[0]) + O(n + length(word[1]) + O(n + length(word[2]) + … O(n + length(word[k-1])`. This time complexity can be written as ***O(n\*k + m)***.

**Aho-Corasick Algorithm** finds all words in ***O(n + m + z)*** time where **z** is total number of occurrences of words in text. The Aho–Corasick string matching algorithm formed the basis of the original Unix command fgrep.



### **Prepocessing :** 

Build an automaton of all words in `arr[]` The **automaton** has mainly three functions:

#### 1. Go To

This function simply follows edges of Trie of all words in `arr[]`. It is represented as 2D array `g[][]` where we store next state for current state and character.

#### 2. Failure 

This function stores all edges that are followed when current character doesn't have edge in Trie.  It is represented as 1D `array f[]` where we store next state for current state.

#### 3. Output

Stores indexes of all words that end at current state. It is represented as 1D array `o[]` where we store indexes of all matching words as a bitmap for current state.

### Matching 

Traverse the given text over built automaton to find all matching words.



### Preprocessing:

1. We first Build a [Trie](https://www.geeksforgeeks.org/trie-insert-and-search/) (or Keyword Tree) of all words.

![aho-corasick](https://media.geeksforgeeks.org/wp-content/uploads/aho-corasick2-1.png)

> NOTE: The figure above has a mistake that edge `i` should start from node after `h`.

This part fills entries in goto `g[][]` and output `o[]`.

2. Next we extend Trie into an automaton to support linear time matching.

![aho-corasick2](https://media.geeksforgeeks.org/wp-content/uploads/aho-corasick1.png)

This part fills entries in failure `f[]` and output `o[]`.

**Go to :**

We build [Trie](https://www.geeksforgeeks.org/trie-insert-and-search/). And for all characters which don’t have an edge at root, we add an edge back to root.

**Failure :**

For a state `s`, we find the longest proper suffix which is a proper prefix of some pattern. This is done using Breadth First Traversal of Trie.

**Output :**

For a state `s`, indexes of all words ending at `s` are stored. These indexes are stored as bitwise map (by doing bitwise OR of values). This is also computing using Breadth First Traversal with Failure.

Below is C++ implementation of Aho-Corasick Algorithm

## Implementation

https://github.com/WojciechMula/pyahocorasick

