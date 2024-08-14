# State space search

通过wikipedia [Search algorithm](https://en.wikipedia.org/wiki/Search_algorithm)，我们可以看到：“search”是一个非常宏大的主题，(有时候有这样的感觉)computer science解决很多问题的解法最终都可以归入search的范轴。正因为search algorithm的无处不在，所以对它的研究是非常有必要的。本章描述[state space search](https://en.wikipedia.org/wiki/State_space_search)，显然它的搜索对象是 **state space**，我们通常将它称之为"解空间"，它的搜索策略包括DFS、BFS等，它是有别于binary search的一种search algorithm。

## 素材

1. wikipedia [State space search](https://en.wikipedia.org/wiki/State_space_search) 

2. wikipedia [State space](https://en.wikipedia.org/wiki/State_space) 

3. wikipedia [Search algorithm](https://en.wikipedia.org/wiki/Search_algorithm) 

4. `计算机算法设计与分析-5-回溯法`，其中也有关于"state space search"的内容



## State space

所谓"**state space**"，其实就是我们平常所说的问题的"解空间"。

### wikipedia [State space (computer science)](https://en.wikipedia.org/wiki/State_space_(computer_science))

In [computer science](https://en.wikipedia.org/wiki/Computer_science), a **state space** is a [discrete space](https://en.wikipedia.org/wiki/Discrete_space) representing the set of all possible configurations of a "system".[[1\]](https://en.wikipedia.org/wiki/State_space_(computer_science)#cite_note-MISSD-1) It is a useful abstraction for reasoning about the behavior of a given system and is widely used in the fields of [artificial intelligence](https://en.wikipedia.org/wiki/Artificial_intelligence) and [game theory](https://en.wikipedia.org/wiki/Game_theory).



### Combinational analysis

问题的解空间的构建依赖于combinational analysis中的原理。

### Combinatorial explosion

#### wikipedia [Combinatorial explosion](https://en.wikipedia.org/wiki/Combinatorial_explosion)



## wikipedia [State space search](https://en.wikipedia.org/wiki/State_space_search) 

> NOTE: 这篇文章介绍得非常好

**State space search** is a process used in the field of [computer science](https://en.wikipedia.org/wiki/Computer_science), including [artificial intelligence](https://en.wikipedia.org/wiki/Artificial_intelligence) (AI), in which successive [configurations](https://en.wikipedia.org/wiki/Configuration_graph) or *states* of an instance are considered, with the intention of finding a *goal state* with the desired property.

Problems are often modelled as a [state space](https://en.wikipedia.org/wiki/State_space), a [set](https://en.wikipedia.org/wiki/Set_(mathematics)) of *states* that a problem can be in. The set of states forms a [graph](https://en.wikipedia.org/wiki/Graph_(discrete_mathematics)) where two states are connected if there is an *operation* that can be performed to transform the first state into the second.

> NOTE: transition、discrete

State space search often differs from traditional [computer science](https://en.wikipedia.org/wiki/Computer_science) [search](https://en.wikipedia.org/wiki/Search_algorithm) methods because the state space is [*implicit*](https://en.wikipedia.org/wiki/Implicit_graph): the typical state space graph is much too large to generate and store in [memory](https://en.wikipedia.org/wiki/Computer_storage). Instead, nodes are generated as they are explored, and typically discarded thereafter. 

A solution to a [combinatorial search](https://en.wikipedia.org/wiki/Combinatorial_search) instance may consist of the goal state itself, or of a **path** from some *initial state* to the goal state.

> NOTE: 上面引出了path

### Representation

In state space search, a **state space** is formally represented as a tuple $S:\langle S,A,Action(s),Result(s,a),Cost(s,a)\rangle$, in which:



## Search space的分类

> Tips: 从具体到抽象

> tips: [discrete space](https://en.wikipedia.org/wiki/Discrete_space)、discrete structure

由于人们的思维往往是易于接受具体，所以对于virtual space这种比较抽象的，我们往往使用具体事物来进行刻画，比如使用search tree来描述问题的解空间，因此，后面在描述各种search strategy的时候，我们是基于concrete structure来进行描述的，这样便于理解，所以讲这部分内容都放到了`Relation-structure-computation\Structure`章节中。

因此我们需要使用抽象而不是具体。

为了更好地描述、总结search algorithm，我们首先站在一个更高的层次，我们首先明确search问题的object：search space。

有着多种分类标准：

| Classification criteria | Examples                                                     |
| ----------------------- | ------------------------------------------------------------ |
| virtual                 | 参见 维基百科 [Search algorithm](https://en.wikipedia.org/wiki/Search_algorithm) `#` For virtual search spaces 章节 |
| physical/concrete       | - list<br>- tree<br>- graph                                  |

按照“结构化思维”可知：不管是virtual search space还是physical/concrete search space，它们本质上都可以使用relation来进行抽象描述，它们都可以归入**discrete structure**范畴；对于virtual search space和concrete search space，如果它们遵循相同的relation，那么：

1. 它们呈现相同的structure

2. 可以使用相同的algorithm来实现它们的computation



## Search in virtual space 

virtual space的搜索和concrete structure的搜索的过程、实现方式非常类似。

virtual space包括：

- 解空间
- 状态空间

以**结构化思维**来看，virtual space也有着**结构**，最最典型的例子是eight-queen puzzle，它可以使用**nesting关系**来解释：第一次包含n个选择，第二次包含n-1个选择，所以它最终呈现树形，所以可以使用**Relation-based algorithm model**。

参见：

- 结构化思维：`Relation-structure-computation\index.md`
- Relation-based algorithm model：`Relation-structure-computation\Computation\Relation-based-algorithm-model.md`
- nesting关系：`Relation-structure-computation\Model\Nesting-relation-model`



### 状态空间 VS 解空间

**解空间**是一种非常典型的state space。



### State space的分类: 树形

complete n-ary tree、subset tree子集树、permutation tree排列树、combination tree组合树,

在下面的章节中，对它们进行了详细描述:

1、`计算机算法设计与分析-5-回溯法`

2、`Expert-labuladong\3.1-回溯算法(DFS算法)系列\回溯算法团灭排列-组合-子集问题`



### `Permutation-and-combination`

由于问题的解空间，往往对应的是permutation 和 combination，因此，将它们也放在了本章节。



## [Graph](https://en.wikipedia.org/wiki/Graph_traversal) **and** [tree search algorithms](https://en.wikipedia.org/wiki/Tree_traversal)

这部分内容`Data-structure\Graph\Search-algorithm`章节进行了描述。



## Search purpose

搜索目标，是在search space中搜索所有的solution，还是搜索best solution。

## Search strategy

在`strategy` 章节中进行了描述。

