# 如何描述structure？

如何来描述结构的结构？我们可以使用不同的语言来进行描述，在计算机科学中，我们往往描述方式往往是human-readable 且 machine-readable的。下面枚举了一些例子：

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



## 图与关系

图能够表示关系

如果从逻辑学的角度来看的话，我觉得关系其实是一种推导

production其实所表达的就是一种关系，nesting关系。这种关系可以使用tree来进行表示。