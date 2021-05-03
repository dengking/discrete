# Bracket and tree

1、使用parenthese来表示tree，会形成一颗expression tree，关于此的最最典型的例子是 matrix chain multiplication

2、与它密切相关的问题是: Catalan

## 括号 和 tree 的对应关系

括号表示的 "contain/nest" 关系，tree中，parent node "contain/nest" children node，因此最外层括号对应的是root node。

## 使用括号来表示tree



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

### Examples

例子包括：

1、C和C++中，使用`{}`来定义block，block中可以再包含block，从而形成nesting结构

2、龙书7.2.1 Activation Trees：

> Stack allocation would not be feasible if procedure calls, or activations of procedures, did not **nest** in time. 

即函数的执行过程，从时间上来看也是嵌套的。

已经看到了有两个项目都是使用括号来表示tree的：

3、nltk的[Noun Phrase Chunking](http://www.nltk.org/book/ch07.html)

4、python的[Python Language Services](https://docs.python.org/3/library/language.html)也使用括号来表示tree

总的来说，在字符终端中，使用括号是非常适合来表示tree的。



## wikipedia [Abstract syntax tree](https://en.wikipedia.org/wiki/Abstract_syntax_tree) and bracket

> For instance, grouping [parentheses](https://en.wikipedia.org/wiki/Bracket#Parentheses) are implicit in the tree structure, so these do not have to be represented as separate nodes. Likewise, a syntactic construct like an if-condition-then expression may be denoted by means of a single node with three branches.

[Reverse Polish Notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation) and bracket





