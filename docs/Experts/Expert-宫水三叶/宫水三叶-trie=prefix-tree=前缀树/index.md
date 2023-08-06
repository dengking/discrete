# 宫水三叶 Trie (前缀树)

https://mp.weixin.qq.com/mp/appmsgalbum?__biz=MzU4NDE3MTEyMA==&action=getalbum&album_id=2049538161285955584&scene=173&from_msgid=2247488490&from_itemidx=1&count=3&nolastread=1#wechat_redirect



## 宫水三叶[【设计数据结构】实现 Trie (前缀树)](https://mp.weixin.qq.com/s/DBTQyNYsEgmN0Vb5fbolUg)



[208. Implement Trie (Prefix Tree)](https://leetcode.cn/problems/implement-trie-prefix-tree/)



Trie 树（又叫「前缀树」或「字典树」）是一种用于快速查询「某个字符串/字符前缀」是否存在的数据结构。

其核心是使用「**边**」来代表有无**字符**，使用「**点**」来记录是否为「**单词结尾**」以及「其后续字符串的字符是什么」。

![图片](https://mmbiz.qpic.cn/mmbiz_png/7oynMNMKBahQMfsIVO5UFDjswwo34pmRB2CzOMc7IU4W3fadBzHiaoEic2ciapBUweTATibcylwibibHJiamy3CiaJXTIA/640?wx_fmt=png&wxfrom=5&wx_lazy=1&wx_co=1)



### 二维数组

> NOTE:
>
> 一、下面对二维数组实现方式的介绍中使用了"格子"这个术语，它对应的是 二维数组 `trie[]` 中的一行，对应的是一个 `TrieNode` 。
>
> 其实这种实现方式是比较高级的，它相当于预先构建了多个 `TrieNode`，和一般通过数组来存储tree的方式一样，它通过数组下标来作为 `TrieNode` 的ID，显然存储一个节点的children node可以通过存储children node的下标来实现。
>
> 这种实现方式还需要解决的一个问题是: 如何存储  `TrieNode.end` 属性，它的解决方法是使用: `int[] count` 

一个朴素的想法是直接使用「二维数组」来实现 `Trie` 树。

1、使用二维数组 `trie[]` 来存储我们所有的单词字符。

2、使用 `index` 来自增记录我们到底用了多少个格子（相当于给被用到格子进行编号）。

3、使用 `count[]` 数组记录某个格子被「被标记为结尾的次数」（当 编号的格子被标记了 `n` 次，则有 `count[index] = n` ）。



```java
package com.company;

class Trie {
    int N = 100009; // TrieNode的个数，直接设置为十万级
    int[][] trie;
    int[] count;
    int index; // row index

    public Trie() {
        trie = new int[N][26];
        count = new int[N];
        index = 0;
    }

    public void insert(String s) {
        int p = 0; // root node在第0行
        for (int i = 0; i < s.length(); i++) {
            int u = s.charAt(i) - 'a';
            if (trie[p][u] == 0) trie[p][u] = ++index;
            p = trie[p][u];
        }
        count[p]++;
    }

    public boolean search(String s) {
        int p = 0; // root node在第0行
        for (int i = 0; i < s.length(); i++) {
            int u = s.charAt(i) - 'a';
            if (trie[p][u] == 0) return false;
            p = trie[p][u];
        }
        return count[p] != 0;
    }

    public boolean startsWith(String s) {
        int p = 0; // root node在第0行
        for (int i = 0; i < s.length(); i++) {
            int u = s.charAt(i) - 'a';
            if (trie[p][u] == 0) return false;
            p = trie[p][u];
        }
        return true;
    }
}

```



###  关于「二维数组」是如何工作 & 1e5 大小的估算





### `TrieNode`

> NOTE:
>
> 一、这种方式相对容易理解。

相比二维数组，更加常规的做法是建立 `TrieNode` 结构节点。

随着数据的不断插入，根据需要不断创建 `TrieNode` 节点。



```Java

class Trie {
    class TrieNode {
        /**
         * 是否为「单词结尾」
         */
        boolean end;
        /**
         * 后续字符串的字符
         * tns=the next string
         */
        TrieNode[] tns = new TrieNode[26];
    }

    TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    /**
     * 沿着path迭代
     *
     * @param s
     */
    public void insert(String s) {
        TrieNode p = root;
        for (int i = 0; i < s.length(); i++) {
            int u = s.charAt(i) - 'a';
            if (p.tns[u] == null) p.tns[u] = new TrieNode();
            p = p.tns[u]; // move to next
        }
        p.end = true;
    }

    /**
     * 沿着path迭代
     *
     * @param s
     * @return
     */
    public boolean search(String s) {
        TrieNode p = root;
        for (int i = 0; i < s.length(); i++) {
            int u = s.charAt(i) - 'a';
            if (p.tns[u] == null) return false;
            p = p.tns[u];
        }
        return p.end;
    }

    /**
     * 沿着path迭代
     *
     * @param s
     * @return
     */
    public boolean startsWith(String s) {
        TrieNode p = root;
        for (int i = 0; i < s.length(); i++) {
            int u = s.charAt(i) - 'a';
            if (p.tns[u] == null) return false;
            p = p.tns[u];
        }
        return true;
    }
}
```

### 两种方式的对比

使用「二维数组」的好处是写起来飞快，同时没有频繁 `new` 对象的开销。但是需要根据数据结构范围估算我们的「二维数组」应该开多少行。

坏处是使用的空间通常是「`TrieNode`」方式的数倍，而且由于通常对行的估算会很大，导致使用的二维数组开得很大，如果这时候每次创建 `Trie` 对象时都去创建数组的话，会比较慢，而且当样例多的时候甚至会触发 `GC`（因为 每测试一个样例会创建一个 `Trie` 对象）。

因此还有一个小技巧是将使用到的数组转为静态，然后利用 `index` 自增的特性在初始化 `Trie` 时执行清理工作 & 重置逻辑。

这样的做法能够使评测时间降低一半，运气好的话可以得到一个与「`TrieNode`」方式差不多的时间。





### 关于 Trie 的应用面

首先，在纯算法领域，前缀树算是一种较为常用的数据结构。

不过如果在工程中，不考虑**前缀匹配**的话，基本上使用 hash 就能满足。

如果考虑**前缀匹配**的话，工程也不会使用 Trie 。一方面是字符集大小不好确定（题目只考虑 26 个字母，字符集大小限制在较小的 26 内）因此可以使用 Trie，但是工程一般兼容各种字符集，一旦字符集大小很大的话，Trie 将会带来很大的空间浪费。另外，对于个别的超长字符 Trie 会进一步变深。

这时候如果 Trie 是存储在硬盘中，Trie 结构过深带来的影响是多次随机 IO，随机 IO 是成本很高的操作。

这时候如果 Trie 是存储在硬盘中，Trie 结构过深带来的影响是多次随机 IO，随机 IO 是成本很高的操作。

同时 Trie 的特殊结构，也会为分布式存储将会带来困难。

因此在工程领域中 Trie 的应用面不广。

至于一些诸如「联想输入」、「模糊匹配」、「全文检索」的典型场景在工程主要是通过 ES (ElasticSearch) 解决的。

而 ES 的实现则主要是依靠「倒排索引」。



## 宫水三叶[【设计数据结构】Trie 运用题](https://mp.weixin.qq.com/s/TPVBlNBLlUpQKXK_XkR-3Q)

[LeetCode-211. Design Add and Search Words Data Structure-Middle](https://leetcode.cn/problems/design-add-and-search-words-data-structure/)

