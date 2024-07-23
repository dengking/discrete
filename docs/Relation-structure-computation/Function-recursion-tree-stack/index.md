# Function、recursive function、tree、stack

本文讨论function、**recursive function**、tree、stack之间的关联，我们首先描述通用的function、tree、stack，然后对**recursive function**进行专门的描述，因为**recursive function**是一种特殊的function，它的符合"Function、tree、stack"的规律。

> **知识回顾**: 
>
> 1. nesting relation能够形成 tree structure
>
> 2. tree、track path、stack
>
>    非线性结构 -> 线性结构
>
>    典型的是树的遍历



## Function、tree、stack

总的思路如下:

Function 和 subfunction 之间具有:

1. contain/nest 关系 --> **函数调用树(activation tree)**

   函数的每次被调用，称为 "activation"，它相当于activation tree中的一个节点。

2. dependent 关系 --> 对 **函数调用树(activation tree)** 执行depth first search

   bottom up自底向上，将return value返回到parent node；

3. **深度优先遍历** --> 需要stack

### Containing/nesting 关系 和 函数调用树(activation tree)

Function 和 subfunction(被它调用的函数) 之间是 containing/nesting 关系，因此: 

如果将程序执行过程精简成函数调用的话，其实整个程序的执行过程也可以画成树形的，即程序的**函数调用树(activation tree)**：这棵树的 root节点就是main函数，main函数所调用的函数处于这棵树的第一层，第一层函数所调用的函数处于第二层，依次递推，就可以得到一棵完整的树了。

> NOTE:   
>
> 1. 上述内容是我在阅读 dragon book的《4.6 Introduction to LR Parsing: Simple LR》时，总结的，其中有着更加完善的分析。

#### PDA、CFG、hierarchy

函数调用/执行过程的一些类比:

1. **production**的推导过程，一个函数调用就相当于一个**non-terminal**，需要进行**expand**。函数是具备hierarchy结构的：如果将函数中的每个语句看做是一个leaf node，将函数调用看做是一个inner node，每次调用一个函数就相当于expand这个node。则整个函数就形成了一棵树。

   函数比也可以看做是类似于production的，都是在描述包含关系。一个函数体中调用了哪些函数，则就相当于production在描述它的body。

2. 函数的执行过程非常类似于`build_nav_tree`中构造整个`nav_tree`的过程。`nav_tree`是nesting in space。

3. 使用栈来生成树：将parsing的过程和函数执行的过程都看做是按照production生成一棵树。



总结: 所有具备nesting结构的都可以使用CFG production来进行描述。TODO: 需要联系pushdown automata和call stack的共同点所在。TODO: tag-PDA=Pushdown-automaton=下推自动机-CFG=context-free-language-hierarchy-structure

**draft:** programming language是context free language。具备nesting结构。

函数的definition也具备nesting结构。

都可以使用cfg来进行描述。

可以将函数的definition也看做是cfg：普通语句就相当于terminal，函数调用语句就相当于non-terminal。

则main函数就相当于start symbol。

则整个函数的执行过程就类似于一个自顶向下的parsing。

**draft:** activation tree，[Parse tree](http://en.wikipedia.org/wiki/Parse_tree)，它们都是呈现的tree结构，但是函数的执行仅仅需要一个call stack，parsing的过程也仅仅只需要一个[pushdown automata](https://en.wikipedia.org/wiki/Pushdown_automaton)（本质上是一个stack），两者存在着非常类似的现象，我们需要去思考现象背后所蕴含的道理。两个过程都具有nesting特性，所以它们的过程都呈现tree structure。在[4.6 Introduction to LR Parsing: Simple LR](https://dengking.github.io/compiler-principle/Chapter-4-Syntax-Analysis/4.6-Introduction-to-LR-Parsing-Simple-LR/)中我对此有过分析。

在[Compilers Principles, Techniques and Tools Second Edition(aka ***dragon book***)](https://en.wikipedia.org/wiki/Compilers:_Principles,_Techniques,_and_Tools) 的[7.2.1 Activation Trees](https://dengking.github.io/compiler-principle/Chapter-7-Run-Time-Environments/7.2-Stack-Allocation-of-Space/#721-activation-trees)中对此进行了详细分析。



### Dependent 关系 和 对activation tree进行depth-first traverse

Function的执行过程是对**activation tree**的depth-first traverse，这是由dependent 关系所决定的，即 function 的return value是依赖于 subfunction的return value的，因此，需要对 **函数调用树(activation tree)** 执行**深度优先遍历**，即需要等**current function**的所有的**dependency**都完成/满足后，才能够得到**current function**的**return value**，显然，这是需要先将**current function** push 到 call stack 中，然后将它的dependency push到call stack中，current function需要等它的所有的dependency完成后，才能够完成，即出栈，显然这是**后进先出**。

> NOTE: 显然，这是construct dependency structure
>

### 如何得到完整的函数调用树(activation tree)？

如何得到完整的函数调用树？

1、csdn [各类分析函数调用关系图的工具](https://blog.csdn.net/cqbamboo/article/details/6736627)

其中提及了 `calltree` 工具。





### [compiler-principle](https://dengking.github.io/compiler-principle/) # [7.2 Stack Allocation of Space](https://dengking.github.io/compiler-principle/Chapter-7-Run-Time-Environments/7.2-Stack-Allocation-of-Space/)

nesting in time，在时间维度是一条线，即一条path，相当于能够将他们给串联起来，类似于一个chain。貌似能够nesting的，都能够**线性化**。

> NOTE: 
>
> 1. 上述"**线性化**": "non-linear structure-Linearization-nest contain relation"
>
> 2. nesting结构是可以线性化的。



## Formal analysis(整体分析)

无论是**LR(0)自动机**以及**函数调用树(activation tree)**，它们都是是我们从全局的角度（整体的角度，分析的角度）来分析这个问题，它们是理论层面的分析，而不是实际的实现，实际的执行过程中，压根就不需要显式地构造出这样的一棵树，并且压根就无需知道整个树是怎样的。比如在LR parser中，parser是从左至右对输入串进行分析，一次只会取一个符号，函数的执行是顺序执行的，一次只会执行一个函数；为什么要这样呢？我觉得这是由计算机的体系结构所决定的，正如各种automaton模型所展示的那样，计算机就是这样的规则，就是这样的顺序，所以我们的算法设计也是需要寻找规则，顺序，这是一种计算思维；

### Path

所以实际的执行过程仅仅对应的是树中的一条路径（有起点，有终点），显然这条路径是**线性的**，是**连续的**（能够从终点再返回到起点）。如果我们将执行的路径连接起来（因为这些路径是连续的，所以能够将它们连接起来），以适当的方式画出了（正如Fig. 4.31），那么它就能够展现出我们的在理论层面分析的形态。

如果从树的构造来看的话，在parser是从左至右对输入串进行分析，一次只会取一个符号，从子树开始构造，然后将一棵一棵的子树结合起来构造更大的树。在data structure中，树是有一个一个的node连接而成的，所以访问一棵树只需要得到这棵树的根结点即可，所以可以使用node来代替一棵树。所以在树的构造过程中，所操作的是一个一个的node，所以使用使用stack就可以完成一棵树的构造。

在计算机科学中，对理论模型的实现时往往选择的是通用的，简单的方式（节约内存等），"实际的执行过程仅仅对应的是树中的一条路径"，所以我们仅仅需要的是能够满足这条路径的结构即可。而栈这种结构就正好符合这些要求：

- 栈是线性的
- 栈是连续的，所以能够实现从终点回到起点

再回到理论分析层面，实际执行过程和理论层面的模型之间是怎样的关联呢？实际执行流程对应的是对树执行深度优先后序遍历；

### Formal analysis的意义

1、它是理解computation complexity的前提，尤其是对于recursive function。

2、它是理解 "Optional substructure-最优子结构" 的前提。

## Recursive function、tree、stack

前面对"function、tree、stack"的formal analysis，其实是能够应用于"recursive function"的，因为"recursive function"是一种特殊的"function"。

### 使用dependency relation来描述recursion

1. 不断地向下构建、递归直到base case。

2. stack order、后进先出

3. 一直不断地往下递归，直到base case，然后出栈、返回，将计算结果返回给上一层



## [call stack](https://en.wikipedia.org/wiki/Call_stack) and stack

> NOTE:
>
> 1、关于[call stack](https://en.wikipedia.org/wiki/Call_stack)，在ABI中已经收录了

|          |      |
| -------- | ---- |
| 函数调用 | 入栈 |
| 函数返回 | 出栈 |

函数调用的过程是深度优先的，因为它需要获得子函数的值。



## true&stack&recursion&induction&production
递归公式是数学上公式，它是理论上的，它可以进行无限的扩展，使用它可以阐述infinite sequence

递归函数是对递归公式的计算机实现，一般需要对它指定递归终止条件，也就是说它不能够想递归公式那样无限地运行下去。


树是满足递归定义的，我们知道，一棵树不是无限的，也就是说它是有叶子节点的，树第叶子节点就对应了递归函数的递归终止条件。

与此类似的是，production中也有terminal，产生式的terminal就相当于树的叶子节点，是递归的终止条件。





