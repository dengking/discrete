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

## cnblogs [AC自动机学习笔记-1（怎么造一台AC自动机?）](https://www.cnblogs.com/sclbgw7/p/9260756.html)
### 前置知识
首先你一定要对Trie树以及KMP了如指掌，尤其是要明白KMP中失配数组(next或fail数组)的本质:利用已经匹配过的部分，跳过重复的匹配，达到快速匹配的目的。
> NOTE: "KMP中失配数组(next或fail数组)" 失配数组，非常好的名称

### AC自动机是什么
大家都知道KMP可以用于在一个大字符串（文本串）中寻找另一个小的字符串（模式串），那么如果有n个模式串，要你把它们全部在文本串中找出来呢？当然，我们可以做n次KMP（别小瞧30分哦），但是其效率并不能差强人意。这个时候，我们可以尝试把模式串做成Trie树，似乎可以提高效率。

比如说，我们有5个模式串：`she,shr,say,he,her`,那么它们所建出来的Trie树应该是长成这样的：（红色节点表示单词的结尾）

![image](https://images2018.cnblogs.com/blog/1313742/201807/1313742-20180703213144078-1801957981.png)

那么，怎么用它来匹配呢？如果我们把文本串的每一个点都作为起点放到Tire树上匹配，它的复杂度将会是...我要你Tire树有何用(╯‵□′)╯︵┻━┻

既然这样，那么如果只把文本串的第一个字符为起点，会发生什么呢？

你以为会是这样的：


![image](https://images2018.cnblogs.com/blog/1313742/201807/1313742-20180703213230940-524045718.png)

完美！

然而实际上却是这样的：

![image](https://images2018.cnblogs.com/blog/1313742/201807/1313742-20180703213257110-1762572679.png)

问题很明显，当我们匹配完`she`时，`he`其实也被匹配到了。所以我们希望这棵Trie树上能够加点东西，让它可以达到下面的效果：

![image](https://images2018.cnblogs.com/blog/1313742/201807/1313742-20180703213310383-388458083.png)


上图中，红色的箭头就是**失配指针**——**fail指针**。它表示文本串在当前节点失配后，我们应该到哪个节点去继续匹配。很显然，对于每个节点，我们要找到这个节点-代表的字符串-在树上所有的节点-表示的字符串中-能找到的最长的后缀，意思就是“我当前匹配到了这个点，我也相当于匹配到了的节点（中的深度最大的节点）。”比如说，在我举的例子中，当我们匹配到了she时，我们在树上走的路径也包含了he，he是she的一个后缀。我们在she上失配，至少说明我们已经匹配到了he，于是就可以跳到代表he的节点上继续匹配。


到这里，你是不是发现fail指针和KMP中的next指针简直一毛一样？它们都被称为“失配指针”。将Trie树上的每一个点都加上fail指针，它就变成了AC自动机。AC自动机其实就是Trie+KMP，它可以用来解决在文本串中寻找很多模式串，即多模匹配问题。


对于一开始的5个单词，它们所构建出的AC自动机就长这样（没有画出红色箭头的点，其fail指针都指向根节点）：


![image](https://images2018.cnblogs.com/blog/1313742/201807/1313742-20180703213322731-1606805669.png)

### 如何构建AC自动机
显然，我们要做的就是快速地求出所有点的fail指针。我们以bfs的顺序依次求出每个节点的fail，这样，当我们要求一个节点的fail时，它的父亲的fail肯定已经求出来了。若当前节点为A，其父节点为B，B的fail为C，那么C所代表的字符串一定是B的最长的后缀。如果C有一个儿子D的字符与A的字符等同，那么显然D所代表的串（C加一个字符）就是A所代表的串（B加一个字符）的最长后缀。如果C没有一个儿子，使其字符与A的字符等同呢？很简单，只需要再访问C的fail就行了。如此反复，直到A的最长后缀找到，或者A的fail指向根节点为止。（A在Trie树中没有后缀，乖乖回到根重新匹配吧！）

为了解释得更清楚，我举一个例子。下面这幅图是我根据别的地方的图重新画的（n次转载？），出处我没找到_(:з」∠)_。节点是根据bfs序标号的。


![image](https://images2018.cnblogs.com/blog/1313742/201807/1313742-20180703213332706-1589913513.png)

步骤：

1、为了少一些特判，设置一个辅助根节点0号节点，0号节点的所有儿子都指向真正的根节点1号节点，然后将1号节点的fail指向0号节点。

2、找到2号节点的父亲节点的fail节点0号节点，看0号节点有没有为a的子节点。有，于是2号节点的fail指向1号节点。

3、找到3号节点的父亲节点的fail节点0号节点，看0号节点有没有为b的子节点。有，于是3号节点的fail指向1号节点。

4、找到4号节点的父亲节点的fail节点1号节点，看1号节点有没有为b的子节点。有，于是4号节点的fail指向3号节点。

5、同上。

6、同上。

7、同上。

8、找到8号节点的父亲节点的fail节点5号节点，看5号节点有没有为b的子节点。没有，于是再找到5号节点的fail节点2号节点，看2号节点有没有为b的子节点。有，于是8号节点的fail指向4号节点。

这样，一个AC自动机就做好了。

注意到由于辅助节点的存在，我们不需要做任何特判，在树上没有后缀的节点的fail指针会自动连向根节点。

构建fail指针的代码：

```
void build()
{
	for(int i=0;i<26;++i)ch[0][i]=1;
    fail[1]=0;
    queue<int>q;
    q.push(1);
    while(!q.empty())
    {
    	int x=q.front();q.pop();
        for(int i=0;i<26;++i)
        {
        	int c=ch[x][i];
            if(!c)continue;
            int fa=fail[x];
            while(fa&&!ch[fa][i])fa=fail[fa];
            fail[c]=ch[fa][i];
            q.push(c);
        }
    }
}

```
### 如何利用AC自动机来查找
这个问题似乎显而易见，只要根据文本串的内容沿着Trie树的边往下走就行了，一失配就沿着fail边向上跳。

fail边不只是失配指针这么简单，如果你像我刚才说的那么做的话，你就可能会面临下面这样的问题：

![image](https://images2018.cnblogs.com/blog/1313742/201807/1313742-20180703213357245-1362436414.png)

为了不让这种事情发生，我们每遇到一个fail指针就必须向上跳到顶，以保证不会漏过任何一个子串，就像这样：
> NOTE: "向上跳到顶"是什么意思？
> ![image](https://images2018.cnblogs.com/blog/1313742/201807/1313742-20180703213408820-186250902.png)

当然，这样未免也太蠢了，于是这里又有一个小优化：如果一个节点的fail指向一个**结尾节点**，那么这个点也成为一个**（伪）结尾节点**。在匹配时，如果遇到**结尾节点**，就进行相应的计数处理。

进行匹配的代码：
```
void print(int x)
{
	while(x)
    {
    	if(end[x])
        {
			//计数、打印等等，视题目要求而定
        }
        x=fail[x];
    }
}

void match(char *s)
{
	int len=strlen(s),now=1;
    for(int i=0;i<len;++i)
    {
    	int id=s[i]-'a';
        while(now&&!ch[now][id])now=fail[now];
        now=ch[now][id];
        if(end[now]||en[now])print(now);
        //en[now]即为伪结尾标记
    }
}

//记得在build中加上这句话
void build()
{
	...
    if(end[fail[c]]||en[fail[c]])en[c]=1;
    ...
}

```

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

