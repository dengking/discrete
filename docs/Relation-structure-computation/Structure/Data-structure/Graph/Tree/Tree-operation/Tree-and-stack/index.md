# 关于本章

本章讨论tree 和 stack之间的关联，目前处于草稿状态。

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

### parenthesis and stack

|        |      |
| ------ | ---- |
| 正括号 | 入栈 |
| 反括号 | 出栈 |



***SUMMARY*** : stack的入栈与出栈是一对户逆的操作，所以stack非常适合于解决哪些存在着互逆操作的问题；



## 草稿3

activation tree，[Parse tree](http://en.wikipedia.org/wiki/Parse_tree)，它们都是呈现的tree结构，但是函数的执行仅仅需要一个call stack，parsing的过程也仅仅只需要一个[pushdown automata](https://en.wikipedia.org/wiki/Pushdown_automaton)（本质上是一个stack），两者存在着非常类似的现象，我们需要取思考现象背后所蕴含的道理。两个过程都具有nesting特性，所以它们的过程都呈现tree structure。在[4.6 Introduction to LR Parsing: Simple LR](https://dengking.github.io/compiler-principle/Chapter-4-Syntax-Analysis/4.6-Introduction-to-LR-Parsing-Simple-LR/)中我对此有过分析。

在[Compilers Principles, Techniques and Tools Second Edition(aka ***dragon book***)](https://en.wikipedia.org/wiki/Compilers:_Principles,_Techniques,_and_Tools) 的[7.2.1 Activation Trees](https://dengking.github.io/compiler-principle/Chapter-7-Run-Time-Environments/7.2-Stack-Allocation-of-Space/#721-activation-trees)中对此进行了详细分析。