# Programming model

1、在维基百科 [Stream (computing)](https://en.wikipedia.org/wiki/Stream_(computing))中，其实已经涉及了对stream的programming model的描述，从中可以看出，stream的programming model可以采用functional programming paradigm的思想。

## 模式

### Pipeline、function composition模式

1、典型的模式是: 函数的输入输出都是stream，将上一个函数的输出作为下一个函数的输入，由此形成了pipeline。

2、这是典型的function composition

### Append模式

1、典型的例子就是C++ `std::stream` + `<<` operator、`>>` operator

`<<` operator，将数据写入到stream中；

`>>` operator，从stream中，读出数据；

2、它也是函数的输入输出都是stream



## 总结: assemble as chain

1、上述两种programming model都是非常优雅的，这是源自于stream结构的简单；

2、它们都是chain形的，都属于"assemble as chain"，关于此，参见:

工程`programming-language`的`Assemble-as-chain`章节



## 相关章节

在下面章节中，描述了相关内容:

1) 工程parallel-computing的`Programming-model`章节。

