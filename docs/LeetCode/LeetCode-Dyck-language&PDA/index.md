# LeetCode-parenthese



## Parenthese & tree

tree是可以使用parenthese来表示，反之亦然，匹配的括号表达式对应一棵expression tree

素材:

- [i-programmer-Parentheses Are Trees](https://www.i-programmer.info/programming/theory/3458-brackets-are-trees.html) 

### Use parenthese to represent tree

括号表示的 "contain/nest" 关系，tree中，parent node "contain/nest" children node，因此最外层括号对应的是root node。

[Nesting](https://en.wikipedia.org/wiki/Nesting_(computing)) 结构在computer science是非常常见，它是一种典型的hierarchy结构，nesting结构可以使用括号的方式来进行表示：

```
( () () ( ( ) ) )
```

上面使用括号来表示nesting结构，因为括号所能够表达的“包含”关系和“嵌套”关系是基本类似的。

上述结构是可以表示成树的，如下：

```
					( )
	
    ( )				( )				 ( )
    								
    								 ( )
```

## Examples

- C和C++中，使用`{}`来定义block，block中可以再包含block，从而形成nesting结构

- nltk的[Noun Phrase Chunking](http://www.nltk.org/book/ch07.html)

- python的[Python Language Services](https://docs.python.org/3/library/language.html)也使用括号来表示tree，总的来说，在字符终端中，使用括号是非常适合来表示tree的。
- matrix chain multiplication



### [Call stack](https://en.wikipedia.org/wiki/Call_stack) & stack & parenthese

TODO: 这个部分需要展开，要增加内容

龙书7.2.1 Activation Trees：

> Stack allocation would not be feasible if procedure calls, or activations of procedures, did not **nest** in time. 

即函数的执行过程，从时间上来看也是嵌套的。



### [Newick format](https://en.wikipedia.org/wiki/Newick_format) *and* [Dyck language](https://en.wikipedia.org/wiki/Dyck_language)

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





### parenthesis and stack

| Parenthesis | Stack |
| ----------- | ----- |
| 正括号      | 入栈  |
| 反括号      | 出栈  |

stack的入栈与出栈是一对互逆的操作，所以stack非常适合于解决哪些存在着互逆操作的问题；

对于[Dyck language](https://en.wikipedia.org/wiki/Dyck_language)，在对其进行parsing的时候，需要使用stack，其实我们进行parsing的时候，是沿着树进行深度优先遍历，一般我们进行parsing时候，遇到开括号`[`是要继续压栈，其实看上图就可以知道，压栈对应着是沿着树路径向下，即不断地向下遍历。遇到闭括号`]`，其实是出栈，开始向上了。



### wikipedia [Abstract syntax tree](https://en.wikipedia.org/wiki/Abstract_syntax_tree) and bracket

> For instance, grouping [parentheses](https://en.wikipedia.org/wiki/Bracket#Parentheses) are implicit in the tree structure, so these do not have to be represented as separate nodes. Likewise, a syntactic construct like an if-condition-then expression may be denoted by means of a single node with three branches.

[Reverse Polish Notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation) and bracket



## Catalan number

TODO



## LeetCode

https://leetcode.cn/problemset/all/?search=%E6%8B%AC%E5%8F%B7



## 素材

一、geeksforgeeks [Binary tree to string with brackets](https://www.geeksforgeeks.org/binary-tree-string-brackets/) 

二、DFA parenthese

DFA 本质上是线性的，因此它无法处理带括号的问题，带括号的是nesting的。

三、labuladong

labuladong [3 分钟看懂如何判断括号的合法性](https://mp.weixin.qq.com/s/o2MjTSIC4FkPscF5MnLXMQ)

labuladong [手把手解决三道括号相关的算法题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247487246&idx=1&sn=4a514020ce9dc8777e2d1d503188b62b&scene=21#wechat_redirect)

labuladong [回溯算法最佳实践：合法括号生成](https://mp.weixin.qq.com/s/XVnoX-lBzColVvVXNkGc5g)

