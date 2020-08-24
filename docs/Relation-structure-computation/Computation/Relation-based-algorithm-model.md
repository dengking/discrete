

# Relation-based algorithm model

“Relation-based algorithm model”即“基于relation的algorithm model”，简单而言是：基于relation来设计algorithm。下面是对它的概括描述：

沿着structure、relation逐个进行处理，采用one-by-one computation（one node by another node）。

## 前提

relation需要具备transitive性质。

## algorithm步骤

### step 1

分析relation。

对于discrete objects，分析其结构，找出relation，给出formal definition，后面我们就可以开始设计algorithm，对其进行计算。

### step 2

rewrite/expand operation

根据relation进行rewrite/expand，relation就相当于rewrite rule，这个过程，需要one-by-one执行。

比如：

- 在parsing中，是根据production进行expand，production所表达的是包含关系
- 在graph中，则是根据相邻关系来进行expand的
- [Function composition](https://en.wikipedia.org/wiki/Function_composition)



## Relation and recursion

同一个relation、transitive relation、的structure，往往是recursive的，可以进行递归定义了，可以使用structural recursion来进行解决。

关于relation、transitive relation，参见`Relation-structure-computation\Relation\Relation`章节。

它和optional sub structure密切相关。



## 计算的方向

沿着关系、结构来进行计算，一般，我们可以选择两个不同的方向。

比如：递归是自顶向下、动态规划是自底向上、backprop是自顶向下、bottom-up parsing。



## Application

### Graph search algorithm

`Relation-structure-computation\Structure\Data-structure\Graph\Search-algorithm`

### CFG

CFG的parsing

### Combinatorial optimization

Combinatorial-optimization，参见 `Relation-structure-computation\Computation\Algorithm\Application\Optimization\Combinatorial-optimization`