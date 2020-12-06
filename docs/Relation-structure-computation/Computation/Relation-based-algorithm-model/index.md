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
- 在backtracing中，往往是根据nesting关系进行expand

## Implementation: recursion and iteration

本节标题的含义是，可以使用recursion 和 iteration来实现relation-based algorithm，下面对此进行分析。

使用同一个relation、transitive relation形成的structure，往往是recursive的，是可以给出递归定义了，可以使用structural recursion来进行解决。



下面是我在学习backtracing算法的实现时，所总结的：

- structure是使用同一种relation形成的（比如 backtracing中的nesting relation），因此可以使用同一种computation
- 对于同一种computation的重复执行，我们往往可以使用 recursion 和 iteration 来实现

下面描述基于recursion的实现：

使用**递归函数**可以实现沿着**结构**重复执行相同的操作（computation），进而逐步构建出完整的**structure**（这其实就是前面描述的expand模型，需要注意的是，此处的structure可能是虚拟的，不一定要显式地构造出来，或者说，这个过程呈现出一定的structure）；因此，一般将结构的 node、level 作为递归函数的入参（这其实是one-by-one computation model，即 逐步构建完整的结构），当node、level 达到完整结构时，表示已经构造出了完整的解，则可以终止递归了，即终止expand了。下面是这个过程的展示

|                    | expand                                   |      |
| ------------------ | ---------------------------------------- | ---- |
| `backtrace(level)` | 过渡到下一level: `backtrace(level + 1)`  |      |
| `backtrace(node)`  | 过渡到下一node: `backtrace( next_node )` |      |

需要结合backtracing来理解上面的内容。

参见：

- 关于relation、transitive relation，参见`Relation-structure-computation\Relation\Relation`章节
- 关于backtracing，参见`Relation-structure-computation\Computation\Algorithm\Paradigm\Backtracking\Backtrack`



## Optional sub structure

最优子结构，它是非常典型的可以使用relation-based algorithm解决的问题。

## Application



### Graph search algorithm

参见`Relation-structure-computation\Structure\Data-structure\Graph\Search-algorithm`。

### CFG

CFG的parsing

### Combinatorial optimization

Combinatorial-optimization，参见 `Relation-structure-computation\Computation\Algorithm\Application\Optimization\Combinatorial-optimization`