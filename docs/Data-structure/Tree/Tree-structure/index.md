# Tree structure

本文所要讨论的是“树形形状”，标题中的“structure”所要表达的含义是“形状”。

本文基于维基百科[Tree structure](https://en.wikipedia.org/wiki/Tree_structure)。

> A **tree structure** or **tree diagram** is a way of representing the [hierarchical](https://en.wikipedia.org/wiki/Hierarchy) nature of a [structure](https://en.wikipedia.org/wiki/Structure) in a graphical form. It is named a "tree structure" because the classic [representation](https://en.wikipedia.org/wiki/Tree_structure#Representing_trees) resembles a [tree](https://en.wikipedia.org/wiki/Tree).

在[Hierarchy](../Structure/Hierarchy.md)中，我们已经总结了**tree structure**对应的是 nested hierarchy structure。

**tree structure** 的最最典型的特性是：

1、一个节点可以有（包含）多个子节点

2、一个子节点只能够有一个父节点

3、root节点没有父节点。

**tree structure** 的 “一个子节点只能够有一个父节点” 的要求，将它和graph区分开来了（参见[Discrete Mathematics and Its Applications](https://www.amazon.com/Discrete-Mathematics-Applications-Kenneth-Rosen/dp/125967651X)的Tree章节）。在本文的后面我们使用“**nesting** ”这个词来描述**tree structure**的这个特性。“**nesting**”的中文含义是“嵌套”，显然，它能够描述元素之间的嵌套关系；这个词的含义是丰富的，它的表面意思是“嵌套”，“嵌套”蕴含着“包含”的含义，“嵌套”蕴含着“递归”的含义；显然具备nesting特性，就具备了如下特性：

1、[hierarchical](https://en.wikipedia.org/wiki/Hierarchy)，即树结构是层次的

2、[recursive](../Data-structure/Recursive-data-type.md)，nesting的递归性：我觉得nesting的递归性可以使用关系的transitive特性来进行解释。比如[recursive](https://en.wikipedia.org/wiki/Scope_(programming)) scope rules ，这种包含关系一种transitive relation。与nesting相关的另外一个词是：level，其实它就和树的深度相关。

具备nesting特性的结构都可以使用tree structure来进行表示。

我第一次碰到这个词是在阅读[Compilers Principles, Techniques and Tools Second Edition(aka ***dragon book***)](https://en.wikipedia.org/wiki/Compilers:_Principles,_Techniques,_and_Tools) 的[7.2.1 Activation Trees](https://dengking.github.io/compiler-principle/Chapter-7-Run-Time-Environments/7.2-Stack-Allocation-of-Space/#721-activation-trees)节时：

> Stack allocation would not be feasible if procedure calls, or activations of procedures, did not **nest in time**. The following example illustrates nesting of procedure calls.

正是“activations of procedures”的“**nest in time**”特性，使得“Stack allocation”变得可行，并且activations of procedures的过程是tree structure的（原文中关于此是有分析的）。

第二次碰到这个词是在阅读[Hierarchy](../Structure/Hierarchy.md)的“Nested hierarchy”节时，至此才更加觉得nesting这个词非常能够体现**tree structure**的本质。

更多关于nesting的描述，参见：[Nesting (computing)](https://en.wikipedia.org/wiki/Nesting_(computing))和[Nested sets](https://en.wikipedia.org/wiki/Nested_set)。

## 树结构的递归性

树的结构是具备递归性的：一个节点的左节点可能是一棵树，右节点也可能是一棵树，显然树的定义是由它自身定义的；所以对树的操作可以充分利用树结构的递归性而写出递归函数；

还有一些结构也是隐式的数结构：



## 哪些关系能够形成树形状

这个问题在[Hierarchy](../Structure/Hierarchy.md)中同样提问过，本段从一些具体的关系的例子出发来进行总结。

### Example: nesting关系

在前面我们已经说明了tree structure的最最根本的特征是nesting，所有的具备nesting关系的数据，按照该关系进行组织，都能够形成tree structure。在计算机科学中，存在着太多太多具备nesting关系的数据了，在[Examples-of-tree-structures](./Examples-of-tree-structures.md)中会枚举具备这种关系的结构。

其实有很多的关系本质上都是nesting关系：

#### 推导关系

Formal grammar的production的head可以derive得到body，这个过程其实非常类似于expand，其实expand就是包含，也就是nesting 关系。更多关于推导关系参见[推导关系分析](#推导关系分析)。

#### [Constituency relation](https://en.wikipedia.org/wiki/Phrase_structure_grammar#Constituency_relation)

这是[Phrase structure grammar](https://en.wikipedia.org/wiki/Phrase_structure_grammar)在描述语言结构时所采用的关系，这种关系本质上也是nesting关系。它描述的语言的结构是一棵树，如下：

![Constituency and dependency relations](https://upload.wikimedia.org/wikipedia/commons/8/8e/Thistreeisillustratingtherelation%28PSG%29.png)



### Example: Parent-child关系

一个parent可以有多个children，一个child只能够有一个parent。其实Parent-child关系也可以归入到nesting关系中。

### 最终答案

这种关系需要是`N:1`的（记得在大学的数据库课程所使用的教材中有过这样的理论，这个理论应该是属于[Relational algebra](https://en.wikipedia.org/wiki/Relational_algebra)，参见：[Relational model](https://en.wikipedia.org/wiki/Relational_model)、[Database normalization](https://en.wikipedia.org/wiki/Database_normalization)）。

这种关系应该是[Transitive relation](https://en.wikipedia.org/wiki/Transitive_relation)。

这个关系不能是[Reflexive relation](https://en.wikipedia.org/wiki/Reflexive_relation)。

可以这样不严谨地进行描述：**具备传递性的包含关系**。

后面我们为了描述的便利，统一将这种关系称为“**nesting关系**”，后面文章中，我们有时候也会将“tree structure”表述成“nesting structure”。

#### 具备传递性的包含关系例子

一些包含关系具有传递性（回去看离散数学对这的描述），比如A包含B，B又包含C，则A应该包含所有的C。

如下是一个例子：

```
有价证券:股票,债券,权证,资产支持证券,买入返售金融资产

债券:国债,企债,非政策型金融债,地方债,可转债,政策性金融债,公司债,央行票据,次级债

```

`有价证券`包含`债券`，债券又包含`国债,企债,非政策型金融债,地方债,可转债,政策性金融债,公司债,央行票据,次级债`，所以`有价证券`包括`国债,企债,非政策型金融债,地方债,可转债,政策性金融债,公司债,央行票据,次级债`。

上述关系是可以使用tree来进行描述的

上述结构可以使用一个dict来进行保存：所有作为key的都是non-terminal，都需要进行扩展；



## Nesting 与 hierarchy

Nesting结构具备hierarchy特性，可以这样来进行解释：

最外层是是第一层、它所直接包含的元素都属于第二层、依次递归。



## 推导关系分析

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





## draft: Tree and relation

[Tree (graph theory)](https://en.wikipedia.org/wiki/Tree_(graph_theory))中有这样的描述：

> As elsewhere in graph theory, the order-zero graph (graph with no vertices) is generally not considered to be a tree: while it is vacuously connected as a graph (any two vertices can be connected by a path), it is not 0-connected (or even (−1)-connected) in algebraic topology, unlike non-empty trees, and violates the "one more vertex than edges" relation.

[Tree (data structure)](https://en.wikipedia.org/wiki/Tree_(data_structure))中也有很多这方面的描述。



### 使用树来描述关系

其实上述都是在使用tree来表示关系，expression中的关系是`+=*/`，recursion invocation tree是函数调用关系，具备传递性的包含关系是包含关系；

在使用tree来描述这些关系的时候，**叶子节点**是**terminal元素**，**内节点**都是在**表达关系**；



## See also

- [Hierarchy](https://en.wikipedia.org/wiki/Hierarchy)
- [Nesting (computing)](https://en.wikipedia.org/wiki/Nesting_(computing))
- [Nested set model](https://en.wikipedia.org/wiki/Nested_set_model)
- [Nested set](https://en.wikipedia.org/wiki/Nested_set)
- [Hereditary property](https://en.wikipedia.org/wiki/Hereditary_property)

