# Representation/implementation/of relation

在computer science中，如何实现relation呢？这是一个非常宏大的问题，在computer science的不同领域，使用不同的语言来，在计算机科学中，我们往往描述方式往往是human-readable 且 machine-readable的。

## DBMS

在DBMS中，广泛采用entity-relationship model，使用table来保存relation

## OOP

在OOP中，inheritance、combination可以描述大部分relationship

## Book-Discrete-Mathematics-and-Its-Applications

在`Book-Discrete-Mathematics-and-Its-Applications\Chpater-9-Relations\9.3-Representing-Relations`中给出了如下两种方式：

1. **Representing Relations Using Matrices**

    

2. **Representing Relations Using Digraphs( directed graphs )**

   directed graph是一种非常强大的表达方式，在本书中，基本上都是基于directed graph来描述relation的。在`Relation-structure-computation\Structure\Data-structure\Graph`中对graph进行描述。



## ASDL

cpython 使用ASDL来描述自己的AST，关于ASDL，参见：

https://www.usenix.org/legacy/publications/library/proceedings/dsl97/full_papers/wang/wang.pdf

http://www.oilshell.org/blog/2016/12/11.html

https://stackoverflow.com/questions/8873126/zephyr-asdl-abstract-syntax-description-language

https://devguide.python.org/compiler/

https://github.com/python/cpython/blob/master/Parser/Python.asdl

http://asdl.sourceforge.net/

https://www.cs.princeton.edu/research/techreps/TR-554-97

显然，它也可以作为一种树描述语言。

https://en.wikipedia.org/wiki/Algebraic_data_type

https://en.wikipedia.org/wiki/Abstract_syntax

## Grammar

Grammar是对语言结构的描述，使用[production](https://en.wikipedia.org/wiki/Production_(computer_science))来表示grammar。

## Function

按照数学定义，relation是集合的笛卡尔积的子集。表示一个relation，一种可选的方式是枚举出所有的ordered pair，可以将它们组织成graph。另外一种方式是使用类似于grammar、function的工具来描述relation的“生成方法”，所谓“生成方法”其实就是确定哪些ordered pair是符合该关系的。


