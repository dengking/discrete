# Bracket and tree

1、使用parenthese来表示tree，会形成一颗expression tree

## 使用括号来表示tree

已经看到了有两个项目都是使用括号来表示tree的：

- nltk的[Noun Phrase Chunking](http://www.nltk.org/book/ch07.html)
- python的[Python Language Services](https://docs.python.org/3/library/language.html)也使用括号来表示tree

总的来说，在字符终端中，使用括号是非常适合来表示tree的。



## geeksforgeeks [Binary tree to string with brackets](https://www.geeksforgeeks.org/binary-tree-string-brackets/)



## geeksforgeeks [Construct Binary Tree from String with bracket representation](https://www.geeksforgeeks.org/construct-binary-tree-string-bracket-representation/)



## wikipedia [Bracket (tournament)](https://en.wikipedia.org/wiki/Bracket_(tournament))

A **bracket** or **tournament bracket** is a [tree diagram](https://en.wikipedia.org/wiki/Tree_structure) that represents the series of games played during a [knockout tournament](https://en.wikipedia.org/wiki/Knockout_tournament). Different knockout tournament formats have different brackets; the simplest and most common is that of the [single-elimination tournament](https://en.wikipedia.org/wiki/Single-elimination_tournament). The name "bracket" is [American English](https://en.wikipedia.org/wiki/American_English), derived from the resemblance of the links in the tree diagram to the [bracket](https://en.wikipedia.org/wiki/Bracket) punctuation symbol ] or [ (called a "square bracket" in [British English](https://en.wikipedia.org/wiki/British_English)). The closest British term is **draw**, although this implies an element of chance, whereas some brackets are determined entirely by [seeding](https://en.wikipedia.org/wiki/Seed_(sports)).



## wikipedia [Abstract syntax tree](https://en.wikipedia.org/wiki/Abstract_syntax_tree) and bracket

> For instance, grouping [parentheses](https://en.wikipedia.org/wiki/Bracket#Parentheses) are implicit in the tree structure, so these do not have to be represented as separate nodes. Likewise, a syntactic construct like an if-condition-then expression may be denoted by means of a single node with three branches.

[Reverse Polish Notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation) and bracket







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

### parenthesis and stack

|        |      |
| ------ | ---- |
| 正括号 | 入栈 |
| 反括号 | 出栈 |



***SUMMARY*** : stack的入栈与出栈是一对户逆的操作，所以stack非常适合于解决哪些存在着互逆操作的问题；





## 思考：如何使用递归来实现括号匹配？？

一般我们都是使用一个显示的stack，那么如何使用递归来使用call stack呢？







## 使用括号来表示树

[Nesting](https://en.wikipedia.org/wiki/Nesting_(computing))结构在computer science是非常常见，它是一种典型的hierarchy结构，nesting结构可以使用括号的方式来进行表示：

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

例子包括：

- C和C++中，使用`{}`来定义block，block中可以再包含block，从而形成nesting结构

- 龙书7.2.1 Activation Trees：

    > Stack allocation would not be feasible if procedure calls, or activations of procedures, did not **nest** in time. 

    即函数的执行过程，从时间上来看也是嵌套的。

