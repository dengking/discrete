# List of algorithms、list of data structure

如何构建algorithm的知识图谱？



wikipedia [List of algorithms](https://en.wikipedia.org/wiki/List_of_algorithms)

wikipedia [List of data structures](https://en.wikipedia.org/wiki/List_of_data_structures)



## sort、select

quick sort、quick select、[introsort](https://en.wikipedia.org/wiki/Introsort)

heap sort、heap select、[introselect](https://en.wikipedia.org/wiki/Introselect)



## Array-based data structure



### Store tree in array

一、implicit data structure tree

二、

1、heap、BIT(Binary Indexed Tree)、union-find-set等都是将tree存储于array中，这是因为这些tree都是complete、perfect的

2、segment tree是perfect-binary-tree，因此它能够将tree存储于array中

3、将 Trie存储于array中

这是我在阅读 [宫水三叶-【设计数据结构】实现 Trie (前缀树)](https://mp.weixin.qq.com/s?__biz=MzU4NDE3MTEyMA==&mid=2247488490&idx=1&sn=db2998cb0e5f08684ee1b6009b974089&chksm=fd9cb8f5caeb31e3f7f67dba981d8d01a24e26c93ead5491edb521c988adc0798d8acb6f9e9d&token=1006889101&lang=zh_CN&scene=21#wechat_redirect) 时发现其中的一种实现方式，trie本质是complete 26-ary tree

三、[malash-链式前向星及其简单应用](https://malash.me/200910/linked-forward-star/)

next，这让我想起了union-find-set的next pointer，它通过使用array来存储linked list

四、数组简单而强大



### Store stack in array



[LeetCode-【宫水三叶】二维凸包模板题](https://leetcode.cn/problems/erect-the-fence/solution/by-ac_oier-4xuu/) 

> 一些细节，为了方便取得栈顶的前两位元素，我们使用数组实现栈，`stk` 代表栈容器，*top* 代表栈顶元素下标。





## children、parent

我们寻常使用的tree的node保存的是child pointer，通过一个node可以获得它们的children node，但是有一些特殊的tree，它们则不同:

1、union-find set: parent node、botom-up

2、heap

3、Binary Indexed Tree or Fenwick Tree，和heap类似，通过数学运算能够准确计算得到parent、children



child pointer:  children contain、top-down、stop condition: leaf node

parent pointer: bottom-up、stop condition: root node



## segment tree、heap



[binary-heap](https://en.wikipedia.org/wiki/Binary_heap)是complete-binary-tree

segment tree是perfect-binary-tree

程序设计大赛



## 基于数学的data structure

一、binary heap的parent、children关系基于简单的数学

二、hash table将映射关系使用一个简单的hash function来保存

三、[Fibonacci heap](https://en.wikipedia.org/wiki/Fibonacci_heap)



## 一分为二

binary search

merge sort

segment tree

