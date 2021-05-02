# Recursion、tree、stack

一、本章讨论Recursion、tree、stack之间的关联。

二、树 和 递归

1、tree是能够表示nesting relation，nesting relation是recursive的

2、

二、相关章节

`Analysis-and-representation-of-recursion`

三、树、path、stack

非线性结构 -> 线性结构

典型的是树的遍历



三、递归 和 树

1、为什么递归可以使用树来进行表示？

递归可以看做是具备nesting关系，因此它可以使用tree来进行表示

关于此的最好的例子就是formal language

四、构建依赖关系

不断地向下构建、递归直到base case。

四、stack order、后进先出

1、一直不断地往下递归，直到base case，然后出栈、返回，将计算结果返回给上一层

2、这让我想起了topological sorting中，找到没有任何依赖的那个节点，然后反向不断地删减

其实，它和析构一个linked list是非常类似的，它们本质上都是对依赖关系的删除

3、这让我想起了destructor 的 destruction order



上面这些，其实都可以使用**依赖关系**来进行说明，显然，当需要析构一个具备依关系的结构的时候，需要找到最最底层的、最被依赖的节点，将其删除，然后反向不断地进行删除，这个过程，最好的模拟例子就是析构一个linked list。

五、从依赖关系的角度来进行理解

1、构建依赖关系

2、析构一个具有依赖关系的结构

## 草稿1

可以使用括号来表示树，这是源于[Newick format](https://en.wikipedia.org/wiki/Newick_format) *and* [Dyck language](https://en.wikipedia.org/wiki/Dyck_language)，如下是一些简单的例子：

`[[[]]]`对应的tree如下：

```
   
       []
      /
     /
   []
  /
 /
[]
```



可以看到，它已经退化成了一个list，这种属于使用tree来描述具有hierarchy structure的数据。

对于[Dyck language](https://en.wikipedia.org/wiki/Dyck_language)，在对其进行parsing的时候，需要使用stack，其实我们进行parsing的时候，是沿着树进行深度优先遍历，一般我们进行parsing时候，遇到开括号`[`是要继续压栈，其实看上图就可以知道，压栈对应着是沿着树路径向下，即不断地向下遍历。遇到闭括号`]`，其实是出栈，开始向上了。

## 草稿2



### [call stack](https://en.wikipedia.org/wiki/Call_stack) and stack

***SUMMARY***:关于[call stack](https://en.wikipedia.org/wiki/Call_stack)，在ABI中已经收录了

|          |      |
| -------- | ---- |
| 函数调用 | 入栈 |
| 函数返回 | 出栈 |

函数调用的过程是深度优先的，因为它需要获得子函数的值。

### parenthesis and stack

|        |      |
| ------ | ---- |
| 正括号 | 入栈 |
| 反括号 | 出栈 |



***SUMMARY*** : stack的入栈与出栈是一对户逆的操作，所以stack非常适合于解决哪些存在着互逆操作的问题；



## 草稿3

activation tree，[Parse tree](http://en.wikipedia.org/wiki/Parse_tree)，它们都是呈现的tree结构，但是函数的执行仅仅需要一个call stack，parsing的过程也仅仅只需要一个[pushdown automata](https://en.wikipedia.org/wiki/Pushdown_automaton)（本质上是一个stack），两者存在着非常类似的现象，我们需要取思考现象背后所蕴含的道理。两个过程都具有nesting特性，所以它们的过程都呈现tree structure。在[4.6 Introduction to LR Parsing: Simple LR](https://dengking.github.io/compiler-principle/Chapter-4-Syntax-Analysis/4.6-Introduction-to-LR-Parsing-Simple-LR/)中我对此有过分析。

在[Compilers Principles, Techniques and Tools Second Edition(aka ***dragon book***)](https://en.wikipedia.org/wiki/Compilers:_Principles,_Techniques,_and_Tools) 的[7.2.1 Activation Trees](https://dengking.github.io/compiler-principle/Chapter-7-Run-Time-Environments/7.2-Stack-Allocation-of-Space/#721-activation-trees)中对此进行了详细分析。



## 草稿4

《递归的分析与表示》可以作为一个非常好的说明

龙书，7.2节


### stack in constructing tree
top-down parsing和`perm`算法都是在构造tree，前者自己使用了一个stack，而后者使用的是系统stack。

### 树&栈&recursion&induction&production
递归公式是数学上公式，它是理论上的，它可以进行无限的扩展，使用它可以阐述infinite sequence

递归函数是对递归公式的计算机实现，一般需要对它指定递归终止条件，也就是说它不能够想递归公式那样无限地运行下去。


树是满足递归定义的，我们知道，一棵树不是无限的，也就是说它是有叶子节点的，树第叶子节点就对应了递归函数的递归终止条件。

与此类似的是，production中也有terminal，产生式的terminal就相当于树的叶子节点，是递归的终止条件。


### recursion&induction
参见：
http://infolab.stanford.edu/~ullman/focs/ch02.pdf



#### 从搜索的角度来看待回溯法

回溯法也可以用于实现搜索。搜索的优化逻辑


### summary
#### 如何描述树与图

formal grammar

三地址码

### 如何基于描述来构造树
parsing，parsing也可以看做是一种搜索，由于formal grammar可能的组合形式是非常多的，每一种组合形式都对应了一棵完整的tree，parsing的过程就是在在所有的可能组合中寻找到一棵能够描述我的string的tree。

隐式的树：解空间是一棵树

#### 树遍历与搜索

基于遍历来进行搜索。回溯就是一种典型的深度优先搜索策略。其实除此之外，还有非常多的搜索策略。

其实，这种基于树遍历的搜索方案

思考：遍历不一定是要进行搜索，还可能是枚举出所有可能的解决方案，但是这其实也可以看做是搜索。

处理基于遍历的搜索，其实hash这种搜索方案就和基于遍历的搜索方案是完全不同的。

关于搜索方案的更加详细的讨论，可以参见https://en.wikipedia.org/wiki/Search_algorithm

### 思考：如何使用递归来实现括号匹配？？
一般我们都是使用一个显示的stack，那么如何使用递归来使用call stack呢？