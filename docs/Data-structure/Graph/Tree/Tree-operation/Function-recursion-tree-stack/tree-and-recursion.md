# 树结构的递归性

树的结构是具备递归性的：一个节点的左节点可能是一棵树，右节点也可能是一棵树，显然树的定义是由它自身定义的；所以对树的操作可以充分利用树结构的递归性而写出递归函数；

还有一些结构也是隐式的数结构：

# 可以使用树结构来进行描述的内容
## 目录
目录是典型的可用使用tree来进行描述的

## [yaml](https://en.wikipedia.org/wiki/YAML)

## expression
[binary expression tree](https://en.wikipedia.org/wiki/Binary_expression_tree)

## source code

[Abstract syntax tree](https://en.wikipedia.org/wiki/Abstract_syntax_tree)使用一棵树表达了源代码的语法结构


## recursion invocation tree

递归函数的调用过程也是可以使用tree来进行描述的

### divide and conquer

[Divide-and-conquer algorithm](https://en.wikipedia.org/wiki/Divide-and-conquer_algorithm)是典型的递归算法


## 具备传递性的包含关系
一些包含关系具有传递性（回去看离散数学对这的描述），比如A包含B，B又包含C，则A应该包含所有的C。

如下是一个例子：

```
有价证券:股票,债券,权证,资产支持证券,买入返售金融资产

债券:国债,企债,非政策型金融债,地方债,可转债,政策性金融债,公司债,央行票据,次级债

```
`有价证券`包含`债券`，债券又包含`国债,企债,非政策型金融债,地方债,可转债,政策性金融债,公司债,央行票据,次级债`，所以`有价证券`包括`国债,企债,非政策型金融债,地方债,可转债,政策性金融债,公司债,央行票据,次级债`。

上述关系是可以使用tree来进行描述的

上述结构可以使用一个dict来进行保存：所有作为key的都是non-terminal，都需要进行扩展；

# 使用树来描述关系
其实上述都是在使用tree来表示关系，expression中的关系是`+=*/`，recursion invocation tree是函数调用关系，具备传递性的包含关系是包含关系；

在使用tree来描述这些关系的时候，**叶子节点**是**terminal元素**，**内节点**都是在**表达关系**；



## 扩展关系

扩展一个使用tree描述的关系的最终目标是获得所有的叶子节点，它的基本算法是：一个节点，只要是non-terminal元素，就需要对它进行expand，其实这个过程就是[Parse tree](https://en.wikipedia.org/wiki/Parse_tree)的生成过程；

所以其实，我上述所描述的都是[Parse tree](https://en.wikipedia.org/wiki/Parse_tree)的生成过程过程；

下面是一段描述上述**具备传递性的包含关系**的获取所有的可能的叶子节点的简单算法，它需要将所有的内节点进行扩展，最终的结果只能够包含叶子节点而不能包含叶子节点

```
self.expanded_fen_zi_dict[fen_zi_word_info] = list()
to_expand_words = list(retriever_context.fen_zi_detail_dict[fen_zi_word_str]) # 待扩展词列表
while len(to_expand_words):
    word = to_expand_words.pop() # 一次只处理一个词
    if word in retriever_context.fen_zi_detail_dict: # 当前词相当于一个内节点
        to_expand_words.extend(retriever_context.fen_zi_detail_dict[word]) # 扩展当前词，并且将它添加到待扩展词列表中
    else: # 当前词是一个页节点
        self.expanded_fen_zi_dict[fen_zi_word_info].append(word) # 将该词进行输出

```

## Tree and relation

[Tree (graph theory)](https://en.wikipedia.org/wiki/Tree_(graph_theory))中有这样的描述：
> As elsewhere in graph theory, the order-zero graph (graph with no vertices) is generally not considered to be a tree: while it is vacuously connected as a graph (any two vertices can be connected by a path), it is not 0-connected (or even (−1)-connected) in algebraic topology, unlike non-empty trees, and violates the "one more vertex than edges" relation.

[Tree (data structure)](https://en.wikipedia.org/wiki/Tree_(data_structure))中也有很多这方面的描述。

## tree and set

# [Tree automaton](https://en.wikipedia.org/wiki/Tree_automaton)